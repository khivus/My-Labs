#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

int main(array<String^>^ args) { // main link func
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    LevyCurve::MyForm form;
    Application::Run(% form);
	return 0;
}
