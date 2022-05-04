#pragma once

namespace LevyCurve {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DrawLevy
	/// </summary>
	public ref class DrawLevy : public System::Windows::Forms::Form
	{
	public:
		DrawLevy(void)
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
		~DrawLevy()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ DrawButton;

	private: System::Windows::Forms::Button^ ExitButton;

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->DrawButton = (gcnew System::Windows::Forms::Button());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
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
			// DrawButton
			// 
			this->DrawButton->Location = System::Drawing::Point(327, 489);
			this->DrawButton->Name = L"DrawButton";
			this->DrawButton->Size = System::Drawing::Size(120, 60);
			this->DrawButton->TabIndex = 1;
			this->DrawButton->Text = L"Draw";
			this->DrawButton->UseVisualStyleBackColor = true;
			this->DrawButton->Click += gcnew System::EventHandler(this, &DrawLevy::button1_Click);
			// 
			// ExitButton
			// 
			this->ExitButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->ExitButton->Location = System::Drawing::Point(453, 489);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(120, 60);
			this->ExitButton->TabIndex = 1;
			this->ExitButton->Text = L"Main page";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &DrawLevy::button1_Click);
			// 
			// DrawLevy
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 561);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->DrawButton);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(600, 600);
			this->MinimumSize = System::Drawing::Size(600, 600);
			this->Name = L"DrawLevy";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Levy Curve";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		System::Void LevyCurve::DrawLevy::draw_levy(int iterations, float l, float a, float x, float y);
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
