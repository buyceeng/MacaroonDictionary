#pragma once

namespace Project7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для WordChange
	/// </summary>
	public ref class WordChange : public System::Windows::Forms::Form
	{
	public:
		WordChange(void)
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
		~WordChange()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ newWord;
	private: System::Windows::Forms::TextBox^ newTranslate;
	private: System::Windows::Forms::TextBox^ newTrans;
	protected:



	private: System::Windows::Forms::Button^ okBtn;
	private: System::Windows::Forms::Button^ cancelBtn;

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
			this->newWord = (gcnew System::Windows::Forms::TextBox());
			this->newTranslate = (gcnew System::Windows::Forms::TextBox());
			this->newTrans = (gcnew System::Windows::Forms::TextBox());
			this->okBtn = (gcnew System::Windows::Forms::Button());
			this->cancelBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(52, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(283, 60);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите данные для замены:";
			// 
			// newWord
			// 
			this->newWord->Location = System::Drawing::Point(12, 72);
			this->newWord->Name = L"newWord";
			this->newWord->Size = System::Drawing::Size(100, 20);
			this->newWord->TabIndex = 1;
			// 
			// newTranslate
			// 
			this->newTranslate->Location = System::Drawing::Point(142, 72);
			this->newTranslate->Name = L"newTranslate";
			this->newTranslate->Size = System::Drawing::Size(100, 20);
			this->newTranslate->TabIndex = 2;
			// 
			// newTrans
			// 
			this->newTrans->Location = System::Drawing::Point(272, 72);
			this->newTrans->Name = L"newTrans";
			this->newTrans->Size = System::Drawing::Size(100, 20);
			this->newTrans->TabIndex = 3;
			// 
			// okBtn
			// 
			this->okBtn->BackColor = System::Drawing::Color::LightGreen;
			this->okBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->okBtn->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->okBtn->Location = System::Drawing::Point(12, 122);
			this->okBtn->Name = L"okBtn";
			this->okBtn->Size = System::Drawing::Size(160, 75);
			this->okBtn->TabIndex = 4;
			this->okBtn->Text = L"Ок";
			this->okBtn->UseVisualStyleBackColor = false;
			this->okBtn->Click += gcnew System::EventHandler(this, &WordChange::okBtn_Click);
			// 
			// cancelBtn
			// 
			this->cancelBtn->BackColor = System::Drawing::Color::IndianRed;
			this->cancelBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cancelBtn->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->cancelBtn->Location = System::Drawing::Point(212, 122);
			this->cancelBtn->Name = L"cancelBtn";
			this->cancelBtn->Size = System::Drawing::Size(160, 75);
			this->cancelBtn->TabIndex = 5;
			this->cancelBtn->Text = L"Отмена";
			this->cancelBtn->UseVisualStyleBackColor = false;
			this->cancelBtn->Click += gcnew System::EventHandler(this, &WordChange::cancelBtn_Click);
			// 
			// WordChange
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 204);
			this->Controls->Add(this->cancelBtn);
			this->Controls->Add(this->okBtn);
			this->Controls->Add(this->newTrans);
			this->Controls->Add(this->newTranslate);
			this->Controls->Add(this->newWord);
			this->Controls->Add(this->label1);
			this->Name = L"WordChange";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"WordChange";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void cancelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Close();
	}
private: System::Void okBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrEmpty(newWord->Text) || String::IsNullOrEmpty(newTranslate->Text) || String::IsNullOrEmpty(newTrans->Text))
	{
		MessageBox::Show("Пожалуйста, заполните все обязательные поля");
		return;
	}

	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}
	public: void WC_setNewWord(String^ NW) { this->newWord->Text = NW; }
	void WC_setNewTranslation(String^ NTR) { this->newTranslate->Text = NTR; }
	void WC_setNewTrans(String^ NTS) { this->newTrans->Text = NTS; }
	String^ WC_getNewWord() { return this->newWord->Text; }
	String^ WC_getNewTranslation() { return this->newTranslate->Text; }
	String^ WC_getNewTrans() { return this->newTrans->Text; }
	   
};
}
