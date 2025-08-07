#include "ImageApplication.h"
#include "MyRandom.h"

#include <omp_llvm.h>
#include <cstring>
#include <chrono>


using namespace System;
using namespace System::IO;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Windows::Forms::DataVisualization::Charting;
using namespace System::Runtime::InteropServices;

namespace NTNUAIP {

	// create single color image
	Bitmap^ ImageApplication::Fill(int width, int height, Color color) {
		Bitmap^ img = gcnew Bitmap(width, height);
		Graphics^ g = Graphics::FromImage(img);
		g->Clear(color);
		return img;
	}
	// fill image with color
	Bitmap^ ImageApplication::Fill(Bitmap^ img, Color color) {
		return Fill(img->Width, img->Height, color);
	}

	// convert to gray image G = 0.299 * R + 0.587 * G + 0.114 * B
	Bitmap^ ImageApplication::ToGray(Bitmap^ img) {
		array<Byte>^ raw = GetRaw(img);
		#pragma omp parallel for
		for (int offset = 0; offset < raw->Length; offset += 4) {
			Byte gray = (Byte)Math::Round(0.299 * raw[offset + R] + 0.587 * raw[offset + G] + 0.114 * raw[offset + B]);
			raw[offset + R] = raw[offset + G] = raw[offset + B] = gray;
		}
		return FromRaw(raw, img->Width, img->Height);
	}
	// convert to gray image G = (R + G + B) / 3
	Bitmap^ ImageApplication::ToGrayAverage(Bitmap^ img) {
		array<Byte>^ raw = GetRaw(img);
		#pragma omp parallel for
		for (int offset = 0; offset < raw->Length; offset += 4) {
			Byte gray = (Byte)Math::Round((raw[offset + R] + raw[offset + G] + raw[offset + B]) / 3.0);
			raw[offset + R] = raw[offset + G] = raw[offset + B] = gray;
		}
		return FromRaw(raw, img->Width, img->Height);
	}
	// convert to red only image
	Bitmap^ ImageApplication::RedOnly(Bitmap^ img) {
		array<Byte>^ raw = GetRaw(img);
		#pragma omp parallel for
		for (int offset = 0; offset < raw->Length; offset += 4) {
			raw[offset + G] = raw[offset + B] = BLACK;
		}
		return FromRaw(raw, img->Width, img->Height);
	}
	// convert to green only image
	Bitmap^ ImageApplication::GreenOnly(Bitmap^ img) {
		array<Byte>^ raw = GetRaw(img);
		#pragma omp parallel for
		for (int offset = 0; offset < raw->Length; offset += 4) {
			raw[offset + R] = raw[offset + B] = BLACK;
		}
		return FromRaw(raw, img->Width, img->Height);
	}
	// convert to blue only image
	Bitmap^ ImageApplication::BlueOnly(Bitmap^ img) {
		array<Byte>^ raw = GetRaw(img);
		#pragma omp parallel for
		for (int offset = 0; offset < raw->Length; offset += 4) {
			raw[offset + R] = raw[offset + G] = BLACK;
		}
		return FromRaw(raw, img->Width, img->Height);
	}
	// increase image brightness
	Bitmap^ ImageApplication::Brighten(Bitmap^ img) {
		array<Byte>^ raw = GetRaw(img);
		array<int>^ rgb = gcnew array<int>{ R, G, B };
		#pragma omp parallel for
		for (int offset = 0; offset < raw->Length; offset += 4) {
			for each (int c in rgb) {
				raw[offset + c] = raw[offset + c] / 2 + GRAY;
			}
		}
		return FromRaw(raw, img->Width, img->Height);
	}
	// decrease image brightness
	Bitmap^ ImageApplication::Darken(Bitmap^ img) {
		array<Byte>^ raw = GetRaw(img);
		const int rgb[3] = { R, G, B };
		#pragma omp parallel for
		for (int offset = 0; offset < raw->Length; offset += 4) {
			for (int c : rgb) {
				raw[offset + c] = raw[offset + c] / 2;
			}
		}
		return FromRaw(raw, img->Width, img->Height);
	}
	// transform brightness by given corresponding grayscale
	Bitmap^ ImageApplication::BrightnessTransform(Bitmap^ img, array<Byte>^ grayscale) {
		array<int>::Resize(grayscale, WHITE + 1);	// resize to enough size
		array<Byte>^ raw = GetRaw(img);
		const int rgb[3] = { R, G, B };
		#pragma omp parallel for
		for (int offset = 0; offset < raw->Length; offset += 4) {
			for (int c : rgb) {
				raw[offset + c] = grayscale[raw[offset + c]];
			}
		}
		return FromRaw(raw, img->Width, img->Height);
	}
	// transform brightness using histogram equalization
	Bitmap^ ImageApplication::HistogramEqualization(Bitmap^ img) {
		Bitmap^ grayimg = ToGray(img);
		array<int>^ graycounter = Counter(grayimg);
		array<int>^ agc = gcnew array<int>(graycounter->Length);
		int min_agc = 0;
		for (int g = 0; g <= WHITE; ++g) {
			if (graycounter[g]) {
				min_agc = agc[g];
				break;
			}
		}
		// accumulate gray counter
		agc[0] = graycounter[0];
		for (int i = 1; i <= WHITE; ++i) {
			agc[i] = agc[i - 1] + graycounter[i];
		}
		// calculate new gray value
		const int NM = img->Width * img->Height;
		array<Byte>^ grayscale = gcnew array<Byte>(WHITE + 1);
		for (int g = 0; g <= WHITE; ++g) {
			grayscale[g] = (Byte)Math::Round((double)(agc[g] - min_agc) / (double)(NM - min_agc) * (double)(WHITE));
		}
		Bitmap^ heimg = BrightnessTransform(grayimg, grayscale);
		// transform on color image
		array<Byte>^ raw = GetRaw(img);
		array<Byte>^ grayraw = GetRaw(grayimg);
		const int rgb[3] = { R, G, B };
		#pragma omp parallel for
		for (int offset = 0; offset < raw->Length; offset += 4) {
			const Byte gray = grayraw[offset + R];
			const Byte hegray = grayscale[gray];
			if (gray != BLACK) {
				const double scale = (double)(hegray) / (double)(gray);
				for (int c : rgb) {
					raw[offset + c] = (Byte)Math::Round((double)(raw[offset + c]) * scale);
				}
			}
		}
		return FromRaw(raw, img->Width, img->Height);
	}
	// convert to negative image
	Bitmap^ ImageApplication::Negative(Bitmap^ img) {
		array<Byte>^ raw = GetRaw(img);
		const int rgb[3] = { R, G, B };
		#pragma omp parallel for
		for (int offset = 0; offset < raw->Length; offset += 4) {
			for (int c : rgb) {
				raw[offset + c] = 255 - raw[offset + c];
			}
		}
		return FromRaw(raw, img->Width, img->Height);
	}

