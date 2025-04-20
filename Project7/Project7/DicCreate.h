#pragma once
//#include "wins.h"
#include "Dictionary.h"

namespace Project7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для DicCreate
	/// </summary>
	public ref class DicCreate : public System::Windows::Forms::Form
	{
	public:
		DicCreate(void)
		{
			InitializeComponent();
			// Определяем событие
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DicCreate()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ NewDicName;
	private: System::Windows::Forms::Button^ ok_btn;
	private: System::Windows::Forms::Button^ cancel_btn;


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->NewDicName = (gcnew System::Windows::Forms::TextBox());
			this->ok_btn = (gcnew System::Windows::Forms::Button());
			this->cancel_btn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(190, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите название словаря:";
			// 
			// NewDicName
			// 
			this->NewDicName->Location = System::Drawing::Point(16, 33);
			this->NewDicName->Name = L"NewDicName";
			this->NewDicName->Size = System::Drawing::Size(256, 20);
			this->NewDicName->TabIndex = 1;
			// 
			// ok_btn
			// 
			this->ok_btn->Location = System::Drawing::Point(9, 69);
			this->ok_btn->Name = L"ok_btn";
			this->ok_btn->Size = System::Drawing::Size(130, 57);
			this->ok_btn->TabIndex = 2;
			this->ok_btn->Text = L"Ок";
			this->ok_btn->UseVisualStyleBackColor = true;
			this->ok_btn->Click += gcnew System::EventHandler(this, &DicCreate::ok_btn_click);
			// 
			// cancel_btn
			// 
			this->cancel_btn->BackColor = System::Drawing::Color::IndianRed;
			this->cancel_btn->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->cancel_btn->Location = System::Drawing::Point(145, 69);
			this->cancel_btn->Name = L"cancel_btn";
			this->cancel_btn->Size = System::Drawing::Size(130, 57);
			this->cancel_btn->TabIndex = 3;
			this->cancel_btn->Text = L"Отмена";
			this->cancel_btn->UseVisualStyleBackColor = false;
			this->cancel_btn->Click += gcnew System::EventHandler(this, &DicCreate::cancel_btn_click);
			// 
			// DicCreate
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 136);
			this->Controls->Add(this->cancel_btn);
			this->Controls->Add(this->ok_btn);
			this->Controls->Add(this->NewDicName);
			this->Controls->Add(this->label1);
			this->Name = L"DicCreate";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"DicCreate";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void ok_btn_click(System::Object^ sender, System::EventArgs^ e) {
	if (NewDicName->Text == "")
	{
		MessageBox::Show("Кажется, вы ничего не ввели ");
	}
	else
	{
		// Определяем количество строк в файле dics.txt
		int num = 0;
		try {
			System::IO::StreamReader^ reader = gcnew System::IO::StreamReader("dics.txt");
			while (reader->ReadLine() != nullptr) {
				num++;
			}
			reader->Close();
		}
		catch (System::Exception^ ex) {
			// Обработка исключения, если файл не найден или произошла другая ошибка
			MessageBox::Show("Ошибка при чтении файла: " + ex->Message);
			return; // Выход из метода в случае ошибки
		}

		num++; // Увеличиваем на 1

		DictionaryOW^ myDictionary = gcnew DictionaryOW(NewDicName->Text, "dics\data" + num.ToString() + ".txt", DictionaryOW::AllDictionaries()->Count);

		// Записываем имя словаря в файл dics.txt
		System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter("dics.txt", true);
		writer->WriteLine(NewDicName->Text + ",удалить,открыть,data" + num.ToString() + ".txt");
		writer->Close();

		this->Close();
	}
}


	private: System::Void cancel_btn_click(System::Object^ sender, System::EventArgs^ e) {
		//wins::OpenDicChoice();
		this->Close();
	}

};
}
