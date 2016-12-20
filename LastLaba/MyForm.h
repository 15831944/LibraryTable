#pragma once
//#include "StringConverter.h"
#include "NewTabDialog.h"
#include "TScanTable.h"
#include "TSortTable.h"
#include "TListTable.h"
#include "TTreeTable.h"
#include "RandomFill.h"
#include <cmath>

namespace LastLaba {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		TTable *MainTable;
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  создатьToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  открытьToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  сохранитьToolStripButton;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->создатьToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->открытьToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->сохранитьToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->Location = System::Drawing::Point(12, 145);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(600, 285);
			this->dataGridView1->TabIndex = 0;
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->создатьToolStripButton,
					this->открытьToolStripButton, this->сохранитьToolStripButton, this->toolStripButton1
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(624, 25);
			this->toolStrip1->TabIndex = 1;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// создатьToolStripButton
			// 
			this->создатьToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->создатьToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"создатьToolStripButton.Image")));
			this->создатьToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->создатьToolStripButton->Name = L"создатьToolStripButton";
			this->создатьToolStripButton->Size = System::Drawing::Size(23, 22);
			this->создатьToolStripButton->Text = L"&Создать";
			this->создатьToolStripButton->Click += gcnew System::EventHandler(this, &MyForm::создатьToolStripButton_Click);
			// 
			// открытьToolStripButton
			// 
			this->открытьToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->открытьToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"открытьToolStripButton.Image")));
			this->открытьToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->открытьToolStripButton->Name = L"открытьToolStripButton";
			this->открытьToolStripButton->Size = System::Drawing::Size(23, 22);
			this->открытьToolStripButton->Text = L"&Открыть";
			this->открытьToolStripButton->Click += gcnew System::EventHandler(this, &MyForm::открытьToolStripButton_Click);
			// 
			// сохранитьToolStripButton
			// 
			this->сохранитьToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->сохранитьToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"сохранитьToolStripButton.Image")));
			this->сохранитьToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->сохранитьToolStripButton->Name = L"сохранитьToolStripButton";
			this->сохранитьToolStripButton->Size = System::Drawing::Size(23, 22);
			this->сохранитьToolStripButton->Text = L"&Сохранить";
			this->сохранитьToolStripButton->Click += gcnew System::EventHandler(this, &MyForm::сохранитьToolStripButton_Click);
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(100, 22);
			this->toolStripButton1->Text = L"AddRandomLine";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 41);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(118, 41);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(224, 41);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 4;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(330, 41);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 5;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(12, 80);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(418, 20);
			this->textBox5->TabIndex = 6;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(436, 38);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(176, 62);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Добавить запись";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"№ Билета";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(115, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Имя";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(221, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(56, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Фамилия";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(327, 25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(54, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Отчество";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(9, 64);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(38, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Адрес";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(9, 103);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(57, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"№ Билета";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(12, 119);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 14;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(118, 117);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 23);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Найти запись";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(330, 119);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(282, 20);
			this->textBox7->TabIndex = 16;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(327, 103);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(102, 13);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Найденная запись";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(224, 117);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 23);
			this->button3->TabIndex = 18;
			this->button3->Text = L"Удалить запись";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"csv";
			this->saveFileDialog1->Filter = L"Exel файлы (*.csv)|*.csv";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 441);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"База данных библиотеки";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
//создание новой таблицы
private: System::Void создатьToolStripButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
	NewTabDialog^ f2 = gcnew NewTabDialog();
	if (f2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		switch (f2->NumOfType)
		{
		case 0: MainTable = new TScanTable(f2->MaxSize); break;
		case 1: MainTable = new TSortTable(f2->MaxSize); break;
		case 2: MainTable = new TListTable(); break;
		case 3: MainTable = new TTreeTable(); break;			
		}
		MainTable->Display(dataGridView1);
	}
}

//добавление эл-та
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (textBox1->Text + textBox2->Text + textBox3->Text + textBox4->Text + textBox5->Text != "") {
		try	{
			TData *d = new TData(ToSTDstring(textBox2->Text), ToSTDstring(textBox3->Text),
				ToSTDstring(textBox4->Text), ToSTDstring(textBox5->Text));
			TKey k;
			try {
				k = Convert::ToInt32(textBox1->Text);
			}
			catch (...) {
				MessageBox::Show("Номер должен быть целым, положительным числом",
					"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			bool res = MainTable->InsRecord(k, d);
			if (!res) MessageBox::Show("Запись с таким номером уже есть",
				"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			MainTable->Display(dataGridView1);
		}
		catch (...)	{
			MessageBox::Show("Сперва нужно создать таблицу",
				"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else{
		MessageBox::Show("Заполните все поля",
			"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

//поиск
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
{
	TKey k;
	try {
		k = Convert::ToInt32(textBox6->Text);
	}
	catch (...) {
		MessageBox::Show("Номер должен быть целым, положительным числом",
			"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	TData* d = MainTable->FindRecord(k);
	if (d == 0)
		textBox7->Text = "Запись не найдена";
	else
		textBox7->Text = d->GetName() + " " + d->GetOtch() + " " + d->GetFaml() + ", " + d->GetAddress();
}

//удаление эл-та
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
{
	TKey k;
	try {
		k = Convert::ToInt32(textBox6->Text);
	}
	catch (...) {
		MessageBox::Show("Номер должен быть целым, положительным числом",
			"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	MainTable->DelRecord(k);
	MainTable->Display(dataGridView1);
}

//сохранение таблицы
private: System::Void сохранитьToolStripButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
	//показать диалог сохранения файла, если ок
	if (saveFileDialog1->ShowDialog() == ::System::Windows::Forms::DialogResult::OK)
	{
		//инициализация потока записи
		StreamWriter^ sw = File::CreateText(saveFileDialog1->FileName);
		MainTable->SaveTable(sw);	
		sw->Close();
	}
}


private: System::Void открытьToolStripButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
	//показать диалог открытия файла, если ок
	if (openFileDialog1->ShowDialog() == ::System::Windows::Forms::DialogResult::OK)
	{
		//инициал. потока чтения
		StreamReader^ sr = File::OpenText(openFileDialog1->FileName);
		//текущая строка
		String^ str;		
		// номер строки
		int CurLine = 0;
		//пока не конец файла
		while (sr->Peek() >= 0)	{
			//считывание строки
			str = sr->ReadLine();
			if (CurLine == 0) {
				array<String^>^ arr = str->Split(';');
				if (arr[0] == "ScanTable"){
					MainTable = new TScanTable(Convert::ToInt32(arr[2]));
				}
				else if (arr[0] == "SortTable")	{
					MainTable = new TSortTable(Convert::ToInt32(arr[2]));
				}
				else if (arr[0] == "ListTable") {
					MainTable = new TListTable();
				}
				else if (arr[0] == "TreeTable") {
					MainTable = new TTreeTable();
				}
			}
			if (CurLine > 1) {
				array<String^>^ arr = str->Split(';');
				TData *d = new TData(ToSTDstring(arr[1]), ToSTDstring(arr[2]),
					ToSTDstring(arr[3]), ToSTDstring(arr[4]));
				TKey k = Convert::ToInt32(arr[0]);
				MainTable->InsRecord(k, d);
			}
			CurLine++;
		}
		sr->Close();
		try {
			MainTable->Display(dataGridView1);
		}
		catch (...)	{
			MessageBox::Show("Некорректный файл",
				"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

//добавить случайную запись
private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	try {
		TKey k = rand();
		TData* g = RandData();
		MainTable->InsRecord(k, g);
		MainTable->Display(dataGridView1);
	}
	catch (...) {
		MessageBox::Show("Сперва нужно создать таблицу",
			"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
};
}