	// rotate 90 degree
	Bitmap^ ImageApplication::Rotate90(Bitmap^ img) {
		img->RotateFlip(RotateFlipType::Rotate90FlipNone);
		return img;
	}
	// rotate 180 degree
	Bitmap^ ImageApplication::Rotate180(Bitmap^ img) {
		img->RotateFlip(RotateFlipType::Rotate180FlipNone);
		return img;
	}
	// rotate 270 degree
	Bitmap^ ImageApplication::Rotate270(Bitmap^ img) {
		img->RotateFlip(RotateFlipType::Rotate270FlipNone);
		return img;
	}

	// convolves image with kernel
	Bitmap^ ImageApplication::Convolution(Bitmap^ img, array<double, 2>^ kernel) {
		array<Byte>^ raw = GetRaw(img);
		const int width = img->Width;
		const int height = img->Height;
		const int kwidth = kernel->GetLength(1);
		const int kheight = kernel->GetLength(0);
		const int nwidth = width - (kwidth - 1);
		const int nheight = height - (kheight - 1);
		array<double>^ newraw = gcnew array<double>(nwidth * nheight * 4);
		const int rgb[3] = { R, G, B };
		const double k[25] = { kernel[0, 0], kernel[0, 1], kernel[0, 2], kernel[0, 3], kernel[0, 4],
							   kernel[1, 0], kernel[1, 1], kernel[1, 2], kernel[1, 3], kernel[1, 4], 
							   kernel[2, 0], kernel[2, 1], kernel[2, 2], kernel[2, 3], kernel[2, 4],
							   kernel[3, 0], kernel[3, 1], kernel[3, 2], kernel[3, 3], kernel[3, 4],
							   kernel[4, 0], kernel[4, 1], kernel[4, 2], kernel[4, 3], kernel[4, 4] };
		#pragma omp parallel for // collapse(2)
		for (int nh = 0; nh < nheight; ++nh) {
			for (int nw = 0; nw < nwidth; ++nw) {
				const int noffset = (nh * nwidth + nw) * 4;
				for each (int c in rgb) {
					double val = 0.0;
					for (int kh = 0, koffset = 0; kh < kheight; ++kh) {
						for (int kw = 0; kw < kwidth; ++koffset, ++kw) {
							const int h = nh + kh;
							const int w = nw + kw;
							const int offset = (h * width + w) * 4;
							val += (double)(raw[offset + c]) * k[koffset];
						}
					}
					newraw[noffset + c] = val;
				}
				newraw[noffset + A] = (double)(WHITE);
			}
		}
		Bitmap^ newimg = FromRaw(newraw, nwidth, nheight);
		return newimg;
	}

