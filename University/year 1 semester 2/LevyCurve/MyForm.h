#pragma once
#include "DrawLevy.h"
#include "DataInput.h"
#include "Anime.h"
#include "AboutMe.h"
#include "DataIterations.h"

namespace LevyCurve {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form {

	private: DrawLevy^ draw;
	private: DataInput^ nInput;
	private: Anime^ animate;
	private: AboutMe^ abt;

	public:
		MyForm(void)
		{
			InitializeComponent();
			draw = gcnew DrawLevy;
			nInput = gcnew DataInput;
			animate = gcnew Anime;
			abt = gcnew AboutMe;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Draw;
	private: System::Windows::Forms::Button^ Animation;
	private: System::Windows::Forms::Button^ Input;
	private: System::Windows::Forms::Button^ About;
	private: System::Windows::Forms::Label^ lmao;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->Draw = (gcnew System::Windows::Forms::Button());
			this->Animation = (gcnew System::Windows::Forms::Button());
			this->Input = (gcnew System::Windows::Forms::Button());
			this->About = (gcnew System::Windows::Forms::Button());
			this->lmao = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Draw
			// 
			this->Draw->Enabled = true;
			this->Draw->Location = System::Drawing::Point(41, 489);
			this->Draw->Name = L"Draw";
			this->Draw->Size = System::Drawing::Size(120, 60);
			this->Draw->TabIndex = 0;
			this->Draw->Text = L"Draw curve";
			this->Draw->UseVisualStyleBackColor = true;
			this->Draw->Click += gcnew System::EventHandler(this, &MyForm::Draw_Click);
			// 
			// Animation
			// 
			this->Animation->Enabled = true;
			this->Animation->Location = System::Drawing::Point(167, 489);
			this->Animation->Name = L"Animation";
			this->Animation->Size = System::Drawing::Size(120, 60);
			this->Animation->TabIndex = 0;
			this->Animation->Text = L"Animation";
			this->Animation->UseVisualStyleBackColor = true;
			this->Animation->Click += gcnew System::EventHandler(this, &MyForm::Animation_Click);
			// 
			// Input
			// 
			this->Input->Location = System::Drawing::Point(293, 489);
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(120, 60);
			this->Input->TabIndex = 0;
			this->Input->Text = L"Iterations input";
			this->Input->UseVisualStyleBackColor = true;
			this->Input->Click += gcnew System::EventHandler(this, &MyForm::Input_Click);
			// 
			// About
			// 
			this->About->Location = System::Drawing::Point(422, 489);
			this->About->Name = L"About";
			this->About->Size = System::Drawing::Size(120, 60);
			this->About->TabIndex = 0;
			this->About->Text = L"About program";
			this->About->UseVisualStyleBackColor = true;
			this->About->Click += gcnew System::EventHandler(this, &MyForm::About_Click);
			// 
			// lmao
			// 
			this->lmao->AutoSize = true;
			this->lmao->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lmao->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->lmao->Location = System::Drawing::Point(537, 13);
			this->lmao->Name = L"lmao";
			this->lmao->Size = System::Drawing::Size(33, 13);
			this->lmao->TabIndex = 1;
			this->lmao->Text = L"Exit ^";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(584, 561);
			this->Controls->Add(this->lmao);
			this->Controls->Add(this->About);
			this->Controls->Add(this->Input);
			this->Controls->Add(this->Animation);
			this->Controls->Add(this->Draw);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(600, 600);
			this->MinimumSize = System::Drawing::Size(600, 600);
			this->Name = L"MyForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Levy Curve";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void Draw_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Animation_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Input_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void About_Click(System::Object^ sender, System::EventArgs^ e);
};
}