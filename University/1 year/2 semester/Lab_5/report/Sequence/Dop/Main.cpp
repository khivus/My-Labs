//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Demofr.h"
#include "Main.h"
#include "about.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
     Application->HelpFile = "Help.hlp";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Exit1Click(TObject *Sender)
{
Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Image1Click(TObject *Sender)
{
Application->CreateForm(__classid(TDemoForm), &DemoForm);
DemoForm->flag=1;
DemoForm->ShowModal();
delete DemoForm;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Image2Click(TObject *Sender)
{
Application->CreateForm(__classid(TDemoForm), &DemoForm);
DemoForm->flag=2;
DemoForm->ShowModal();
delete DemoForm;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Image3Click(TObject *Sender)
{
Application->CreateForm(__classid(TDemoForm), &DemoForm);
DemoForm->flag=3;
DemoForm->ShowModal();
delete DemoForm;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Image4Click(TObject *Sender)
{
Application->CreateForm(__classid(TDemoForm), &DemoForm);
DemoForm->flag=4;
DemoForm->ShowModal();
delete DemoForm;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Image5Click(TObject *Sender)
{
Application->CreateForm(__classid(TDemoForm), &DemoForm);
DemoForm->flag=5;
DemoForm->ShowModal();
delete DemoForm;

}
//---------------------------------------------------------------------------


void __fastcall TMainForm::About1Click(TObject *Sender)
{
Application->CreateForm(__classid(TAboutBox), &AboutBox);
AboutBox->ShowModal();
delete AboutBox;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Context1Click(TObject *Sender)
{
  Application->HelpCommand(HELP_FINDER, 0);
}
//---------------------------------------------------------------------------