	// add box blur to output image
	Bitmap^ ImageApplication::BoxBlur(Bitmap^ img) {
		array<double, 2>^ kernel = {
			{ 0.04, 0.04, 0.04, 0.04, 0.04 },
			{ 0.04, 0.04, 0.04, 0.04, 0.04 },
			{ 0.04, 0.04, 0.04, 0.04, 0.04 },
			{ 0.04, 0.04, 0.04, 0.04, 0.04 },
			{ 0.04, 0.04, 0.04, 0.04, 0.04 }
		};
		img = AddBorder(img, 2, 2, 2, 2);
		return Convolution(img, kernel);
	}
	// add Gaussian blur to output image
	Bitmap^ ImageApplication::GaussianBlur(Bitmap^ img) {
		array<double, 2>^ kernel = {
			{  1.0 / 273.0,  4.0 / 273.0,  7.0 / 273.0,  4.0 / 273.0,  1.0 / 273.0 },
			{  4.0 / 273.0, 16.0 / 273.0, 26.0 / 273.0, 16.0 / 273.0,  4.0 / 273.0 },
			{  7.0 / 273.0, 26.0 / 273.0, 41.0 / 273.0, 26.0 / 273.0,  7.0 / 273.0 },
			{  4.0 / 273.0, 16.0 / 273.0, 26.0 / 273.0, 16.0 / 273.0,  4.0 / 273.0 },
			{  1.0 / 273.0,  4.0 / 273.0,  7.0 / 273.0,  4.0 / 273.0,  1.0 / 273.0 }
		};
		return Convolution(AddBorder(img, 2, 2, 2, 2), kernel);
	}

