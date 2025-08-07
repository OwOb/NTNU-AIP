#pragma once

#include "InputDecimalForm.h"

namespace NTNUAIP {

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ MenuStrip;
	protected:

	protected:
	private: System::Windows::Forms::Panel^ OriginalImagePanel;
	private: System::Windows::Forms::Panel^ OutputImagePanel;
	private: System::Windows::Forms::Label^ OriginalImageLabel;
	private: System::Windows::Forms::Label^ OutputImageLabel;
	private: System::Windows::Forms::PictureBox^ OriginalPictureBox;
	private: System::Windows::Forms::PictureBox^ OutputPictureBox;
	
	private: System::Windows::Forms::ToolStripMenuItem^ FileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ OpenImageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ SaveImageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ResetImageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ CloseImageToolStripMenuItem;
			
	private: System::Windows::Forms::ToolStripMenuItem^ ColorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ GrayToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ GrayAverageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ GrayGeneralToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ SingleColorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ RedOnlyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ GreenOnlyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ BlueOnlyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ NegativeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ BrightnessToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ BrightenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ DarkenToolStripMenuItem;
			
	private: System::Windows::Forms::ToolStripMenuItem^ RotateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ Rotation90ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ Rotation180ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ Rotation270ToolStripMenuItem;
			
	private: System::Windows::Forms::ToolStripMenuItem^ StatisticsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ BrightnessGrayToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ BrightnessRedToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ BrightnessGreenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ BrightnessBlueToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ BrightnessRGBToolStripMenuItem;
			
