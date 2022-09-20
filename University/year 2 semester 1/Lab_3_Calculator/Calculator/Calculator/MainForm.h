// CppCalculator v1.0.0 2022 Aleksey Kharin
// Release ver!

#pragma once

#include <string>
#include <msclr\marshal_cppstd.h>
#include "DllForCalc.h"

namespace WindowsFormsTemplate {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ But0;
	private: System::Windows::Forms::Button^ ButDot;
	private: System::Windows::Forms::Button^ ButGetRes;
	private: System::Windows::Forms::Button^ But2;
	protected:

	protected:

	private: System::Windows::Forms::Button^ But3;
	private: System::Windows::Forms::Button^ ButPlus;
	private: System::Windows::Forms::Button^ But1;
	private: System::Windows::Forms::Button^ But5;
	private: System::Windows::Forms::Button^ But6;
	private: System::Windows::Forms::Button^ ButMinus;
	private: System::Windows::Forms::Button^ But4;
	private: System::Windows::Forms::Button^ But8;
	private: System::Windows::Forms::Button^ But9;
	private: System::Windows::Forms::Button^ ButMulti;
	private: System::Windows::Forms::Button^ But7;
	private: System::Windows::Forms::Button^ ButSqr;
	private: System::Windows::Forms::Button^ ButRoot;
	private: System::Windows::Forms::Button^ ButDiv;
	private: System::Windows::Forms::Button^ ButCos;
	private: System::Windows::Forms::Button^ ButClearEverything;
	private: System::Windows::Forms::Button^ ButClear;
	private: System::Windows::Forms::Button^ ButTan;
	private: System::Windows::Forms::Button^ ButSin;
	private: System::Windows::Forms::RichTextBox^ richTextBoxMain;
	private: System::Windows::Forms::RichTextBox^ richTextBoxRes;
	private: System::Windows::Forms::RichTextBox^ richTextBoxSign;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->But0 = (gcnew System::Windows::Forms::Button());
			this->ButDot = (gcnew System::Windows::Forms::Button());
			this->ButGetRes = (gcnew System::Windows::Forms::Button());
			this->But2 = (gcnew System::Windows::Forms::Button());
			this->But3 = (gcnew System::Windows::Forms::Button());
			this->ButPlus = (gcnew System::Windows::Forms::Button());
			this->But1 = (gcnew System::Windows::Forms::Button());
			this->But5 = (gcnew System::Windows::Forms::Button());
			this->But6 = (gcnew System::Windows::Forms::Button());
			this->ButMinus = (gcnew System::Windows::Forms::Button());
			this->But4 = (gcnew System::Windows::Forms::Button());
			this->But8 = (gcnew System::Windows::Forms::Button());
			this->But9 = (gcnew System::Windows::Forms::Button());
			this->ButMulti = (gcnew System::Windows::Forms::Button());
			this->But7 = (gcnew System::Windows::Forms::Button());
			this->ButSqr = (gcnew System::Windows::Forms::Button());
			this->ButRoot = (gcnew System::Windows::Forms::Button());
			this->ButDiv = (gcnew System::Windows::Forms::Button());
			this->ButCos = (gcnew System::Windows::Forms::Button());
			this->ButClearEverything = (gcnew System::Windows::Forms::Button());
			this->ButClear = (gcnew System::Windows::Forms::Button());
			this->ButTan = (gcnew System::Windows::Forms::Button());
			this->ButSin = (gcnew System::Windows::Forms::Button());
			this->richTextBoxMain = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBoxRes = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBoxSign = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// But0
			// 
			this->But0->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->But0->FlatAppearance->BorderSize = 0;
			this->But0->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->But0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->But0->Location = System::Drawing::Point(12, 489);
			this->But0->Name = L"But0";
			this->But0->Size = System::Drawing::Size(206, 60);
			this->But0->TabIndex = 0;
			this->But0->Text = L"0";
			this->But0->UseVisualStyleBackColor = true;
			this->But0->Click += gcnew System::EventHandler(this, &MainForm::ButPad_Click);
			// 
			// ButDot
			// 
			this->ButDot->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ButDot->FlatAppearance->BorderSize = 0;
			this->ButDot->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->ButDot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ButDot->Location = System::Drawing::Point(224, 489);
			this->ButDot->Name = L"ButDot";
			this->ButDot->Size = System::Drawing::Size(100, 60);
			this->ButDot->TabIndex = 0;
			this->ButDot->Text = L".";
			this->ButDot->UseVisualStyleBackColor = true;
			this->ButDot->Click += gcnew System::EventHandler(this, &MainForm::ButPad_Click);
			// 
			// ButGetRes
			// 
			this->ButGetRes->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ButGetRes->FlatAppearance->BorderSize = 0;
			this->ButGetRes->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->ButGetRes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ButGetRes->Location = System::Drawing::Point(330, 489);
			this->ButGetRes->Name = L"ButGetRes";
			this->ButGetRes->Size = System::Drawing::Size(100, 60);
			this->ButGetRes->TabIndex = 0;
			this->ButGetRes->Text = L"=";
			this->ButGetRes->UseVisualStyleBackColor = true;
			this->ButGetRes->Click += gcnew System::EventHandler(this, &MainForm::OperatorConverter_click);
			// 
			// But2
			// 
			this->But2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->But2->FlatAppearance->BorderSize = 0;
			this->But2->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->But2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->But2->Location = System::Drawing::Point(118, 423);
			this->But2->Name = L"But2";
			this->But2->Size = System::Drawing::Size(100, 60);
			this->But2->TabIndex = 0;
			this->But2->Text = L"2";
			this->But2->UseVisualStyleBackColor = true;
			this->But2->Click += gcnew System::EventHandler(this, &MainForm::ButPad_Click);
			// 
			// But3
			// 
			this->But3->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->But3->FlatAppearance->BorderSize = 0;
			this->But3->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->But3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->But3->Location = System::Drawing::Point(224, 423);
			this->But3->Name = L"But3";
			this->But3->Size = System::Drawing::Size(100, 60);
			this->But3->TabIndex = 0;
			this->But3->Text = L"3";
			this->But3->UseVisualStyleBackColor = true;
			this->But3->Click += gcnew System::EventHandler(this, &MainForm::ButPad_Click);
			// 
			// ButPlus
			// 
			this->ButPlus->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ButPlus->FlatAppearance->BorderSize = 0;
			this->ButPlus->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->ButPlus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ButPlus->Location = System::Drawing::Point(330, 423);
			this->ButPlus->Name = L"ButPlus";
			this->ButPlus->Size = System::Drawing::Size(100, 60);
			this->ButPlus->TabIndex = 0;
			this->ButPlus->Text = L"+";
			this->ButPlus->UseVisualStyleBackColor = true;
			this->ButPlus->Click += gcnew System::EventHandler(this, &MainForm::OperatorConverter_click);
			// 
			// But1
			// 
			this->But1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->But1->FlatAppearance->BorderSize = 0;
			this->But1->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->But1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->But1->Location = System::Drawing::Point(12, 423);
			this->But1->Name = L"But1";
			this->But1->Size = System::Drawing::Size(100, 60);
			this->But1->TabIndex = 0;
			this->But1->Text = L"1";
			this->But1->UseVisualStyleBackColor = true;
			this->But1->Click += gcnew System::EventHandler(this, &MainForm::ButPad_Click);
			// 
			// But5
			// 
			this->But5->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->But5->FlatAppearance->BorderSize = 0;
			this->But5->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->But5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->But5->Location = System::Drawing::Point(118, 357);
			this->But5->Name = L"But5";
			this->But5->Size = System::Drawing::Size(100, 60);
			this->But5->TabIndex = 0;
			this->But5->Text = L"5";
			this->But5->UseVisualStyleBackColor = true;
			this->But5->Click += gcnew System::EventHandler(this, &MainForm::ButPad_Click);
			// 
			// But6
			// 
			this->But6->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->But6->FlatAppearance->BorderSize = 0;
			this->But6->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->But6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->But6->Location = System::Drawing::Point(224, 357);
			this->But6->Name = L"But6";
			this->But6->Size = System::Drawing::Size(100, 60);
			this->But6->TabIndex = 0;
			this->But6->Text = L"6";
			this->But6->UseVisualStyleBackColor = true;
			this->But6->Click += gcnew System::EventHandler(this, &MainForm::ButPad_Click);
			// 
			// ButMinus
			// 
			this->ButMinus->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ButMinus->FlatAppearance->BorderSize = 0;
			this->ButMinus->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->ButMinus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ButMinus->Location = System::Drawing::Point(330, 357);
			this->ButMinus->Name = L"ButMinus";
			this->ButMinus->Size = System::Drawing::Size(100, 60);
			this->ButMinus->TabIndex = 0;
			this->ButMinus->Text = L"-";
			this->ButMinus->UseVisualStyleBackColor = true;
			this->ButMinus->Click += gcnew System::EventHandler(this, &MainForm::OperatorConverter_click);
			// 
			// But4
			// 
			this->But4->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->But4->FlatAppearance->BorderSize = 0;
			this->But4->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->But4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->But4->Location = System::Drawing::Point(12, 357);
			this->But4->Name = L"But4";
			this->But4->Size = System::Drawing::Size(100, 60);
			this->But4->TabIndex = 0;
			this->But4->Text = L"4";
			this->But4->UseVisualStyleBackColor = true;
			this->But4->Click += gcnew System::EventHandler(this, &MainForm::ButPad_Click);
			// 
			// But8
			// 
			this->But8->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->But8->FlatAppearance->BorderSize = 0;
			this->But8->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->But8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->But8->Location = System::Drawing::Point(118, 291);
			this->But8->Name = L"But8";
			this->But8->Size = System::Drawing::Size(100, 60);
			this->But8->TabIndex = 0;
			this->But8->Text = L"8";
			this->But8->UseVisualStyleBackColor = true;
			this->But8->Click += gcnew System::EventHandler(this, &MainForm::ButPad_Click);
			// 
			// But9
			// 
			this->But9->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->But9->FlatAppearance->BorderSize = 0;
			this->But9->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->But9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->But9->Location = System::Drawing::Point(224, 291);
			this->But9->Name = L"But9";
			this->But9->Size = System::Drawing::Size(100, 60);
			this->But9->TabIndex = 0;
			this->But9->Text = L"9";
			this->But9->UseVisualStyleBackColor = true;
			this->But9->Click += gcnew System::EventHandler(this, &MainForm::ButPad_Click);
			// 
			// ButMulti
			// 
			this->ButMulti->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ButMulti->FlatAppearance->BorderSize = 0;
			this->ButMulti->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->ButMulti->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ButMulti->Location = System::Drawing::Point(330, 291);
			this->ButMulti->Name = L"ButMulti";
			this->ButMulti->Size = System::Drawing::Size(100, 60);
			this->ButMulti->TabIndex = 0;
			this->ButMulti->Text = L"*";
			this->ButMulti->UseVisualStyleBackColor = true;
			this->ButMulti->Click += gcnew System::EventHandler(this, &MainForm::OperatorConverter_click);
			// 
			// But7
			// 
			this->But7->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->But7->FlatAppearance->BorderSize = 0;
			this->But7->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->But7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->But7->Location = System::Drawing::Point(12, 291);
			this->But7->Name = L"But7";
			this->But7->Size = System::Drawing::Size(100, 60);
			this->But7->TabIndex = 0;
			this->But7->Text = L"7";
			this->But7->UseVisualStyleBackColor = true;
			this->But7->Click += gcnew System::EventHandler(this, &MainForm::ButPad_Click);
			// 
			// ButSqr
			// 
			this->ButSqr->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ButSqr->FlatAppearance->BorderSize = 0;
			this->ButSqr->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->ButSqr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ButSqr->Location = System::Drawing::Point(12, 225);
			this->ButSqr->Name = L"ButSqr";
			this->ButSqr->Size = System::Drawing::Size(100, 60);
			this->ButSqr->TabIndex = 0;
			this->ButSqr->Text = L"sqr";
			this->ButSqr->UseVisualStyleBackColor = true;
			this->ButSqr->Click += gcnew System::EventHandler(this, &MainForm::OperatorConverter_click);
			// 
			// ButRoot
			// 
			this->ButRoot->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ButRoot->FlatAppearance->BorderSize = 0;
			this->ButRoot->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->ButRoot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ButRoot->Location = System::Drawing::Point(12, 159);
			this->ButRoot->Name = L"ButRoot";
			this->ButRoot->Size = System::Drawing::Size(100, 60);
			this->ButRoot->TabIndex = 0;
			this->ButRoot->Text = L"root";
			this->ButRoot->UseVisualStyleBackColor = true;
			this->ButRoot->Click += gcnew System::EventHandler(this, &MainForm::OperatorConverter_click);
			// 
			// ButDiv
			// 
			this->ButDiv->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ButDiv->FlatAppearance->BorderSize = 0;
			this->ButDiv->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->ButDiv->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ButDiv->Location = System::Drawing::Point(330, 225);
			this->ButDiv->Name = L"ButDiv";
			this->ButDiv->Size = System::Drawing::Size(100, 60);
			this->ButDiv->TabIndex = 0;
			this->ButDiv->Text = L"/";
			this->ButDiv->UseVisualStyleBackColor = true;
			this->ButDiv->Click += gcnew System::EventHandler(this, &MainForm::OperatorConverter_click);
			// 
			// ButCos
			// 
			this->ButCos->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ButCos->FlatAppearance->BorderSize = 0;
			this->ButCos->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->ButCos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ButCos->Location = System::Drawing::Point(118, 225);
			this->ButCos->Name = L"ButCos";
			this->ButCos->Size = System::Drawing::Size(100, 60);
			this->ButCos->TabIndex = 0;
			this->ButCos->Text = L"cos";
			this->ButCos->UseVisualStyleBackColor = true;
			this->ButCos->Click += gcnew System::EventHandler(this, &MainForm::OperatorConverter_click);
			// 
			// ButClearEverything
			// 
			this->ButClearEverything->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ButClearEverything->FlatAppearance->BorderSize = 0;
			this->ButClearEverything->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->ButClearEverything->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ButClearEverything->Location = System::Drawing::Point(224, 159);
			this->ButClearEverything->Name = L"ButClearEverything";
			this->ButClearEverything->Size = System::Drawing::Size(100, 60);
			this->ButClearEverything->TabIndex = 0;
			this->ButClearEverything->Text = L"CE";
			this->ButClearEverything->UseVisualStyleBackColor = true;
			this->ButClearEverything->Click += gcnew System::EventHandler(this, &MainForm::ButClearEverything_Click);
			// 
			// ButClear
			// 
			this->ButClear->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ButClear->FlatAppearance->BorderSize = 0;
			this->ButClear->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->ButClear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ButClear->Location = System::Drawing::Point(330, 159);
			this->ButClear->Name = L"ButClear";
			this->ButClear->Size = System::Drawing::Size(100, 60);
			this->ButClear->TabIndex = 0;
			this->ButClear->Text = L"C";
			this->ButClear->UseVisualStyleBackColor = true;
			this->ButClear->Click += gcnew System::EventHandler(this, &MainForm::ButClear_Click);
			// 
			// ButTan
			// 
			this->ButTan->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ButTan->FlatAppearance->BorderSize = 0;
			this->ButTan->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->ButTan->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ButTan->Location = System::Drawing::Point(118, 159);
			this->ButTan->Name = L"ButTan";
			this->ButTan->Size = System::Drawing::Size(100, 60);
			this->ButTan->TabIndex = 0;
			this->ButTan->Text = L"tan";
			this->ButTan->UseVisualStyleBackColor = true;
			this->ButTan->Click += gcnew System::EventHandler(this, &MainForm::OperatorConverter_click);
			// 
			// ButSin
			// 
			this->ButSin->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ButSin->FlatAppearance->BorderSize = 0;
			this->ButSin->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->ButSin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ButSin->Location = System::Drawing::Point(224, 225);
			this->ButSin->Name = L"ButSin";
			this->ButSin->Size = System::Drawing::Size(100, 60);
			this->ButSin->TabIndex = 0;
			this->ButSin->Text = L"sin";
			this->ButSin->UseVisualStyleBackColor = true;
			this->ButSin->Click += gcnew System::EventHandler(this, &MainForm::OperatorConverter_click);
			// 
			// richTextBoxMain
			// 
			this->richTextBoxMain->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->richTextBoxMain->Location = System::Drawing::Point(12, 12);
			this->richTextBoxMain->MaxLength = 19;
			this->richTextBoxMain->Multiline = false;
			this->richTextBoxMain->Name = L"richTextBoxMain";
			this->richTextBoxMain->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->richTextBoxMain->Size = System::Drawing::Size(418, 141);
			this->richTextBoxMain->TabIndex = 2;
			this->richTextBoxMain->Text = L"0";
			// 
			// richTextBoxRes
			// 
			this->richTextBoxRes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBoxRes->ForeColor = System::Drawing::SystemColors::GrayText;
			this->richTextBoxRes->Location = System::Drawing::Point(78, 113);
			this->richTextBoxRes->MaxLength = 19;
			this->richTextBoxRes->Multiline = false;
			this->richTextBoxRes->Name = L"richTextBoxRes";
			this->richTextBoxRes->ReadOnly = true;
			this->richTextBoxRes->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->richTextBoxRes->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->richTextBoxRes->Size = System::Drawing::Size(352, 40);
			this->richTextBoxRes->TabIndex = 3;
			this->richTextBoxRes->Text = L"0";
			// 
			// richTextBoxSign
			// 
			this->richTextBoxSign->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->richTextBoxSign->ForeColor = System::Drawing::SystemColors::GrayText;
			this->richTextBoxSign->Location = System::Drawing::Point(12, 113);
			this->richTextBoxSign->MaxLength = 4;
			this->richTextBoxSign->Multiline = false;
			this->richTextBoxSign->Name = L"richTextBoxSign";
			this->richTextBoxSign->ReadOnly = true;
			this->richTextBoxSign->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->richTextBoxSign->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->richTextBoxSign->Size = System::Drawing::Size(60, 40);
			this->richTextBoxSign->TabIndex = 4;
			this->richTextBoxSign->Text = L"";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(442, 561);
			this->Controls->Add(this->richTextBoxSign);
			this->Controls->Add(this->richTextBoxRes);
			this->Controls->Add(this->richTextBoxMain);
			this->Controls->Add(this->ButSin);
			this->Controls->Add(this->ButCos);
			this->Controls->Add(this->But7);
			this->Controls->Add(this->But4);
			this->Controls->Add(this->But1);
			this->Controls->Add(this->ButTan);
			this->Controls->Add(this->ButClear);
			this->Controls->Add(this->ButDiv);
			this->Controls->Add(this->ButRoot);
			this->Controls->Add(this->ButMulti);
			this->Controls->Add(this->But9);
			this->Controls->Add(this->ButMinus);
			this->Controls->Add(this->ButClearEverything);
			this->Controls->Add(this->But6);
			this->Controls->Add(this->ButSqr);
			this->Controls->Add(this->ButPlus);
			this->Controls->Add(this->But8);
			this->Controls->Add(this->But3);
			this->Controls->Add(this->But5);
			this->Controls->Add(this->ButGetRes);
			this->Controls->Add(this->But2);
			this->Controls->Add(this->ButDot);
			this->Controls->Add(this->But0);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Calculator";
			this->ResumeLayout(false);

		}