	// detection edge of output image
	Bitmap^ ImageApplication::EdgeDetection(Bitmap^ img) {
		array<double, 2>^ kernel = {
			{  0.0,  0.0, -1.0,  0.0,  0.0 },
			{  0.0, -1.0, -2.0, -1.0,  0.0 },
			{ -1.0, -2.0, 16.0, -2.0, -1.0 },
			{  0.0, -1.0, -2.0, -1.0,  0.0 },
			{  0.0,  0.0, -1.0,  0.0,  0.0 }
		};
		return Convolution(AddBorder(img, 2, 2, 2, 2), kernel);
	}
	// detection horizontal edge of output image
	Bitmap^ ImageApplication::EdgeDetectionHorizontal(Bitmap^ img) {
		array<double, 2>^ kernel = {
			{  2.0,  2.0,  4.0,  2.0,  2.0 },
			{  1.0,  1.0,  2.0,  1.0,  1.0 },
			{  0.0,  0.0,  0.0,  0.0,  0.0 },
			{ -1.0, -1.0, -2.0, -1.0, -1.0 },
			{ -2.0, -2.0, -4.0, -2.0, -2.0 }
		};
		return Convolution(AddBorder(img, 2, 2, 2, 2), kernel);
	}
	// detection vertical edge of output image
	Bitmap^ ImageApplication::EdgeDetectionVertical(Bitmap^ img) {
		array<double, 2>^ kernel = {
			{  2.0,  1.0,  0.0, -1.0, -2.0 },
			{  2.0,  1.0,  0.0, -1.0, -2.0 },
			{  4.0,  2.0,  0.0, -2.0, -4.0 },
			{  2.0,  1.0,  0.0, -1.0, -2.0 },
			{  2.0,  1.0,  0.0, -1.0, -2.0 }
		};
		return Convolution(AddBorder(img, 2, 2, 2, 2), kernel);
	}

	// show Gaussian noise image
	Bitmap^ ImageApplication::OnlyGaussianNoiseGray(int width, int height, double sigma) {
		return AddGaussianNoiseGray(Fill(width, height, Color::Gray), sigma);
	}
	// show Gaussian noise image
	Bitmap^ ImageApplication::OnlyGaussianNoiseRGB(int width, int height, double sigma) {
		return AddGaussianNoiseRGB(Fill(width, height, Color::Gray), sigma);
	}
	// show Gaussian noise image
	Bitmap^ ImageApplication::AddGaussianNoiseGray(Bitmap^ img, double sigma) {
		MyRandom^ rand = gcnew MyRandom();
		array<Byte>^ raw = GetRaw(img);
		array<double>^ rands = rand->NormalRandomVariables(img->Width * img->Height, 0.0, sigma);
		for (int i = 0, offset = 0; offset < raw->Length; ++i, offset += 4) {
			raw[offset + R] = (Byte)Math::Round(Clamp((double)(raw[offset + R]) + rands[i]));
			raw[offset + G] = (Byte)Math::Round(Clamp((double)(raw[offset + G]) + rands[i]));
			raw[offset + B] = (Byte)Math::Round(Clamp((double)(raw[offset + B]) + rands[i]));
			raw[offset + A] = WHITE;
		}
		return FromRaw(raw, img->Width, img->Height);
	}
	// show Gaussian noise image
	Bitmap^ ImageApplication::AddGaussianNoiseRGB(Bitmap^ img, double sigma) {
		MyRandom^ rand = gcnew MyRandom();
		array<Byte>^ raw = GetRaw(img);
		array<double>^ rands = rand->NormalRandomVariables(img->Width * img->Height * 3, 0.0, sigma);
		for (int i = 0, offset = 0; offset < raw->Length; i += 3, offset += 4) {
			raw[offset + R] = (Byte)Math::Round(Clamp((double)(raw[offset + R]) + rands[i]));
			raw[offset + G] = (Byte)Math::Round(Clamp((double)(raw[offset + G]) + rands[i + 1]));
			raw[offset + B] = (Byte)Math::Round(Clamp((double)(raw[offset + B]) + rands[i + 2]));
			raw[offset + A] = WHITE;
		}
		return FromRaw(raw, img->Width, img->Height);
	}
	// show gray salt-and-pepper noise image
	Bitmap^ ImageApplication::OnlySaltAndPepperNoiseGray(int width, int height, double probability) {
		return AddSaltAndPepperNoiseGray(Fill(width, height, Color::Gray), probability);
	}
	// show color salt-and-pepper noise image
	Bitmap^ ImageApplication::OnlySaltAndPepperNoiseRGB(int width, int height, double probability) {
		return AddSaltAndPepperNoiseRGB(Fill(width, height, Color::Gray), probability);
	}
	// add gray salt-and-pepper noise to output image
	Bitmap^ ImageApplication::AddSaltAndPepperNoiseGray(Bitmap^ img, double probability) {
		MyRandom^ rand = gcnew MyRandom();
		array<Byte>^ raw = GetRaw(img);
		array<bool>^ rands = rand->BernoulliRandomVariables(img->Width * img->Height, probability);
		for (int i = 0, offset = 0; offset < raw->Length; ++i, offset += 4) {
			if (rands[i]) {
				Byte color = WHITE;
				if (rand->NextDouble() < 0.5) {
					color = BLACK;
				}
				raw[offset + R] = raw[offset + G] = raw[offset + B] = color;
			}
			raw[offset + A] = WHITE;
		}
		return FromRaw(raw, img->Width, img->Height);
	}
	// add color salt-and-pepper noise to output image
	Bitmap^ ImageApplication::AddSaltAndPepperNoiseRGB(Bitmap^ img, double probability) {
		MyRandom^ rand = gcnew MyRandom();
		array<Byte>^ raw = GetRaw(img);
		array<int>^ rgb = {R, G, B};
		const int clen = rgb->Length;
		array<bool>^ rands = rand->BernoulliRandomVariables(img->Width * img->Height * 3, probability);
		for (int i = 0, offset = 0; offset < raw->Length; offset += 4) {
			for (int c = 0; c < rgb->Length; ++i, ++c) {
				if (rands[i]) {
					Byte color = WHITE;
					if (rand->NextDouble() < 0.5) {
						color = BLACK;
					}
					raw[offset + rgb[c]] = color;
				}
			}
			raw[offset + A] = WHITE;
		}
		return FromRaw(raw, img->Width, img->Height);
	}

