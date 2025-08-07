#include "MainForm.h"
#include "Netpbm.h"
#include "ImageApplication.h"
#include "InputDecimalForm.h"
#include "InputMatrixForm.h"

using namespace System;
using namespace System::IO;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::Windows::Forms;

namespace NTNUAIP {

	// enable options
	System::Void MainForm::EnableImageOptions() {
		this->SaveImageToolStripMenuItem->Enabled = true;
		this->ResetImageToolStripMenuItem->Enabled = true;
		this->CloseImageToolStripMenuItem->Enabled = true;
		this->ColorToolStripMenuItem->Enabled = true;
		this->RotateToolStripMenuItem->Enabled = true;
		this->ConvolutionToolStripMenuItem->Enabled = true;
		this->NoiseToolStripMenuItem->Enabled = true;
		this->StatisticsToolStripMenuItem->Enabled = true;
	}

	// disable options
	System::Void MainForm::DisableImageOptions() {
		this->SaveImageToolStripMenuItem->Enabled = false;
		this->ResetImageToolStripMenuItem->Enabled = false;
		this->CloseImageToolStripMenuItem->Enabled = false;
		this->ColorToolStripMenuItem->Enabled = false;
		this->RotateToolStripMenuItem->Enabled = false;
		this->ConvolutionToolStripMenuItem->Enabled = false;
		this->NoiseToolStripMenuItem->Enabled = false;
		this->StatisticsToolStripMenuItem->Enabled = false;
	}

	// release current image
	System::Void MainForm::ReleaseImage() {
		// release both
		this->ReleaseOriginalImage();
		this->ReleaseOutputImage();
	}

	System::Void MainForm::ReleaseOriginalImage() {
		if (this->OriginalPictureBox->Image) {
			this->OriginalPictureBox->Image = nullptr;
		}
		if (this->OriginalImage) {
			this->OriginalImage = nullptr;
		}
		GC::Collect();
	}

	System::Void MainForm::ReleaseOutputImage() {
		if (this->OutputPictureBox->Image) {
			this->OutputPictureBox->Image = nullptr;
		}
		if (this->OutputImage) {
			this->OutputImage = nullptr;
		}
		GC::Collect();
	}

	// show both image
	System::Void MainForm::RenewImage() {
		this->RenewOriginalImage();
		this->RenewOutputImage();
	}

	System::Void MainForm::RenewOriginalImage() {
		::Size^ imgSize = this->OriginalImage->Size;
		::Size^ boxSize = this->OriginalPictureBox->Size;
		double scale = System::Math::Min(
			(double)(boxSize->Width) / (double)(imgSize->Width),
			(double)boxSize->Height / (double)(imgSize->Height)
		);
		if (scale > 2.0) {
			::Size^ newSize = gcnew ::Size(
				(int)System::Math::Round((double)imgSize->Width * scale),
				(int)System::Math::Round((double)imgSize->Height * scale)
			);
			Bitmap^ img = gcnew Bitmap(newSize->Width, newSize->Height);
			Graphics^ g = Graphics::FromImage(img);
			g->InterpolationMode = InterpolationMode::NearestNeighbor;
			g->PixelOffsetMode = PixelOffsetMode::Half;
			g->DrawImage(this->OriginalImage, 0, 0, newSize->Width, newSize->Height);
			this->OriginalPictureBox->Image = img;
		}
		else {
			this->OriginalPictureBox->Image = this->OriginalImage;
		}
		this->OriginalPictureBox->Refresh();
		GC::Collect();
	}

	System::Void MainForm::RenewOutputImage() {
		::Size^ imgSize = this->OutputImage->Size;
		::Size^ boxSize = this->OutputPictureBox->Size;
		double scale = System::Math::Min(
			(double)(boxSize->Width) / (double)(imgSize->Width),
			(double)(boxSize->Height) / (double)(imgSize->Height)
		);
		if (scale > 2.0) {
			::Size^ newSize = gcnew ::Size(
				(int)System::Math::Round((double)imgSize->Width * scale),
				(int)System::Math::Round((double)imgSize->Height * scale)
			);
			Bitmap^ img = gcnew Bitmap(newSize->Width, newSize->Height);
			Graphics^ g = Graphics::FromImage(img);
			g->InterpolationMode = InterpolationMode::NearestNeighbor;
			g->PixelOffsetMode = PixelOffsetMode::Half;
			g->DrawImage(this->OutputImage, 0, 0, newSize->Width, newSize->Height);
			this->OutputPictureBox->Image = img;
		}
		else {
			this->OutputPictureBox->Image = this->OutputImage;
		}
		this->OutputPictureBox->Refresh();
		GC::Collect();
	}

	// check size of output image
	System::Boolean MainForm::CheckSize(int width, int height) {
		return (width <= this->OutputImage->Width && height <= this->OutputImage->Height);
	}
	
