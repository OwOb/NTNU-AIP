#pragma once

namespace NTNUAIP {

	public ref class InputMatrixForm : public System::Windows::Forms::Form
	{
	public:
		InputMatrixForm(void) {
			InitializeComponent();
			InitializeTable();
		}
		InputMatrixForm(System::String^ title, System::String^ content) {
			InitializeComponent();
			InitializeTable();
			this->Title = title;
			this->Content = content;
		}

	protected:
		~InputMatrixForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label;
	private: System::Windows::Forms::DataGridView^ dataGridView;

	private: System::Windows::Forms::Button^ buttonOK;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;







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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label = (gcnew System::Windows::Forms::Label());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->Location = System::Drawing::Point(9, 9);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(142, 15);
			this->label->TabIndex = 5;
			this->label->Text = L"輸入卷積遮罩數值：";
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			this->dataGridView->AllowUserToResizeColumns = false;
			this->dataGridView->AllowUserToResizeRows = false;
			this->dataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->ColumnHeadersVisible = false;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5
			});
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->Format = L"N3";
			dataGridViewCellStyle1->NullValue = L"0.000";
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView->DefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView->EnableHeadersVisualStyles = false;
			this->dataGridView->Location = System::Drawing::Point(12, 41);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->RowHeadersVisible = false;
			this->dataGridView->RowHeadersWidth = 50;
			dataGridViewCellStyle2->Format = L"N3";
			dataGridViewCellStyle2->NullValue = nullptr;
			this->dataGridView->RowsDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView->RowTemplate->Height = 27;
			this->dataGridView->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridView->ShowCellToolTips = false;
			this->dataGridView->ShowEditingIcon = false;
			this->dataGridView->ShowRowErrors = false;
			this->dataGridView->Size = System::Drawing::Size(360, 200);
			this->dataGridView->TabIndex = 6;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Column1";
			this->Column1->MaxInputLength = 10;
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Column2";
			this->Column2->MaxInputLength = 10;
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Column3";
			this->Column3->MaxInputLength = 10;
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Column4";
			this->Column4->MaxInputLength = 10;
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Column5";
			this->Column5->MaxInputLength = 10;
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			this->Column5->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column5->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// buttonOK
			// 
			this->buttonOK->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->buttonOK->Location = System::Drawing::Point(161, 247);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(60, 25);
			this->buttonOK->TabIndex = 7;
			this->buttonOK->Text = L"確認";
			this->buttonOK->UseVisualStyleBackColor = true;
			// 
			// InputMatrixForm
			// 
			this->AcceptButton = this->buttonOK;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(382, 283);
			this->ControlBox = false;
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->dataGridView);
			this->Controls->Add(this->label);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"InputMatrixForm";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"輸入參數";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void InitializeTable() {
			const int rowCount = 5;
			array<System::String^>^ row = { "0.00", "0.00", "0.00", "0.00", "0.00" };
			this->dataGridView->RowTemplate->Height = this->dataGridView->Size.Height / rowCount - 1;
			for (int i = 0; i < rowCount; ++i) {
				this->dataGridView->Rows->Add(row);
			}
			this->dataGridView->Rows[2]->Cells[2]->Value = "1.00";
		}

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
		property array<double, 2>^ Value {
			array<double, 2>^ get() {
				array<double, 2>^ data = gcnew array<double, 2>(this->dataGridView->RowCount, this->dataGridView->ColumnCount);
				for (int i = 0; i < this->dataGridView->RowCount; ++i) {
					for (int j = 0; j < this->dataGridView->ColumnCount; ++j) {
						data[i, j] = System::Convert::ToDouble(this->dataGridView->Rows[i]->Cells[j]->Value->ToString());
					}
				}
				return data;
			}
		}
	};
}
