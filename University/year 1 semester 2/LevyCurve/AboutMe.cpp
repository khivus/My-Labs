#include "AboutMe.h"

System::Void LevyCurve::AboutMe::GoToSite_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::Diagnostics::Process::Start("site\\html\\main.html"); //go to developer site path
}
