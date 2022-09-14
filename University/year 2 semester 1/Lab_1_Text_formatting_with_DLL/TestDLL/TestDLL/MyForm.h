// Lab_1 v1.0.2 2022 Aleksey Kharin

#pragma once
#include "myDLL.h"
#include <cstdio>
#include <msclr\marshal_cppstd.h>

namespace TestDLL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	//private: TextBox^ txt;
	private:  System::Drawing::Font^ bold_font;
	private:  System::Drawing::Font^ def_font;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private:  System::Drawing::Font^ italic_font;

	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ button5;



	private: System::Windows::Forms::Button^ button6;

	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::Label^ WarningLabel;



	private:  System::Drawing::Color^ krasniy;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//txt = gcnew TextBox;
			bold_font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, richTextBox1->Font->Size, System::Drawing::FontStyle::Bold);
			italic_font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, richTextBox1->Font->Size, System::Drawing::FontStyle::Italic);
			def_font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, richTextBox1->Font->Size, System::Drawing::FontStyle::Regular);
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->WarningLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(182, 170);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(120, 50);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Count vowels";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(238, 231);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(24, 25);
			this->label1->TabIndex = 4;
			this->label1->Text = L"0";
			this->label1->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(95, 232);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(137, 24);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Vowel counter:";
			this->label2->Visible = false;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox1->Location = System::Drawing::Point(12, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(310, 84);
			this->richTextBox1->TabIndex = 7;
			this->richTextBox1->Text = L"";
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(116, 259);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(100, 40);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Reset";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(30, 170);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(120, 50);
			this->button6->TabIndex = 3;
			this->button6->Text = L"Apply";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton1->Location = System::Drawing::Point(23, 112);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(70, 28);
			this->radioButton1->TabIndex = 11;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Bold";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton2->Location = System::Drawing::Point(99, 112);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(64, 28);
			this->radioButton2->TabIndex = 11;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Italic";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton3->ForeColor = System::Drawing::Color::Red;
			this->radioButton3->Location = System::Drawing::Point(169, 112);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(142, 28);
			this->radioButton3->TabIndex = 11;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Selected Red";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// WarningLabel
			// 
			this->WarningLabel->AutoSize = true;
			this->WarningLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->WarningLabel->ForeColor = System::Drawing::Color::Red;
			this->WarningLabel->Location = System::Drawing::Point(26, 143);
			this->WarningLabel->Name = L"WarningLabel";
			this->WarningLabel->Size = System::Drawing::Size(276, 24);
			this->WarningLabel->TabIndex = 12;
			this->WarningLabel->Text = L"No one radio button is selected!";
			this->WarningLabel->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(334, 311);
			this->Controls->Add(this->WarningLabel);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(350, 350);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(350, 350);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Text redactor";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public: 
	char* SystemStringToChar(System::String^ string) {
		return (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(string);
	}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	label1->Text = Convert::ToString(VowelCount(SystemStringToChar(richTextBox1->Text)));
	label1->Visible = true;
	label2->Visible = true;
	}

private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	richTextBox1->Font = def_font;
	richTextBox1->ForeColor = richTextBox1->DefaultForeColor;
	richTextBox1->Text = "";
	label1->Text = "0";
	label1->Visible = false;
	label2->Visible = false;
	radioButton1->Checked = false;
	radioButton2->Checked = false;
	radioButton3->Checked = false;
}

private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	WarningLabel->Visible = false;
	richTextBox1->Font = def_font;
	int mode;

	if (radioButton1->Checked) { mode = RadioButtonSelection(1); }
	else if (radioButton2->Checked) { mode = RadioButtonSelection(2); }
	else if (radioButton3->Checked) { mode = RadioButtonSelection(3); }
	else { mode = RadioButtonSelection(4); }

	switch (mode) {
	case 1:
		richTextBox1->Font = bold_font;
		break;
	case 2:
		richTextBox1->Font = italic_font;
		break;
	case 3:
		richTextBox1->SelectionColor = System::Drawing::Color::Red;
		break;
	default:
		WarningLabel->Visible = true;
		break;
	}

}
};
}
