#pragma once

#include <math.h>

#define PI 3.1415

namespace LevyCurve {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainDraw
	/// </summary>
	public ref class LevyForm : public System::Windows::Forms::Form
	{

	public:
		LevyForm(void)
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
		~LevyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ToMainButton;
	protected:
	private: System::Windows::Forms::Button^ ResetButton;
	private: System::Windows::Forms::Button^ AnimateButton;
	private: System::Windows::Forms::Button^ FbfButton;
	private: System::Windows::Forms::Button^ DrawButton;
	private: System::Windows::Forms::NumericUpDown^ Iterations;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ IterationsLabel;
	private: System::Windows::Forms::PictureBox^ PictureBox;
	private: int counter = 0;
	private: System::Windows::Forms::Timer^ timer1;
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
			this->components = (gcnew System::ComponentModel::Container());
			this->ToMainButton = (gcnew System::Windows::Forms::Button());
			this->ResetButton = (gcnew System::Windows::Forms::Button());
			this->AnimateButton = (gcnew System::Windows::Forms::Button());
			this->FbfButton = (gcnew System::Windows::Forms::Button());
			this->DrawButton = (gcnew System::Windows::Forms::Button());
			this->Iterations = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->IterationsLabel = (gcnew System::Windows::Forms::Label());
			this->PictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Iterations))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// ToMainButton
			// 
			this->ToMainButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->ToMainButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ToMainButton->Location = System::Drawing::Point(602, 349);
			this->ToMainButton->Name = L"ToMainButton";
			this->ToMainButton->Size = System::Drawing::Size(120, 50);
			this->ToMainButton->TabIndex = 0;
			this->ToMainButton->Text = L"Main page";
			this->ToMainButton->UseVisualStyleBackColor = true;
			this->ToMainButton->Click += gcnew System::EventHandler(this, &LevyForm::ToMainButton_Click);
			// 
			// ResetButton
			// 
			this->ResetButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ResetButton->Location = System::Drawing::Point(602, 293);
			this->ResetButton->Name = L"ResetButton";
			this->ResetButton->Size = System::Drawing::Size(120, 50);
			this->ResetButton->TabIndex = 0;
			this->ResetButton->Text = L"Reset";
			this->ResetButton->UseVisualStyleBackColor = true;
			this->ResetButton->Click += gcnew System::EventHandler(this, &LevyForm::ResetButton_Click);
			// 
			// AnimateButton
			// 
			this->AnimateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AnimateButton->Location = System::Drawing::Point(602, 237);
			this->AnimateButton->Name = L"AnimateButton";
			this->AnimateButton->Size = System::Drawing::Size(120, 50);
			this->AnimateButton->TabIndex = 0;
			this->AnimateButton->Text = L"Animate";
			this->AnimateButton->UseVisualStyleBackColor = true;
			this->AnimateButton->Click += gcnew System::EventHandler(this, &LevyForm::AnimateButton_Click);
			// 
			// FbfButton
			// 
			this->FbfButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FbfButton->Location = System::Drawing::Point(602, 181);
			this->FbfButton->Name = L"FbfButton";
			this->FbfButton->Size = System::Drawing::Size(120, 50);
			this->FbfButton->TabIndex = 0;
			this->FbfButton->Text = L"Frame by frame";
			this->FbfButton->UseVisualStyleBackColor = true;
			this->FbfButton->Click += gcnew System::EventHandler(this, &LevyForm::FbfButton_Click);
			// 
			// DrawButton
			// 
			this->DrawButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DrawButton->Location = System::Drawing::Point(602, 125);
			this->DrawButton->Name = L"DrawButton";
			this->DrawButton->Size = System::Drawing::Size(120, 50);
			this->DrawButton->TabIndex = 0;
			this->DrawButton->Text = L"Draw";
			this->DrawButton->UseVisualStyleBackColor = true;
			this->DrawButton->Click += gcnew System::EventHandler(this, &LevyForm::DrawButton_Click);
			// 
			// Iterations
			// 
			this->Iterations->Location = System::Drawing::Point(602, 99);
			this->Iterations->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
			this->Iterations->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->Iterations->Name = L"Iterations";
			this->Iterations->Size = System::Drawing::Size(120, 20);
			this->Iterations->TabIndex = 1;
			this->Iterations->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(598, 72);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 24);
			this->label1->TabIndex = 2;
			this->label1->Text = L"1 - 15";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(597, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(95, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Iteration:";
			// 
			// IterationsLabel
			// 
			this->IterationsLabel->AutoSize = true;
			this->IterationsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->IterationsLabel->Location = System::Drawing::Point(698, 31);
			this->IterationsLabel->Name = L"IterationsLabel";
			this->IterationsLabel->Size = System::Drawing::Size(24, 25);
			this->IterationsLabel->TabIndex = 4;
			this->IterationsLabel->Text = L"0";
			// 
			// PictureBox
			// 
			this->PictureBox->Location = System::Drawing::Point(13, 13);
			this->PictureBox->Name = L"PictureBox";
			this->PictureBox->Size = System::Drawing::Size(583, 386);
			this->PictureBox->TabIndex = 5;
			this->PictureBox->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &LevyForm::timer1_Tick);
			// 
			// MainDraw
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(734, 411);
			this->Controls->Add(this->PictureBox);
			this->Controls->Add(this->IterationsLabel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Iterations);
			this->Controls->Add(this->DrawButton);
			this->Controls->Add(this->FbfButton);
			this->Controls->Add(this->AnimateButton);
			this->Controls->Add(this->ResetButton);
			this->Controls->Add(this->ToMainButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainDraw";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Draw Levy C Curve";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &LevyForm::LevyForm_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Iterations))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}

