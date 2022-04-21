//---------------------------------------------------------------------------

#ifndef DemoFrH
#define DemoFrH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TDemoForm : public TForm
{
__published:	// IDE-managed Components
 TImage *BackImage;
 TRichEdit *Ptext;
 TSpeedButton *NextBtn;
 TRichEdit *Comment;
 TSpeedButton *ExitBtn;
 TButton *ShowAll;
 TRichEdit *Rich;
 TSpeedButton *PrevBtn;
 TImage *WindowFr;
 TBevel *Frame;
 TLabel *Label3;
 TLabel *Label4;
        TSpeedButton *HelpBtn;
 void __fastcall NextBtnClick(TObject *Sender);
 void __fastcall ExitBtnClick(TObject *Sender);
 void __fastcall ShowAllClick(TObject *Sender);
 void __fastcall PrevBtnClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall HelpBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
 __fastcall TDemoForm(TComponent* Owner);
 void __fastcall Stack();
 void __fastcall Queue();
 void __fastcall DlList();
 void __fastcall SlList();
 void __fastcall Tree();
 int n;
 int flag;
};
//---------------------------------------------------------------------------
extern PACKAGE TDemoForm *DemoForm;
//---------------------------------------------------------------------------
#endif