	// show size error message
	System::Void MainForm::ShowSizeErrorMessage(int width, int height) {
		MessageBox::Show(String::Format(L"使用捲積操作時，\n"
										L"輸出圖片大小至少需與捲積遮罩一樣大。\n"
										L"(捲積遮罩大小: {0}x{1})", width, height), L"錯誤");
	}

	// open image file
	System::Void MainForm::OpenImageToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		// open image
		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		ofd->Title = L"開啟圖片";
		ofd->Filter = "Image Files(*.bmp;*.jpg;*.jpeg;*.png;*.pbm;*.pgm;*.ppm)|*.bmp;*.jpg;*.jpeg;*.png;*.pbm;*.pgm;*.ppm";
		// cancel selection
		if (ofd->ShowDialog() != ::DialogResult::OK) {
			return ;
		}
		// confirm selection
		FileStream^ fs = nullptr;
		Bitmap^ img = nullptr;
		try {
			fs = gcnew FileStream(ofd->FileName, FileMode::Open, FileAccess::Read);
			String^ extension = Path::GetExtension(ofd->FileName)->ToLower();
			if (Netpbm::CheckSignature(fs)) {
				img = Netpbm::ToBitmap(fs);
			}
			else {
				img = gcnew Bitmap(fs);
			}
		}
		catch (System::Exception^) {
			MessageBox::Show(L"載入圖片失敗！\n不支援的圖片格式或圖片格式有誤！", L"錯誤");
			return ;
		}
		finally {
			if (fs) {
				fs->Close();
			}
		}
		// successfully read image
		this->ReleaseImage();		// release current image first
		this->OriginalImage = img;
		this->OutputImage = gcnew Bitmap(img);
		this->EnableImageOptions();
		this->RenewImage();
	}
	// save image file
	System::Void MainForm::SaveImageToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		SaveFileDialog^ sfd = gcnew SaveFileDialog();
		sfd->Title = L"儲存圖片";
		sfd->FileName = "image";
		sfd->Filter = "BPM Image(*.bmp)|*.bmp|JPEG Image(*.jpg;*.jpeg)|*.jpg;*.jpeg|PNG Image(*.png)|*.png";
		sfd->FilterIndex = 2;
		// cancel selection
		if (sfd->ShowDialog() != ::DialogResult::OK) {
			return;
		}
		// confirm selection
		String^ extension = Path::GetExtension(sfd->FileName)->ToLower();
		Imaging::ImageFormat^ fmt = nullptr;
		if (extension->Equals(".bmp")) {
			fmt = Imaging::ImageFormat::Bmp;
		}
		else if (extension->Equals(".jpg") || extension->Equals(".jpeg")) {
			fmt = Imaging::ImageFormat::Jpeg;
		}
		else if (extension->Equals(".png")) {
			fmt = Imaging::ImageFormat::Png;
		}
		this->OutputImage->Save(sfd->FileName, fmt);
	}
	// reset image
	System::Void MainForm::ResetImageToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		if (!this->OriginalImage) {
			return;
		}
		this->OutputImage = gcnew Bitmap(this->OriginalImage);
		this->RenewOutputImage();
	}
	// close image
	System::Void MainForm::CloseImageToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		// release image
		this->ReleaseImage();
		// disable options
		this->DisableImageOptions();
	}

	// convert to gray image G = 0.299 * R + 0.587 * G + 0.114 * B
	System::Void MainForm::GrayGeneralToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		this->TransformOutputImage(ImageApplication::ToGray);
	}
	// convert to gray image by average G = (R + G + B) / 3
	System::Void MainForm::GrayAverageToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		this->TransformOutputImage(ImageApplication::ToGrayAverage);
	}
	// convert to red only
	System::Void MainForm::RedOnlyToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		this->TransformOutputImage(ImageApplication::RedOnly);
	}
	// convert to green only
	System::Void MainForm::GreenOnlyToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		this->TransformOutputImage(ImageApplication::GreenOnly);
	}
	// convert to blue only
	System::Void MainForm::BlueOnlyToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		this->TransformOutputImage(ImageApplication::BlueOnly);
	}
	// increase image brightness
	System::Void MainForm::BrightenToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		this->TransformOutputImage(ImageApplication::Brighten);
	}
	// decrease image brightness
	System::Void MainForm::DarkenToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		this->TransformOutputImage(ImageApplication::Darken);
	}
	// histogram equalization transform
	System::Void MainForm::HistogramEqualizationToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		this->TransformOutputImage(ImageApplication::HistogramEqualization);
	}
	// convert to negative image
	System::Void MainForm::NegativeToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		this->TransformOutputImage(ImageApplication::Negative);
	}

	// rotate 90 degree
	System::Void MainForm::Rotation90ToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		this->TransformOutputImage(ImageApplication::Rotate90);
	}
	// rotate 180 degree
	System::Void MainForm::Rotation180ToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		this->TransformOutputImage(ImageApplication::Rotate180);
	}
	// rotate 270 degree
	System::Void MainForm::Rotation270ToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		this->TransformOutputImage(ImageApplication::Rotate270);
	}

	// 5x5 box blur for output image
	System::Void MainForm::BlurBoxToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->TransformOutputImage(ImageApplication::BoxBlur);
	}
	// 5x5 Gaussian blur for output image
	System::Void MainForm::BlurGaussianToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->TransformOutputImage(ImageApplication::GaussianBlur);
	}
	// 5x5 edge detection for output image
	System::Void MainForm::EdgeDetectionAllToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->TransformOutputImage(ImageApplication::EdgeDetection);
	}
	// 5x5 horizontal edge detection for output image
	System::Void MainForm::EdgeDetectionHorizontalToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->TransformOutputImage(ImageApplication::EdgeDetectionHorizontal);
	}
	// 5x5 vertical edge detection for output image
	System::Void MainForm::EdgeDetectionVerticalToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->TransformOutputImage(ImageApplication::EdgeDetectionVertical);
	}
	// 5x5 custom kernel of convolution for output image
	System::Void MainForm::CustomConvolutionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		InputMatrixForm^ imform = gcnew InputMatrixForm();
		imform->ShowDialog();
		array<double, 2>^ kernel;
		try {
			kernel = imform->Value;
		}
		catch (System::Exception^) {
			System::Windows::Forms::MessageBox::Show(L"輸入數值非浮點數！。", L"錯誤");
			return;
		}
		this->OutputImage = ImageApplication::Convolution(this->OutputImage, kernel);
		this->RenewOutputImage();
	}

	// show gray Gaussian noise image
	System::Void MainForm::OnlyGaussianNoiseGrayToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		double sigma = GetSigmaValue();
		this->TransformOutputImage(ImageApplication::OnlyGaussianNoiseGray, this->OutputImage->Width, this->OutputImage->Height, sigma);
	}
	// show color Gaussian noise image
	System::Void MainForm::OnlyGaussianNoiseRGBToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		double sigma = GetSigmaValue();
		this->TransformOutputImage(ImageApplication::OnlyGaussianNoiseRGB, this->OutputImage->Width, this->OutputImage->Height, sigma);
	}
	// add gray Gaussian noise to output image
	System::Void MainForm::AddGaussianNoiseGrayToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		double sigma = GetSigmaValue();
		this->TransformOutputImage(ImageApplication::AddGaussianNoiseGray, sigma);
	}
	// add color Gaussian noise to output image
	System::Void MainForm::AddGaussianNoiseRGBToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		double sigma = GetSigmaValue();
		this->TransformOutputImage(ImageApplication::AddGaussianNoiseRGB, sigma);
	}
	// show gray salt-and-pepper noise image
	System::Void MainForm::OnlySaltAndPepperNoiseGrayToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		double probability = GetProbabilityValue();
		this->TransformOutputImage(ImageApplication::OnlySaltAndPepperNoiseGray, this->OutputImage->Width, this->OutputImage->Height, probability);
	}
	// show color salt-and-pepper noise image
	System::Void MainForm::OnlySaltAndPepperNoiseRGBToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		double probability = GetProbabilityValue();
		this->TransformOutputImage(ImageApplication::OnlySaltAndPepperNoiseRGB, this->OutputImage->Width, this->OutputImage->Height, probability);
	}
	// add gray salt-and-pepper noise to output image
	System::Void MainForm::AddSaltAndPepperNoiseGrayToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		double probability = GetProbabilityValue();
		this->TransformOutputImage(ImageApplication::AddSaltAndPepperNoiseGray, probability);
	}
	// add color salt-and-pepper noise to output image
	System::Void MainForm::AddSaltAndPepperNoiseRGBToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		double probability = GetProbabilityValue();
		this->TransformOutputImage(ImageApplication::AddSaltAndPepperNoiseRGB, probability);
	}

	// show histogram for brightness of gray image
	System::Void MainForm::BrightnessGrayToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		this->TransformOutputImage(ImageApplication::ToHistogramBrightnessGray);
	}
	// show histogram for red brightness of image
	System::Void MainForm::BrightnessRedToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		this->TransformOutputImage(ImageApplication::ToHistogramBrightnessRed);
	}
	// show histogram for green brightness of image
	System::Void MainForm::BrightnessGreenToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		this->TransformOutputImage(ImageApplication::ToHistogramBrightnessGreen);
	}
	// show histogram for blue brightness of image
	System::Void MainForm::BrightnessBlueToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		this->TransformOutputImage(ImageApplication::ToHistogramBrightnessBlue);
	}
	// show histogram for RGB brightnesses of image
	System::Void MainForm::BrightnessRGBToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
		this->TransformOutputImage(ImageApplication::ToHistogramBrightnessRGB);
	}
}