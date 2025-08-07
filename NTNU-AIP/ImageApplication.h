#pragma once

namespace NTNUAIP {

	using System::Byte;
	using System::Drawing::Bitmap;
	using System::Drawing::Color;
	using System::Drawing::Point;
	using System::Windows::Forms::DataVisualization::Charting::Chart;
	using System::Windows::Forms::DataVisualization::Charting::Series;
	

	ref class ImageApplication
	{
	public:
		// const variable
		static const int A = System::BitConverter::IsLittleEndian ? 3 : 0;
		static const int R = System::BitConverter::IsLittleEndian ? 2 : 1;
		static const int G = System::BitConverter::IsLittleEndian ? 1 : 2;
		static const int B = System::BitConverter::IsLittleEndian ? 0 : 3;
		static constexpr System::Byte BLACK = 0;
		static constexpr System::Byte GRAY = 128;
		static constexpr System::Byte WHITE = 255;

	public:
		// fill
		static Bitmap^ Fill(int, int, Color);
		static Bitmap^ Fill(Bitmap^, Color);

	public:
		// color
		static Bitmap^ ToGray(Bitmap^);
		static Bitmap^ ToGrayAverage(Bitmap^);
		static Bitmap^ RedOnly(Bitmap^);
		static Bitmap^ GreenOnly(Bitmap^);
		static Bitmap^ BlueOnly(Bitmap^);
		static Bitmap^ Brighten(Bitmap^);
		static Bitmap^ Darken(Bitmap^);
		static Bitmap^ BrightnessTransform(Bitmap^, array<Byte>^);
		static Bitmap^ HistogramEqualization(Bitmap^);
		static Bitmap^ Negative(Bitmap^);

		// rotate
		static Bitmap^ Rotate90(Bitmap^);
		static Bitmap^ Rotate180(Bitmap^);
		static Bitmap^ Rotate270(Bitmap^);

		// convolution
		static Bitmap^ Convolution(Bitmap^, array<double, 2>^);

		// blur
		static Bitmap^ BoxBlur(Bitmap^);
		static Bitmap^ GaussianBlur(Bitmap^);

		// edge detection
		static Bitmap^ EdgeDetection(Bitmap^);
		static Bitmap^ EdgeDetectionHorizontal(Bitmap^);
		static Bitmap^ EdgeDetectionVertical(Bitmap^);

		// noise
		static Bitmap^ OnlyGaussianNoiseGray(int, int, double);
		static Bitmap^ OnlyGaussianNoiseRGB(int, int, double);
		static Bitmap^ AddGaussianNoiseGray(Bitmap^, double);
		static Bitmap^ AddGaussianNoiseRGB(Bitmap^, double);
		static Bitmap^ OnlySaltAndPepperNoiseGray(int, int, double);
		static Bitmap^ OnlySaltAndPepperNoiseRGB(int, int, double);
		static Bitmap^ AddSaltAndPepperNoiseGray(Bitmap^, double);
		static Bitmap^ AddSaltAndPepperNoiseRGB(Bitmap^, double);

		// statistics
		static Bitmap^ ToHistogramBrightnessGray(Bitmap^);
		static Bitmap^ ToHistogramBrightnessRed(Bitmap^);
		static Bitmap^ ToHistogramBrightnessGreen(Bitmap^);
		static Bitmap^ ToHistogramBrightnessBlue(Bitmap^);
		static Bitmap^ ToHistogramBrightnessRGB(Bitmap^);

	public:
		// raw
		static array<Byte>^ GetRaw(Bitmap^);
		static Byte* GetCRaw(Bitmap^);
		static Bitmap^ FromRaw(array<Byte>^, int, int);
		static Bitmap^ FromRaw(array<double>^, int, int);
		static Bitmap^ FromCRaw(Byte*, int, int);
		static Bitmap^ FromCRaw(double*, int, int);

		// counter
		static array<int>^ CounterRaw(array<Byte>^, int channel);
		static array<int>^ CounterRaw(array<Byte>^ raw) {
			return CounterRaw(raw, R);
		}
		static array<int>^ Counter(Bitmap^, int channel);
		static array<int>^ Counter(Bitmap^ img) {
			return Counter(img, R);
		}

		// border
		static Bitmap^ AddBorder(Bitmap^, int, int, int, int);

	
	private:
		// utils
		template<class T>
		static T Clamp(T val, T min, T max) {
			return val < min ? min : (val > max ? max : val);
		}
		template<class T>
		static T Clamp(T val) {
			return val < 0 ? 0 : (val > 255 ? 255 : val);
		}
		// chart
		static Series^ CreateSeries(array<int>^, Color);
		static Chart^ CreateChart(array<Series^>^);
		static Bitmap^ FromChart(Chart^);
	};
}
