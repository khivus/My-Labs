//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Demo.res");
USEFORM("Main.cpp", MainForm);
USEFORM("DemoFr.cpp", DemoForm);
USEFORM("About.cpp", AboutBox);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
