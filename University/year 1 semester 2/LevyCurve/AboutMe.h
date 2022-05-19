#pragma once

namespace LevyCurve {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AboutMe
	/// </summary>
	public ref class AboutMe : public System::Windows::Forms::Form
	{
	public:
		AboutMe(void)
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
		~AboutMe()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ExitButtonB;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ GoToSite;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutMe::typeid));
			this->ExitButtonB = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->GoToSite = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// ExitButtonB
			// 
			this->ExitButtonB->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->ExitButtonB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ExitButtonB->Location = System::Drawing::Point(452, 489);
			this->ExitButtonB->Name = L"ExitButtonB";
			this->ExitButtonB->Size = System::Drawing::Size(120, 60);
			this->ExitButtonB->TabIndex = 2;
			this->ExitButtonB->Text = L"Main page";
			this->ExitButtonB->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(508, 168);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Program: Levy C Curve\r\nRelease version: 1.10\r\nYear 2022\r\nDeveloped by Aleksey Kha"
				L"rin";
			// 
			// GoToSite
			// 
			this->GoToSite->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GoToSite->Location = System::Drawing::Point(326, 489);
			this->GoToSite->Name = L"GoToSite";
			this->GoToSite->Size = System::Drawing::Size(120, 60);
			this->GoToSite->TabIndex = 2;
			this->GoToSite->Text = L"Developer site";
			this->GoToSite->UseVisualStyleBackColor = true;
			this->GoToSite->Click += gcnew System::EventHandler(this, &AboutMe::GoToSite_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(279, 303);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(290, 180);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 230);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(543, 60);
			this->label2->TabIndex = 6;
			this->label2->Text = L"The fractal curve that is the limit of this \"infinite\" process is the Lévy C curv"
				L"e. \r\nIt takes its name from its resemblance to a highly \r\nornamented version of "
				L"the letter \"C\".";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(15, 203);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(321, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"the Lévy C curve is a self-similar fractal curve\r\n";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(15, 303);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(258, 180);
			this->label4->TabIndex = 6;
			this->label4->Text = resources->GetString(L"label4.Text");
			// 
			// AboutMe
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 561);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->GoToSite);
			this->Controls->Add(this->ExitButtonB);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(600, 600);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(600, 600);
			this->Name = L"AboutMe";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"About program";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void GoToSite_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Diagnostics::Process::Start("..\\site\\html\\main.html"); //go to developer site path
	}
	};
}
