#pragma once

namespace NTNUAIP {

	public ref class InputDecimalForm : public System::Windows::Forms::Form
	{
	public:
		InputDecimalForm(void) {
			InitializeComponent();
		}
		InputDecimalForm(System::String^ title, System::String^ content, double def, double minimum, double maximum) :
			InputDecimalForm(title, content, System::Convert::ToDecimal(def), System::Convert::ToDecimal(minimum), System::Convert::ToDecimal(maximum)) {}
		InputDecimalForm(System::String^ title, System::String^ content, System::Decimal def, System::Decimal minimum, System::Decimal maximum) {
			InitializeComponent();
			this->Title = title;
			this->Content = content;
			this->Value = def;
			this->Minimum = minimum;
			this->Maximum = maximum;
			this->defaultValue = this->Value;
		}

	protected:
		~InputDecimalForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown;
	private: System::Windows::Forms::Button^ buttonOK;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label = (gcnew System::Windows::Forms::Label());
			this->numericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->CausesValidation = false;
			this->label->Location = System::Drawing::Point(32, 35);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(37, 15);
			this->label->TabIndex = 0;
			this->label->Text = L"內容";
			// 
			// numericUpDown
			// 
			this->numericUpDown->DecimalPlaces = 2;
			this->numericUpDown->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			this->numericUpDown->Location = System::Drawing::Point(35, 53);
			this->numericUpDown->Name = L"numericUpDown";
			this->numericUpDown->Size = System::Drawing::Size(160, 25);
			this->numericUpDown->TabIndex = 1;
			this->numericUpDown->Click += gcnew System::EventHandler(this, &InputDecimalForm::numericUpDown_Click);
			// 
			// buttonOK
			// 
			this->buttonOK->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->buttonOK->Location = System::Drawing::Point(84, 99);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(60, 25);
			this->buttonOK->TabIndex = 2;
			this->buttonOK->Text = L"確認";
			this->buttonOK->UseVisualStyleBackColor = true;
			// 
			// InputDecimalForm
			// 
			this->AcceptButton = this->buttonOK;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(232, 153);
			this->ControlBox = false;
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->numericUpDown);
			this->Controls->Add(this->label);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"InputDecimalForm";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"標題";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Decimal defaultValue;
		System::Reflection::FieldInfo^ upDownEditField = (System::Windows::Forms::UpDownBase::typeid)->GetField(
			"upDownEdit", System::Reflection::BindingFlags::Instance | System::Reflection::BindingFlags::NonPublic
		);
		System::Type^ upDownEditType = upDownEditField->FieldType;
		System::Reflection::PropertyInfo^ selectionStartProperty = upDownEditType->GetProperty("SelectionStart");

	public:
		property System::String^ Title {
			System::String^ get() {
				return this->Text;
			}
			void set(System::String^ title) {
				this->Text = title;
			}
		}
		property System::String^ Content {
			System::String^ get() {
				return this->label->Text;
			}
			void set(System::String^ content) {
				this->label->Text = content;
			}
		}
		property System::Decimal Value {
			System::Decimal get() {
				if (this->numericUpDown->Text->Equals(System::String::Empty)) {
					return this->Minimum;
				}
				return this->numericUpDown->Value;
			}
			void set(System::Decimal val) {
				this->numericUpDown->Value = val;
			}
		}
		property System::Decimal Minimum {
			System::Decimal get() {
				return this->numericUpDown->Minimum;
			}
			void set(System::Decimal val) {
				this->numericUpDown->Minimum = val;
			}
		}
		property System::Decimal Maximum {
			System::Decimal get() {
				return this->numericUpDown->Maximum;
			}
			void set(System::Decimal val) {
				this->numericUpDown->Maximum = val;
			}
		}
		property int SelectionStart {
			int get() {
				return (int)this->selectionStartProperty->GetValue(this->upDownEditField->GetValue(this->numericUpDown), nullptr);
			}
			void set(int val) {
				if (val >= 0) {
					this->selectionStartProperty->SetValue(this->upDownEditField->GetValue(this->numericUpDown), val, nullptr);
				}
			}
		}

	private:
		//System::Void RefreshText() {
		//	int oldCursorPosition = this->SelectionStart;
		//	if (this->numericUpDown->Text->Equals(System::String::Empty)) {
		//		this->numericUpDown->Value = this->defaultValue;
		//	}
		//	this->numericUpDown->Value;		// update text
		//	this->numericUpDown->Select(oldCursorPosition, 0);
		//}
		//System::Void numericUpDown_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		//	try {
		//		System::Decimal textval = System::Convert::ToDecimal(this->numericUpDown->Text);
		//		if (textval < this->Minimum || this->Maximum < textval) {
		//			RefreshText();
		//		}
		//		return;
		//	}
		//	catch (System::Exception^) {
		//		return;
		//	}
		//}
		//System::Void InputDecimalForm_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		//	if (!this->numericUpDown->Capture) {
		//		RefreshText();
		//		this->numericUpDown->Select(this->numericUpDown->Text->Length, 0);
		//	}
		//}
		System::Void numericUpDown_Click(System::Object^ sender, System::EventArgs^ e) {
			this->numericUpDown->Value;
		}
	};
}