	// create histogram for brightness of gray image
	Bitmap^ ImageApplication::ToHistogramBrightnessGray(Bitmap^ img) {
		// conver to gray image first
		img = ToGray(img);
		// counter
		array<int>^ counter = Counter(img);
		// craete chart
		Series^ series = CreateSeries(counter, Color::Gray);
		Chart^ chart = CreateChart(gcnew array<Series^>{series});
		return FromChart(chart);
	}
	// create histogram for red brightness of image
	Bitmap^ ImageApplication::ToHistogramBrightnessRed(Bitmap^ img) {
		// counter
		array<int>^ counter = Counter(img, R);
		// craete chart
		Series^ series = CreateSeries(counter, Color::IndianRed);
		Chart^ chart = CreateChart(gcnew array<Series^>{series});
		return FromChart(chart);
	}
	// create histogram for green brightness of image
	Bitmap^ ImageApplication::ToHistogramBrightnessGreen(Bitmap^ img) {
		// counter
		array<int>^ counter = Counter(img, G);
		// craete chart
		Series^ series = CreateSeries(counter, Color::MediumSeaGreen);
		Chart^ chart = CreateChart(gcnew array<Series^>{series});
		return FromChart(chart);
	}
	// create histogram for blue brightness of image
	Bitmap^ ImageApplication::ToHistogramBrightnessBlue(Bitmap^ img) {
		// counter
		array<int>^ counter = Counter(img, B);
		// craete chart
		Series^ series = CreateSeries(counter, Color::LightSkyBlue);
		Chart^ chart = CreateChart(gcnew array<Series^>{series});
		return FromChart(chart);
	}
	// create histogram for RGB brightnesses of image
	Bitmap^ ImageApplication::ToHistogramBrightnessRGB(Bitmap^ img) {
		// counter
		array<Byte>^ raw = GetRaw(img);
		array<int>^ counterRed = CounterRaw(raw, R);
		array<int>^ counterGreen = CounterRaw(raw, G);
		array<int>^ counterBlue = CounterRaw(raw, B);
		// craete chart
		Series^ seriesRed = CreateSeries(counterRed, Color::FromArgb(128, Color::IndianRed));
		Series^ seriesGreen = CreateSeries(counterGreen, Color::FromArgb(128, Color::MediumSeaGreen));
		Series^ seriesBlue = CreateSeries(counterBlue, Color::FromArgb(128, Color::LightSkyBlue));
		Chart^ chart = CreateChart(gcnew array<Series^>{seriesRed, seriesGreen, seriesBlue});
		return FromChart(chart);
	}

