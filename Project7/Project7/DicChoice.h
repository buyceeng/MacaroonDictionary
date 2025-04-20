#pragma once
#include "Dictionary.h"
#include "DicCreate.h"
#include "DataSourceEventArgs.h"
#include <String>

//#include "wins.h"

namespace Project7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Сводка для DicChoice
	/// </summary>
	public ref class DicChoice : public System::Windows::Forms::Form
	{
	public:
		event EventHandler<DataSourceEventArgs^>^ DataSourceChanged;
		DicChoice(void)
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
		~DicChoice()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView12;
	protected:


	private: System::Windows::Forms::Button^ CreateDic_btn;





	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DicName;
	private: System::Windows::Forms::DataGridViewButtonColumn^ btn_choice;
	private: System::Windows::Forms::DataGridViewButtonColumn^ OpnDic_btn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ file;




	private: System::ComponentModel::IContainer^ components;


	public:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView12 = (gcnew System::Windows::Forms::DataGridView());
			this->DicName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btn_choice = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->OpnDic_btn = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->file = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CreateDic_btn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView12))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView12
			// 
			this->dataGridView12->AllowUserToAddRows = false;
			this->dataGridView12->AllowUserToDeleteRows = false;
			this->dataGridView12->AllowUserToResizeColumns = false;
			this->dataGridView12->AllowUserToResizeRows = false;
			this->dataGridView12->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView12->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView12->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->DicName,
					this->btn_choice, this->OpnDic_btn, this->file
			});
			this->dataGridView12->Location = System::Drawing::Point(13, 113);
			this->dataGridView12->Name = L"dataGridView12";
			this->dataGridView12->ReadOnly = true;
			this->dataGridView12->Size = System::Drawing::Size(359, 261);
			this->dataGridView12->TabIndex = 0;
			this->dataGridView12->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DicChoice::dataGridView12_CellContentClick);
			// 
			// DicName
			// 
			this->DicName->HeaderText = L"Словарь";
			this->DicName->Name = L"DicName";
			this->DicName->ReadOnly = true;
			// 
			// btn_choice
			// 
			this->btn_choice->HeaderText = L"";
			this->btn_choice->Name = L"btn_choice";
			this->btn_choice->ReadOnly = true;
			// 
			// OpnDic_btn
			// 
			this->OpnDic_btn->HeaderText = L"";
			this->OpnDic_btn->Name = L"OpnDic_btn";
			this->OpnDic_btn->ReadOnly = true;
			// 
			// file
			// 
			this->file->HeaderText = L"Файл";
			this->file->Name = L"file";
			this->file->ReadOnly = true;
			this->file->Visible = false;
			// 
			// CreateDic_btn
			// 
			this->CreateDic_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CreateDic_btn->Location = System::Drawing::Point(13, 12);
			this->CreateDic_btn->Name = L"CreateDic_btn";
			this->CreateDic_btn->Size = System::Drawing::Size(359, 83);
			this->CreateDic_btn->TabIndex = 1;
			this->CreateDic_btn->Text = L"Создать";
			this->CreateDic_btn->UseVisualStyleBackColor = true;
			this->CreateDic_btn->Click += gcnew System::EventHandler(this, &DicChoice::button1_Click);
			// 
			// DicChoice
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 386);
			this->Controls->Add(this->CreateDic_btn);
			this->Controls->Add(this->dataGridView12);
			this->Name = L"DicChoice";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"DicChoice";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &DicChoice::DicChoice_FormClosed);
			this->Load += gcnew System::EventHandler(this, &DicChoice::DicChoice_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView12))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion


		void SaveDics() {
			System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter("dics.txt");

			// Проход по строкам DataGridView
			for (int i = 0; i < dataGridView12->Rows->Count; i++) {
				String^ line = "";
				for (int j = 0; j < dataGridView12->Columns->Count; j++) {
					// Проверка на null
					if (dataGridView12->Rows[i]->Cells[j]->Value != nullptr) {
						line += dataGridView12->Rows[i]->Cells[j]->Value->ToString();
					}
					line += ","; // Добавляем запятую после значения
				}
				// Удаляем последнюю запятую, если строка не пустая
				if (line->Length > 0) {
					line = line->Substring(0, line->Length - 1);
				}

				sw->WriteLine(line);
			}

			sw->Close();
		}


		void LoadData() {
			if ("dics.txt") {
				System::IO::StreamReader^ sr = gcnew System::IO::StreamReader("dics.txt");
				String^ line;

				// Чтение файла построчно
				while ((line = sr->ReadLine()) != nullptr) {
					array<String^>^ values = line->Split(',');
					dataGridView12->Rows->Add(values);
				}

				sr->Close();
			}
			dataGridView12->CurrentCell = nullptr;
			dataGridView12->ClearSelection();
			// Проходим по всем строкам в DataGridView
			for (int i = 0; i < dataGridView12->Rows->Count; i++)
			{
				// Проверяем, содержится ли "абв" в какой-либо ячейке строки
				for (int j = 0; j < dataGridView12->Columns->Count; j++)
				{
					if (dataGridView12->Rows[i]->Cells[j]->Value != nullptr &&
						dataGridView12->Rows[i]->Cells[j]->Value->ToString()->Contains(DictionaryOW::GetCurrent()->GetSourceFile()))
					{
						// Изменяем цвет фона строки
						dataGridView12->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::Green; // или любой другой цвет
						break; // Выходим из внутреннего цикла, если нашли совпадение
					}
				}
			}
			dataGridView12->CurrentCell = nullptr;
			dataGridView12->ClearSelection();
		}


		public: void GridUpdate()
		{
			dataGridView12->Rows->Clear();
			LoadData();
		}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		DicCreate^ dicCreateInstance = gcnew DicCreate();
		dicCreateInstance->FormClosed += gcnew FormClosedEventHandler(this, &DicChoice::OnDicCreateClosed);
		dicCreateInstance->ShowDialog();
	}
	void OnDicCreateClosed(Object^ sender, FormClosedEventArgs^ e)
			{
		GridUpdate();
			}
	private: System::Void DicChoice_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadData();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		GridUpdate();
	}
private: System::Void DicChoice_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	SaveDics();
}
private: System::Void dataGridView12_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex >= 0 && e->ColumnIndex >= 1)
	{
		if (e->ColumnIndex == 1) // Кнопка 1
		{
			if (MessageBox::Show("Вы уверены, что хотите удалить этот словарь?", "Подтверждение", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes)
			{
				// Удаляем строку
				auto cellValue = dataGridView12->Rows[e->RowIndex]->Cells[3]->Value;
				File::Delete(cellValue->ToString());
				this->dataGridView12->Rows->RemoveAt(e->RowIndex);
				SaveDics();
			}
		}
		else if (e->ColumnIndex == 2) // Кнопка 2
		{

			auto cellValue = dataGridView12->Rows[e->RowIndex]->Cells[3]->Value;
			if (cellValue != nullptr) {
				DictionaryOW::GetCurrent()->SetSourceFile(cellValue->ToString());
			}

			this->Close(); // Закрываем форму после изменения источника данных
		}


	}

}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	GridUpdate();
}
};
}