#pragma endregion

	private: System::Void draw_levy(float x, float y, float length, float alpha, int iteration) {
		Graphics^ gfx = PictureBox->CreateGraphics();
		float rads = 0;
		if (iteration > 0) {
			length = length / (float)sqrt(2);
			draw_levy(x, y, length, alpha + 45, iteration - 1);
			rads = rads + (float)((alpha + 45) * PI) / 180;
			x = x + length * (float)cos(rads);
			y = y + length * (float)sin(rads);
			draw_levy(x, y, length, alpha - 45, iteration - 1);
		}
		else {
			rads = rads + (float)(alpha * PI) / 180;
			gfx->DrawLine(Pens::Black, x, y, x + length * (float)cos(rads), y + length * (float)sin(rads));
		}
	}

	private: System::Void DrawButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ gfx = PictureBox->CreateGraphics();
		gfx->Clear(Color::White);
		if (counter == 0) {
			AnimateButton->Enabled = false;
			FbfButton->Enabled = false;
		}
		int iterations = Convert::ToInt32(Iterations->Value);
		IterationsLabel->Text = Convert::ToString(iterations);
		float x = (float)(PictureBox->Width / 3.6);
		float y = (float)(PictureBox->Height / 3.5);
		float length = 250;
		float alpha = 0;
		draw_levy(x, y, length, alpha, iterations);
	}

	private: System::Void FbfButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ gfx = PictureBox->CreateGraphics();
		gfx->Clear(Color::White);
		if (counter == 0) {
			DrawButton->Enabled = false;
			AnimateButton->Enabled = false;
		}
		if (counter == 20) {
			FbfButton->Enabled = false;
		}
		counter++;
		IterationsLabel->Text = Convert::ToString(counter);
		float x = (float)(PictureBox->Width / 3.6);
		float y = (float)(PictureBox->Height / 3.5);
		float length = 250;
		float alpha = 0;
		draw_levy(x, y, length, alpha, counter);
	}

	private: System::Void AnimateButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (timer1->Enabled == false) {
			timer1->Start();
		}
		else {
			timer1->Stop();
		}
		if (counter == 0) {
			DrawButton->Enabled = false;
			FbfButton->Enabled = false;
		}
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ gfx = PictureBox->CreateGraphics();
		gfx->Clear(Color::White);
		counter++;
		IterationsLabel->Text = Convert::ToString(counter);
		float x = (float)(PictureBox->Width / 3.6);
		float y = (float)(PictureBox->Height / 3.5);
		float length = 250;
		float alpha = 0;
		draw_levy(x, y, length, alpha, counter);
		if (counter >= Convert::ToInt32(Iterations->Value)) {
			counter = 0;
			timer1->Stop();
		}
	}

	private: System::Void Reset() {
		Graphics^ gfx = PictureBox->CreateGraphics();
		gfx->Clear(Color::White);
		timer1->Stop();
		IterationsLabel->Text = "0";
		counter = 0;
		AnimateButton->Enabled = true;
		FbfButton->Enabled = true;
		DrawButton->Enabled = true;
	}

	private: System::Void ResetButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Reset();
	}

	private: System::Void LevyForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		Reset();
	}

	private: System::Void ToMainButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Reset();
	}
	};
}
