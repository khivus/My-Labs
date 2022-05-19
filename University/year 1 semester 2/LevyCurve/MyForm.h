#pragma once
#include "LevyForm.h"
#include "AboutMe.h"


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

	private: LevyForm^ lform;
	private: System::Windows::Forms::Button^ ToDrawButton;
	private: AboutMe^ abt;

	public:
		MyForm(void)
		{
			InitializeComponent();
			lform = gcnew LevyForm;
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

	private: System::Windows::Forms::Button^ About;

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
			this->About = (gcnew System::Windows::Forms::Button());
			this->ToDrawButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// About
			// 
			this->About->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->About->Location = System::Drawing::Point(307, 78);
			this->About->Name = L"About";
			this->About->Size = System::Drawing::Size(120, 60);
			this->About->TabIndex = 0;
			this->About->Text = L"About program";
			this->About->UseVisualStyleBackColor = true;
			this->About->Click += gcnew System::EventHandler(this, &MyForm::About_Click);
			// 
			// ToDrawButton
			// 
			this->ToDrawButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ToDrawButton->Location = System::Drawing::Point(307, 12);
			this->ToDrawButton->Name = L"ToDrawButton";
			this->ToDrawButton->Size = System::Drawing::Size(120, 60);
			this->ToDrawButton->TabIndex = 0;
			this->ToDrawButton->Text = L"Draw Levy";
			this->ToDrawButton->UseVisualStyleBackColor = true;
			this->ToDrawButton->Click += gcnew System::EventHandler(this, &MyForm::ToDrawButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(734, 411);
			this->Controls->Add(this->ToDrawButton);
			this->Controls->Add(this->About);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(750, 450);
			this->MinimumSize = System::Drawing::Size(750, 450);
			this->Name = L"MyForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Levy С Curve";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void About_Click(System::Object^ sender, System::EventArgs^ e) {
		abt->ShowDialog(); // transition between forms
}
private: System::Void ToDrawButton_Click(System::Object^ sender, System::EventArgs^ e) {
	lform->ShowDialog(); // transition between forms
}
};
}