	// get raw data from image
	array<Byte>^ ImageApplication::GetRaw(Bitmap^ img) {
		if (!img) {
			return nullptr;
		}
		BitmapData^ data = img->LockBits(Rectangle(0, 0, img->Width, img->Height), ImageLockMode::ReadOnly, PixelFormat::Format32bppArgb);
		int len = data->Stride * data->Height;
		array<Byte>^ raw = gcnew array<Byte>(len);
		Marshal::Copy(data->Scan0, raw, 0, len);
		img->UnlockBits(data);
		return raw;
	}
	// get raw data from image
	Byte* ImageApplication::GetCRaw(Bitmap^ img) {
		if (!img) {
			return nullptr;
		}
		BitmapData^ data = img->LockBits(Rectangle(0, 0, img->Width, img->Height), ImageLockMode::ReadOnly, PixelFormat::Format32bppArgb);
		int len = data->Stride * data->Height;
		Byte* raw = new Byte[len];
		memcpy(raw, data->Scan0.ToPointer(), len);
		img->UnlockBits(data);
		return raw;
	}
	// get image from raw data
	Bitmap^ ImageApplication::FromRaw(array<Byte>^ raw, int width, int height) {
		Bitmap^ img = gcnew Bitmap(width, height);
		BitmapData^ data = img->LockBits(Rectangle(0, 0, img->Width, img->Height), ImageLockMode::WriteOnly, PixelFormat::Format32bppArgb);
		Marshal::Copy(raw, 0, data->Scan0, raw->Length);
		img->UnlockBits(data);
		return img;
	}
	// get image from raw float data
	Bitmap^ ImageApplication::FromRaw(array<double>^ raw, int width, int height) {
		array<Byte>^ byteraw = gcnew array<Byte>(width * height * 4);
		#pragma omp parallel for
		for (int offset = 0; offset < raw->Length; ++offset) {
			byteraw[offset] = (Byte)Math::Round(Clamp(raw[offset], 0.0, 255.0));
		}
		return FromRaw(byteraw, width, height);
	}
	// get image from raw data
	Bitmap^ ImageApplication::FromCRaw(Byte* raw, int width, int height) {
		Bitmap^ img = gcnew Bitmap(width, height);
		BitmapData^ data = img->LockBits(Rectangle(0, 0, img->Width, img->Height), ImageLockMode::WriteOnly, PixelFormat::Format32bppArgb);
		memcpy(data->Scan0.ToPointer(), raw, width * height * 4);
		img->UnlockBits(data);
		return img;
	}
	// get image from raw float data
	Bitmap^ ImageApplication::FromCRaw(double* raw, int width, int height) {
		const int len = width * height * 4;
		Byte* byteraw = new Byte[len];
		#pragma omp parallel for
		for (int offset = 0; offset < len; ++offset) {
			byteraw[offset] = (Byte)Math::Round(Clamp(raw[offset], 0.0, 255.0));
		}
		Bitmap^ img = FromCRaw(byteraw, width, height);
		delete[] byteraw;
		return img;
	}

	// count brightness with specified channel in raw data
	array<int>^ ImageApplication::CounterRaw(array<Byte>^ raw, int channel) {
		array<int>^ counter = gcnew array<int>(WHITE + 1);
		#pragma omp parallel
		{
			array<int>^ thread_counter = gcnew array<int>(WHITE + 1);
			#pragma omp for
			for (int offset = channel; offset < raw->Length; offset += 4) {
				++thread_counter[raw[offset]];
			}
			#pragma omp critical
			{
				for (int g = 0; g <= WHITE; ++g) {
					counter[g] += thread_counter[g];
				}
			}
		}
		return counter;
	}
	// count brightness with specified channel
	array<int>^ ImageApplication::Counter(Bitmap^ img, int channel) {
		array<Byte>^ raw = GetRaw(img);
		return CounterRaw(raw, channel);
	}

