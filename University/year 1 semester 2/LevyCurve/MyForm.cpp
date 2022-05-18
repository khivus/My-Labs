#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args) { // main link func
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    LevyCurve::MyForm form;
    Application::Run(% form);
}

// Functions that down for open and close other forms

System::Void LevyCurve::MyForm::Draw_Click(System::Object^ sender, System::EventArgs^ e) {
	draw->ShowDialog();
}

System::Void LevyCurve::MyForm::Animation_Click(System::Object^ sender, System::EventArgs^ e) {
	animate->ShowDialog();
}

System::Void LevyCurve::MyForm::Input_Click(System::Object^ sender, System::EventArgs^ e) {
	if (nInput->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		// Enable buttons that was unreached at start of program
		Draw->Enabled = true;
		Animation->Enabled = true;
		AttentionText->Visible = false;
	}
}

System::Void LevyCurve::MyForm::About_Click(System::Object^ sender, System::EventArgs^ e) {
	abt->ShowDialog();
}
