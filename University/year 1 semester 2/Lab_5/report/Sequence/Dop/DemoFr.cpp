//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DemoFr.h"
//#include "mainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDemoForm *DemoForm;
//---------------------------------------------------------------------------
__fastcall TDemoForm::TDemoForm(TComponent* Owner)
 : TForm(Owner)
{
n=0;

}
//---------------------------------------------------------------------------

void __fastcall TDemoForm::NextBtnClick(TObject *Sender)
{
if (n<1) PrevBtn->Visible=false;
 else    PrevBtn->Visible=true;
Ptext->SetFocus();
Ptext->SelectAll();
Ptext->SelAttributes->Style=TFontStyles();
Ptext->SelLength=0;
if (flag==1) Queue();
if (flag==2) Stack();
if (flag==3) SlList();
if (flag==4) DlList();
if (flag==5) Tree();
Ptext->SelAttributes->Style=TFontStyles()<< fsBold << fsUnderline;
Ptext->SelLength=0;
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::ExitBtnClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::Tree()
{
switch (n){
case 0:{
        Ptext->SetFocus();
        Ptext->Lines->LoadFromFile("bitree.cpp");
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add(" ��� ������� ��������� ����������\n������ � �������� �������.");
        Rich->Lines->Add(" ��� ������� ��������� ����������\n������ � �������� �������.");
        break;}
case 1:{
        WindowFr->Picture->LoadFromFile("tree\\tree1.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n1. �� ������� �������� �������� ����� ������:\n ������ - ������ ������� ������;\n ������� ������ - ������ �������;\n ��������� - ����� �������� ������;\n ������ - �������������� ����(��������).");
        Rich->Lines->Add("\n1. �� ������� �������� �������� ����� ������:\n ������ - ������ ������� ������;\n ������� ������ - ������ �������;\n ��������� - ����� �������� ������;\n ������ - �������������� ����(��������).");
        break;}
case 2:{
        WindowFr->Picture->LoadFromFile("tree\\tree2.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n2. ���� ������ �� ����������� ������ ���� �����������, �� � ����������� ������� ������������ ������ �����.\n ������������� ������ - ��� ������, � ������� ����� ��������� �������� �������, ������� ��� ������ �����, � ������ �������� �������, ������� �����.\n C��������� ��� ������ ������ ������:\n ������������ �����;\n ������ �����;\n ����� �����.\n �� ������� ������� c����������� ����� ������ (a b c d e f g).\n ��� ������������ ������ �������������� ������� ����� ���������, ����� ������, � ����� ������ ���������.");
        Rich->Lines->Add("\n2. ���� ������ �� ����������� ������ ���� �����������, �� � ����������� ������� ������������ ������ �����.\n ������������� ������ - ��� ������, � ������� ����� ��������� �������� �������, ������� ��� ������ �����, � ������ �������� �������, ������� �����.\n C��������� ��� ������ ������ ������:\n ������������ �����;\n ������ �����;\n ����� �����.\n �� ������� ������� c����������� ����� ������ (a b c d e f g).\n ��� ������������ ������ �������������� ������� ����� ���������, ����� ������, � ����� ������ ���������.");
        break;}
case 3:{
        WindowFr->Picture->LoadFromFile("tree\\tree3.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n3. �� ������� ������� ������ ����� ������ (d b a c f e g). ��� ������ ������ �������������� ������� ������, ����� ����� ���������, � ����� ������.");
        Rich->Lines->Add("\n3. �� ������� ������� ������ ����� ������ (d b a c f e g). ��� ������ ������ �������������� ������� ������, ����� ����� ���������, � ����� ������.");
        break;}
case 4:{
        WindowFr->Picture->LoadFromFile("tree\\tree4.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n4. �� ������� ������� ����� ����� (a c b e g f d). ��� ������ ����� �������������� ������� ����� ���������,����� ������ � ������� ������.");
        Rich->Lines->Add("\n4. �� ������� ������� ����� ����� (a c b e g f d). ��� ������ ����� �������������� ������� ����� ���������,����� ������ � ������� ������.");
        break;}
case 5:{
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add(" ���������� ��������� ������� ��� ������� ��� ������� ��������� ���������:  ���������� �������� � ������ � �������� �������� � ��� �������.");
        Rich->Lines->Add(" ���������� ��������� ������� ��� ������� ��� ������� ��������� ���������:  ���������� �������� � ������ � �������� �������� � ��� �������.");
        break;}
case 6:{
        Ptext->SelStart=43;
        Ptext->SelLength=78;
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n6. ���������� ��������� 'tree', � ������ ������� �������������� ����� � ���� ������� � ��� ���������: �� ����� � ������ ��������");
        Rich->Lines->Add("\n6. ���������� ��������� 'tree', � ������ ������� �������������� ����� � ���� ������� � ��� ���������: �� ����� � ������ ��������");
        break;}
case 7:{
        Ptext->SelStart=271;
        Ptext->SelLength=27;
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n7. ��������� ��������� �� ������ ������.");
        Rich->Lines->Add("\n7. ��������� ��������� �� ������ ������.");
        break;}
case 8:{
        Ptext->SelStart=298;
        Ptext->SelLength=34;
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n8. �������� ������� stree(root, root, 'd'), ������� ��������� ����� ������� � ������. ���������� ������� stree().");
        Rich->Lines->Add("\n8. �������� ������� stree(root, root, 'd'), ������� ��������� ����� ������� � ������. ���������� ������� stree().");
        break;}
case 9:{
        Ptext->SelStart=838;
        Ptext->SelLength=7;
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n9. ���� r ����� NULL (����� �� ���� ����� ���� ����� �������� �������) �����...");
        Rich->Lines->Add("\n9. ���� r ����� NULL (����� �� ���� ����� ���� ����� �������� �������) �����...");
        break;}
case 10:{
        Ptext->SelStart=844;
        Ptext->SelLength=110;
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n10. ����������� ������� � ������ ����������  NULL � info � ��� �������������� �����.");
        Rich->Lines->Add("\n10. ����������� ������� � ������ ����������  NULL � info � ��� �������������� �����.");
        break;}
case 11:{
        Ptext->SelStart=954;
        Ptext->SelLength=23;
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n11. ���� ��� ������ ������� � ������ (root=NULL), �� ������� r, �.� r - ����� ������ ������.");
        Rich->Lines->Add("\n11. ���� ��� ������ ������� � ������ (root=NULL), �� ������� r, �.� r - ����� ������ ������.");
        break;}
case 12:{
        Ptext->SelStart=977;
        Ptext->SelLength=79;
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n12. ��������� ���� ������� � ������ ������ (��� ���������) ����� ������� ����� ��� ���� ������������� � ���������� r.");
        Rich->Lines->Add("\n12. ��������� ���� ������� � ������ ������ (��� ���������) ����� ������� ����� ��� ���� ������������� � ���������� r.");
        break;}
case 13:{
        Ptext->SelStart=1063;
        Ptext->SelLength=85;
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n13. � ���� r �� ����� NULL  �� ����� ������������ �� ������ ����� ������� ����� ��� ���� �������������.");
        Rich->Lines->Add("\n13. � ���� r �� ����� NULL  �� ����� ������������ �� ������ ����� ������� ����� ��� ���� �������������.");
        break;}
case 14:{
        Ptext->SelStart=298;
        Ptext->SelLength=34;
        WindowFr->Picture->LoadFromFile("tree\\tree17.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n14. ��� ����� ������.");
        Rich->Lines->Add("\n14. ��� ����� ������.");
        break;}
case 15:{
        Ptext->SelStart=332;
        Ptext->SelLength=34;
        WindowFr->Picture->LoadFromFile("tree\\tree16.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n15. ��������� �������.");
        Rich->Lines->Add("\n15. ��������� �������.");
        break;}
case 16:{
        Ptext->SelStart=366;
        Ptext->SelLength=34;
        WindowFr->Picture->LoadFromFile("tree\\tree15.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n16. ��������� �������.");
        Rich->Lines->Add("\n16. ��������� �������.");
        break;}
case 17:{
        Ptext->SelStart=400;
        Ptext->SelLength=34;
        WindowFr->Picture->LoadFromFile("tree\\tree14.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n17. ��������� �������.");
        Rich->Lines->Add("\n17. ��������� �������.");
        break;}
case 18:{
        Ptext->SelStart=434;
        Ptext->SelLength=34;
        WindowFr->Picture->LoadFromFile("tree\\tree13.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n18. ��������� �������.");
        Rich->Lines->Add("\n18. ��������� �������.");
        break;}
case 19:{
        Ptext->SelStart=368;
        Ptext->SelLength=34;
        WindowFr->Picture->LoadFromFile("tree\\tree12.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n19. ��������� �������.");
        Rich->Lines->Add("\n19. ��������� �������.");
        break;}
case 20:{
        Ptext->SelStart=502;
        Ptext->SelLength=34;
        WindowFr->Picture->LoadFromFile("tree\\tree5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n20. ��������� �������.");
        Rich->Lines->Add("\n20. ��������� �������.");
        break;}
case 21:{
        Ptext->SelStart=536;
        Ptext->SelLength=28;
        WindowFr->Picture->LoadFromFile("tree\\tree5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n21. �������� ������� dtree(root, 'b'), ������� ������� �������, ��������� ��� ����� � ������. ���������� ������� dteee().");
        Rich->Lines->Add("\n21. �������� ������� dtree(root, 'b'), ������� ������� �������, ��������� ��� ����� � ������. ���������� ������� dteee().");
        break;}
case 22:{
        Ptext->SelStart=1220;
        Ptext->SelLength=23;
        WindowFr->Picture->LoadFromFile("tree\\tree5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n22. ��������� 2 ��������� p � p2.");
        Rich->Lines->Add("\n22. ��������� 2 ��������� p � p2.");
        break;}
case 23:{
        Ptext->SelStart=1243;
        Ptext->SelLength=26;
        WindowFr->Picture->LoadFromFile("tree\\tree5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n23. ���� ������ �� ���������� ��� ������� �� ������, �� �����.");
        Rich->Lines->Add("\n23. ���� ������ �� ���������� ��� ������� �� ������, �� �����.");
        break;}
case 24:{
        Ptext->SelStart=1269;
        Ptext->SelLength=23;
        WindowFr->Picture->LoadFromFile("tree\\tree5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n24. ���� ������� ������, �� ...");
        Rich->Lines->Add("\n24. ���� ������� ������, �� ...");
        break;}
case 25:{
        Ptext->SelStart=1296;
        Ptext->SelLength=70;
        WindowFr->Picture->LoadFromFile("tree\\tree5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n25. ���� ������ � ����� NULL, �� ������� ��� ������� � ���������� NULL.");
        Rich->Lines->Add("\n25. ���� ������ � ����� NULL, �� ������� ��� ������� � ���������� NULL.");
        break;}
case 26:{
        Ptext->SelStart=1366;
        Ptext->SelLength=86;
        WindowFr->Picture->LoadFromFile("tree\\tree5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n26. ���� ����� NULL, �� ������� ��� ������� � ���������� ��������� �� ������.");
        Rich->Lines->Add("\n26. ���� ������ � ����� NULL, �� ������� ��� ������� � ���������� NULL.");
        break;}
case 27:{
        Ptext->SelStart=1366;
        Ptext->SelLength=86;
        WindowFr->Picture->LoadFromFile("tree\\tree5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n27. ���� ������ NULL, �� ������� ��� ������� � ���������� ��������� �� ����� �������.");
        Rich->Lines->Add("\n27. ���� ������ NULL, �� ������� ��� ������� � ���������� ��������� �� ����� �������.");
        break;}
case 28:{
        Ptext->SelStart=1538;
        Ptext->SelLength=141;
        WindowFr->Picture->LoadFromFile("tree\\tree5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n28. ���� ����� � ������ �� NULL, �� �� ������� ��������� ������� ����� ����� ��������� ������ (��� �� �� ��������� ��������������� � ������) � ����������� ����� �������� ����� ����� ��������� ��������, ������� ������� � ���������� ��������� �� ��� ������ �����, ����������� � ��������� p2.");
        Rich->Lines->Add("\n28. ���� ����� � ������ �� NULL, �� �� ������� ��������� ������� ����� ����� ��������� ������ (��� �� �� ��������� ��������������� � ������) � ����������� ����� �������� ����� ����� ��������� ��������, ������� ������� � ���������� ��������� �� ��� ������ �����, ����������� � ��������� p2.");
        break;}
case 29:{
        Ptext->SelStart=1684;
        Ptext->SelLength=124;
        WindowFr->Picture->LoadFromFile("tree\\tree5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n29. ���� ������� �� ������, �� ������������ �� ������.");
        Rich->Lines->Add("\n29. ���� ������� �� ������, �� ������������ �� ������.");
        break;}
case 30:{
        Ptext->SelStart=536;
        Ptext->SelLength=28;
        WindowFr->Picture->LoadFromFile("tree\\tree6.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n30. ������� ������� b.");
        Rich->Lines->Add("\n30. ������� ������� b.");
        break;}
case 31:{
        Ptext->SelStart=564;
        Ptext->SelLength=28;
        WindowFr->Picture->LoadFromFile("tree\\tree7.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n31. ������� ������ ������ d.");
        Rich->Lines->Add("\n31. ������� ������ ������ d.");
        break;}
case 32:{
        Ptext->SelStart=592;
        Ptext->SelLength=28;
        WindowFr->Picture->LoadFromFile("tree\\tree8.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n32. ������� ������� �.");
        Rich->Lines->Add("\n32. ������� ������� �.");
        break;}
case 33:{
        Ptext->SelStart=620;
        Ptext->SelLength=28;
        WindowFr->Picture->LoadFromFile("tree\\tree9.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n33. ������� ������� �.");
        Rich->Lines->Add("\n33. ������� ������� �.");
        break;}
case 34:{
        Ptext->SelStart=648;
        Ptext->SelLength=28;
        WindowFr->Picture->LoadFromFile("tree\\tree10.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n34. ������� ������� �.");
        Rich->Lines->Add("\n34. ������� ������� �.");
        break;}
case 35:{
        Ptext->SelStart=676;
        Ptext->SelLength=28;
        WindowFr->Picture->LoadFromFile("tree\\tree11.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n35. ������� ������� f.");
        Rich->Lines->Add("\n35. ������� ������� f.");
        break;}
case 36:{
        Ptext->SelStart=704;
        Ptext->SelLength=28;
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n36. ������� ������� g.");
        Rich->Lines->Add("\n36. ������� ������� g.");
        break;}
case 37:{
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n37. ��� � ���.");
        Rich->Lines->Add("\n37. ��� � ���.");
        if (Application->MessageBoxA("������� ���������� ��� ���?","",MB_ICONQUESTION|MB_YESNO)==IDNO) Close();
        n=-1;
        break;}

  }
n++;
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::SlList()
{
switch (n){
case 0:{
        Ptext->SetFocus();
        Ptext->Lines->LoadFromFile("sllist.cpp");
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add(" ��� ������� ��������� ����������\n������ � ����������� ������� ");
        Rich->Lines->Add(" ��� ������� ��������� ����������\n������ � ����������� ������� ");
        break;}
case 1:{
        Ptext->SelStart=86;
        Ptext->SelLength=37;
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n1. ���������� ��������� 'list', � ������ ������� �������������� ����� � ���� ����� � ��������� �� ��������� �������");
        Rich->Lines->Add("\n1. ���������� ��������� 'list', � ������ ������� �������������� ����� � ���� ����� � ��������� �� ��������� �������");
        break;}
case 2:{
        Ptext->SelStart=274;
        Ptext->SelLength=49;
        WindowFr->Picture->LoadFromFile("sllist\\sllist1.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n2. ��������� ��� ��������� �� ����. ������. ��� �� ������ (start) � �� ������� ������� (i).");
        Rich->Lines->Add("\n2. ��������� ��� ��������� �� ����. ������. ��� �� ������ (start) � �� ������� ������� (i).");
        break;}
case 3:{
        Ptext->SelStart=337;
        Ptext->SelLength=21;
        WindowFr->Picture->LoadFromFile("sllist\\sllist1.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n3. �������� ������� add(&i,&start,12), ������� ��������� ����� ������� � ������. ���������� ������� add().");
        Rich->Lines->Add("\n3. �������� ������� add(&i,&start,12), ������� ��������� ����� ������� � ������. ���������� ������� add().");
        break;}
case 4:{
        Ptext->SelStart=721;
        Ptext->SelLength=78;
        WindowFr->Picture->LoadFromFile("sllist\\sllist2.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n4. ��������� ��������� �� ����� �������. �������� ��� ���� ������ � ����������� ��� �������������� ����� ����� ���������� � �������.");
        Rich->Lines->Add("\n4. ��������� ��������� �� ����� �������. �������� ��� ���� ������ � ����������� ��� �������������� ����� ����� ���������� � �������.");
        break;}
case 5:{
        Ptext->SelStart=799;
        Ptext->SelLength=15;
        WindowFr->Picture->LoadFromFile("sllist\\sllist2.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n5. ���� ��� ������� ������� � ������ (start ����� NULL), �� ...");
        Rich->Lines->Add("\n5. ���� ��� ������� ������� � ������ (start ����� NULL), �� ...");
        break;}
case 6:{
        Ptext->SelStart=819;
        Ptext->SelLength=44;
        WindowFr->Picture->LoadFromFile("sllist\\sllist3.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n6. start ����� new_node � �������� ��� �� ���� ((*start)->next=*start)");
        Rich->Lines->Add("\n6. start ����� new_node � �������� ��� �� ���� ((*start)->next=*start)");
        break;}
case 7:{
        Ptext->SelStart=937;
        Ptext->SelLength=14;
        WindowFr->Picture->LoadFromFile("sllist\\sllist4.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n7. ��������� �� ������� ������� ����� ��������� �� ����� �������.");
        Rich->Lines->Add("\n7. ��������� �� ������� ������� ����� ��������� �� ����� �������.");
        break;}
case 8:{
        Ptext->SelStart=358;
        Ptext->SelLength=21;
        WindowFr->Picture->LoadFromFile("sllist\\sllist4.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n8. �������� ������� add(&i,&start,13), ������� ��������� ����� ������� � ������.");
        Rich->Lines->Add("\n8. �������� ������� add(&i,&start,13), ������� ��������� ����� ������� � ������.");
        break;}
case 9:{
        Ptext->SelStart=799;
        Ptext->SelLength=15;
        WindowFr->Picture->LoadFromFile("sllist\\sllist5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n9. �.� � ������ ��� ���� ��������, �� ...");
        Rich->Lines->Add("\n9. �.� � ������ ��� ���� ��������, �� ...");
        break;}
case 10:{
        Ptext->SelStart=880;
        Ptext->SelLength=52;
        WindowFr->Picture->LoadFromFile("sllist\\sllist6.jpg");
        Comment->Lines->Clear();
//        Comment->Lines->Add("\n10. �.� � ������ ��� ���� ��������, �� ...");
//        Rich->Lines->Add("\n9. �.� � ������ ��� ���� ��������, �� ...");
        break;}
case 11:{
        Ptext->SelStart=937;
        WindowFr->Picture->LoadFromFile("sllist\\sllist7.jpg");
        Ptext->SelLength=14;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n7. ��������� �� ������� ������� ����� ��������� �� ����� �������.");
        Rich->Lines->Add("\n7. ��������� �� ������� ������� ����� ��������� �� ����� �������.");
        break;}
case 12:{
        Ptext->SelStart=379;
        WindowFr->Picture->LoadFromFile("sllist\\sllist8.jpg");
        Ptext->SelLength=42;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n12. ��������� ��� ��� �������� 14 � 15.");
        Rich->Lines->Add("\n7. ��������� �� ������� ������� ����� ��������� �� ����� �������.");
        break;}
case 13:{
        Ptext->SelStart=421;
        Ptext->SelLength=23;
        WindowFr->Picture->LoadFromFile("sllist\\sllist8.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n13. �������� ������� del(&i,&start,&error) - ������� i-�� �������. ���������� ������� del");
        Rich->Lines->Add("\n13.  �������� ������� del(&i,&start,&error) - ������� i-�� �������. ���������� ������� del");
        break;}
case 14:{
        Ptext->SelStart=1027;
        Ptext->SelLength=25;
        WindowFr->Picture->LoadFromFile("sllist\\sllist8.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n14. ��������� ��������� �� ���������� ������� (����� �������� ����� �������� �������)");
        Rich->Lines->Add("\n14. ��������� ��������� �� ���������� ������� (����� �������� ����� �������� �������)");
        break;}
case 15:{
        Ptext->SelStart=1052;
        Ptext->SelLength=20;
        WindowFr->Picture->LoadFromFile("sllist\\sllist8.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n15. ���� ������ �� ���������� (start ����� NULL), �� ������ (error=1).");
        Rich->Lines->Add("\n15. ���� ������ �� ���������� (start ����� NULL), �� ������ (error=1).");
        break;}
case 16:{
        Ptext->SelStart=1093;
        Ptext->SelLength=38;
        WindowFr->Picture->LoadFromFile("sllist\\sllist8.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n16. ����� ����� ���� ��� ������ ���� �� ������� ��������� ������� � ������ ��� �� ���������.");
        Rich->Lines->Add("\n16. ����� ����� ���� ��� ������ ���� �� ������� ��������� ������� � ������ ��� �� ���������.");
        break;}
case 17:{
        Ptext->SelStart=1226;
        Ptext->SelLength=57;
        WindowFr->Picture->LoadFromFile("sllist\\sllist9.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n17. ��������� �� ������ �� ������ �� ����, ���� ��������� �� ����� ��������� �� i-�� �������.");
        Rich->Lines->Add("\n17. ��������� �� ������ �� ������ �� ����, ���� ��������� �� ����� ��������� �� i-�� �������.");
        break;}
case 18:{
        Ptext->SelStart=1283;
        Ptext->SelLength=32;
        WindowFr->Picture->LoadFromFile("sllist\\sllist10.jpg");
        Comment->Lines->Clear();
     //   Comment->Lines->Add("\n17. ��������� �� ������ �� ������ �� ����, ���� ��������� �� ����� ��������� �� i-�� �������.");
     //   Rich->Lines->Add("\n17. ��������� �� ������ �� ������ �� ����, ���� ��������� �� ����� ��������� �� i-�� �������.");
        break;}
case 19:{
        Ptext->SelStart=1315;
        Ptext->SelLength=15;
        WindowFr->Picture->LoadFromFile("sllist\\sllist11.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n19. ������� ������ �� ��������� i.");
        Rich->Lines->Add("\n19. ������� ������ �� ��������� i.");
        break;}
case 20:{
        Ptext->SelStart=1330;
        Ptext->SelLength=36;
        WindowFr->Picture->LoadFromFile("sllist\\sllist11.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n20. ���� �� ������� ������ ������, �� ���������� ��� �� previous.");
        Rich->Lines->Add("\n20. ���� �� ������� ������ ������, �� ���������� ��� �� previous.");
        break;}
case 21:{
        Ptext->SelStart=1368;
        Ptext->SelLength=33;
        WindowFr->Picture->LoadFromFile("sllist\\sllist12.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n21. ���������� ��������� i �� previous. �������� ��� ������ ��� (error=0).");
        Rich->Lines->Add("\n21. ���������� ��������� i �� previous. �������� ��� ������ ��� (error=0).");
        break;}
case 22:{
        Ptext->SelStart=446;
        Ptext->SelLength=34;
        WindowFr->Picture->LoadFromFile("sllist\\sllist13.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n22. ���������� ��������� i ������ (�� start) � ��������� ����� �������.");
        Rich->Lines->Add("\n22. ���������� ��������� i ������ (�� start) � ��������� ����� �������.");
        break;}
case 23:{
        Ptext->SelStart=480;
        Ptext->SelLength=25;
        WindowFr->Picture->LoadFromFile("sllist\\sllist14.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n23. ������� ����������� �������.");
        Rich->Lines->Add("\n23. ������� ����������� �������.");
        break;}
case 24:{
        Ptext->SelStart=505;
        Ptext->SelLength=21;
        WindowFr->Picture->LoadFromFile("sllist\\sllist15.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n24. ��������� ��� ���� �������.");
        Rich->Lines->Add("\n24. ��������� ��� ���� �������.");
        break;}
case 25:{
        Ptext->SelStart=526;
        Ptext->SelLength=38;
        Comment->Lines->Clear();
        WindowFr->Picture->LoadFromFile("sllist\\sllist16.jpg");
        Comment->Lines->Add("\n25. ���������� ��������� i ������ � ������� �������.");
        Rich->Lines->Add("\n25. ���������� ��������� i ������ � ������� �������.");
        break;}
case 26:{
        Ptext->SelStart=564;
        Ptext->SelLength=38;
        WindowFr->Picture->LoadFromFile("sllist\\sllist17.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n26. ���������� ��������� i ������ � ������� �������.");
        Rich->Lines->Add("\n26. ���������� ��������� i ������ � ������� �������.");
        break;}
case 27:{
        Ptext->SelStart=602;
        Ptext->SelLength=25;
        WindowFr->Picture->LoadFromFile("sllist\\sllist18.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n27. ������� �������.");
        Rich->Lines->Add("\n27. ������� �������.");
        break;}
case 28:{
        Ptext->SelStart=627;
        Ptext->SelLength=25;
        WindowFr->Picture->LoadFromFile("sllist\\sllist18.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n28. ������� ��������� ���������� �������.");
        Rich->Lines->Add("\n28. ������� ��������� ���������� �������.");
        break;}
case 29:{
        Ptext->SelStart=1138;
        Ptext->SelLength=65;
        WindowFr->Picture->LoadFromFile("sllist\\sllist19.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n29. ������� ������ �� ��������� start, � ����������� ���������� start � i �������� NULL.");
        Rich->Lines->Add("\n29. ������� ��������� ���������� �������.");
        break;}
case 30:{
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n30. ��� � ���.");
        Rich->Lines->Add("\n30. ��� � ���.");
        if (Application->MessageBoxA("������� ���������� ��� ���?","",MB_ICONQUESTION|MB_YESNO)==IDNO) Close();
        n=-1;
        break;}



 }
n++;
}
void __fastcall TDemoForm::DlList()
{
switch (n){
case 0:{
        Ptext->SetFocus();
        Ptext->Lines->LoadFromFile("dllist.cpp");
        Comment->Lines->Clear();
        Comment->Lines->Add(" ��� ������� ��������� ����������\n������ � ����������� �������");
        Rich->Lines->Add(" ��� ������� ��������� ����������\n������ � ���������� �������");
        break;}
case 1:{
        Ptext->SelStart=86;
        Ptext->SelLength=51;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n1. ���������� ��������� 'list', � ������ ������� �������������� ����� � ���� ����� � ��� ���������: �� ��������� � �� ���������� ��������");
        Rich->Lines->Add("\n1. ���������� ��������� 'list', � ������ ������� �������������� ����� � ���� ����� � ��� ���������: �� ��������� � �� ���������� ��������");
        break;}
case 2:{
        Ptext->SelStart=334;
        Ptext->SelLength=55;
        Comment->Lines->Clear();
        WindowFr->Picture->LoadFromFile("dllist\\dllist1.jpg");
        Comment->Lines->Add("\n2. ��������� 3 ��������� �� ��������� list:\n i - i-�� ������� (�������)\n start - ��������� �� ������ ������\n last - ��������� �� ����� ������");
        Rich->Lines->Add("\n2. ��������� 3 ��������� �� ��������� list:\n i - i-�� ������� (�������)\n start - ��������� �� ������ ������\n last - ��������� �� ����� ������");
        break;}
case 3:{
        Ptext->SelStart=416;
        Ptext->SelLength=27;
        Comment->Lines->Clear();
        WindowFr->Picture->LoadFromFile("dllist\\dllist1.jpg");
        Comment->Lines->Add("\n3. �������� ������� add(&i,&start,&last,12), ������� ��������� ����� ������� � ������. ���������� ������� add().");
        Rich->Lines->Add("\n3. �������� ������� add(&i,&start,&last,12), ������� ��������� ����� ������� � ������. ���������� ������� add().");
        break;}
case 4:{
        Ptext->SelStart=769;
        Ptext->SelLength=84;
        WindowFr->Picture->LoadFromFile("dllist\\dllist1.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n4. � ������� void add(LIST **i,LIST **start,LIST **last,int n) ����� �������� 4 ���������:\n - ��������� �� ������� �������\n - ��������� �� ������ ������\n - ��������� �� ����� ������\n  - � ����� ���� int.");
        Rich->Lines->Add("\n4. � ������� void add(LIST **i,LIST **start,LIST **last,int n) ����� �������� 4 ���������:\n - ��������� �� ������� �������\n - ��������� �� ������ ������\n - ��������� �� ����� ������\n  - � ����� ���� int.");
        break;}
case 5:{
        Ptext->SelStart=856;
        Ptext->SelLength=16;
        WindowFr->Picture->LoadFromFile("dllist\\dllist1.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n5. ��������� ��������� �� ����� ������.");
        Rich->Lines->Add("\n5. ��������� ��������� �� ����� ������.");
        break;}
case 6:{
        Ptext->SelStart=874;
        Ptext->SelLength=60;
        WindowFr->Picture->LoadFromFile("dllist\\dllist2.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n6. �������� ������ ��� ����� ������� � ����������� ��� �������������� ����� ����� ���������� � �������.");
        Rich->Lines->Add("\n6. �������� ������ ��� ����� ������� � ����������� ��� �������������� ����� ����� ���������� � �������.");
        break;}
case 7:{
        Ptext->SelStart=934;
        Ptext->SelLength=18;
        WindowFr->Picture->LoadFromFile("dllist\\dllist2.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n7. ���� ������ ��� (start ����� NULL), �� ...");
        Rich->Lines->Add("\n7. ���� ������ ��� (start ����� NULL), �� ...");
        break;}
case 8:{
        Ptext->SelStart=959;
        Ptext->SelLength=98;
        WindowFr->Picture->LoadFromFile("dllist\\dllist3.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n8. ��������� start � last ����� ��������� �� ����� �������, �.� ��� ������ ������� � � ���� ��� �� ���������� �� �����������, �� �� ����������� � NULL. � i-�� ������� ����� ��������� �� �����.");
        Rich->Lines->Add("\n8. ��������� start � last ����� ��������� �� ����� �������, �.� ��� ������ ������� � � ���� ��� �� ���������� �� �����������, �� �� ����������� � NULL. � i-�� ������� ����� ��������� �� �����.");
        break;}
case 9:{
        Ptext->SelStart=1062;
        Ptext->SelLength=24;
        WindowFr->Picture->LoadFromFile("dllist\\dllist3.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n9. �.� ������ (*i)->next ����� NULL, �� ������� �����������.");
        Rich->Lines->Add("\n9. �.� ������ (*i)->next ����� NULL, �� ������� �����������.");
        break;}
case 10:{
        Ptext->SelStart=443;
        Ptext->SelLength=26;
        WindowFr->Picture->LoadFromFile("dllist\\dllist3.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n10. ��������� ����� ������� � ������ 13, ����� i-���.");
        Rich->Lines->Add("\n10. ��������� ����� ������� � ������ 13, ����� i-���.");
        break;}
case 11:{
        Ptext->SelStart=934;
        Ptext->SelLength=18;
        WindowFr->Picture->LoadFromFile("dllist\\dllist24.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n11. �.� start �� ����� NULL, �� ���� ������.");
        Rich->Lines->Add("\n11. �.� start �� ����� NULL, �� ���� ������.");
        break;}
case 12:{
        Ptext->SelStart=1062;
        Ptext->SelLength=24;
        WindowFr->Picture->LoadFromFile("dllist\\dllist24.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n12. ������ (*i)->next ����� NULL, ������������� ��������� �������� � ����� ������.");
        Rich->Lines->Add("\n12. ������ (*i)->next ����� NULL, ������������� ��������� �������� � ����� ������.");
        break;}
case 13:{
        Ptext->SelStart=1214;
        Ptext->SelLength=23;
        WindowFr->Picture->LoadFromFile("dllist\\dllist4.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n13. ��������� �� ��������� ������� ����� ������ ����������� � ������ ��������.");
        Rich->Lines->Add("\n13. ��������� �� ��������� ������� ����� ������ ����������� � ������ ��������.");
        break;}
case 14:{
        Ptext->SelStart=1239;
        Ptext->SelLength=49;
        WindowFr->Picture->LoadFromFile("dllist\\dllist5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n14. ��������� �� ���������� ������� �������� �������� ����������� � ���������� ��-�� ������, � ��������� NULL.");
        Rich->Lines->Add("\n14. ��������� �� ���������� ������� �������� �������� ����������� � ���������� ��-�� ������, � ��������� NULL.");
        break;}
case 15:{
        Ptext->SelStart=1288;
        Ptext->SelLength=37;
        WindowFr->Picture->LoadFromFile("dllist\\dllist6.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n15. ��������� ����� ������ � i-�� ������� (����������� �� � ������ ��������).");
        Rich->Lines->Add("\n15. ��������� ����� ������ � i-�� ������� (����������� �� � ������ ��������).");
        break;}
case 16:{
        Ptext->SelStart=470;
        Ptext->SelLength=57;
        WindowFr->Picture->LoadFromFile("dllist\\dllist7.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n16. ���������� ��������� ��� ��� �������� (i ����� last).");
        Rich->Lines->Add("\n16. ���������� ��������� ��� ��� �������� (i ����� last).");
        break;}
case 17:{
        Ptext->SelStart=527;
        Ptext->SelLength=31;
        WindowFr->Picture->LoadFromFile("dllist\\dllist7.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n17. ��������� ��� ���� ������� � ������ ������.");
        Rich->Lines->Add("\n17. ��������� ��� ���� ������� � ������ ������.");
        break;}
case 18:{
        Ptext->SelStart=1062;
        Ptext->SelLength=24;
        WindowFr->Picture->LoadFromFile("dllist\\dllist8.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n18. ������ (*i)->next �� ����� NULL, ������������� ��������� �������� � �������� ������.");
        Rich->Lines->Add("\n18. ������ (*i)->next �� ����� NULL, ������������� ��������� �������� � �������� ������.");
        break;}
case 19:{
        Ptext->SelStart=1091;
        Ptext->SelLength=29;
        WindowFr->Picture->LoadFromFile("dllist\\dllist9.jpg");
        Comment->Lines->Clear();
//        Comment->Lines->Add("\n19. ������ (*i)->next �� ����� NULL, ������������� ��������� �������� � �������� ������.");
//        Rich->Lines->Add("\n19. ������ (*i)->next �� ����� NULL, ������������� ��������� �������� � �������� ������.");
        break;}
case 20:{
        Ptext->SelStart=1120;
        Ptext->SelLength=29;
        WindowFr->Picture->LoadFromFile("dllist\\dllist10.jpg");
        Comment->Lines->Clear();
//        Comment->Lines->Add("\n19. ������ (*i)->next �� ����� NULL, ������������� ��������� �������� � �������� ������.");
//        Rich->Lines->Add("\n19. ������ (*i)->next �� ����� NULL, ������������� ��������� �������� � �������� ������.");
        break;}
case 21:{
        Ptext->SelStart=1149;
        Ptext->SelLength=21;
        WindowFr->Picture->LoadFromFile("dllist\\dllist11.jpg");
        Comment->Lines->Clear();
//        Comment->Lines->Add("\n19. ������ (*i)->next �� ����� NULL, ������������� ��������� �������� � �������� ������.");
//        Rich->Lines->Add("\n19. ������ (*i)->next �� ����� NULL, ������������� ��������� �������� � �������� ������.");
        break;}
case 22:{
        Ptext->SelStart=1170;
        Ptext->SelLength=23;
        WindowFr->Picture->LoadFromFile("dllist\\dllist12.jpg");
        Comment->Lines->Clear();
//        Comment->Lines->Add("\n19. ������ (*i)->next �� ����� NULL, ������������� ��������� �������� � �������� ������.");
//        Rich->Lines->Add("\n19. ������ (*i)->next �� ����� NULL, ������������� ��������� �������� � �������� ������.");
        break;}
case 23:{
        Ptext->SelStart=558;
        Ptext->SelLength=34;
        WindowFr->Picture->LoadFromFile("dllist\\dllist12.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n23. �������� �������  del(&last,&start,&last,&error), ������� ������� ������� �� �������. ���������� ������� del.");
        Rich->Lines->Add("\n23. �������� �������  del(&last,&start,&last,&error), ������� ������� ������� �� �������. ���������� ������� del.");
        break;}
case 24:{
        Ptext->SelStart=1336;
        Ptext->SelLength=89;
        WindowFr->Picture->LoadFromFile("dllist\\dllist12.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n24. � ������� void del(LIST **i,LIST **start,LIST **last,int *error) ����� �������� 4 ���������:\n - ��������� �� ��������� �������\n - ��������� �� ������ ������\n - ��������� �� ����� ������\n  - � ��������� �� int ��� ������������ ������.");
        Rich->Lines->Add("\n24. � ������� void del(LIST **i,LIST **start,LIST **last,int *error) ����� �������� 4 ���������:\n - ��������� �� ��������� �������\n - ��������� �� ������ ������\n - ��������� �� ����� ������\n  - � ��������� �� int ��� ������������ ������.");
        break;}
case 25:{
        Ptext->SelStart=1429;
        Ptext->SelLength=18;
        WindowFr->Picture->LoadFromFile("dllist\\dllist12.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n25. ��������� ��������� �� ��������� �������.");
        Rich->Lines->Add("\n25. ��������� ��������� �� ��������� �������.");
        break;}
case 26:{
        Ptext->SelStart=1449;
        Ptext->SelLength=59;
        WindowFr->Picture->LoadFromFile("dllist\\dllist12.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n26. ���� ���� �� ���� �� ����������, ���������� � �������, ����� NULL, �� error=1 (�������� �� ������). ����� ���������� 3 ��������: �������� ������� ��-��, �������� �� �������� ������ � �������� � ����� ������.");
        Rich->Lines->Add("\n26. ���� ���� �� ���� �� ����������, ���������� � �������, ����� NULL, �� error=1 (�������� �� ������). ����� ���������� 3 ��������: �������� ������� ��-��, �������� �� �������� ������ � �������� � ����� ������.");
        break;}
case 27:{
        Ptext->SelStart=1618;
        Ptext->SelLength=18;
        WindowFr->Picture->LoadFromFile("dllist\\dllist12.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n27. �.� ������ i ����� last, �� ������� ��������� �������.");
        Rich->Lines->Add("\n27. �.� ������ i ����� last, �� ������� ��������� �������.");
        break;}
case 28:{
        Ptext->SelStart=1642;
        Ptext->SelLength=53;
        WindowFr->Picture->LoadFromFile("dllist\\dllist13.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n28. �.� i �� ����� start,�� ������ ��� i->prev �� ����� NULL, ������������� ����� ��� �������� �������� ������� (i-��) ������� �����. ����� �������� ����� � ��������� �� ��������� �������. � ����������� ������, ������, ��� ��������� ������� ���������� ����� NULL");
        Rich->Lines->Add("\n28. �.� i �� ����� start,�� ������ ��� i->prev �� ����� NULL, ������������� ����� ��� �������� �������� ������� (i-��) ������� �����. ����� �������� ����� � ��������� �� ��������� �������. � ����������� ������, ������, ��� ��������� ������� ���������� ����� NULL");
        break;}
case 29:{
        Ptext->SelStart=1805;
        Ptext->SelLength=30;
        Comment->Lines->Clear();
        WindowFr->Picture->LoadFromFile("dllist\\dllist14.jpg");
        Comment->Lines->Add("\n29. ����������� ���������� error 0, ������ � ��� ,��� ������ ��� � ����������� ������ �� ��������� old_node");
        Rich->Lines->Add("\n29. ����������� ���������� error 0, ������ � ��� ,��� ������ ��� � ����������� ������ �� ��������� old_node");
        break;}
case 30:{
        Ptext->SelStart=592;
        Ptext->SelLength=35;
        WindowFr->Picture->LoadFromFile("dllist\\dllist14.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n30. ������� ������ �������");
        Rich->Lines->Add("\n30. ������� ������ �������");
        break;}
case 31:{
        Ptext->SelStart=1520;
        Ptext->SelLength=18;
        Comment->Lines->Clear();
        WindowFr->Picture->LoadFromFile("dllist\\dllist15.jpg");
        Comment->Lines->Add("\n31. �.� ������ i ����� start, �� ������� ������ �������.");
        Rich->Lines->Add("\n31. �.� ������ i ����� start, �� ������� ������ �������.");
        break;}
case 32:{
        Ptext->SelStart=1543;
        Ptext->SelLength=34;
        WindowFr->Picture->LoadFromFile("dllist\\dllist16.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n32. �������� �������� start � i ������ �� ���� �������.");
        Rich->Lines->Add("\n32. �������� �������� start � i ������ �� ���� �������.");
        break;}
case 33:{
        Ptext->SelStart=1577;
        Ptext->SelLength=29;
        WindowFr->Picture->LoadFromFile("dllist\\dllist17.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n33. ���� ��� �� ��������� ������� � ������, �� ���������� ������ ���� ����� NULL.");
        Rich->Lines->Add("\n33. ���� ��� �� ��������� ������� � ������, �� ���������� ������ ���� ����� NULL.");
        break;}
case 34:{
        Ptext->SelStart=1805;
        Ptext->SelLength=30;
        WindowFr->Picture->LoadFromFile("dllist\\dllist18.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n34. ����������� ���������� error 0, ������ � ��� ,��� ������ ��� � ����������� ������ �� ��������� old_node");
        Rich->Lines->Add("\n34. ����������� ���������� error 0, ������ � ��� ,��� ������ ��� � ����������� ������ �� ��������� old_node");
        break;}
case 35:{
        Ptext->SelStart=627;
        Ptext->SelLength=42;
        WindowFr->Picture->LoadFromFile("dllist\\dllist19.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n35. �������� ��������� �� ������� ������� �� ���� ������� ����� � ������� ���.");
        Rich->Lines->Add("\n35. �������� ��������� �� ������� ������� �� ���� ������� ����� � ������� ���.");
        break;}
case 36:{
        Ptext->SelStart=1715;
        Ptext->SelLength=32;
        WindowFr->Picture->LoadFromFile("dllist\\dllist20.jpg");
        Comment->Lines->Clear();
    //    Comment->Lines->Add("\n35. �������� ��������� �� ������� ������� �� ���� ������� ����� � ������� ���.");
    //    Rich->Lines->Add("\n35. �������� ��������� �� ������� ������� �� ���� ������� ����� � ������� ���.");
        break;}
case 37:{
        Ptext->SelStart=1747;
        Ptext->SelLength=52;
        WindowFr->Picture->LoadFromFile("dllist\\dllist21.jpg");
        Comment->Lines->Clear();
    //    Comment->Lines->Add("\n35. �������� ��������� �� ������� ������� �� ���� ������� ����� � ������� ���.");
    //    Rich->Lines->Add("\n35. �������� ��������� �� ������� ������� �� ���� ������� ����� � ������� ���.");
        break;}
case 38:{
        Ptext->SelStart=1805;
        Ptext->SelLength=30;
        WindowFr->Picture->LoadFromFile("dllist\\dllist22.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n38. ����������� ���������� error 0, ������ � ��� ,��� ������ ��� � ����������� ������ �� ��������� old_node");
        Rich->Lines->Add("\n38. ����������� ���������� error 0, ������ � ��� ,��� ������ ��� � ����������� ������ �� ��������� old_node");
        break;}
case 39:{
        Ptext->SelStart=671;
        Ptext->SelLength=62;
        WindowFr->Picture->LoadFromFile("dllist\\dllist23.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n39. ������� ���������� ��� ��� �������");
        Rich->Lines->Add("\n39. ������� ���������� ��� ��� �������");
        break;}
case 40:{
        Ptext->SelStart=733;
        Ptext->SelLength=31;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n40. ��� �������� ��������������� �������� (i ����� NULL) ���������� error ����� ����� �������.");
        Rich->Lines->Add("\n40. ��� �������� ��������������� �������� (i ����� NULL) ���������� error ����� ����� �������.");
        break;}
case 41:{
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n41. ��� � ���.");
        Rich->Lines->Add("\n41. ��� � ���.");
        if (Application->MessageBoxA("������� ���������� ��� ���?","",MB_ICONQUESTION|MB_YESNO)==IDNO) Close();
        n=-1;
        break;}

 }
n++;

}
void __fastcall TDemoForm::Stack()
{
switch (n){
case 0:{
        Ptext->SetFocus();
        Ptext->Lines->LoadFromFile("Stack.cpp");
        Comment->Lines->Clear();
        Comment->Lines->Add(" ��� ������� ��������� ����������\n������ �� ������");
        Comment->Lines->Add("\n1. � ������ ������� �������� ������������ ����� \"alloc.h\"-��� ����� � ������� � \"stdio.h\"-��� ������ ���������� �� �����");
        Rich->Lines->Add(" ��� ������� ��������� ����������\n������ �� ������");
        Rich->Lines->Add("\n1. � ������ ������� �������� ������������ ����� \"alloc.h\"-��� ����� � ������� � \"stdio.h\"-��� ������ ���������� �� �����");
        Ptext->SelStart=0;
        Ptext->SelLength=40;
        break;}
case 1:{
        Ptext->SelStart=40;
        Ptext->SelLength=26;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n2. ����� ����� �� ������ ������ ��� � ������ 'struct stack' ���������, ��� ������ STACK ���������� ������ �������� 'struct stack'");
        Rich->Lines->Add("\n2. ����� ����� �� ������ ������ ��� � ������ 'struct stack' ���������, ��� ������ STACK ���������� ������ �������� 'struct stack'");
        break;}
case 2:{
        Ptext->SelStart=68;
        Ptext->SelLength=43;
        Rich->Lines->Add("\n3. ��������� ��������� 'stack' � ������� ������� ���������� info ���� int, � ������� ����� ������� �����-�� �����, � ��������� �� �������� ������� ����� 'struct stack *next'");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n3. ��������� ��������� 'stack' � ������� ������� ���������� info ���� int, � ������� ����� ������� �����-�� �����, � ��������� �� �������� ������� ����� 'struct stack *next'");
        break;}
case 3:{

        Ptext->SelStart=111;
        Ptext->SelLength=105;
        Rich->Lines->Add("\n4. ��������� 3 �������:\n void push (STACK **s, int item); \n      - '���������' ������� � ���� \n int pop (STACK **s, int *error); \n       - '����������' ������� �� ����� \n int peek (STACK *s, int *error); \n       - ����� ������ ��� ��������");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n4. ��������� 3 �������:\n void push (STACK **s, int item); \n     - '���������' ������� � ���� \n int pop (STACK **s, int *error); \n       - '����������' ������� �� ����� \n int peek (STACK *s, int *error); \n       - ����� ������ ��� ��������");
        break;}
case 4:{
        Ptext->SelStart=737;
        Ptext->SelLength=11;
        WindowFr->Picture=NULL;
        Rich->Lines->Add("\n5. ���������� ������� ������� - ������� main");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n5. ���������� ������� ������� - ������� main");
        break;}
case 5:{
        Ptext->SelStart=754;
        Ptext->SelLength=18;
        WindowFr->Picture->LoadFromFile("stack\\stack1.jpg");
        Rich->Lines->Add("\n6. ��������� ��� �����: s1 � s2");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n6. ��������� ��� �����: s1 � s2");
        break;}
case 6:{
        Ptext->SelStart=772;
        Ptext->SelLength=14;
        WindowFr->Picture->LoadFromFile("stack\\stack2.jpg");
        Rich->Lines->Add("\n7. ��������� ���������� 'error' ���� int");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n7. ��������� ���������� 'error' ���� int");
        break;}
case 7:{
        Ptext->SelStart=786;
        Ptext->SelLength=19;
        WindowFr->Picture->LoadFromFile("stack\\stack2.jpg");
        Rich->Lines->Add("\n8. �������� ������� 'void push(&s1,12)' - ��������� � ���� s1 �������� 12 ...\n ���� '&' ���������� �.� �� ����� �������� �������� ��������� s1");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n8. �������� ������� 'void push(&s1,12)' - ��������� � ���� s1 �������� 12 ...\n ���� '&' ���������� �.� �� ����� �������� �������� ��������� s1");
        break;}
case 8:{
        Ptext->SelStart=256;
        Ptext->SelLength=19;
        WindowFr->Picture->LoadFromFile("stack\\stack2.jpg");
        Rich->Lines->Add("\n9. ��������� ��������� �� ��������� 'stack' ");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n9. ��������� ��������� �� ��������� 'stack'");
        break;}
case 9:{
        Ptext->SelStart=278;
        Ptext->SelLength=44;
        WindowFr->Picture->LoadFromFile("stack\\stack2.jpg");
        Rich->Lines->Add("\n10. �������� ������ ��� ����� �������");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n10. �������� ������ ��� ����� �������");
        break;}
case 10:{
        Ptext->SelStart=324;
        Ptext->SelLength=21;
        WindowFr->Picture->LoadFromFile("stack\\stack3.jpg");
        Rich->Lines->Add("\n11. ����������� �������������� ����� ������ �������� ��������, ������ �� �������� ������� (� ���� ������ 12)");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n11. ����������� �������������� ����� ������ �������� ��������, ������ �� �������� ������� (� ���� ������ 12)");
        break;}
case 11:{
        Ptext->SelStart=349;
        Ptext->SelLength=19;
        WindowFr->Picture->LoadFromFile("stack\\stack4.jpg");
        Rich->Lines->Add("\n12. ��������� ����� ������� �� ������, ����� ������� ��� � ������ �����");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n12. ��������� ����� ������� �� ������, ����� ������� ��� � ������ �����");
        break;}
case 12:{
        Ptext->SelStart=372;
        Ptext->SelLength=13;
        WindowFr->Picture->LoadFromFile("stack\\stack5.jpg");
        Rich->Lines->Add("\n13. ������ ��������� 's' ������ �� ��������� �� ����� ������ �����");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n13. ������ ��������� 's' ������ �� ��������� �� ����� ������ �����");
        break;}
case 13:{
        Ptext->SelStart=807;
        Ptext->SelLength=48;
        WindowFr->Picture->LoadFromFile("stack\\stack6.jpg");
        Rich->Lines->Add("\n14. �������� ������� ������� 'peek' ������� ���������� �������� 'info' �� �������� ���������, ���� �� �� NULL, � ���� NULL, �� ��������� 0 � error=1;");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n14. �������� ������� ������� 'peek' ������� ���������� �������� 'info' �� �������� ���������, ���� �� �� NULL, � ���� NULL, �� ��������� 0 � error=1;");
        break;}
case 14:{
        Ptext->SelStart=859;
        Ptext->SelLength=14;
        WindowFr->Picture->LoadFromFile("stack\\stack6.jpg");
        Rich->Lines->Add("\n15. �������� ������� 'void push(&s1,13)' - ��������� � ���� s1 �������� 13 ...\n ���� '&' ���������� �.� �� ����� �������� �������� ��������� s1");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n15. �������� ������� 'void push(&s1,13)' - ��������� � ���� s1 �������� 13 ...\n ���� '&' ���������� �.� �� ����� �������� �������� ��������� s1");
        break;}
case 15:{
        Ptext->SelStart=930;
        Ptext->SelLength=15;
        WindowFr->Picture->LoadFromFile("stack\\stack7.jpg");
        Rich->Lines->Add("\n16. �������� ������� 'void push(&s1,14)' - ��������� � ���� s1 �������� 14 ...\n ���� '&' ���������� �.� �� ����� �������� �������� ��������� s1");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n16. �������� ������� 'void push(&s1,14)' - ��������� � ���� s1 �������� 14 ...\n ���� '&' ���������� �.� �� ����� �������� �������� ��������� s1");
        break;}
case 16:{
        Ptext->SelStart=1004;
        Ptext->SelLength=30;
        WindowFr->Picture->LoadFromFile("stack\\stack8.jpg");
        Rich->Lines->Add("\n17. ���������� � ���� �2 �������� �� 1-�� �����, ������ ��� �������� �� 1-�� �����\n���������� ������� pop()");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n17. ���������� � ���� �2 �������� �� 1-�� �����, ������ ��� �������� �� 1-�� �����\n���������� ������� pop()");
        break;}
case 17:{
        Ptext->SelStart=430;
        Ptext->SelLength=20;
        WindowFr->Picture->LoadFromFile("stack\\stack8.jpg");
        Rich->Lines->Add("\n18. ��������� ��������� �� ��������� 'stack' ");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n18. ��������� ��������� �� ��������� 'stack'");
        break;}
case 18:{
        Ptext->SelStart=454;
        Ptext->SelLength=17;
        WindowFr->Picture->LoadFromFile("stack\\stack8.jpg");
        Rich->Lines->Add("\n19. ��������� ���������� ���� int ��� �������� ��������");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n19. ��������� ���������� ���� int ��� �������� ��������");
        break;}
case 19:{
        Ptext->SelStart=473;
        Ptext->SelLength=37;
        WindowFr->Picture->LoadFromFile("stack\\stack8.jpg");
        Rich->Lines->Add("\n20. ���� s �� NULL, ����� old_info ,����� ������ �������������� ����� ��������, �� ������� ��������� s (� ���� ������ 14)");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n20. ���� s �� NULL, ����� old_info ,����� ������ �������������� ����� ��������, �� ������� ��������� s (� ���� ������ 14)");
        break;}
case 20:{
        Ptext->SelStart=513;
        Ptext->SelLength=45;
        WindowFr->Picture->LoadFromFile("stack\\stack8.jpg");
        Rich->Lines->Add("\n21. ���� s �� NULL, ����� s ����� ��������� �� ��������� �������\n ������� free ��������� ������ �� ��������� old_item � return ������ �������� old_info");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n21. ���� s �� NULL, ����� s ����� ��������� �� ��������� �������\n ������� free ��������� ������ �� ��������� old_item � return ������ �������� old_info");
        break;}
case 21:{
        Ptext->SelStart=564;
        Ptext->SelLength=19;
        WindowFr->Picture->LoadFromFile("stack\\stack9.jpg");
        Rich->Lines->Add("\n22. ���� s = NULL, ����� error=1 � ������� ������ 0");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n22. ���� s = NULL, ����� error=1 � ������� ������ 0");
        break;}
case 22:{
        Ptext->SelStart=1004;
        Ptext->SelLength=30;
        WindowFr->Picture->LoadFromFile("stack\\stack9.jpg");        Rich->Lines->Add("\n23. ��������� ��� �������� ������ �� ������� ����� �� ������");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n23. ��������� ��� �������� ������ �� ������� ����� �� ������");
        break;}
case 23:{
        Ptext->SelStart=1041;
        Ptext->SelLength=30;
        WindowFr->Picture->LoadFromFile("stack\\stack10.jpg");
        Rich->Lines->Add("\n24. ���������� � ���� �2 �������� �� 1-�� �����, ������ ��� �������� �� 1-�� �����\n���������� ������� pop()");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n24. ���������� � ���� �2 �������� �� 1-�� �����, ������ ��� �������� �� 1-�� �����\n���������� ������� pop()");
        break;}
case 24:{
        Ptext->SelStart=1078;
        Ptext->SelLength=30;
        WindowFr->Picture->LoadFromFile("stack\\stack11.jpg");
        Rich->Lines->Add("\n25. ���������� � ���� �2 �������� �� 1-�� �����, ������ ��� �������� �� 1-�� �����\n���������� ������� pop()");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n25. ���������� � ���� �2 �������� �� 1-�� �����, ������ ��� �������� �� 1-�� �����\n���������� ������� pop()");
        break;}
case 25:{
        Ptext->SelStart=1112;
        Ptext->SelLength=47;
        WindowFr->Picture->LoadFromFile("stack\\stack12.jpg");
        Rich->Lines->Add("\n26. ������� ������� �� ������� �����. �� ������ ���������� ����� 14");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n26. ������� ������� �� ������� �����. �� ������ ���������� ����� 14");
        break;}
case 26:{
        Ptext->SelStart=1163;
        Ptext->SelLength=47;
        WindowFr->Picture->LoadFromFile("stack\\stack13.jpg");
        Rich->Lines->Add("\n27. ������� ������� �� ������� �����. �� ������ ���������� ����� 13");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n27. ������� ������� �� ������� �����. �� ������ ���������� ����� 13");
        break;}
case 27:{
        Ptext->SelStart=1214;
        Ptext->SelLength=47;
        WindowFr->Picture->LoadFromFile("stack\\stack14.jpg");
        Rich->Lines->Add("\n28. ������� ������� �� ������� �����. �� ������ ���������� ����� 12");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n28. ������� ������� �� ������� �����. �� ������ ���������� ����� 12");
        break;}
case 28:{
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n28. ��� � ���.");
        Rich->Lines->Add("\n28. ��� � ���.");
        if (Application->MessageBoxA("������� ���������� ��� ���?","",MB_ICONQUESTION|MB_YESNO)==IDNO) Close();
        n=-1;
        break;}

}
n++;
}
void __fastcall TDemoForm::Queue()
{
switch (n){
case 0:{
        Ptext->SetFocus();
        Ptext->Lines->LoadFromFile("queue.cpp");
        Comment->Lines->Clear();
        Comment->Lines->Add(" ��� ������� ��������� ����������\n������ � ��������, ��� ��������� ���������� ������ ������������ ������� �������� �� �������, ��������� q1 � q2 - ��� ��������� �� ������ ������� 1 � 2 ��������������.");
        Rich->Lines->Add(" ��� ������� ��������� ����������\n������ � ��������, ��� ��������� ���������� ������ ������������ ������� �������� �� �������, ��������� q1 � q2 - ��� ��������� �� ������ ������� 1 � 2 ��������������.");
        break;}
case 1:{
        Ptext->SelStart=88;
        Ptext->SelLength=41;
        Frame->Refresh();
        Rich->Lines->Add("\n1. ��������� Queue � ������� ���������� �������������� �����(����� info ���� int) � ��������� �� ��������� �������");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n1. ��������� Queue � ������� ���������� �������������� �����(����� info ���� int) � ��������� �� ��������� �������");
        break;}
case 2:{
        Ptext->SelStart=908;
        Ptext->SelLength=19;
        Frame->Refresh();
        WindowFr->Picture->LoadFromFile("queue\\queue1.jpg");
        Rich->Lines->Add("\n2. ������ ��� ��������� �� ������ �������� q1 � q2, ������� ��������� �� NULL.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n2. ������ ��� ��������� �� ������ �������� q1 � q2, ������� ��������� �� NULL.");
        break;}
case 3:{
        Ptext->SelStart=930;
        Ptext->SelLength=16;
        WindowFr->Picture->LoadFromFile("queue\\queue1.jpg");
        Rich->Lines->Add("\n3. �������� ������� 'void insert(&q1,12)' - ��������� � ������� q1 �������� 12 ...\n ���� '&' ���������� �.� �� ����� �������� �������� ��������� q1!!!");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n3. �������� ������� 'void insert(&q1,12)' - ��������� � ������� q1 �������� 12 ...\n ���� '&' ���������� �.� �� ����� �������� �������� ��������� q1!!!");
        break;}
case 4:{
        Ptext->SelStart=257;
        Ptext->SelLength=68;
        WindowFr->Picture->LoadFromFile("queue\\queue1.jpg");
        Rich->Lines->Add("\n4. ��������� 3 ��������� �� ��������� QUEUE:\n\n  current-������� � ����������� ��� �������� q (������ ��� ����� NULL, �.� ������ ���, ���� �� �� ���, �� �� �� �������� �� ������ �������  �������)\n previous=0 - ��� ��������� �� ��������� �������.\n new_node- ��� ��������� �� ����� �������.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n4. ��������� 3 ��������� �� ��������� QUEUE:\n\n  current-������� � ����������� ��� �������� q (������ ��� ����� NULL, �.� ������ ���, ���� �� �� ���, �� �� �� �������� �� ������ �������  �������)\n previous=0 - ��� ��������� �� ��������� �������.\n new_node- ��� ��������� �� ����� �������.");
        break;}
case 5:{
        Ptext->SelStart=325;
        Ptext->SelLength=79;
        WindowFr->Picture->LoadFromFile("queue\\queue1.jpg");
        Rich->Lines->Add("\n5. ���� ������� ������� �� ���� ��������� ������������� ��������, � ������� ���� ������ �� ������� (current = current -> next;).");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n5. ���� ������� ������� �� ���� ��������� ������������� ��������, � ������� ���� ������ �� ������� (current = current -> next;).");
        break;}
case 6:{
        Ptext->SelStart=404;
        Ptext->SelLength=78;
        WindowFr->Picture->LoadFromFile("queue\\queue2.jpg");
        Rich->Lines->Add("\n6. �������� ������ ��� ����� ������� � ����������� ��� �������������� ����� �����, ���������� � �������.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n6. �������� ������ ��� ����� ������� � ����������� ��� �������������� ����� �����, ���������� � �������.");
        break;}
case 7:{
        Ptext->SelStart=484;
        Ptext->SelLength=95;
        WindowFr->Picture->LoadFromFile("queue\\queue2.jpg");
        Rich->Lines->Add("\n7. ������� � ����� �������. ���� ��������� ������� ��������� �� �� NULL, ����� ��������� ������� � ������ ����� ��������� �� ��������� ����������, � ����� �����, ��������� ������� � ������� ���������� (�� ��� �������������) ����� ��������� �� ����� �������. PS. ����� ��������, ��� previos->next ������ NULL � ��������: \nprevios->next=current;\n current->next=NULL;");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n7. ������� � ����� �������. ���� ��������� ������� ��������� �� �� NULL, ����� ��������� ������� � ������ ����� ��������� �� ��������� ����������, � ����� �����, ��������� ������� � ������� ���������� (�� ��� �������������) ����� ��������� �� ����� �������. PS. ����� ��������, ��� previos->next ������ NULL � ��������: \nprevios->next=current;\n current->next=NULL;");
        break;}
case 8:{
        Ptext->SelStart=579;
        Ptext->SelLength=55;
        WindowFr->Picture->LoadFromFile("queue\\queue3.jpg");
        Rich->Lines->Add("\n8. ������� ������� ��������. ���� ��������� ������� ��������� �� NULL, �� q(��������� �� ������ �������) ����� ��������� �� ����� �������, � ��������� ����� NULL.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n8. ������� ������� ��������. ���� ��������� ������� ��������� �� NULL, �� q(��������� �� ������ �������) ����� ��������� �� ����� �������, � ��������� ����� NULL.");
        break;}
case 9:{
        Ptext->SelStart=948;
        Ptext->SelLength=19;
        WindowFr->Picture->LoadFromFile("queue\\queue3.jpg");
        Rich->Lines->Add("\n9. ������� � ������� ������ ��������.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n9. ������� � ������� ������ ��������.");
        break;}
case 10:{
        Ptext->SelStart=484;
        Ptext->SelLength=59;
        WindowFr->Picture->LoadFromFile("queue\\queue4.jpg");
        Rich->Lines->Add("\n10. ������� ������ ��� ����� �������, ������ ��� ��������� �� ��������� ����� previous->next (�.� NULL).");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n10. ������� ������ ��� ����� �������, ������ ��� ��������� �� ��������� ����� previous->next (�.� NULL).");
        break;}
case 11:{
        Ptext->SelStart=543;
        Ptext->SelLength=31;
        WindowFr->Picture->LoadFromFile("queue\\queue5.jpg");
        Rich->Lines->Add("\n11. ��������� ����� ������� � ��������.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n11. ��������� ����� ������� � ��������.");
        break;}
case 12:{
        Ptext->SelStart=967;
        Ptext->SelLength=17;
        WindowFr->Picture->LoadFromFile("queue\\queue6.jpg");
        Rich->Lines->Add("\n12. ������� � ������� ������ ��������");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n12. ������� � ������� ������ ��������");
        break;}
case 13:{
        Ptext->SelStart=987;
        Ptext->SelLength=39;
        WindowFr->Picture->LoadFromFile("queue\\queue6.jpg");
        Rich->Lines->Add("\n13. ������� �� ������ ������� ������ �������� � �������� �������� �� ������ �������.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n13. ������� �� ������ ������� ������ �������� � �������� �������� �� ������ �������.");
        break;}
case 14:{
        Ptext->SelStart=682;
        Ptext->SelLength=45;
        WindowFr->Picture->LoadFromFile("queue\\queue6.jpg");
        Rich->Lines->Add("\n14. ������� 'int take_out(QUEUE  **q, int *error )':\n ��������� ���������� value � ������ ����� ��������� ������������ �������� ���������� ��������, �  ��������� �� ���� ������� ����������� �� ������ �������.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n14. ������� 'int take_out(QUEUE  **q, int *error )':\n ��������� ���������� value � ������ ����� ��������� ������������ �������� ���������� ��������, �  ��������� �� ���� ������� ����������� �� ������ �������.");
        break;}
case 15:{
        Ptext->SelStart=727;
        Ptext->SelLength=43;
        WindowFr->Picture->LoadFromFile("queue\\queue6.jpg");
        Rich->Lines->Add("\n15. ���� ������� ���������� (q!=NULL), �� ���������� value ������������� �������� ���������� ��������");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n15. ���� ������� ���������� (q!=NULL), �� ���������� value ������������� �������� ���������� ��������");
        break;}
case 16:{
        Ptext->SelStart=772;
        Ptext->SelLength=18;
        WindowFr->Picture->LoadFromFile("queue\\queue7.jpg");
        Rich->Lines->Add("\n16. ������� ������ ������� �� ���� ������� ������.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n16. ������� ������ ������� �� ���� ������� ������.");
        break;}
case 17:{
        Ptext->SelStart=792;
        Ptext->SelLength=38;
        WindowFr->Picture->LoadFromFile("queue\\queue8.jpg");
        Rich->Lines->Add("\n17. ������� ������� old_header �� �������, � ����������� ���������� error �������� 0 (�.� ������ ���).");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n17. ������� ������� old_header �� �������, � ����������� ���������� error �������� 0 (�.� ������ ���).");
        break;}
case 18:{
        Ptext->SelStart=835;
        Ptext->SelLength=22;
        WindowFr->Picture->LoadFromFile("queue\\queue8.jpg");
        Rich->Lines->Add("\n18. � ���� ������� ��� (q=NULL), �� ���������� error ����������� ������� ������ �� ������.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n18. � ���� ������� ��� (q=NULL), �� ���������� error ����������� ������� ������ �� ������.");
        break;}
case 19:{
        Ptext->SelStart=857;
        Ptext->SelLength=17;
        WindowFr->Picture->LoadFromFile("queue\\queue9.jpg");
        Rich->Lines->Add("\n19. ���������� �������� ���������� ��������, ��� 0 ��� ������� ������.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n19. ���������� �������� ���������� ��������, ��� 0 ��� ������� ������.");
        break;}
case 20:{
        Ptext->SelStart=1027;
        Ptext->SelLength=39;
        WindowFr->Picture->LoadFromFile("queue\\queue10.jpg");
        Rich->Lines->Add("\n20. ������� �� ������ ������� ������ �������� � �������� �������� �� ������ �������.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n20. ������� �� ������ ������� ������ �������� � �������� �������� �� ������ �������.");
        break;}
case 21:{
        Ptext->SelStart=1067;
        Ptext->SelLength=39;
        WindowFr->Picture->LoadFromFile("queue\\queue11.jpg");
        Rich->Lines->Add("\n21. ������� �� ������ ������� ������ �������� � �������� �������� �� ������ �������.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n21. ������� �� ������ ������� ������ �������� � �������� �������� �� ������ �������.");
        break;}
case 22:{
        Ptext->SelStart=1106;
        Ptext->SelLength=57;
        WindowFr->Picture->LoadFromFile("queue\\queue12.jpg");
        Rich->Lines->Add("\n22. �������� �������� �� ������ ������� � ����� ��� �������� �� �����. �� ������ ����� ����� 12.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n22. �������� �������� �� ������ ������� � ����� ��� �������� �� �����. �� ������ ����� ����� 12.");
        break;}
case 23:{
        Ptext->SelStart=1163;
        Ptext->SelLength=57;
        WindowFr->Picture->LoadFromFile("queue\\queue13.jpg");
        Rich->Lines->Add("\n23. �������� �������� �� ������ ������� � ����� ��� �������� �� �����. �� ������ ����� ����� 13.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n23. �������� �������� �� ������ ������� � ����� ��� �������� �� �����. �� ������ ����� ����� 13.");
        break;}
case 24:{
        Ptext->SelStart=1220;
        Ptext->SelLength=57;
        WindowFr->Picture->LoadFromFile("queue\\queue14.jpg");
        Rich->Lines->Add("\n24. �������� �������� �� ������ ������� � ����� ��� �������� �� �����. �� ������ ����� ����� 14.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n24. �������� �������� �� ������ ������� � ����� ��� �������� �� �����. �� ������ ����� ����� 14.");
        break;}
case 25:{
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n25. ��� � ���.");
        Rich->Lines->Add("\n25. ��� � ���.");
        if (Application->MessageBoxA("������� ���������� ��� ���?","",MB_ICONQUESTION|MB_YESNO)==IDNO) Close();
        n=-1;
        break;}

}
n++;
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::ShowAllClick(TObject *Sender)
{
 Comment->Lines=Rich->Lines;

}
//---------------------------------------------------------------------------

void __fastcall TDemoForm::PrevBtnClick(TObject *Sender)
{
if (n>1)
 {
  n-=2;
  NextBtn->Click();
 }
}
//---------------------------------------------------------------------------







void __fastcall TDemoForm::FormShow(TObject *Sender)
{
NextBtn->Click();
}
//---------------------------------------------------------------------------

void __fastcall TDemoForm::HelpBtnClick(TObject *Sender)
{
Application->HelpContext(flag+1);
}
//---------------------------------------------------------------------------