	// add reflect101 border to image
	Bitmap^ ImageApplication::AddBorder(Bitmap^ img, int top, int bottom, int left, int right) {
		const int width = img->Width;
		const int height = img->Height;
		const int stride = width * 4;
		array<Byte>^ raw = GetRaw(img);
		const int nwidth = left + width + right;
		const int nheight = top + height + bottom;
		const int nstride = nwidth * 4;
		array<Byte>^ newraw = gcnew array<Byte>(nstride * nheight);
		array<int>^ argb = { A, R, G, B };
		const int clen = argb->Length;
		// copy
		for (int h = 0; h < height; ++h) {
			Array::Copy(raw, h * stride, newraw, (top + h) * nstride + left * 4, stride);
		}
		// left
		for (int nw = left - 1, w = left + 1; nw >= 0; --nw, ++w) {
			if (w - nw >= 2 * width) {
				w = nw + 2;
			}
			for (int nh = top; nh < top + height; ++nh) {
				for (int c = 0; c < clen; ++c) {
					newraw[(nh * nwidth + nw) * 4 + argb[c]] = newraw[(nh * nwidth + w) * 4 + argb[c]];
				}
			}
		}
		// right
		for (int nw = left + width, w = left + width - 2; nw < nwidth; ++nw, --w) {
			if (nw - w >= 2 * width) {
				w = nw - 2;
			}
			for (int nh = top; nh < top + height; ++nh) {
				for (int c = 0; c < clen; ++c) {
					newraw[(nh * nwidth + nw) * 4 + argb[c]] = newraw[(nh * nwidth + w) * 4 + argb[c]];
				}
			}
		}
		// top
		for (int nh = top - 1, h = top + 1; nh >= 0; --nh, ++h) {
			if (h - nh >= 2 * height) {
				h = nh + 2;
			}
			Array::Copy(newraw, h * nstride, newraw, nh * nstride, nstride);
		}
		// bottom
		for (int nh = top + height, h = top + height - 2; nh < nheight; ++nh, --h) {
			if (nh - h >= 2 * height) {
				h = nh - 2;
			}
			Array::Copy(newraw, h * nstride, newraw, nh * nstride, nstride);
		}
		return FromRaw(newraw, nwidth, nheight);
	}
	
	// create series with info
	Series^ ImageApplication::CreateSeries(array<int>^ counter, Color color) {
		Series^ series = gcnew Series();
		series->IsVisibleInLegend = false;
		series->ChartType = SeriesChartType::Column;
		series->SetCustomProperty("PointWidth", "1");
		series->SetCustomProperty("DrawSideBySide", "False");
		series->Color = color;
		if (counter) {
			for (int i = 0; i <= WHITE; ++i) {
				series->Points->AddXY(i, counter[i]);
			}
		}
		return series;
	}
	// create series with series
	Chart^ ImageApplication::CreateChart(array<Series^>^ series) {
		ChartArea^ area = gcnew ChartArea();
		Chart^ chart = gcnew Chart();
		chart->Width = 480;
		chart->Height = 480;
		if (series) {
			for (int i = 0; i < series->Length; ++i) {
				chart->Series->Add(series[i]);
			}
		}
		area->AxisX->Title = L"亮度";
		area->AxisY->Title = L"個數";
		area->AxisX->TitleFont = gcnew Font(L"微軟正黑體", 12);
		area->AxisY->TitleFont = gcnew Font(L"微軟正黑體", 12);
		area->AxisX->Minimum = 0;
		area->AxisX->Maximum = 255;
		area->AxisX->Interval = 50;
		area->AxisX->MajorGrid->Enabled = false;
		area->AxisX->MinorGrid->Enabled = false;
		area->AxisY->MajorGrid->Enabled = false;
		area->AxisY->MinorGrid->Enabled = false;
		chart->ChartAreas->Add(area);
		return chart;
	}
	// get image from chart
	Bitmap^ ImageApplication::FromChart(Chart^ chart) {
		MemoryStream^ ms = gcnew MemoryStream();
		chart->SaveImage(ms, ImageFormat::Png);
		return gcnew Bitmap(ms);
	}
}