	private: System::Windows::Forms::ToolStripMenuItem^ NoiseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ GaussianNoiseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ OnlyGaussianNoiseGrayToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ OnlyGaussianNoiseRGBToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ AddGaussianNoiseGrayToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ AddGaussianNoiseRGBToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ SaltAndPepperNoiseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ OnlySaltAndPepperNoiseGrayToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ OnlySaltAndPepperNoiseRGBToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ AddSaltAndPepperNoiseGrayToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ AddSaltAndPepperNoiseRGBToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ConvolutionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ BlurToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ BlurBoxToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ BlurGaussianToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ EdgeDetectionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ EdgeDetectionAllToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ EdgeDetectionHorizontalToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ EdgeDetectionVerticalToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ CustomConvolutionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ HistogramEqualizationToolStripMenuItem;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->MenuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->FileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OpenImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SaveImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ResetImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CloseImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ColorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->GrayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->GrayGeneralToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->GrayAverageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SingleColorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RedOnlyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->GreenOnlyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BlueOnlyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BrightnessToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BrightenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DarkenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->HistogramEqualizationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->NegativeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RotateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Rotation90ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Rotation180ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Rotation270ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ConvolutionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BlurToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BlurBoxToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BlurGaussianToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->EdgeDetectionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->EdgeDetectionAllToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->EdgeDetectionHorizontalToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->EdgeDetectionVerticalToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CustomConvolutionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->NoiseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->GaussianNoiseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OnlyGaussianNoiseGrayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OnlyGaussianNoiseRGBToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->AddGaussianNoiseGrayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->AddGaussianNoiseRGBToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SaltAndPepperNoiseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OnlySaltAndPepperNoiseGrayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OnlySaltAndPepperNoiseRGBToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->AddSaltAndPepperNoiseGrayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->AddSaltAndPepperNoiseRGBToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->StatisticsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BrightnessGrayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BrightnessRedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BrightnessGreenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BrightnessBlueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BrightnessRGBToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OriginalImagePanel = (gcnew System::Windows::Forms::Panel());
			this->OriginalPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->OriginalImageLabel = (gcnew System::Windows::Forms::Label());
			this->OutputImagePanel = (gcnew System::Windows::Forms::Panel());
			this->OutputPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->OutputImageLabel = (gcnew System::Windows::Forms::Label());
			this->MenuStrip->SuspendLayout();
			this->OriginalImagePanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OriginalPictureBox))->BeginInit();
			this->OutputImagePanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OutputPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// MenuStrip
			// 
			this->MenuStrip->BackColor = System::Drawing::SystemColors::MenuBar;
			this->MenuStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->MenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->FileToolStripMenuItem,
					this->ColorToolStripMenuItem, this->RotateToolStripMenuItem, this->ConvolutionToolStripMenuItem, this->NoiseToolStripMenuItem,
					this->StatisticsToolStripMenuItem
			});
			this->MenuStrip->Location = System::Drawing::Point(0, 0);
			this->MenuStrip->Name = L"MenuStrip";
			this->MenuStrip->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->MenuStrip->Size = System::Drawing::Size(1022, 27);
			this->MenuStrip->TabIndex = 0;
			// 
			// FileToolStripMenuItem
			// 
			this->FileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->OpenImageToolStripMenuItem,
					this->SaveImageToolStripMenuItem, this->ResetImageToolStripMenuItem, this->CloseImageToolStripMenuItem
			});
			this->FileToolStripMenuItem->Name = L"FileToolStripMenuItem";
			this->FileToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F));
			this->FileToolStripMenuItem->Size = System::Drawing::Size(53, 23);
			this->FileToolStripMenuItem->Text = L"檔案";
			// 
			// OpenImageToolStripMenuItem
			// 
			this->OpenImageToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->OpenImageToolStripMenuItem->Name = L"OpenImageToolStripMenuItem";
			this->OpenImageToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->OpenImageToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->OpenImageToolStripMenuItem->Text = L"開啟圖片";
			this->OpenImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::OpenImageToolStripMenuItem_Click);
			// 
			// SaveImageToolStripMenuItem
			// 
			this->SaveImageToolStripMenuItem->Enabled = false;
			this->SaveImageToolStripMenuItem->Name = L"SaveImageToolStripMenuItem";
			this->SaveImageToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->SaveImageToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->SaveImageToolStripMenuItem->Text = L"儲存圖片";
			this->SaveImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::SaveImageToolStripMenuItem_Click);
			// 
			// ResetImageToolStripMenuItem
			// 
			this->ResetImageToolStripMenuItem->Enabled = false;
			this->ResetImageToolStripMenuItem->Name = L"ResetImageToolStripMenuItem";
			this->ResetImageToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::R));
			this->ResetImageToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->ResetImageToolStripMenuItem->Text = L"重置圖片";
			this->ResetImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ResetImageToolStripMenuItem_Click);
			// 
			// CloseImageToolStripMenuItem
			// 
			this->CloseImageToolStripMenuItem->Enabled = false;
			this->CloseImageToolStripMenuItem->Name = L"CloseImageToolStripMenuItem";
			this->CloseImageToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::W));
			this->CloseImageToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->CloseImageToolStripMenuItem->Text = L"關閉圖片";
			this->CloseImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::CloseImageToolStripMenuItem_Click);
			// 
			// ColorToolStripMenuItem
			// 
			this->ColorToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->GrayToolStripMenuItem,
					this->SingleColorToolStripMenuItem, this->BrightnessToolStripMenuItem, this->NegativeToolStripMenuItem
			});
			this->ColorToolStripMenuItem->Enabled = false;
			this->ColorToolStripMenuItem->Name = L"ColorToolStripMenuItem";
			this->ColorToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::C));
			this->ColorToolStripMenuItem->Size = System::Drawing::Size(53, 23);
			this->ColorToolStripMenuItem->Text = L"色彩";
			// 
			// GrayToolStripMenuItem
			// 
			this->GrayToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->GrayGeneralToolStripMenuItem,
					this->GrayAverageToolStripMenuItem
			});
			this->GrayToolStripMenuItem->Name = L"GrayToolStripMenuItem";
			this->GrayToolStripMenuItem->Size = System::Drawing::Size(179, 26);
			this->GrayToolStripMenuItem->Text = L"灰階";
			// 
			// GrayGeneralToolStripMenuItem
			// 
			this->GrayGeneralToolStripMenuItem->Name = L"GrayGeneralToolStripMenuItem";
			this->GrayGeneralToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::G));
			this->GrayGeneralToolStripMenuItem->Size = System::Drawing::Size(178, 26);
			this->GrayGeneralToolStripMenuItem->Text = L"一般";
			this->GrayGeneralToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::GrayGeneralToolStripMenuItem_Click);
			// 
			// GrayAverageToolStripMenuItem
			// 
			this->GrayAverageToolStripMenuItem->Name = L"GrayAverageToolStripMenuItem";
			this->GrayAverageToolStripMenuItem->Size = System::Drawing::Size(178, 26);
			this->GrayAverageToolStripMenuItem->Text = L"平均";
			this->GrayAverageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::GrayAverageToolStripMenuItem_Click);
			// 
			// SingleColorToolStripMenuItem
			// 
			this->SingleColorToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->RedOnlyToolStripMenuItem,
					this->GreenOnlyToolStripMenuItem, this->BlueOnlyToolStripMenuItem
			});
			this->SingleColorToolStripMenuItem->Name = L"SingleColorToolStripMenuItem";
			this->SingleColorToolStripMenuItem->Size = System::Drawing::Size(179, 26);
			this->SingleColorToolStripMenuItem->Text = L"單色";
			// 
			// RedOnlyToolStripMenuItem
			// 
			this->RedOnlyToolStripMenuItem->Name = L"RedOnlyToolStripMenuItem";
			this->RedOnlyToolStripMenuItem->Size = System::Drawing::Size(122, 26);
			this->RedOnlyToolStripMenuItem->Text = L"紅色";
			this->RedOnlyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::RedOnlyToolStripMenuItem_Click);
			// 
			// GreenOnlyToolStripMenuItem
			// 
			this->GreenOnlyToolStripMenuItem->Name = L"GreenOnlyToolStripMenuItem";
			this->GreenOnlyToolStripMenuItem->Size = System::Drawing::Size(122, 26);
			this->GreenOnlyToolStripMenuItem->Text = L"綠色";
			this->GreenOnlyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::GreenOnlyToolStripMenuItem_Click);
			// 
			// BlueOnlyToolStripMenuItem
			// 
			this->BlueOnlyToolStripMenuItem->Name = L"BlueOnlyToolStripMenuItem";
			this->BlueOnlyToolStripMenuItem->Size = System::Drawing::Size(122, 26);
			this->BlueOnlyToolStripMenuItem->Text = L"藍色";
			this->BlueOnlyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::BlueOnlyToolStripMenuItem_Click);
			// 
			// BrightnessToolStripMenuItem
			// 
			this->BrightnessToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->BrightenToolStripMenuItem,
					this->DarkenToolStripMenuItem, this->HistogramEqualizationToolStripMenuItem
			});
			this->BrightnessToolStripMenuItem->Name = L"BrightnessToolStripMenuItem";
			this->BrightnessToolStripMenuItem->Size = System::Drawing::Size(179, 26);
			this->BrightnessToolStripMenuItem->Text = L"亮度";
			// 
			// BrightenToolStripMenuItem
			// 
			this->BrightenToolStripMenuItem->Name = L"BrightenToolStripMenuItem";
			this->BrightenToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::L));
			this->BrightenToolStripMenuItem->Size = System::Drawing::Size(193, 26);
			this->BrightenToolStripMenuItem->Text = L"增加";
			this->BrightenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::BrightenToolStripMenuItem_Click);
			// 
			// DarkenToolStripMenuItem
			// 
			this->DarkenToolStripMenuItem->Name = L"DarkenToolStripMenuItem";
			this->DarkenToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D));
			this->DarkenToolStripMenuItem->Size = System::Drawing::Size(193, 26);
			this->DarkenToolStripMenuItem->Text = L"減少";
			this->DarkenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::DarkenToolStripMenuItem_Click);
			// 
			// HistogramEqualizationToolStripMenuItem
			// 
			this->HistogramEqualizationToolStripMenuItem->Name = L"HistogramEqualizationToolStripMenuItem";
			this->HistogramEqualizationToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::H));
			this->HistogramEqualizationToolStripMenuItem->Size = System::Drawing::Size(193, 26);
			this->HistogramEqualizationToolStripMenuItem->Text = L"均衡化";
			this->HistogramEqualizationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::HistogramEqualizationToolStripMenuItem_Click);
			// 
			// NegativeToolStripMenuItem
			// 
			this->NegativeToolStripMenuItem->Name = L"NegativeToolStripMenuItem";
			this->NegativeToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->NegativeToolStripMenuItem->Size = System::Drawing::Size(179, 26);
			this->NegativeToolStripMenuItem->Text = L"負片";
			this->NegativeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::NegativeToolStripMenuItem_Click);
			// 
			// RotateToolStripMenuItem
			// 
			this->RotateToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->Rotation90ToolStripMenuItem,
					this->Rotation180ToolStripMenuItem, this->Rotation270ToolStripMenuItem
			});
			this->RotateToolStripMenuItem->Enabled = false;
			this->RotateToolStripMenuItem->Name = L"RotateToolStripMenuItem";
			this->RotateToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::R));
			this->RotateToolStripMenuItem->Size = System::Drawing::Size(53, 23);
			this->RotateToolStripMenuItem->Text = L"旋轉";
			// 
			// Rotation90ToolStripMenuItem
			// 
			this->Rotation90ToolStripMenuItem->Name = L"Rotation90ToolStripMenuItem";
			this->Rotation90ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::T));
			this->Rotation90ToolStripMenuItem->Size = System::Drawing::Size(248, 26);
			this->Rotation90ToolStripMenuItem->Text = L"順時針旋轉 90°";
			this->Rotation90ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::Rotation90ToolStripMenuItem_Click);
			// 
			// Rotation180ToolStripMenuItem
			// 
			this->Rotation180ToolStripMenuItem->Name = L"Rotation180ToolStripMenuItem";
			this->Rotation180ToolStripMenuItem->Size = System::Drawing::Size(248, 26);
			this->Rotation180ToolStripMenuItem->Text = L"旋轉 180°";
			this->Rotation180ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::Rotation180ToolStripMenuItem_Click);
			// 
			// Rotation270ToolStripMenuItem
			// 
			this->Rotation270ToolStripMenuItem->Name = L"Rotation270ToolStripMenuItem";
			this->Rotation270ToolStripMenuItem->Size = System::Drawing::Size(248, 26);
			this->Rotation270ToolStripMenuItem->Text = L"逆時針旋轉 90°";
			this->Rotation270ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::Rotation270ToolStripMenuItem_Click);
			// 
			// ConvolutionToolStripMenuItem
			// 
			this->ConvolutionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->BlurToolStripMenuItem,
					this->EdgeDetectionToolStripMenuItem, this->CustomConvolutionToolStripMenuItem
			});
			this->ConvolutionToolStripMenuItem->Enabled = false;
			this->ConvolutionToolStripMenuItem->Name = L"ConvolutionToolStripMenuItem";
			this->ConvolutionToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::C));
			this->ConvolutionToolStripMenuItem->Size = System::Drawing::Size(53, 23);
			this->ConvolutionToolStripMenuItem->Text = L"卷積";
			// 
			// BlurToolStripMenuItem
			// 
			this->BlurToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->BlurBoxToolStripMenuItem,
					this->BlurGaussianToolStripMenuItem
			});
			this->BlurToolStripMenuItem->Name = L"BlurToolStripMenuItem";
			this->BlurToolStripMenuItem->Size = System::Drawing::Size(152, 26);
			this->BlurToolStripMenuItem->Text = L"模糊化";
			// 
			// BlurBoxToolStripMenuItem
			// 
			this->BlurBoxToolStripMenuItem->Name = L"BlurBoxToolStripMenuItem";
			this->BlurBoxToolStripMenuItem->Size = System::Drawing::Size(152, 26);
			this->BlurBoxToolStripMenuItem->Text = L"均值模糊";
			this->BlurBoxToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::BlurBoxToolStripMenuItem_Click);
			// 
			// BlurGaussianToolStripMenuItem
			// 
			this->BlurGaussianToolStripMenuItem->Name = L"BlurGaussianToolStripMenuItem";
			this->BlurGaussianToolStripMenuItem->Size = System::Drawing::Size(152, 26);
			this->BlurGaussianToolStripMenuItem->Text = L"高斯模糊";
			this->BlurGaussianToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::BlurGaussianToolStripMenuItem_Click);
			// 
			// EdgeDetectionToolStripMenuItem
			// 
			this->EdgeDetectionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->EdgeDetectionAllToolStripMenuItem,
					this->EdgeDetectionHorizontalToolStripMenuItem, this->EdgeDetectionVerticalToolStripMenuItem
			});
			this->EdgeDetectionToolStripMenuItem->Name = L"EdgeDetectionToolStripMenuItem";
			this->EdgeDetectionToolStripMenuItem->Size = System::Drawing::Size(152, 26);
			this->EdgeDetectionToolStripMenuItem->Text = L"邊緣偵測";
			// 
			// EdgeDetectionAllToolStripMenuItem
			// 
			this->EdgeDetectionAllToolStripMenuItem->Name = L"EdgeDetectionAllToolStripMenuItem";
			this->EdgeDetectionAllToolStripMenuItem->Size = System::Drawing::Size(122, 26);
			this->EdgeDetectionAllToolStripMenuItem->Text = L"全部";
			this->EdgeDetectionAllToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::EdgeDetectionAllToolStripMenuItem_Click);
			// 
			// EdgeDetectionHorizontalToolStripMenuItem
			// 
			this->EdgeDetectionHorizontalToolStripMenuItem->Name = L"EdgeDetectionHorizontalToolStripMenuItem";
			this->EdgeDetectionHorizontalToolStripMenuItem->Size = System::Drawing::Size(122, 26);
			this->EdgeDetectionHorizontalToolStripMenuItem->Text = L"水平";
			this->EdgeDetectionHorizontalToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::EdgeDetectionHorizontalToolStripMenuItem_Click);
			// 
			// EdgeDetectionVerticalToolStripMenuItem
			// 
			this->EdgeDetectionVerticalToolStripMenuItem->Name = L"EdgeDetectionVerticalToolStripMenuItem";
			this->EdgeDetectionVerticalToolStripMenuItem->Size = System::Drawing::Size(122, 26);
			this->EdgeDetectionVerticalToolStripMenuItem->Text = L"垂直";
			this->EdgeDetectionVerticalToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::EdgeDetectionVerticalToolStripMenuItem_Click);
			// 
			// CustomConvolutionToolStripMenuItem
			// 
			this->CustomConvolutionToolStripMenuItem->Name = L"CustomConvolutionToolStripMenuItem";
			this->CustomConvolutionToolStripMenuItem->Size = System::Drawing::Size(152, 26);
			this->CustomConvolutionToolStripMenuItem->Text = L"自訂卷積";
			this->CustomConvolutionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::CustomConvolutionToolStripMenuItem_Click);
			// 
			// NoiseToolStripMenuItem
			// 
			this->NoiseToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->GaussianNoiseToolStripMenuItem,
					this->SaltAndPepperNoiseToolStripMenuItem
			});
			this->NoiseToolStripMenuItem->Enabled = false;
			this->NoiseToolStripMenuItem->Name = L"NoiseToolStripMenuItem";
			this->NoiseToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::N));
			this->NoiseToolStripMenuItem->Size = System::Drawing::Size(53, 23);
			this->NoiseToolStripMenuItem->Text = L"雜訊";
			// 
			// GaussianNoiseToolStripMenuItem
			// 
			this->GaussianNoiseToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->OnlyGaussianNoiseGrayToolStripMenuItem,
					this->OnlyGaussianNoiseRGBToolStripMenuItem, this->AddGaussianNoiseGrayToolStripMenuItem, this->AddGaussianNoiseRGBToolStripMenuItem
			});
			this->GaussianNoiseToolStripMenuItem->Name = L"GaussianNoiseToolStripMenuItem";
			this->GaussianNoiseToolStripMenuItem->Size = System::Drawing::Size(152, 26);
			this->GaussianNoiseToolStripMenuItem->Text = L"高斯雜訊";
			// 
			// OnlyGaussianNoiseGrayToolStripMenuItem
			// 
			this->OnlyGaussianNoiseGrayToolStripMenuItem->Name = L"OnlyGaussianNoiseGrayToolStripMenuItem";
			this->OnlyGaussianNoiseGrayToolStripMenuItem->Size = System::Drawing::Size(196, 26);
			this->OnlyGaussianNoiseGrayToolStripMenuItem->Text = L"純雜訊 (灰階)";
			this->OnlyGaussianNoiseGrayToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::OnlyGaussianNoiseGrayToolStripMenuItem_Click);
			// 
			// OnlyGaussianNoiseRGBToolStripMenuItem
			// 
			this->OnlyGaussianNoiseRGBToolStripMenuItem->Name = L"OnlyGaussianNoiseRGBToolStripMenuItem";
			this->OnlyGaussianNoiseRGBToolStripMenuItem->Size = System::Drawing::Size(196, 26);
			this->OnlyGaussianNoiseRGBToolStripMenuItem->Text = L"純雜訊 (RGB)";
			this->OnlyGaussianNoiseRGBToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::OnlyGaussianNoiseRGBToolStripMenuItem_Click);
			// 
			// AddGaussianNoiseGrayToolStripMenuItem
			// 
			this->AddGaussianNoiseGrayToolStripMenuItem->Name = L"AddGaussianNoiseGrayToolStripMenuItem";
			this->AddGaussianNoiseGrayToolStripMenuItem->Size = System::Drawing::Size(196, 26);
			this->AddGaussianNoiseGrayToolStripMenuItem->Text = L"增加雜訊 (灰階)";
			this->AddGaussianNoiseGrayToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::AddGaussianNoiseGrayToolStripMenuItem_Click);
			// 
			// AddGaussianNoiseRGBToolStripMenuItem
			// 
			this->AddGaussianNoiseRGBToolStripMenuItem->Name = L"AddGaussianNoiseRGBToolStripMenuItem";
			this->AddGaussianNoiseRGBToolStripMenuItem->Size = System::Drawing::Size(196, 26);
			this->AddGaussianNoiseRGBToolStripMenuItem->Text = L"增加雜訊 (RGB)";
			this->AddGaussianNoiseRGBToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::AddGaussianNoiseRGBToolStripMenuItem_Click);
			// 
			// SaltAndPepperNoiseToolStripMenuItem
			// 
			this->SaltAndPepperNoiseToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->OnlySaltAndPepperNoiseGrayToolStripMenuItem,
					this->OnlySaltAndPepperNoiseRGBToolStripMenuItem, this->AddSaltAndPepperNoiseGrayToolStripMenuItem, this->AddSaltAndPepperNoiseRGBToolStripMenuItem
			});
			this->SaltAndPepperNoiseToolStripMenuItem->Name = L"SaltAndPepperNoiseToolStripMenuItem";
			this->SaltAndPepperNoiseToolStripMenuItem->Size = System::Drawing::Size(152, 26);
			this->SaltAndPepperNoiseToolStripMenuItem->Text = L"椒鹽雜訊";
			// 
			// OnlySaltAndPepperNoiseGrayToolStripMenuItem
			// 
			this->OnlySaltAndPepperNoiseGrayToolStripMenuItem->Name = L"OnlySaltAndPepperNoiseGrayToolStripMenuItem";
			this->OnlySaltAndPepperNoiseGrayToolStripMenuItem->Size = System::Drawing::Size(196, 26);
			this->OnlySaltAndPepperNoiseGrayToolStripMenuItem->Text = L"純雜訊 (灰階)";
			this->OnlySaltAndPepperNoiseGrayToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::OnlySaltAndPepperNoiseGrayToolStripMenuItem_Click);
			// 
			// OnlySaltAndPepperNoiseRGBToolStripMenuItem
			// 
			this->OnlySaltAndPepperNoiseRGBToolStripMenuItem->Name = L"OnlySaltAndPepperNoiseRGBToolStripMenuItem";
			this->OnlySaltAndPepperNoiseRGBToolStripMenuItem->Size = System::Drawing::Size(196, 26);
			this->OnlySaltAndPepperNoiseRGBToolStripMenuItem->Text = L"純雜訊 (RGB)";
			this->OnlySaltAndPepperNoiseRGBToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::OnlySaltAndPepperNoiseRGBToolStripMenuItem_Click);
			// 
			// AddSaltAndPepperNoiseGrayToolStripMenuItem
			// 
			this->AddSaltAndPepperNoiseGrayToolStripMenuItem->Name = L"AddSaltAndPepperNoiseGrayToolStripMenuItem";
			this->AddSaltAndPepperNoiseGrayToolStripMenuItem->Size = System::Drawing::Size(196, 26);
			this->AddSaltAndPepperNoiseGrayToolStripMenuItem->Text = L"增加雜訊 (灰階)";
			this->AddSaltAndPepperNoiseGrayToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::AddSaltAndPepperNoiseGrayToolStripMenuItem_Click);
			// 
			// AddSaltAndPepperNoiseRGBToolStripMenuItem
			// 
			this->AddSaltAndPepperNoiseRGBToolStripMenuItem->Name = L"AddSaltAndPepperNoiseRGBToolStripMenuItem";
			this->AddSaltAndPepperNoiseRGBToolStripMenuItem->Size = System::Drawing::Size(196, 26);
			this->AddSaltAndPepperNoiseRGBToolStripMenuItem->Text = L"增加雜訊 (RGB)";
			this->AddSaltAndPepperNoiseRGBToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::AddSaltAndPepperNoiseRGBToolStripMenuItem_Click);
			// 
			// StatisticsToolStripMenuItem
			// 
			this->StatisticsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->BrightnessGrayToolStripMenuItem,
					this->BrightnessRedToolStripMenuItem, this->BrightnessGreenToolStripMenuItem, this->BrightnessBlueToolStripMenuItem, this->BrightnessRGBToolStripMenuItem
			});
			this->StatisticsToolStripMenuItem->Enabled = false;
			this->StatisticsToolStripMenuItem->Name = L"StatisticsToolStripMenuItem";
			this->StatisticsToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::S));
			this->StatisticsToolStripMenuItem->Size = System::Drawing::Size(53, 23);
			this->StatisticsToolStripMenuItem->Text = L"統計";
			// 
			// BrightnessGrayToolStripMenuItem
			// 
			this->BrightnessGrayToolStripMenuItem->Name = L"BrightnessGrayToolStripMenuItem";
			this->BrightnessGrayToolStripMenuItem->Size = System::Drawing::Size(166, 26);
			this->BrightnessGrayToolStripMenuItem->Text = L"亮度 (灰階)";
			this->BrightnessGrayToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::BrightnessGrayToolStripMenuItem_Click);
			// 
			// BrightnessRedToolStripMenuItem
			// 
			this->BrightnessRedToolStripMenuItem->Name = L"BrightnessRedToolStripMenuItem";
			this->BrightnessRedToolStripMenuItem->Size = System::Drawing::Size(166, 26);
			this->BrightnessRedToolStripMenuItem->Text = L"亮度 (紅色)";
			this->BrightnessRedToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::BrightnessRedToolStripMenuItem_Click);
			// 
			// BrightnessGreenToolStripMenuItem
			// 
			this->BrightnessGreenToolStripMenuItem->Name = L"BrightnessGreenToolStripMenuItem";
			this->BrightnessGreenToolStripMenuItem->Size = System::Drawing::Size(166, 26);
			this->BrightnessGreenToolStripMenuItem->Text = L"亮度 (綠色)";
			this->BrightnessGreenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::BrightnessGreenToolStripMenuItem_Click);
			// 
			// BrightnessBlueToolStripMenuItem
			// 
			this->BrightnessBlueToolStripMenuItem->Name = L"BrightnessBlueToolStripMenuItem";
			this->BrightnessBlueToolStripMenuItem->Size = System::Drawing::Size(166, 26);
			this->BrightnessBlueToolStripMenuItem->Text = L"亮度 (藍色)";
			this->BrightnessBlueToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::BrightnessBlueToolStripMenuItem_Click);
			// 
			// BrightnessRGBToolStripMenuItem
			// 
			this->BrightnessRGBToolStripMenuItem->Name = L"BrightnessRGBToolStripMenuItem";
			this->BrightnessRGBToolStripMenuItem->Size = System::Drawing::Size(166, 26);
			this->BrightnessRGBToolStripMenuItem->Text = L"亮度 (RGB)";
			this->BrightnessRGBToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::BrightnessRGBToolStripMenuItem_Click);
			// 
			// OriginalImagePanel
			// 
			this->OriginalImagePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->OriginalImagePanel->CausesValidation = false;
			this->OriginalImagePanel->Controls->Add(this->OriginalPictureBox);
			this->OriginalImagePanel->Location = System::Drawing::Point(20, 60);
			this->OriginalImagePanel->Name = L"OriginalImagePanel";
			this->OriginalImagePanel->Size = System::Drawing::Size(480, 480);
			this->OriginalImagePanel->TabIndex = 1;
			// 
			// OriginalPictureBox
			// 
			this->OriginalPictureBox->Location = System::Drawing::Point(-1, -1);
			this->OriginalPictureBox->Name = L"OriginalPictureBox";
			this->OriginalPictureBox->Size = System::Drawing::Size(480, 480);
			this->OriginalPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->OriginalPictureBox->TabIndex = 0;
			this->OriginalPictureBox->TabStop = false;
			// 
			// OriginalImageLabel
			// 
			this->OriginalImageLabel->AutoSize = true;
			this->OriginalImageLabel->CausesValidation = false;
			this->OriginalImageLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->OriginalImageLabel->Location = System::Drawing::Point(15, 32);
			this->OriginalImageLabel->Name = L"OriginalImageLabel";
			this->OriginalImageLabel->Size = System::Drawing::Size(92, 25);
			this->OriginalImageLabel->TabIndex = 2;
			this->OriginalImageLabel->Text = L"原始圖片";
			this->OriginalImageLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// OutputImagePanel
			// 
			this->OutputImagePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->OutputImagePanel->CausesValidation = false;
			this->OutputImagePanel->Controls->Add(this->OutputPictureBox);
			this->OutputImagePanel->Location = System::Drawing::Point(520, 60);
			this->OutputImagePanel->Name = L"OutputImagePanel";
			this->OutputImagePanel->Size = System::Drawing::Size(480, 480);
			this->OutputImagePanel->TabIndex = 3;
			// 
			// OutputPictureBox
			// 
			this->OutputPictureBox->Location = System::Drawing::Point(-1, -1);
			this->OutputPictureBox->Name = L"OutputPictureBox";
			this->OutputPictureBox->Size = System::Drawing::Size(480, 480);
			this->OutputPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->OutputPictureBox->TabIndex = 1;
			this->OutputPictureBox->TabStop = false;
			// 
			// OutputImageLabel
			// 
			this->OutputImageLabel->AutoSize = true;
			this->OutputImageLabel->CausesValidation = false;
			this->OutputImageLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->OutputImageLabel->Location = System::Drawing::Point(515, 32);
			this->OutputImageLabel->Name = L"OutputImageLabel";
			this->OutputImageLabel->Size = System::Drawing::Size(92, 25);
			this->OutputImageLabel->TabIndex = 4;
			this->OutputImageLabel->Text = L"輸出圖片";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(1022, 553);
			this->Controls->Add(this->OutputImageLabel);
			this->Controls->Add(this->OutputImagePanel);
			this->Controls->Add(this->OriginalImageLabel);
			this->Controls->Add(this->OriginalImagePanel);
			this->Controls->Add(this->MenuStrip);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->MenuStrip;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"NTNU-AIP";
			this->MenuStrip->ResumeLayout(false);
			this->MenuStrip->PerformLayout();
			this->OriginalImagePanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OriginalPictureBox))->EndInit();
			this->OutputImagePanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OutputPictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Drawing::Bitmap^ OriginalImage = nullptr;
		System::Drawing::Bitmap^ OutputImage = nullptr;

	private:
		System::Void EnableImageOptions();
		System::Void DisableImageOptions();
		System::Void ReleaseImage();
		System::Void ReleaseOriginalImage();
		System::Void ReleaseOutputImage();
		System::Void RenewImage();
		System::Void RenewOriginalImage();
		System::Void RenewOutputImage();
		
		template<class... Ts>
		System::Void TransformOutputImage(System::Drawing::Bitmap ^ (*func)(System::Drawing::Bitmap^, Ts...), Ts... args) {
			this->TransformOutputImage(func, this->OutputImage, args...);
		}
		template<class... Ts>
		System::Void TransformOutputImage(System::Drawing::Bitmap ^ (*func)(Ts...), Ts... args) {
			this->OutputImage = func(args...);
			this->RenewOutputImage();
		}

		template<class... Ts>
		static double GetValueFromInputDecimalForm(System::String^ title, System::String^ content, Ts... args) {
			InputDecimalForm^ idform = gcnew InputDecimalForm(title, content, args...);
			idform->ShowDialog();
			return System::Decimal::ToDouble(idform->Value);
		}
		static double GetSigmaValue() {
			return GetValueFromInputDecimalForm(L"參數輸入", L"百分比", 10.0, 0.0, 100.0);
		}
		static double GetProbabilityValue() {
			return GetValueFromInputDecimalForm(L"參數輸入", L"百分比", 10.0, 0.0, 100.0) / 100.0;
		}

		System::Boolean CheckSize(int, int);
		System::Void ShowSizeErrorMessage(int, int);

	private: 
		// file
		System::Void OpenImageToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void SaveImageToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void ResetImageToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void CloseImageToolStripMenuItem_Click(System::Object^, System::EventArgs^);

		// color
		System::Void GrayGeneralToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void GrayAverageToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void RedOnlyToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void GreenOnlyToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void BlueOnlyToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void BrightenToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void DarkenToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void HistogramEqualizationToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void NegativeToolStripMenuItem_Click(System::Object^, System::EventArgs^);

		// rotate
		System::Void Rotation90ToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void Rotation180ToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void Rotation270ToolStripMenuItem_Click(System::Object^, System::EventArgs^);

		// convolution
		System::Void BlurBoxToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void BlurGaussianToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void EdgeDetectionAllToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void EdgeDetectionHorizontalToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void EdgeDetectionVerticalToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void CustomConvolutionToolStripMenuItem_Click(System::Object^, System::EventArgs^);

		// noise
		System::Void OnlyGaussianNoiseGrayToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void OnlyGaussianNoiseRGBToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void AddGaussianNoiseGrayToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void AddGaussianNoiseRGBToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void OnlySaltAndPepperNoiseGrayToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void OnlySaltAndPepperNoiseRGBToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void AddSaltAndPepperNoiseGrayToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void AddSaltAndPepperNoiseRGBToolStripMenuItem_Click(System::Object^, System::EventArgs^);

		// statistics
		System::Void BrightnessGrayToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void BrightnessRedToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void BrightnessGreenToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void BrightnessBlueToolStripMenuItem_Click(System::Object^, System::EventArgs^);
		System::Void BrightnessRGBToolStripMenuItem_Click(System::Object^, System::EventArgs^);
	};
}
