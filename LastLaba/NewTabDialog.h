#pragma once

namespace LastLaba {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для NewTabDialog
	/// </summary>
	public ref class NewTabDialog : public System::Windows::Forms::Form
	{
	public:
		NewTabDialog(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~NewTabDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(15, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(125, 20);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(127, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Максимальный размер";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(157, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Тип таблицы";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"ScanTable", L"SortTable", L"ListTable", L"TreeTable" });
			this->comboBox1->Location = System::Drawing::Point(160, 24);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(125, 21);
			this->comboBox1->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 50);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(270, 25);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Создать таблицу";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &NewTabDialog::button1_Click);
			// 
			// NewTabDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(304, 81);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"NewTabDialog";
			this->Text = L"Новая таблица";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: int MaxSize;
	public: int NumOfType;

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{		
		if (comboBox1->SelectedIndex != -1) {
			if ((comboBox1->SelectedIndex <= 1) && (textBox1->Text != ""))
			{
				try {
					MaxSize = Convert::ToInt32(textBox1->Text);
				}
				catch (...) {
					MessageBox::Show("Размер должен быть целым, положительным",
						"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				NumOfType = comboBox1->SelectedIndex;
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
			}
			else if (comboBox1->SelectedIndex >= 2)
			{
				NumOfType = comboBox1->SelectedIndex;
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
			}
		}
		else
		{
			MessageBox::Show("Выберите тип таблицы",
				"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		delete this;
	}

};
}
