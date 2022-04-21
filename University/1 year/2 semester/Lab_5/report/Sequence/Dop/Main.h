//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Exit1;
        TMenuItem *Help1;
        TMenuItem *About1;
        TImageList *ImageList1;
        TMenuItem *Context1;
        TMenuItem *Demonstration1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N5;
        TImage *Image1;
        TImage *Image2;
        TImage *Image3;
        TImage *Image4;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TImage *Image5;
        TLabel *Label5;
        TLabel *Label6;
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall Image1Click(TObject *Sender);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Image3Click(TObject *Sender);
        void __fastcall Image4Click(TObject *Sender);
        void __fastcall Image5Click(TObject *Sender);
        void __fastcall About1Click(TObject *Sender);
        void __fastcall Context1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
