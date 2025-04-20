#pragma once
#include "DicChoice.h"
#include "DicCreate.h"
#include "WordChange.h"

namespace Project7 {

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
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::TextBox^ eng;
	private: System::Windows::Forms::TextBox^ rus;
	private: System::Windows::Forms::TextBox^ trans;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;




	private: System::Windows::Forms::PictureBox^ pictureBox1;




	private: System::Windows::Forms::TextBox^ SearchBox;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;




	private: System::Windows::Forms::Button^ DicChoice_btn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ column_eng;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ column_rus;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ column_trans;
	private: System::Windows::Forms::DataGridViewButtonColumn^ del_btns;
	private: System::Windows::Forms::DataGridViewButtonColumn^ change_btns;











	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->column_eng = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->column_rus = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->column_trans = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->del_btns = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->change_btns = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->eng = (gcnew System::Windows::Forms::TextBox());
			this->rus = (gcnew System::Windows::Forms::TextBox());
			this->trans = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->SearchBox = (gcnew System::Windows::Forms::TextBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->DicChoice_btn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->column_eng,
					this->column_rus, this->column_trans, this->del_btns, this->change_btns
			});
			this->dataGridView1->Location = System::Drawing::Point(4, 25);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(400, 500);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// column_eng
			// 
			this->column_eng->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
			this->column_eng->HeaderText = L"Слово";
			this->column_eng->Name = L"column_eng";
			this->column_eng->ReadOnly = true;
			this->column_eng->Width = 63;
			// 
			// column_rus
			// 
			this->column_rus->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->column_rus->HeaderText = L"Перевод";
			this->column_rus->Name = L"column_rus";
			this->column_rus->ReadOnly = true;
			// 
			// column_trans
			// 
			this->column_trans->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->column_trans->HeaderText = L"Транскрипция";
			this->column_trans->Name = L"column_trans";
			this->column_trans->ReadOnly = true;
			// 
			// del_btns
			// 
			this->del_btns->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->del_btns->HeaderText = L"";
			this->del_btns->Name = L"del_btns";
			this->del_btns->ReadOnly = true;
			this->del_btns->Text = L"Удалить";
			// 
			// change_btns
			// 
			this->change_btns->HeaderText = L"";
			this->change_btns->Name = L"change_btns";
			this->change_btns->ReadOnly = true;
			// 
			// eng
			// 
			this->eng->Location = System::Drawing::Point(443, 355);
			this->eng->Name = L"eng";
			this->eng->Size = System::Drawing::Size(90, 20);
			this->eng->TabIndex = 1;
			// 
			// rus
			// 
			this->rus->Location = System::Drawing::Point(558, 355);
			this->rus->Name = L"rus";
			this->rus->Size = System::Drawing::Size(90, 20);
			this->rus->TabIndex = 2;
			// 
			// trans
			// 
			this->trans->Location = System::Drawing::Point(672, 355);
			this->trans->Name = L"trans";
			this->trans->Size = System::Drawing::Size(90, 20);
			this->trans->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(466, 339);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Слово:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(580, 339);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Перевод:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(679, 339);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Транскрипция:";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(439, 399);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(323, 132);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Записать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(443, -48);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(338, 280);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// SearchBox
			// 
			this->SearchBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SearchBox->Location = System::Drawing::Point(443, 288);
			this->SearchBox->Name = L"SearchBox";
			this->SearchBox->Size = System::Drawing::Size(319, 29);
			this->SearchBox->TabIndex = 9;
			this->SearchBox->TextChanged += gcnew System::EventHandler(this, &MyForm::SearchBox_TextChanged);
			// 
			// DicChoice_btn
			// 
			this->DicChoice_btn->Location = System::Drawing::Point(443, 239);
			this->DicChoice_btn->Name = L"DicChoice_btn";
			this->DicChoice_btn->Size = System::Drawing::Size(319, 43);
			this->DicChoice_btn->TabIndex = 10;
			this->DicChoice_btn->Text = L"Выбрать словарь";
			this->DicChoice_btn->UseVisualStyleBackColor = true;
			this->DicChoice_btn->Click += gcnew System::EventHandler(this, &MyForm::DicChoice_btn_Click);
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->DicChoice_btn);
			this->Controls->Add(this->SearchBox);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trans);
			this->Controls->Add(this->rus);
			this->Controls->Add(this->eng);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void SaveData(String^ filePath) {
			try {
				// Проверка на null
				if (String::IsNullOrEmpty(filePath)) {
					throw gcnew System::ArgumentNullException("filePath", "Значение не может быть неопределенным.");
				}

				System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(filePath);

				// Проход по строкам DataGridView
				for (int i = 0; i < dataGridView1->Rows->Count; i++) {
					String^ line = "";
					for (int j = 0; j < dataGridView1->Columns->Count; j++) {
						// Проверка на null значение ячейки
						if (dataGridView1->Rows[i]->Cells[j]->Value != nullptr) {
							line += dataGridView1->Rows[i]->Cells[j]->Value->ToString() + ",";
						}
					}
					// Удаление последней запятой, если строка не пустая
					if (line->Length > 0) {
						line = line->Substring(0, line->Length - 1);
					}
					sw->WriteLine(line);
				}

				sw->Close();
			}
			catch (System::Exception^ ex) {
				// Обработка исключения, например, вывод сообщения об ошибке
				System::Windows::Forms::MessageBox::Show("Ошибка при сохранении данных: " + ex->Message, "Ошибка", 
					System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
			}
		}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->eng->Text == "" || this->rus->Text == "" || this->trans->Text == "")
		{
			MessageBox::Show("Пожалуйста, заполните все поля");
		}
		else {
			array<String^>^ row = gcnew array<String^>(5);
			row[0] = this->eng->Text;
			row[1] = this->rus->Text;
			row[2] = this->trans->Text;
			row[3] = "Удалить";
			row[4] = "изменить";
			this->dataGridView1->Rows->Add(row);
			this->trans->Text = "";
			this->rus->Text = "";
			this->eng->Text = "";
			dataGridView1->Sort(dataGridView1->Columns[0], System::ComponentModel::ListSortDirection::Ascending);
			SaveData(DictionaryOW::GetCurrent()->GetSourceFile());
			//MessageBox::Show("Сохранено в " + DictionaryOW::GetCurrent()->GetSourceFile());
			//Console::WriteLine("Сохранено в " + DictionaryOW::GetCurrent()->GetSourceFile());
		}
	}

	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		try
		{
			// Проверяем, что dataGridView1 и его колонки и строки инициализированы
			if (this->dataGridView1 != nullptr && this->dataGridView1->Columns != nullptr && this->dataGridView1->Rows != nullptr && this->dataGridView1->Columns->Contains("del_btns")) // Проверяем наличие колонки "Delete"
			{
				if (e->ColumnIndex == this->dataGridView1->Columns["del_btns"]->Index && e->RowIndex >= 0)
				{
					if (this->dataGridView1->Rows->Count > e->RowIndex)
					{
						// Подтверждение удаления
						if (MessageBox::Show("Вы уверены, что хотите удалить эту строку?", "Подтверждение", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes)
						{
							// Удаляем строку
							this->dataGridView1->Rows->RemoveAt(e->RowIndex);
							SaveData(DictionaryOW::GetCurrent()->GetSourceFile());

						}
					}
				}
				else if (e->ColumnIndex == this->dataGridView1->Columns["change_btns"]->Index && e->RowIndex >= 0)
				{
					//if (MessageBox::Show("Вы хотите заменить данные слова на введенные?", "Подтверждение", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
					//	if (this->eng->Text == "" || this->rus->Text == "" || this->trans->Text == "")
					//	{
					//		MessageBox::Show("Пожалуйста, заполните все поля");
					//		return;
					//	}
					//	this->dataGridView1->Rows[e->RowIndex]->Cells[0]->Value = this->eng->Text;
					//	this->dataGridView1->Rows[e->RowIndex]->Cells[1]->Value = this->rus->Text;
					//	this->dataGridView1->Rows[e->RowIndex]->Cells[2]->Value = this->trans->Text;
					//	this->trans->Text = "";
					//	this->rus->Text = "";
					//	this->eng->Text = "";
					//	dataGridView1->Sort(dataGridView1->Columns[0], System::ComponentModel::ListSortDirection::Ascending);
					//	SaveData(DictionaryOW::GetCurrent()->GetSourceFile());
					//}
					WordChange^ WordChangeInst = gcnew WordChange();
					//dicChoice->FormClosed += gcnew FormClosedEventHandler(this, &MyForm::OnDicChoiceClosed);
					WordChangeInst->WC_setNewWord(this->dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString());
					WordChangeInst->WC_setNewTranslation(this->dataGridView1->Rows[e->RowIndex]->Cells[1]->Value->ToString());
					WordChangeInst->WC_setNewTrans(this->dataGridView1->Rows[e->RowIndex]->Cells[2]->Value->ToString());
					if (WordChangeInst->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					{
						// Обновляем только если пользователь нажал OK
						this->dataGridView1->Rows[e->RowIndex]->Cells[0]->Value = WordChangeInst->WC_getNewWord();
						this->dataGridView1->Rows[e->RowIndex]->Cells[1]->Value = WordChangeInst->WC_getNewTranslation();
						this->dataGridView1->Rows[e->RowIndex]->Cells[2]->Value = WordChangeInst->WC_getNewTrans();

						// Сортируем и сохраняем
						dataGridView1->Sort(dataGridView1->Columns[0], System::ComponentModel::ListSortDirection::Ascending);
						SaveData(DictionaryOW::GetCurrent()->GetSourceFile());
					}

				}
			}
		}
		catch (NullReferenceException^ ex)
		{
			MessageBox::Show("NullReferenceException: " + ex->Message);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Ошибка при удалении строки: " + ex->Message);
		}
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		// Проверка наличия файла
		if (System::IO::File::Exists(DictionaryOW::GetCurrent()->GetSourceFile())) {
			System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(DictionaryOW::GetCurrent()->GetSourceFile());
			String^ line;

			// Чтение файла построчно
			while ((line = sr->ReadLine()) != nullptr) {
				array<String^>^ values = line->Split(',');
				dataGridView1->Rows->Add(values);
			}

			sr->Close();
		}
	}
	private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		SaveData(DictionaryOW::GetCurrent()->GetSourceFile());
		File::WriteAllText("last.txt", DictionaryOW::GetCurrent()->GetSourceFile());
	}