#pragma endregion

		bool is_operation_performed = false;
		bool first_operation = true;

		char* SystemStringToChar(System::String^ string) {
			return (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(string);
		}

		void perform(char mode) {
			char* str_main = SystemStringToChar(richTextBoxMain->Text);
			char* str_res = SystemStringToChar(richTextBoxRes->Text);
			double num_main, num_res, num = 0;
			bool flag = false;
			try {
				if (strlen(str_main) > 19 || strlen(str_res) > 19) throw 0; // Overflow
				if (!TextBoxCheck(str_main) || !TextBoxCheck(str_res)) throw 1; // Letters in TextBox
				else {
					num_main = atof(str_main);
					num_res = atof(str_res);
				}
				if (num_main == 0 && mode == '/') throw 2;
				if (num_main < 0 && mode == 'r') throw 3;
				num = Calculate(mode, num_main, num_res);
			}
			catch (int a) {
				switch (a)
				{
				case 0:
					richTextBoxMain->Text = "TextBox Overflow";
					break;
				case 1:
					richTextBoxMain->Text = "Wrong input";
					break;
				case 2:
					richTextBoxMain->Text = "Division by zero";
					break;
				case 3:
					richTextBoxMain->Text = "Imposible operation";
					break;
				default:
					break;
				}
				flag = true;
			}
			if (!flag) {
				richTextBoxRes->Text = Convert::ToString(num);
			}
			is_operation_performed = true;
		}

	private: System::Void ButPad_Click(System::Object^ sender, System::EventArgs^ e) {
		if (richTextBoxMain->Text == "0" || is_operation_performed) {
			richTextBoxMain->Clear();
		}
		is_operation_performed = false;
		Button^ button = (Button^)sender;
		if (richTextBoxMain->Text->Length < richTextBoxMain->MaxLength) {
			if (button->Text == ".") {
				if (!richTextBoxMain->Text->Contains(".")) {
					richTextBoxMain->Text = richTextBoxMain->Text + button->Text;
				}
			}
			else {
				richTextBoxMain->Text = richTextBoxMain->Text + button->Text;
			}
		}
	}

	private: System::Void ButClear_Click(System::Object^ sender, System::EventArgs^ e) {
		richTextBoxMain->Text = "0";
	}

	private: System::Void ButClearEverything_Click(System::Object^ sender, System::EventArgs^ e) {
		richTextBoxMain->Text = "0";
		richTextBoxRes->Text = "0";
		richTextBoxSign->Clear();
		first_operation = true;
	}

	private: System::Void OperatorConverter_click(System::Object^ sender, System::EventArgs^ e) {
		Button^ button = (Button^)sender;
		if (button->Text != "=") {
			richTextBoxSign->Text = button->Text;
			first_operation = false;
		}
		char* operator_mode = SystemStringToChar(button->Text);
		char mode;
		static char last_mode;
		if (strcmp(operator_mode, "sin") == 0) {
			mode = 's';
		}
		else if (strcmp(operator_mode, "cos") == 0) {
			mode = 'c';
		}
		else if (strcmp(operator_mode, "tan") == 0) {
			mode = 't';
		}
		else if (strcmp(operator_mode, "sqr") == 0) {
			mode = 'q';
		}
		else if (strcmp(operator_mode, "root") == 0) {
			mode = 'r';
		}
		else if (strcmp(operator_mode, "+") == 0) {
			mode = '+';
		}
		else if (strcmp(operator_mode, "-") == 0) {
			mode = '-';
		}
		else if (strcmp(operator_mode, "*") == 0) {
			mode = '*';
		}
		else if (strcmp(operator_mode, "/") == 0) {
			mode = '/';
		}
		else if (strcmp(operator_mode, "=") == 0) {
			if (first_operation) {
				richTextBoxRes->Text = richTextBoxMain->Text;
				is_operation_performed = true;
			}
			else {
				mode = last_mode;
			}
		}
		if (!first_operation) {
			last_mode = mode;
			perform(mode);
		}
	}

};
}
