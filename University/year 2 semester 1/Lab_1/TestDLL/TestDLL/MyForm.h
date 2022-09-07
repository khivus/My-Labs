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
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private:  System::Drawing::Font^ italic_font;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ button5;
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
	private: System::Windows::Forms::Button^ button1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(260, 126);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(170, 70);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Apply bold";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(260, 222);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(170, 70);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Apply italic";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(54, 222);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(170, 70);
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
			this->label1->Location = System::Drawing::Point(193, 333);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(24, 25);
			this->label1->TabIndex = 4;
			this->label1->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(50, 334);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(137, 24);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Vowel counter:";
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::Color::Red;
			this->button4->Location = System::Drawing::Point(54, 126);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(170, 70);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Make selected\r\n text red";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox1->Location = System::Drawing::Point(12, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(462, 84);
			this->richTextBox1->TabIndex = 7;
			this->richTextBox1->Text = L"";
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(330, 328);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(100, 40);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Reset";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(486, 386);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public: 
	char* SystemStringToChar(System::String^ string) {
		return (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(string);
	}

	System::String^ CharToSystemString(char* ch) {
			  return gcnew String(ch);
	}

private: 
	System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		richTextBox1->Font = bold_font;
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		richTextBox1->Font = italic_font;
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	label1->Text = Convert::ToString(VowelCount(SystemStringToChar(richTextBox1->Text)));
	}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	richTextBox1->SelectionColor = System::Drawing::Color::Red;
	
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	richTextBox1->Font = def_font;
	richTextBox1->ForeColor = richTextBox1->DefaultForeColor;
}

};
}
