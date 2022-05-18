#pragma once

namespace LevyCurve {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Anime
	/// </summary>
	public ref class Anime : public System::Windows::Forms::Form
	{

	public:
		Anime(void)
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
		~Anime()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:
	private: System::Windows::Forms::Button^ ExitButtonA;
	private: System::Windows::Forms::Button^ Animate;
	private: System::Windows::Forms::Button^ FrameUser;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ IterationNow;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	private: int counter = 0;
	private: System::Windows::Forms::Button^ ResetButton;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->ExitButtonA = (gcnew System::Windows::Forms::Button());
			this->Animate = (gcnew System::Windows::Forms::Button());
			this->FrameUser = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->IterationNow = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->ResetButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(560, 471);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// ExitButtonA
			// 
			this->ExitButtonA->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->ExitButtonA->Location = System::Drawing::Point(482, 489);
			this->ExitButtonA->Name = L"ExitButtonA";
			this->ExitButtonA->Size = System::Drawing::Size(90, 60);
			this->ExitButtonA->TabIndex = 1;
			this->ExitButtonA->Text = L"Main page";
			this->ExitButtonA->UseVisualStyleBackColor = true;
			this->ExitButtonA->Click += gcnew System::EventHandler(this, &Anime::ExitButtonA_Click);
			// 
			// Animate
			// 
			this->Animate->Location = System::Drawing::Point(290, 489);
			this->Animate->Name = L"Animate";
			this->Animate->Size = System::Drawing::Size(90, 60);
			this->Animate->TabIndex = 1;
			this->Animate->Text = L"Animate";
			this->Animate->UseVisualStyleBackColor = true;
			this->Animate->Click += gcnew System::EventHandler(this, &Anime::Animate_Click);
			// 
			// FrameUser
			// 
			this->FrameUser->Location = System::Drawing::Point(194, 489);
			this->FrameUser->Name = L"FrameUser";
			this->FrameUser->Size = System::Drawing::Size(90, 60);
			this->FrameUser->TabIndex = 1;
			this->FrameUser->Text = L"Frame by frame";
			this->FrameUser->UseVisualStyleBackColor = true;
			this->FrameUser->Click += gcnew System::EventHandler(this, &Anime::FrameUser_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 498);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(128, 31);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Iteration: ";
			// 
			// IterationNow
			// 
			this->IterationNow->AutoSize = true;
			this->IterationNow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->IterationNow->Location = System::Drawing::Point(146, 498);
			this->IterationNow->Name = L"IterationNow";
			this->IterationNow->Size = System::Drawing::Size(30, 31);
			this->IterationNow->TabIndex = 3;
			this->IterationNow->Text = L"0";
			// 
			// timer1
			// 
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &Anime::timer1_Tick);
			// 
			// ResetButton
			// 
			this->ResetButton->Location = System::Drawing::Point(386, 489);
			this->ResetButton->Name = L"ResetButton";
			this->ResetButton->Size = System::Drawing::Size(90, 60);
			this->ResetButton->TabIndex = 1;
			this->ResetButton->Text = L"Reset";
			this->ResetButton->UseVisualStyleBackColor = true;
			this->ResetButton->Click += gcnew System::EventHandler(this, &Anime::ResetButton_Click);
			// 
			// Anime
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 561);
			this->Controls->Add(this->IterationNow);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->FrameUser);
			this->Controls->Add(this->Animate);
			this->Controls->Add(this->ResetButton);
			this->Controls->Add(this->ExitButtonA);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(600, 600);
			this->MinimumSize = System::Drawing::Size(600, 600);
			this->Name = L"Anime";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Animetion";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Anime::Anime_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Anime::Anime_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		System::Void LevyCurve::Anime::animate_levy(float x, float y, float length, float alpha, int iteration);
	private: System::Void FrameUser_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Animate_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e);
private: System::Void ResetButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ExitButtonA_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Anime_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
};
}
