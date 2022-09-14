// CppCalculator v0.1.0 2022 Aleksey Kharin
//
// I need to make list:
// * Backspace button
// * Signchange button
// * Other buttons (for now, idk need to do them)
// * Error handling (like div by 0)
// * Better multiplication

#pragma once

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
	private: System::Windows::Forms::Button^ ButSignChange;
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
	private: System::Windows::Forms::Button^ But1Divx;
	private: System::Windows::Forms::Button^ ButClearEverything;



	private: System::Windows::Forms::Button^ ButClear;

	private: System::Windows::Forms::Button^ ButBackspace;
	private: System::Windows::Forms::Button^ ButDivWithoutRemainder;




	private: System::Windows::Forms::MenuStrip^ menuStrip1;
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
			this->ButSignChange = (gcnew System::Windows::Forms::Button());
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
			this->But1Divx = (gcnew System::Windows::Forms::Button());
			this->ButClearEverything = (gcnew System::Windows::Forms::Button());
			this->ButClear = (gcnew System::Windows::Forms::Button());
			this->ButBackspace = (gcnew System::Windows::Forms::Button());
			this->ButDivWithoutRemainder = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
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
			this->But0->Location = System::Drawing::Point(118, 489);
			this->But0->Name = L"But0";
			this->But0->Size = System::Drawing::Size(100, 60);
			this->But0->TabIndex = 0;
			this->But0->Text = L"0";
			this->But0->UseVisualStyleBackColor = true;
			this->But0->Click += gcnew System::EventHandler(this, &MainForm::But0_Click);
			// 
			// ButSignChange
			// 
			this->ButSignChange->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ButSignChange->FlatAppearance->BorderSize = 0;
			this->ButSignChange->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->ButSignChange->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ButSignChange->Location = System::Drawing::Point(12, 489);
			this->ButSignChange->Name = L"ButSignChange";
			this->ButSignChange->Size = System::Drawing::Size(100, 60);
			this->ButSignChange->TabIndex = 0;
			this->ButSignChange->Text = L"+/-";
			this->ButSignChange->UseVisualStyleBackColor = true;
			this->ButSignChange->Click += gcnew System::EventHandler(this, &MainForm::ButSignChange_Click);
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
			this->ButDot->Click += gcnew System::EventHandler(this, &MainForm::ButDot_Click);
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
			this->ButGetRes->Click += gcnew System::EventHandler(this, &MainForm::ButGetRes_Click);
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
			this->But2->Click += gcnew System::EventHandler(this, &MainForm::But2_Click);
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
			this->But3->Click += gcnew System::EventHandler(this, &MainForm::But3_Click);
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
			this->ButPlus->Click += gcnew System::EventHandler(this, &MainForm::ButPlus_Click);
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
			this->But1->Click += gcnew System::EventHandler(this, &MainForm::But1_Click);
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
			this->But5->Click += gcnew System::EventHandler(this, &MainForm::But5_Click);
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
			this->But6->Click += gcnew System::EventHandler(this, &MainForm::But6_Click);
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
			this->ButMinus->Click += gcnew System::EventHandler(this, &MainForm::ButMinus_Click);
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
			this->But4->Click += gcnew System::EventHandler(this, &MainForm::But4_Click);
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
			this->But8->Click += gcnew System::EventHandler(this, &MainForm::But8_Click);
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
			this->But9->Click += gcnew System::EventHandler(this, &MainForm::But9_Click);
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
			this->ButMulti->Text = L"X";
			this->ButMulti->UseVisualStyleBackColor = true;
			this->ButMulti->Click += gcnew System::EventHandler(this, &MainForm::ButMulti_Click);
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
			this->But7->Click += gcnew System::EventHandler(this, &MainForm::But7_Click);
			// 
			// ButSqr
			// 
			this->ButSqr->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ButSqr->FlatAppearance->BorderSize = 0;
			this->ButSqr->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->ButSqr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ButSqr->Location = System::Drawing::Point(118, 225);
			this->ButSqr->Name = L"ButSqr";
			this->ButSqr->Size = System::Drawing::Size(100, 60);
			this->ButSqr->TabIndex = 0;
			this->ButSqr->Text = L"x^2";
			this->ButSqr->UseVisualStyleBackColor = true;
			// 
			// ButRoot
			// 
			this->ButRoot->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ButRoot->FlatAppearance->BorderSize = 0;
			this->ButRoot->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->ButRoot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ButRoot->Location = System::Drawing::Point(224, 225);
			this->ButRoot->Name = L"ButRoot";
			this->ButRoot->Size = System::Drawing::Size(100, 60);
			this->ButRoot->TabIndex = 0;
			this->ButRoot->Text = L"x^1/2";
			this->ButRoot->UseVisualStyleBackColor = true;
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
			this->ButDiv->Click += gcnew System::EventHandler(this, &MainForm::ButDiv_Click);
			// 
			// But1Divx
			// 
			this->But1Divx->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->But1Divx->FlatAppearance->BorderSize = 0;
			this->But1Divx->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->But1Divx->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->But1Divx->Location = System::Drawing::Point(12, 225);
			this->But1Divx->Name = L"But1Divx";
			this->But1Divx->Size = System::Drawing::Size(100, 60);
			this->But1Divx->TabIndex = 0;
			this->But1Divx->Text = L"1/x";
			this->But1Divx->UseVisualStyleBackColor = true;
			// 
			// ButClearEverything
			// 
			this->ButClearEverything->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ButClearEverything->FlatAppearance->BorderSize = 0;
			this->ButClearEverything->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->ButClearEverything->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ButClearEverything->Location = System::Drawing::Point(118, 159);
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
			this->ButClear->Location = System::Drawing::Point(224, 159);
			this->ButClear->Name = L"ButClear";
			this->ButClear->Size = System::Drawing::Size(100, 60);
			this->ButClear->TabIndex = 0;
			this->ButClear->Text = L"C";
			this->ButClear->UseVisualStyleBackColor = true;
			this->ButClear->Click += gcnew System::EventHandler(this, &MainForm::ButClear_Click);
			// 
			// ButBackspace
			// 
			this->ButBackspace->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ButBackspace->FlatAppearance->BorderSize = 0;
			this->ButBackspace->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->ButBackspace->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ButBackspace->Location = System::Drawing::Point(330, 159);
			this->ButBackspace->Name = L"ButBackspace";
			this->ButBackspace->Size = System::Drawing::Size(100, 60);
			this->ButBackspace->TabIndex = 0;
			this->ButBackspace->Text = L"<--";
			this->ButBackspace->UseVisualStyleBackColor = true;
			this->ButBackspace->Click += gcnew System::EventHandler(this, &MainForm::ButBackspace_Click);
			// 
			// ButDivWithoutRemainder
			// 
			this->ButDivWithoutRemainder->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ButDivWithoutRemainder->FlatAppearance->BorderSize = 0;
			this->ButDivWithoutRemainder->FlatAppearance->CheckedBackColor = System::Drawing::Color::Gray;
			this->ButDivWithoutRemainder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ButDivWithoutRemainder->Location = System::Drawing::Point(12, 159);
			this->ButDivWithoutRemainder->Name = L"ButDivWithoutRemainder";
			this->ButDivWithoutRemainder->Size = System::Drawing::Size(100, 60);
			this->ButDivWithoutRemainder->TabIndex = 0;
			this->ButDivWithoutRemainder->Text = L"%";
			this->ButDivWithoutRemainder->UseVisualStyleBackColor = true;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(442, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// richTextBoxMain
			// 
			this->richTextBoxMain->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->richTextBoxMain->Location = System::Drawing::Point(12, 27);
			this->richTextBoxMain->Name = L"richTextBoxMain";
			this->richTextBoxMain->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->richTextBoxMain->Size = System::Drawing::Size(418, 126);
			this->richTextBoxMain->TabIndex = 2;
			this->richTextBoxMain->Text = L"0";
			// 
			// richTextBoxRes
			// 
			this->richTextBoxRes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBoxRes->Location = System::Drawing::Point(12, 109);
			this->richTextBoxRes->Name = L"richTextBoxRes";
			this->richTextBoxRes->ReadOnly = true;
			this->richTextBoxRes->Size = System::Drawing::Size(261, 44);
			this->richTextBoxRes->TabIndex = 3;
			this->richTextBoxRes->Text = L"0";
			// 
			// richTextBoxSign
			// 
			this->richTextBoxSign->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->richTextBoxSign->Location = System::Drawing::Point(279, 109);
			this->richTextBoxSign->Name = L"richTextBoxSign";
			this->richTextBoxSign->Size = System::Drawing::Size(45, 44);
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
			this->Controls->Add(this->ButDivWithoutRemainder);
			this->Controls->Add(this->But1Divx);
			this->Controls->Add(this->But7);
			this->Controls->Add(this->But4);
			this->Controls->Add(this->But1);
			this->Controls->Add(this->ButSignChange);
			this->Controls->Add(this->ButBackspace);
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
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Calculator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		bool flag = false;
		bool dot = false;

private: System::Void But0_Click(System::Object^ sender, System::EventArgs^ e) {
	ClickPad(0);
}
private: System::Void But1_Click(System::Object^ sender, System::EventArgs^ e) {
	ClickPad(1);
}
private: System::Void But2_Click(System::Object^ sender, System::EventArgs^ e) {
	ClickPad(2);
}
private: System::Void But3_Click(System::Object^ sender, System::EventArgs^ e) {
	ClickPad(3);
}
private: System::Void But4_Click(System::Object^ sender, System::EventArgs^ e) {
	ClickPad(4);
}
private: System::Void But5_Click(System::Object^ sender, System::EventArgs^ e) {
	ClickPad(5);
}
private: System::Void But6_Click(System::Object^ sender, System::EventArgs^ e) {
	ClickPad(6);
}
private: System::Void But7_Click(System::Object^ sender, System::EventArgs^ e) {
	ClickPad(7);
}
private: System::Void But8_Click(System::Object^ sender, System::EventArgs^ e) {
	ClickPad(8);
}
private: System::Void But9_Click(System::Object^ sender, System::EventArgs^ e) {
	ClickPad(9);
}
private: System::Void ButClear_Click(System::Object^ sender, System::EventArgs^ e) {
	richTextBoxMain->Text = "0";
	dot = false;
}
private: System::Void ButClearEverything_Click(System::Object^ sender, System::EventArgs^ e) {
	richTextBoxMain->Text = "0";
	richTextBoxRes->Text = "0";
	richTextBoxSign->Text = "";
	dot = false;
}
private: System::Void ButDot_Click(System::Object^ sender, System::EventArgs^ e) {
	ClickPad(10);
}
private: System::Void ButSignChange_Click(System::Object^ sender, System::EventArgs^ e) {
	//will work at this later
}

private: System::Void ButBackspace_Click(System::Object^ sender, System::EventArgs^ e) {
	//richTextBoxMain->Text[richTextBoxMain->Text->Length - 1] = '';
	//also will work soon
	//just res_num - last digit
}
	   void ClickPad(int mode) {
		   if (flag) {
			   flag = false;
			   richTextBoxMain->Text = "";
		   }
		   if (richTextBoxMain->Text == "0" && mode != 10) {
			   richTextBoxMain->Text = Convert::ToString(mode);
		   }
		   else if (mode < 10 && mode > -1) {
			   richTextBoxMain->Text = richTextBoxMain->Text + mode;
		   }
		   else if (!dot){
			   richTextBoxMain->Text = richTextBoxMain->Text + ".";
			   dot = true;
		   }
	   }

	   void Calculate(int mode) {
		   double res_num = Convert::ToDouble(richTextBoxRes->Text);
		   double tmp_num = Convert::ToDouble(richTextBoxMain->Text);
		   static int last_sign;
		   double num;
		   switch (mode) {
		   case 1: // +
			   num = res_num + tmp_num;
			   richTextBoxSign->Text = "+";
			   break;
		   case 2: // -
			   num = res_num - tmp_num;
			   richTextBoxSign->Text = "-";
			   break;
		   case 3: // *
			   num = res_num * tmp_num;
			   richTextBoxSign->Text = "*";
			   break;
		   case 4: // /
			   num = res_num / tmp_num;
			   richTextBoxSign->Text = "/";
			   break;
		   case 5:
			   Calculate(last_sign);
			   break;
		   default:
			   break;
		   }
		   if (mode != 5) {
			   last_sign = mode;
			   richTextBoxRes->Text = Convert::ToString(num);
			   flag = true;
			   dot = false;
		   }
	   }

private: System::Void ButGetRes_Click(System::Object^ sender, System::EventArgs^ e) {
	Calculate(5);
}
private: System::Void ButPlus_Click(System::Object^ sender, System::EventArgs^ e) {
	Calculate(1);
}
private: System::Void ButMinus_Click(System::Object^ sender, System::EventArgs^ e) {
	Calculate(2);
}
private: System::Void ButMulti_Click(System::Object^ sender, System::EventArgs^ e) {
	Calculate(3);
}
private: System::Void ButDiv_Click(System::Object^ sender, System::EventArgs^ e) {
	Calculate(4);
}
};
}