private: System::Void SearchBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	String^ searchValue = SearchBox->Text->ToLower();
	dataGridView1->Rows->Clear();

	// Проверяем наличие файла перед чтением
	if (System::IO::File::Exists(DictionaryOW::GetCurrent()->GetSourceFile())) {
		System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(DictionaryOW::GetCurrent()->GetSourceFile());
		String^ line;

		// Чтение файла построчно
		while ((line = sr->ReadLine()) != nullptr) {
			array<String^>^ values = line->Split(',');
			// Проверка на наличие данных в массиве
			if (!String::IsNullOrEmpty(searchValue)) {
				if (values->Length > 0) {
					bool found = false;
					for (int i = 0; i < values->Length; i++) {
						if (values[i]->ToLower()->Contains(searchValue)) {
							found = true;
							break;
						}
					}
					if (found) {
						dataGridView1->Rows->Add(values);
					}
				}

			}
			else {
				dataGridView1->Rows->Add(values);
			}
		}
		sr->Close();
	}
}
			
private: System::Void DicChoice_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	//this->Hide();
	DicChoice^ dicChoice = gcnew DicChoice();
	dicChoice->FormClosed += gcnew FormClosedEventHandler(this, &MyForm::OnDicChoiceClosed);
	dicChoice->ShowDialog();

}
	void OnDicChoiceClosed(Object^ sender, FormClosedEventArgs^ e)
	   {
		   dataGridView1->Rows->Clear();
		   if (System::IO::File::Exists(DictionaryOW::GetCurrent()->GetSourceFile())) {
			   System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(DictionaryOW::GetCurrent()->GetSourceFile());
			   String^ line;

			   // Чтение файла построчно
			   while ((line = sr->ReadLine()) != nullptr) {
				   array<String^>^ values = line->Split(',');
				   dataGridView1->Rows->Add(values);
			   }

			   sr->Close();
		   }
		   //this->Show();
	}
};
}
