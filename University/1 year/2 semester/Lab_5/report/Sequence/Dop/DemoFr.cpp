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
        Comment->Lines->Add(" Эта простая программа показывает\nработу с бинарным деревом.");
        Rich->Lines->Add(" Эта простая программа показывает\nработу с бинарным деревом.");
        break;}
case 1:{
        WindowFr->Picture->LoadFromFile("tree\\tree1.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n1. На рисунке показаны основные части дерева:\n Корень - первый элемент дерева;\n Вершина дерева - Каждый элемент;\n Поддерево - любой фрагмент дерева;\n Листья - заключительный узлы(элементы).");
        Rich->Lines->Add("\n1. На рисунке показаны основные части дерева:\n Корень - первый элемент дерева;\n Вершина дерева - Каждый элемент;\n Поддерево - любой фрагмент дерева;\n Листья - заключительный узлы(элементы).");
        break;}
case 2:{
        WindowFr->Picture->LoadFromFile("tree\\tree2.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n2. Хотя дерево не обязательно должно быть упорядочено, но в большинстве случаев используются именно такие.\n Упорядоченное дерево - это дерево, в котором левое поддерево содержит вершины, меньшие или равные корню, а правое содержит вершины, большие корня.\n Cуществует три метода обхода дерева:\n симметричный обход;\n прямой обход;\n обход снизу.\n На рисунке показан cимметричный обход дерева (a b c d e f g).\n При симметричном обходе обрабатывается сначало левое поддерево, затем корень, а затем правое поддерево.");
        Rich->Lines->Add("\n2. Хотя дерево не обязательно должно быть упорядочено, но в большинстве случаев используются именно такие.\n Упорядоченное дерево - это дерево, в котором левое поддерево содержит вершины, меньшие или равные корню, а правое содержит вершины, большие корня.\n Cуществует три метода обхода дерева:\n симметричный обход;\n прямой обход;\n обход снизу.\n На рисунке показан cимметричный обход дерева (a b c d e f g).\n При симметричном обходе обрабатывается сначало левое поддерево, затем корень, а затем правое поддерево.");
        break;}
case 3:{
        WindowFr->Picture->LoadFromFile("tree\\tree3.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n3. На рисунке показан прямой обход дерева (d b a c f e g). При прямом обходе обрабатывается сначала корень, затем левое поддерево, а затем правое.");
        Rich->Lines->Add("\n3. На рисунке показан прямой обход дерева (d b a c f e g). При прямом обходе обрабатывается сначала корень, затем левое поддерево, а затем правое.");
        break;}
case 4:{
        WindowFr->Picture->LoadFromFile("tree\\tree4.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n4. На рисунке показан обход снизу (a c b e g f d). При обходе снизу обрабатывается сначала левое поддерево,затем правое и наконец корень.");
        Rich->Lines->Add("\n4. На рисунке показан обход снизу (a c b e g f d). При обходе снизу обрабатывается сначала левое поддерево,затем правое и наконец корень.");
        break;}
case 5:{
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add(" Рассмотрим программу имеющую две функции для работыс бинарными деревьями:  добавления элемента в дерево и удаление элемента с его поиском.");
        Rich->Lines->Add(" Рассмотрим программу имеющую две функции для работыс бинарными деревьями:  добавления элемента в дерево и удаление элемента с его поиском.");
        break;}
case 6:{
        Ptext->SelStart=43;
        Ptext->SelLength=78;
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n6. Определяем структуру 'tree', в кторой имеется информационная часть в виде символа и два указателя: на левый и правый элементы");
        Rich->Lines->Add("\n6. Определяем структуру 'tree', в кторой имеется информационная часть в виде символа и два указателя: на левый и правый элементы");
        break;}
case 7:{
        Ptext->SelStart=271;
        Ptext->SelLength=27;
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n7. Объявляем указатель на корень дерева.");
        Rich->Lines->Add("\n7. Объявляем указатель на корень дерева.");
        break;}
case 8:{
        Ptext->SelStart=298;
        Ptext->SelLength=34;
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n8. Вызываем функцию stree(root, root, 'd'), которая добавляет новый элемент в дерево. Рассмотрим функцию stree().");
        Rich->Lines->Add("\n8. Вызываем функцию stree(root, root, 'd'), которая добавляет новый элемент в дерево. Рассмотрим функцию stree().");
        break;}
case 9:{
        Ptext->SelStart=838;
        Ptext->SelLength=7;
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n9. Если r равен NULL (дошли до того места куда нужно вставить элемент) тогда...");
        Rich->Lines->Add("\n9. Если r равен NULL (дошли до того места куда нужно вставить элемент) тогда...");
        break;}
case 10:{
        Ptext->SelStart=844;
        Ptext->SelLength=110;
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n10. Присваиваем правому и левому указателям  NULL и info к его информационной части.");
        Rich->Lines->Add("\n10. Присваиваем правому и левому указателям  NULL и info к его информационной части.");
        break;}
case 11:{
        Ptext->SelStart=954;
        Ptext->SelLength=23;
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n11. Если это первый элемент в дереве (root=NULL), то вернуть r, т.е r - будет корнем дерева.");
        Rich->Lines->Add("\n11. Если это первый элемент в дереве (root=NULL), то вернуть r, т.е r - будет корнем дерева.");
        break;}
case 12:{
        Ptext->SelStart=977;
        Ptext->SelLength=79;
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n12. Связываем этот элемент с корнем дерева (или поддерева) таким образом чтобы оно было упорядоченным и возвращаем r.");
        Rich->Lines->Add("\n12. Связываем этот элемент с корнем дерева (или поддерева) таким образом чтобы оно было упорядоченным и возвращаем r.");
        break;}
case 13:{
        Ptext->SelStart=1063;
        Ptext->SelLength=85;
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n13. А если r не равен NULL  то тогда перемещаемся по дереву таким образом чтобы оно было упорядоченным.");
        Rich->Lines->Add("\n13. А если r не равен NULL  то тогда перемещаемся по дереву таким образом чтобы оно было упорядоченным.");
        break;}
case 14:{
        Ptext->SelStart=298;
        Ptext->SelLength=34;
        WindowFr->Picture->LoadFromFile("tree\\tree17.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n14. Это будет корень.");
        Rich->Lines->Add("\n14. Это будет корень.");
        break;}
case 15:{
        Ptext->SelStart=332;
        Ptext->SelLength=34;
        WindowFr->Picture->LoadFromFile("tree\\tree16.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n15. Добавляем элемент.");
        Rich->Lines->Add("\n15. Добавляем элемент.");
        break;}
case 16:{
        Ptext->SelStart=366;
        Ptext->SelLength=34;
        WindowFr->Picture->LoadFromFile("tree\\tree15.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n16. Добавляем элемент.");
        Rich->Lines->Add("\n16. Добавляем элемент.");
        break;}
case 17:{
        Ptext->SelStart=400;
        Ptext->SelLength=34;
        WindowFr->Picture->LoadFromFile("tree\\tree14.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n17. Добавляем элемент.");
        Rich->Lines->Add("\n17. Добавляем элемент.");
        break;}
case 18:{
        Ptext->SelStart=434;
        Ptext->SelLength=34;
        WindowFr->Picture->LoadFromFile("tree\\tree13.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n18. Добавляем элемент.");
        Rich->Lines->Add("\n18. Добавляем элемент.");
        break;}
case 19:{
        Ptext->SelStart=368;
        Ptext->SelLength=34;
        WindowFr->Picture->LoadFromFile("tree\\tree12.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n19. Добавляем элемент.");
        Rich->Lines->Add("\n19. Добавляем элемент.");
        break;}
case 20:{
        Ptext->SelStart=502;
        Ptext->SelLength=34;
        WindowFr->Picture->LoadFromFile("tree\\tree5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n20. Добавляем элемент.");
        Rich->Lines->Add("\n20. Добавляем элемент.");
        break;}
case 21:{
        Ptext->SelStart=536;
        Ptext->SelLength=28;
        WindowFr->Picture->LoadFromFile("tree\\tree5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n21. Вызываем функцию dtree(root, 'b'), которая удаляет элемент, производя его поиск в дереве. Рассмотрим функцию dteee().");
        Rich->Lines->Add("\n21. Вызываем функцию dtree(root, 'b'), которая удаляет элемент, производя его поиск в дереве. Рассмотрим функцию dteee().");
        break;}
case 22:{
        Ptext->SelStart=1220;
        Ptext->SelLength=23;
        WindowFr->Picture->LoadFromFile("tree\\tree5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n22. Объявляем 2 указателя p и p2.");
        Rich->Lines->Add("\n22. Объявляем 2 указателя p и p2.");
        break;}
case 23:{
        Ptext->SelStart=1243;
        Ptext->SelLength=26;
        WindowFr->Picture->LoadFromFile("tree\\tree5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n23. Если дерева не существует или элемент не найден, то выход.");
        Rich->Lines->Add("\n23. Если дерева не существует или элемент не найден, то выход.");
        break;}
case 24:{
        Ptext->SelStart=1269;
        Ptext->SelLength=23;
        WindowFr->Picture->LoadFromFile("tree\\tree5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n24. Если элемент найден, то ...");
        Rich->Lines->Add("\n24. Если элемент найден, то ...");
        break;}
case 25:{
        Ptext->SelStart=1296;
        Ptext->SelLength=70;
        WindowFr->Picture->LoadFromFile("tree\\tree5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n25. Если правый и левый NULL, то удаляем эту вершину и возвращаем NULL.");
        Rich->Lines->Add("\n25. Если правый и левый NULL, то удаляем эту вершину и возвращаем NULL.");
        break;}
case 26:{
        Ptext->SelStart=1366;
        Ptext->SelLength=86;
        WindowFr->Picture->LoadFromFile("tree\\tree5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n26. Если левый NULL, то удаляем эту вершину и возвращаем указатель на правый.");
        Rich->Lines->Add("\n26. Если правый и левый NULL, то удаляем эту вершину и возвращаем NULL.");
        break;}
case 27:{
        Ptext->SelStart=1366;
        Ptext->SelLength=86;
        WindowFr->Picture->LoadFromFile("tree\\tree5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n27. Если правый NULL, то удаляем эту вершину и возвращаем указатель на левый элемент.");
        Rich->Lines->Add("\n27. Если правый NULL, то удаляем эту вершину и возвращаем указатель на левый элемент.");
        break;}
case 28:{
        Ptext->SelStart=1538;
        Ptext->SelLength=141;
        WindowFr->Picture->LoadFromFile("tree\\tree5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n28. Если левый и правый не NULL, то по правому поддереву находим самый левый свободный элемет (так мы не разрушаем упорядоченность в дереве) и присваиваем этому элементу левую ветвь удалемого элемента, удаляем элемент и возвращаем указатель на его правую ветвь, сохраненную в указателе p2.");
        Rich->Lines->Add("\n28. Если левый и правый не NULL, то по правому поддереву находим самый левый свободный элемет (так мы не разрушаем упорядоченность в дереве) и присваиваем этому элементу левую ветвь удалемого элемента, удаляем элемент и возвращаем указатель на его правую ветвь, сохраненную в указателе p2.");
        break;}
case 29:{
        Ptext->SelStart=1684;
        Ptext->SelLength=124;
        WindowFr->Picture->LoadFromFile("tree\\tree5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n29. Если элемент не найден, то перемещаемся по дереву.");
        Rich->Lines->Add("\n29. Если элемент не найден, то перемещаемся по дереву.");
        break;}
case 30:{
        Ptext->SelStart=536;
        Ptext->SelLength=28;
        WindowFr->Picture->LoadFromFile("tree\\tree6.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n30. Удалили вершину b.");
        Rich->Lines->Add("\n30. Удалили вершину b.");
        break;}
case 31:{
        Ptext->SelStart=564;
        Ptext->SelLength=28;
        WindowFr->Picture->LoadFromFile("tree\\tree7.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n31. Удаляем корень дерева d.");
        Rich->Lines->Add("\n31. Удаляем корень дерева d.");
        break;}
case 32:{
        Ptext->SelStart=592;
        Ptext->SelLength=28;
        WindowFr->Picture->LoadFromFile("tree\\tree8.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n32. Удаляем вершину а.");
        Rich->Lines->Add("\n32. Удаляем вершину а.");
        break;}
case 33:{
        Ptext->SelStart=620;
        Ptext->SelLength=28;
        WindowFr->Picture->LoadFromFile("tree\\tree9.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n33. Удаляем вершину с.");
        Rich->Lines->Add("\n33. Удаляем вершину с.");
        break;}
case 34:{
        Ptext->SelStart=648;
        Ptext->SelLength=28;
        WindowFr->Picture->LoadFromFile("tree\\tree10.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n34. Удаляем вершину е.");
        Rich->Lines->Add("\n34. Удаляем вершину е.");
        break;}
case 35:{
        Ptext->SelStart=676;
        Ptext->SelLength=28;
        WindowFr->Picture->LoadFromFile("tree\\tree11.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n35. Удаляем вершину f.");
        Rich->Lines->Add("\n35. Удаляем вершину f.");
        break;}
case 36:{
        Ptext->SelStart=704;
        Ptext->SelLength=28;
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n36. Удаляем вершину g.");
        Rich->Lines->Add("\n36. Удаляем вершину g.");
        break;}
case 37:{
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n37. Вот и все.");
        Rich->Lines->Add("\n37. Вот и все.");
        if (Application->MessageBoxA("Желаите посмотреть еще раз?","",MB_ICONQUESTION|MB_YESNO)==IDNO) Close();
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
        Comment->Lines->Add(" Эта простая программа показывает\nработу с циклическим списком ");
        Rich->Lines->Add(" Эта простая программа показывает\nработу с циклическим списком ");
        break;}
case 1:{
        Ptext->SelStart=86;
        Ptext->SelLength=37;
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n1. Определяем структуру 'list', в кторой имеется информационная часть в виде числа и указатель на следующий элемент");
        Rich->Lines->Add("\n1. Определяем структуру 'list', в кторой имеется информационная часть в виде числа и указатель на следующий элемент");
        break;}
case 2:{
        Ptext->SelStart=274;
        Ptext->SelLength=49;
        WindowFr->Picture->LoadFromFile("sllist\\sllist1.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n2. Объявляем два указателя на цикл. список. Оди на начало (start) и на текущий элемент (i).");
        Rich->Lines->Add("\n2. Объявляем два указателя на цикл. список. Оди на начало (start) и на текущий элемент (i).");
        break;}
case 3:{
        Ptext->SelStart=337;
        Ptext->SelLength=21;
        WindowFr->Picture->LoadFromFile("sllist\\sllist1.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n3. Вызываем функцию add(&i,&start,12), которая добавляет новый элемент в список. Рассмотрим функцию add().");
        Rich->Lines->Add("\n3. Вызываем функцию add(&i,&start,12), которая добавляет новый элемент в список. Рассмотрим функцию add().");
        break;}
case 4:{
        Ptext->SelStart=721;
        Ptext->SelLength=78;
        WindowFr->Picture->LoadFromFile("sllist\\sllist2.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n4. Объявляем указатель на новый элемент. Выделяем под него память и присваиваем его информационной части число переданное в функцию.");
        Rich->Lines->Add("\n4. Объявляем указатель на новый элемент. Выделяем под него память и присваиваем его информационной части число переданное в функцию.");
        break;}
case 5:{
        Ptext->SelStart=799;
        Ptext->SelLength=15;
        WindowFr->Picture->LoadFromFile("sllist\\sllist2.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n5. Если это перваый элемент в списке (start равен NULL), то ...");
        Rich->Lines->Add("\n5. Если это перваый элемент в списке (start равен NULL), то ...");
        break;}
case 6:{
        Ptext->SelStart=819;
        Ptext->SelLength=44;
        WindowFr->Picture->LoadFromFile("sllist\\sllist3.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n6. start равен new_node и замыкаем его на себя ((*start)->next=*start)");
        Rich->Lines->Add("\n6. start равен new_node и замыкаем его на себя ((*start)->next=*start)");
        break;}
case 7:{
        Ptext->SelStart=937;
        Ptext->SelLength=14;
        WindowFr->Picture->LoadFromFile("sllist\\sllist4.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n7. Указатель на текущий элемент будет указывать на новый элемент.");
        Rich->Lines->Add("\n7. Указатель на текущий элемент будет указывать на новый элемент.");
        break;}
case 8:{
        Ptext->SelStart=358;
        Ptext->SelLength=21;
        WindowFr->Picture->LoadFromFile("sllist\\sllist4.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n8. Вызываем функцию add(&i,&start,13), которая добавляет новый элемент в список.");
        Rich->Lines->Add("\n8. Вызываем функцию add(&i,&start,13), которая добавляет новый элемент в список.");
        break;}
case 9:{
        Ptext->SelStart=799;
        Ptext->SelLength=15;
        WindowFr->Picture->LoadFromFile("sllist\\sllist5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n9. Т.к в списке уже есть элементы, то ...");
        Rich->Lines->Add("\n9. Т.к в списке уже есть элементы, то ...");
        break;}
case 10:{
        Ptext->SelStart=880;
        Ptext->SelLength=52;
        WindowFr->Picture->LoadFromFile("sllist\\sllist6.jpg");
        Comment->Lines->Clear();
//        Comment->Lines->Add("\n10. Т.к в списке уже есть элементы, то ...");
//        Rich->Lines->Add("\n9. Т.к в списке уже есть элементы, то ...");
        break;}
case 11:{
        Ptext->SelStart=937;
        WindowFr->Picture->LoadFromFile("sllist\\sllist7.jpg");
        Ptext->SelLength=14;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n7. Указатель на текущий элемент будет указывать на новый элемент.");
        Rich->Lines->Add("\n7. Указатель на текущий элемент будет указывать на новый элемент.");
        break;}
case 12:{
        Ptext->SelStart=379;
        WindowFr->Picture->LoadFromFile("sllist\\sllist8.jpg");
        Ptext->SelLength=42;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n12. Добавляем еще два элемента 14 и 15.");
        Rich->Lines->Add("\n7. Указатель на текущий элемент будет указывать на новый элемент.");
        break;}
case 13:{
        Ptext->SelStart=421;
        Ptext->SelLength=23;
        WindowFr->Picture->LoadFromFile("sllist\\sllist8.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n13. Вызываем функцию del(&i,&start,&error) - удаляем i-ий элемент. Рассмотрим функцию del");
        Rich->Lines->Add("\n13.  Вызываем функцию del(&i,&start,&error) - удаляем i-ий элемент. Рассмотрим функцию del");
        break;}
case 14:{
        Ptext->SelStart=1027;
        Ptext->SelLength=25;
        WindowFr->Picture->LoadFromFile("sllist\\sllist8.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n14. Объявляем указатель на предыдущий элемент (после которого будет удалятся элемент)");
        Rich->Lines->Add("\n14. Объявляем указатель на предыдущий элемент (после которого будет удалятся элемент)");
        break;}
case 15:{
        Ptext->SelStart=1052;
        Ptext->SelLength=20;
        WindowFr->Picture->LoadFromFile("sllist\\sllist8.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n15. Если списка не существует (start равен NULL), то ошибка (error=1).");
        Rich->Lines->Add("\n15. Если списка не существует (start равен NULL), то ошибка (error=1).");
        break;}
case 16:{
        Ptext->SelStart=1093;
        Ptext->SelLength=38;
        WindowFr->Picture->LoadFromFile("sllist\\sllist8.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n16. Иначе может быть два случая либо мы удаляем последний элемент в списке или не последний.");
        Rich->Lines->Add("\n16. Иначе может быть два случая либо мы удаляем последний элемент в списке или не последний.");
        break;}
case 17:{
        Ptext->SelStart=1226;
        Ptext->SelLength=57;
        WindowFr->Picture->LoadFromFile("sllist\\sllist9.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n17. Двигаемся по списку от начала до того, пока следующий не будет указывать на i-ий элемент.");
        Rich->Lines->Add("\n17. Двигаемся по списку от начала до того, пока следующий не будет указывать на i-ий элемент.");
        break;}
case 18:{
        Ptext->SelStart=1283;
        Ptext->SelLength=32;
        WindowFr->Picture->LoadFromFile("sllist\\sllist10.jpg");
        Comment->Lines->Clear();
     //   Comment->Lines->Add("\n17. Двигаемся по списку от начала до того, пока следующий не будет указывать на i-ий элемент.");
     //   Rich->Lines->Add("\n17. Двигаемся по списку от начала до того, пока следующий не будет указывать на i-ий элемент.");
        break;}
case 19:{
        Ptext->SelStart=1315;
        Ptext->SelLength=15;
        WindowFr->Picture->LoadFromFile("sllist\\sllist11.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n19. Очищаем память по указателю i.");
        Rich->Lines->Add("\n19. Очищаем память по указателю i.");
        break;}
case 20:{
        Ptext->SelStart=1330;
        Ptext->SelLength=36;
        WindowFr->Picture->LoadFromFile("sllist\\sllist11.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n20. Если мы удалили начало списка, то перемещаем его на previous.");
        Rich->Lines->Add("\n20. Если мы удалили начало списка, то перемещаем его на previous.");
        break;}
case 21:{
        Ptext->SelStart=1368;
        Ptext->SelLength=33;
        WindowFr->Picture->LoadFromFile("sllist\\sllist12.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n21. Перемещаем указатель i на previous. Сообщаем что ошибок нет (error=0).");
        Rich->Lines->Add("\n21. Перемещаем указатель i на previous. Сообщаем что ошибок нет (error=0).");
        break;}
case 22:{
        Ptext->SelStart=446;
        Ptext->SelLength=34;
        WindowFr->Picture->LoadFromFile("sllist\\sllist13.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n22. Перемещаем указатель i вперед (на start) и добавляем новый элемент.");
        Rich->Lines->Add("\n22. Перемещаем указатель i вперед (на start) и добавляем новый элемент.");
        break;}
case 23:{
        Ptext->SelStart=480;
        Ptext->SelLength=25;
        WindowFr->Picture->LoadFromFile("sllist\\sllist14.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n23. Удаляем вставленный элемент.");
        Rich->Lines->Add("\n23. Удаляем вставленный элемент.");
        break;}
case 24:{
        Ptext->SelStart=505;
        Ptext->SelLength=21;
        WindowFr->Picture->LoadFromFile("sllist\\sllist15.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n24. Вставляем еще один элемент.");
        Rich->Lines->Add("\n24. Вставляем еще один элемент.");
        break;}
case 25:{
        Ptext->SelStart=526;
        Ptext->SelLength=38;
        Comment->Lines->Clear();
        WindowFr->Picture->LoadFromFile("sllist\\sllist16.jpg");
        Comment->Lines->Add("\n25. Перемещаем указатель i вперед и удаляем элемент.");
        Rich->Lines->Add("\n25. Перемещаем указатель i вперед и удаляем элемент.");
        break;}
case 26:{
        Ptext->SelStart=564;
        Ptext->SelLength=38;
        WindowFr->Picture->LoadFromFile("sllist\\sllist17.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n26. Перемещаем указатель i вперед и удаляем элемент.");
        Rich->Lines->Add("\n26. Перемещаем указатель i вперед и удаляем элемент.");
        break;}
case 27:{
        Ptext->SelStart=602;
        Ptext->SelLength=25;
        WindowFr->Picture->LoadFromFile("sllist\\sllist18.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n27. Удаляем элемент.");
        Rich->Lines->Add("\n27. Удаляем элемент.");
        break;}
case 28:{
        Ptext->SelStart=627;
        Ptext->SelLength=25;
        WindowFr->Picture->LoadFromFile("sllist\\sllist18.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n28. Удаляем последний оставшийся элемент.");
        Rich->Lines->Add("\n28. Удаляем последний оставшийся элемент.");
        break;}
case 29:{
        Ptext->SelStart=1138;
        Ptext->SelLength=65;
        WindowFr->Picture->LoadFromFile("sllist\\sllist19.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n29. Очищаем память по указателю start, и присваиваем указателям start и i значение NULL.");
        Rich->Lines->Add("\n29. Удаляем последний оставшийся элемент.");
        break;}
case 30:{
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n30. Вот и все.");
        Rich->Lines->Add("\n30. Вот и все.");
        if (Application->MessageBoxA("Желаите посмотреть еще раз?","",MB_ICONQUESTION|MB_YESNO)==IDNO) Close();
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
        Comment->Lines->Add(" Эта простая программа показывает\nработу с двусваязным списком");
        Rich->Lines->Add(" Эта простая программа показывает\nработу с двусвязным списком");
        break;}
case 1:{
        Ptext->SelStart=86;
        Ptext->SelLength=51;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n1. Определяем структуру 'list', в кторой имеется информационная часть в виде числа и два указателя: на следующий и на предыдущий элементы");
        Rich->Lines->Add("\n1. Определяем структуру 'list', в кторой имеется информационная часть в виде числа и два указателя: на следующий и на предыдущий элементы");
        break;}
case 2:{
        Ptext->SelStart=334;
        Ptext->SelLength=55;
        Comment->Lines->Clear();
        WindowFr->Picture->LoadFromFile("dllist\\dllist1.jpg");
        Comment->Lines->Add("\n2. Объявляем 3 указателя на структуру list:\n i - i-ий элемент (текущий)\n start - указатель на начало списка\n last - указатель на конец списка");
        Rich->Lines->Add("\n2. Объявляем 3 указателя на структуру list:\n i - i-ий элемент (текущий)\n start - указатель на начало списка\n last - указатель на конец списка");
        break;}
case 3:{
        Ptext->SelStart=416;
        Ptext->SelLength=27;
        Comment->Lines->Clear();
        WindowFr->Picture->LoadFromFile("dllist\\dllist1.jpg");
        Comment->Lines->Add("\n3. Вызываем функцию add(&i,&start,&last,12), которая добавляет новый элемент в список. Рассмотрим функцию add().");
        Rich->Lines->Add("\n3. Вызываем функцию add(&i,&start,&last,12), которая добавляет новый элемент в список. Рассмотрим функцию add().");
        break;}
case 4:{
        Ptext->SelStart=769;
        Ptext->SelLength=84;
        WindowFr->Picture->LoadFromFile("dllist\\dllist1.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n4. В функцию void add(LIST **i,LIST **start,LIST **last,int n) нужно передать 4 параметра:\n - указатель на текущий элемент\n - указатель на начало списка\n - указаетль на конец списка\n  - и число типа int.");
        Rich->Lines->Add("\n4. В функцию void add(LIST **i,LIST **start,LIST **last,int n) нужно передать 4 параметра:\n - указатель на текущий элемент\n - указатель на начало списка\n - указаетль на конец списка\n  - и число типа int.");
        break;}
case 5:{
        Ptext->SelStart=856;
        Ptext->SelLength=16;
        WindowFr->Picture->LoadFromFile("dllist\\dllist1.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n5. Объявляем указатель на новый элемет.");
        Rich->Lines->Add("\n5. Объявляем указатель на новый элемет.");
        break;}
case 6:{
        Ptext->SelStart=874;
        Ptext->SelLength=60;
        WindowFr->Picture->LoadFromFile("dllist\\dllist2.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n6. Выделяем память под новый элемент и присваиваем его информационной части число переданное в функцию.");
        Rich->Lines->Add("\n6. Выделяем память под новый элемент и присваиваем его информационной части число переданное в функцию.");
        break;}
case 7:{
        Ptext->SelStart=934;
        Ptext->SelLength=18;
        WindowFr->Picture->LoadFromFile("dllist\\dllist2.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n7. Если списка нет (start равен NULL), то ...");
        Rich->Lines->Add("\n7. Если списка нет (start равен NULL), то ...");
        break;}
case 8:{
        Ptext->SelStart=959;
        Ptext->SelLength=98;
        WindowFr->Picture->LoadFromFile("dllist\\dllist3.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n8. Указатели start и last будут указывать на новый элемент, т.к это первый элемент и у него нет ни следующего ни придыдущего, то их присваиваем к NULL. И i-ий элемент будет указавать на новый.");
        Rich->Lines->Add("\n8. Указатели start и last будут указывать на новый элемент, т.к это первый элемент и у него нет ни следующего ни придыдущего, то их присваиваем к NULL. И i-ий элемент будет указавать на новый.");
        break;}
case 9:{
        Ptext->SelStart=1062;
        Ptext->SelLength=24;
        WindowFr->Picture->LoadFromFile("dllist\\dllist3.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n9. Т.к сейчас (*i)->next равен NULL, то функуия завершается.");
        Rich->Lines->Add("\n9. Т.к сейчас (*i)->next равен NULL, то функуия завершается.");
        break;}
case 10:{
        Ptext->SelStart=443;
        Ptext->SelLength=26;
        WindowFr->Picture->LoadFromFile("dllist\\dllist3.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n10. Добавляем новый элемент с числом 13, после i-ого.");
        Rich->Lines->Add("\n10. Добавляем новый элемент с числом 13, после i-ого.");
        break;}
case 11:{
        Ptext->SelStart=934;
        Ptext->SelLength=18;
        WindowFr->Picture->LoadFromFile("dllist\\dllist24.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n11. Т.к start не равен NULL, то идем дальше.");
        Rich->Lines->Add("\n11. Т.к start не равен NULL, то идем дальше.");
        break;}
case 12:{
        Ptext->SelStart=1062;
        Ptext->SelLength=24;
        WindowFr->Picture->LoadFromFile("dllist\\dllist24.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n12. Сейчас (*i)->next равен NULL, следовательно добавляем элементо в конец списка.");
        Rich->Lines->Add("\n12. Сейчас (*i)->next равен NULL, следовательно добавляем элементо в конец списка.");
        break;}
case 13:{
        Ptext->SelStart=1214;
        Ptext->SelLength=23;
        WindowFr->Picture->LoadFromFile("dllist\\dllist4.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n13. Указатель на следующий элемент конца списка присваиваем к новому элементу.");
        Rich->Lines->Add("\n13. Указатель на следующий элемент конца списка присваиваем к новому элементу.");
        break;}
case 14:{
        Ptext->SelStart=1239;
        Ptext->SelLength=49;
        WindowFr->Picture->LoadFromFile("dllist\\dllist5.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n14. Указатель на предыдущий элемент текущего элемента присваиваем к последнему эл-ту списка, а следующий NULL.");
        Rich->Lines->Add("\n14. Указатель на предыдущий элемент текущего элемента присваиваем к последнему эл-ту списка, а следующий NULL.");
        break;}
case 15:{
        Ptext->SelStart=1288;
        Ptext->SelLength=37;
        WindowFr->Picture->LoadFromFile("dllist\\dllist6.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n15. Обновляем конец списка и i-ий элемент (присваиваем их к новому элементу).");
        Rich->Lines->Add("\n15. Обновляем конец списка и i-ий элемент (присваиваем их к новому элементу).");
        break;}
case 16:{
        Ptext->SelStart=470;
        Ptext->SelLength=57;
        WindowFr->Picture->LoadFromFile("dllist\\dllist7.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n16. Аналогично вставляем еще два элемента (i равен last).");
        Rich->Lines->Add("\n16. Аналогично вставляем еще два элемента (i равен last).");
        break;}
case 17:{
        Ptext->SelStart=527;
        Ptext->SelLength=31;
        WindowFr->Picture->LoadFromFile("dllist\\dllist7.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n17. Вставляем еще один элемент в начало списка.");
        Rich->Lines->Add("\n17. Вставляем еще один элемент в начало списка.");
        break;}
case 18:{
        Ptext->SelStart=1062;
        Ptext->SelLength=24;
        WindowFr->Picture->LoadFromFile("dllist\\dllist8.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n18. Сейчас (*i)->next не равен NULL, следовательно добавляем элементо в середину списка.");
        Rich->Lines->Add("\n18. Сейчас (*i)->next не равен NULL, следовательно добавляем элементо в середину списка.");
        break;}
case 19:{
        Ptext->SelStart=1091;
        Ptext->SelLength=29;
        WindowFr->Picture->LoadFromFile("dllist\\dllist9.jpg");
        Comment->Lines->Clear();
//        Comment->Lines->Add("\n19. Сейчас (*i)->next не равен NULL, следовательно добавляем элементо в середину списка.");
//        Rich->Lines->Add("\n19. Сейчас (*i)->next не равен NULL, следовательно добавляем элементо в середину списка.");
        break;}
case 20:{
        Ptext->SelStart=1120;
        Ptext->SelLength=29;
        WindowFr->Picture->LoadFromFile("dllist\\dllist10.jpg");
        Comment->Lines->Clear();
//        Comment->Lines->Add("\n19. Сейчас (*i)->next не равен NULL, следовательно добавляем элементо в середину списка.");
//        Rich->Lines->Add("\n19. Сейчас (*i)->next не равен NULL, следовательно добавляем элементо в середину списка.");
        break;}
case 21:{
        Ptext->SelStart=1149;
        Ptext->SelLength=21;
        WindowFr->Picture->LoadFromFile("dllist\\dllist11.jpg");
        Comment->Lines->Clear();
//        Comment->Lines->Add("\n19. Сейчас (*i)->next не равен NULL, следовательно добавляем элементо в середину списка.");
//        Rich->Lines->Add("\n19. Сейчас (*i)->next не равен NULL, следовательно добавляем элементо в середину списка.");
        break;}
case 22:{
        Ptext->SelStart=1170;
        Ptext->SelLength=23;
        WindowFr->Picture->LoadFromFile("dllist\\dllist12.jpg");
        Comment->Lines->Clear();
//        Comment->Lines->Add("\n19. Сейчас (*i)->next не равен NULL, следовательно добавляем элементо в середину списка.");
//        Rich->Lines->Add("\n19. Сейчас (*i)->next не равен NULL, следовательно добавляем элементо в середину списка.");
        break;}
case 23:{
        Ptext->SelStart=558;
        Ptext->SelLength=34;
        WindowFr->Picture->LoadFromFile("dllist\\dllist12.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n23. Вызываем функцию  del(&last,&start,&last,&error), которая удаляет элемент из списока. Рассмотрим функцию del.");
        Rich->Lines->Add("\n23. Вызываем функцию  del(&last,&start,&last,&error), которая удаляет элемент из списока. Рассмотрим функцию del.");
        break;}
case 24:{
        Ptext->SelStart=1336;
        Ptext->SelLength=89;
        WindowFr->Picture->LoadFromFile("dllist\\dllist12.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n24. В функцию void del(LIST **i,LIST **start,LIST **last,int *error) нужно передать 4 параметра:\n - указатель на удаляемый элемент\n - указатель на начало списка\n - указаетль на конец списка\n  - и указатель на int для отслеживания ошибок.");
        Rich->Lines->Add("\n24. В функцию void del(LIST **i,LIST **start,LIST **last,int *error) нужно передать 4 параметра:\n - указатель на удаляемый элемент\n - указатель на начало списка\n - указаетль на конец списка\n  - и указатель на int для отслеживания ошибок.");
        break;}
case 25:{
        Ptext->SelStart=1429;
        Ptext->SelLength=18;
        WindowFr->Picture->LoadFromFile("dllist\\dllist12.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n25. Объявляем указатель на удаляемый элемент.");
        Rich->Lines->Add("\n25. Объявляем указатель на удаляемый элемент.");
        break;}
case 26:{
        Ptext->SelStart=1449;
        Ptext->SelLength=59;
        WindowFr->Picture->LoadFromFile("dllist\\dllist12.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n26. Если хотя бы один из указателей, переданных в функцию, равен NULL, то error=1 (сообщаем об ощибке). Иначе существует 3 варианта: удаление первого эл-та, удаление из середины списка и удаление с конца списка.");
        Rich->Lines->Add("\n26. Если хотя бы один из указателей, переданных в функцию, равен NULL, то error=1 (сообщаем об ощибке). Иначе существует 3 варианта: удаление первого эл-та, удаление из середины списка и удаление с конца списка.");
        break;}
case 27:{
        Ptext->SelStart=1618;
        Ptext->SelLength=18;
        WindowFr->Picture->LoadFromFile("dllist\\dllist12.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n27. Т.к сейчас i равен last, то удаляем последний элемент.");
        Rich->Lines->Add("\n27. Т.к сейчас i равен last, то удаляем последний элемент.");
        break;}
case 28:{
        Ptext->SelStart=1642;
        Ptext->SelLength=53;
        WindowFr->Picture->LoadFromFile("dllist\\dllist13.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n28. Т.к i не равен start,то значит что i->prev не равен NULL, следовательно можно без опасения сдвинуть текущий (i-ий) элемент назад. Далее сдвигаем назад и указатель на последний элемент. И заканчиваем список, указав, что следующий элемент последнего равен NULL");
        Rich->Lines->Add("\n28. Т.к i не равен start,то значит что i->prev не равен NULL, следовательно можно без опасения сдвинуть текущий (i-ий) элемент назад. Далее сдвигаем назад и указатель на последний элемент. И заканчиваем список, указав, что следующий элемент последнего равен NULL");
        break;}
case 29:{
        Ptext->SelStart=1805;
        Ptext->SelLength=30;
        Comment->Lines->Clear();
        WindowFr->Picture->LoadFromFile("dllist\\dllist14.jpg");
        Comment->Lines->Add("\n29. Присваиваем переменной error 0, говоря о том ,что ошибок нет и освобождаем память по указателю old_node");
        Rich->Lines->Add("\n29. Присваиваем переменной error 0, говоря о том ,что ошибок нет и освобождаем память по указателю old_node");
        break;}
case 30:{
        Ptext->SelStart=592;
        Ptext->SelLength=35;
        WindowFr->Picture->LoadFromFile("dllist\\dllist14.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n30. Удаляем первый элемент");
        Rich->Lines->Add("\n30. Удаляем первый элемент");
        break;}
case 31:{
        Ptext->SelStart=1520;
        Ptext->SelLength=18;
        Comment->Lines->Clear();
        WindowFr->Picture->LoadFromFile("dllist\\dllist15.jpg");
        Comment->Lines->Add("\n31. Т.к сейчас i равен start, то удаляем первый элемент.");
        Rich->Lines->Add("\n31. Т.к сейчас i равен start, то удаляем первый элемент.");
        break;}
case 32:{
        Ptext->SelStart=1543;
        Ptext->SelLength=34;
        WindowFr->Picture->LoadFromFile("dllist\\dllist16.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n32. Сдвигаем указтели start и i вперед на один элемент.");
        Rich->Lines->Add("\n32. Сдвигаем указтели start и i вперед на один элемент.");
        break;}
case 33:{
        Ptext->SelStart=1577;
        Ptext->SelLength=29;
        WindowFr->Picture->LoadFromFile("dllist\\dllist17.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n33. Если это не посдедний элемент в списке, то предыдущий должен быть равен NULL.");
        Rich->Lines->Add("\n33. Если это не посдедний элемент в списке, то предыдущий должен быть равен NULL.");
        break;}
case 34:{
        Ptext->SelStart=1805;
        Ptext->SelLength=30;
        WindowFr->Picture->LoadFromFile("dllist\\dllist18.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n34. Присваиваем переменной error 0, говоря о том ,что ошибок нет и освобождаем память по указателю old_node");
        Rich->Lines->Add("\n34. Присваиваем переменной error 0, говоря о том ,что ошибок нет и освобождаем память по указателю old_node");
        break;}
case 35:{
        Ptext->SelStart=627;
        Ptext->SelLength=42;
        WindowFr->Picture->LoadFromFile("dllist\\dllist19.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n35. Сдвигаем указатель на текущий элемент на один элемент назад и удаляем его.");
        Rich->Lines->Add("\n35. Сдвигаем указатель на текущий элемент на один элемент назад и удаляем его.");
        break;}
case 36:{
        Ptext->SelStart=1715;
        Ptext->SelLength=32;
        WindowFr->Picture->LoadFromFile("dllist\\dllist20.jpg");
        Comment->Lines->Clear();
    //    Comment->Lines->Add("\n35. Сдвигаем указатель на текущий элемент на один элемент назад и удаляем его.");
    //    Rich->Lines->Add("\n35. Сдвигаем указатель на текущий элемент на один элемент назад и удаляем его.");
        break;}
case 37:{
        Ptext->SelStart=1747;
        Ptext->SelLength=52;
        WindowFr->Picture->LoadFromFile("dllist\\dllist21.jpg");
        Comment->Lines->Clear();
    //    Comment->Lines->Add("\n35. Сдвигаем указатель на текущий элемент на один элемент назад и удаляем его.");
    //    Rich->Lines->Add("\n35. Сдвигаем указатель на текущий элемент на один элемент назад и удаляем его.");
        break;}
case 38:{
        Ptext->SelStart=1805;
        Ptext->SelLength=30;
        WindowFr->Picture->LoadFromFile("dllist\\dllist22.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n38. Присваиваем переменной error 0, говоря о том ,что ошибок нет и освобождаем память по указателю old_node");
        Rich->Lines->Add("\n38. Присваиваем переменной error 0, говоря о том ,что ошибок нет и освобождаем память по указателю old_node");
        break;}
case 39:{
        Ptext->SelStart=671;
        Ptext->SelLength=62;
        WindowFr->Picture->LoadFromFile("dllist\\dllist23.jpg");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n39. Удаляем аналогично еще два элемнта");
        Rich->Lines->Add("\n39. Удаляем аналогично еще два элемнта");
        break;}
case 40:{
        Ptext->SelStart=733;
        Ptext->SelLength=31;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n40. При удалении несуществующего элемента (i равен NULL) переменная error будет равна единице.");
        Rich->Lines->Add("\n40. При удалении несуществующего элемента (i равен NULL) переменная error будет равна единице.");
        break;}
case 41:{
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n41. Вот и все.");
        Rich->Lines->Add("\n41. Вот и все.");
        if (Application->MessageBoxA("Желаите посмотреть еще раз?","",MB_ICONQUESTION|MB_YESNO)==IDNO) Close();
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
        Comment->Lines->Add(" Эта простая программа показывает\nработу со стеком");
        Comment->Lines->Add("\n1. В первых строках включены заголовочные файлы \"alloc.h\"-для рабты с памятью и \"stdio.h\"-для вывода информации на экран");
        Rich->Lines->Add(" Эта простая программа показывает\nработу со стеком");
        Rich->Lines->Add("\n1. В первых строках включены заголовочные файлы \"alloc.h\"-для рабты с памятью и \"stdio.h\"-для вывода информации на экран");
        Ptext->SelStart=0;
        Ptext->SelLength=40;
        break;}
case 1:{
        Ptext->SelStart=40;
        Ptext->SelLength=26;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n2. Далее чтобы не писать каждый раз в тексте 'struct stack' объявляем, что вместо STACK компилятор должен понимать 'struct stack'");
        Rich->Lines->Add("\n2. Далее чтобы не писать каждый раз в тексте 'struct stack' объявляем, что вместо STACK компилятор должен понимать 'struct stack'");
        break;}
case 2:{
        Ptext->SelStart=68;
        Ptext->SelLength=43;
        Rich->Lines->Add("\n3. Объявляем структуру 'stack' в которой имеется переменная info типа int, в которой будем хранить какое-то число, и указатель на следущий элемент стека 'struct stack *next'");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n3. Объявляем структуру 'stack' в которой имеется переменная info типа int, в которой будем хранить какое-то число, и указатель на следущий элемент стека 'struct stack *next'");
        break;}
case 3:{

        Ptext->SelStart=111;
        Ptext->SelLength=105;
        Rich->Lines->Add("\n4. Объявляем 3 функции:\n void push (STACK **s, int item); \n      - 'втолкнуть' элемент в стек \n int pop (STACK **s, int *error); \n       - 'вытолкнуть' элемент из стека \n int peek (STACK *s, int *error); \n       - взять только его значение");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n4. Объявляем 3 функции:\n void push (STACK **s, int item); \n     - 'втолкнуть' элемент в стек \n int pop (STACK **s, int *error); \n       - 'вытолкнуть' элемент из стека \n int peek (STACK *s, int *error); \n       - взять только его значение");
        break;}
case 4:{
        Ptext->SelStart=737;
        Ptext->SelLength=11;
        WindowFr->Picture=NULL;
        Rich->Lines->Add("\n5. Объявление главной функции - функции main");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n5. Объявление главной функции - функции main");
        break;}
case 5:{
        Ptext->SelStart=754;
        Ptext->SelLength=18;
        WindowFr->Picture->LoadFromFile("stack\\stack1.jpg");
        Rich->Lines->Add("\n6. Объявляем два стека: s1 и s2");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n6. Объявляем два стека: s1 и s2");
        break;}
case 6:{
        Ptext->SelStart=772;
        Ptext->SelLength=14;
        WindowFr->Picture->LoadFromFile("stack\\stack2.jpg");
        Rich->Lines->Add("\n7. Объявляем переменную 'error' типа int");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n7. Объявляем переменную 'error' типа int");
        break;}
case 7:{
        Ptext->SelStart=786;
        Ptext->SelLength=19;
        WindowFr->Picture->LoadFromFile("stack\\stack2.jpg");
        Rich->Lines->Add("\n8. Вызываем функцию 'void push(&s1,12)' - добавляем в стек s1 значение 12 ...\n знак '&' обязателен т.к мы будем изменять значение указателя s1");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n8. Вызываем функцию 'void push(&s1,12)' - добавляем в стек s1 значение 12 ...\n знак '&' обязателен т.к мы будем изменять значение указателя s1");
        break;}
case 8:{
        Ptext->SelStart=256;
        Ptext->SelLength=19;
        WindowFr->Picture->LoadFromFile("stack\\stack2.jpg");
        Rich->Lines->Add("\n9. Объявляем указатель на структуру 'stack' ");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n9. Объявляем указатель на структуру 'stack'");
        break;}
case 9:{
        Ptext->SelStart=278;
        Ptext->SelLength=44;
        WindowFr->Picture->LoadFromFile("stack\\stack2.jpg");
        Rich->Lines->Add("\n10. Выделяем память под новый элемент");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n10. Выделяем память под новый элемент");
        break;}
case 10:{
        Ptext->SelStart=324;
        Ptext->SelLength=21;
        WindowFr->Picture->LoadFromFile("stack\\stack3.jpg");
        Rich->Lines->Add("\n11. Присваиваем информационной части нового элемента значение, кторое мы передали функции (в этом случае 12)");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n11. Присваиваем информационной части нового элемента значение, кторое мы передали функции (в этом случае 12)");
        break;}
case 11:{
        Ptext->SelStart=349;
        Ptext->SelLength=19;
        WindowFr->Picture->LoadFromFile("stack\\stack4.jpg");
        Rich->Lines->Add("\n12. Связываем новый элемент со стеком, путем вставки его в начало стека");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n12. Связываем новый элемент со стеком, путем вставки его в начало стека");
        break;}
case 12:{
        Ptext->SelStart=372;
        Ptext->SelLength=13;
        WindowFr->Picture->LoadFromFile("stack\\stack5.jpg");
        Rich->Lines->Add("\n13. Меняем указатель 's' теперь он указывает на новое начало стека");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n13. Меняем указатель 's' теперь он указывает на новое начало стека");
        break;}
case 13:{
        Ptext->SelStart=807;
        Ptext->SelLength=48;
        WindowFr->Picture->LoadFromFile("stack\\stack6.jpg");
        Rich->Lines->Add("\n14. Вызываем простую функцию 'peek' которая возвращает значение 'info' по текущему указателю, если он не NULL, а если NULL, то возварщет 0 и error=1;");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n14. Вызываем простую функцию 'peek' которая возвращает значение 'info' по текущему указателю, если он не NULL, а если NULL, то возварщет 0 и error=1;");
        break;}
case 14:{
        Ptext->SelStart=859;
        Ptext->SelLength=14;
        WindowFr->Picture->LoadFromFile("stack\\stack6.jpg");
        Rich->Lines->Add("\n15. Вызываем функцию 'void push(&s1,13)' - добавляем в стек s1 значение 13 ...\n знак '&' обязателен т.к мы будем изменять значение указателя s1");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n15. Вызываем функцию 'void push(&s1,13)' - добавляем в стек s1 значение 13 ...\n знак '&' обязателен т.к мы будем изменять значение указателя s1");
        break;}
case 15:{
        Ptext->SelStart=930;
        Ptext->SelLength=15;
        WindowFr->Picture->LoadFromFile("stack\\stack7.jpg");
        Rich->Lines->Add("\n16. Вызываем функцию 'void push(&s1,14)' - добавляем в стек s1 значение 14 ...\n знак '&' обязателен т.к мы будем изменять значение указателя s1");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n16. Вызываем функцию 'void push(&s1,14)' - добавляем в стек s1 значение 14 ...\n знак '&' обязателен т.к мы будем изменять значение указателя s1");
        break;}
case 16:{
        Ptext->SelStart=1004;
        Ptext->SelLength=30;
        WindowFr->Picture->LoadFromFile("stack\\stack8.jpg");
        Rich->Lines->Add("\n17. Записываем в стек №2 значение из 1-го стека, удаляя это значение из 1-го стека\nрассмотрим функцию pop()");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n17. Записываем в стек №2 значение из 1-го стека, удаляя это значение из 1-го стека\nрассмотрим функцию pop()");
        break;}
case 17:{
        Ptext->SelStart=430;
        Ptext->SelLength=20;
        WindowFr->Picture->LoadFromFile("stack\\stack8.jpg");
        Rich->Lines->Add("\n18. Объявляем указатель на структуру 'stack' ");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n18. Объявляем указатель на структуру 'stack'");
        break;}
case 18:{
        Ptext->SelStart=454;
        Ptext->SelLength=17;
        WindowFr->Picture->LoadFromFile("stack\\stack8.jpg");
        Rich->Lines->Add("\n19. Объявляем переменную типа int для хранения значения");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n19. Объявляем переменную типа int для хранения значения");
        break;}
case 19:{
        Ptext->SelStart=473;
        Ptext->SelLength=37;
        WindowFr->Picture->LoadFromFile("stack\\stack8.jpg");
        Rich->Lines->Add("\n20. Если s не NULL, тогда old_info ,будет равено информационной части элемента, на который указывает s (в этом случае 14)");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n20. Если s не NULL, тогда old_info ,будет равено информационной части элемента, на который указывает s (в этом случае 14)");
        break;}
case 20:{
        Ptext->SelStart=513;
        Ptext->SelLength=45;
        WindowFr->Picture->LoadFromFile("stack\\stack8.jpg");
        Rich->Lines->Add("\n21. Если s не NULL, тогда s будет указывать на следующий элемент\n функция free освободит память по указателю old_item и return вернет значение old_info");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n21. Если s не NULL, тогда s будет указывать на следующий элемент\n функция free освободит память по указателю old_item и return вернет значение old_info");
        break;}
case 21:{
        Ptext->SelStart=564;
        Ptext->SelLength=19;
        WindowFr->Picture->LoadFromFile("stack\\stack9.jpg");
        Rich->Lines->Add("\n22. Если s = NULL, тогда error=1 и функция вернет 0");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n22. Если s = NULL, тогда error=1 и функция вернет 0");
        break;}
case 22:{
        Ptext->SelStart=1004;
        Ptext->SelLength=30;
        WindowFr->Picture->LoadFromFile("stack\\stack9.jpg");        Rich->Lines->Add("\n23. Добавляем это значение взятое из первого стека во второй");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n23. Добавляем это значение взятое из первого стека во второй");
        break;}
case 23:{
        Ptext->SelStart=1041;
        Ptext->SelLength=30;
        WindowFr->Picture->LoadFromFile("stack\\stack10.jpg");
        Rich->Lines->Add("\n24. Записываем в стек №2 значение из 1-го стека, удаляя это значение из 1-го стека\nрассмотрим функцию pop()");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n24. Записываем в стек №2 значение из 1-го стека, удаляя это значение из 1-го стека\nрассмотрим функцию pop()");
        break;}
case 24:{
        Ptext->SelStart=1078;
        Ptext->SelLength=30;
        WindowFr->Picture->LoadFromFile("stack\\stack11.jpg");
        Rich->Lines->Add("\n25. Записываем в стек №2 значение из 1-го стека, удаляя это значение из 1-го стека\nрассмотрим функцию pop()");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n25. Записываем в стек №2 значение из 1-го стека, удаляя это значение из 1-го стека\nрассмотрим функцию pop()");
        break;}
case 25:{
        Ptext->SelStart=1112;
        Ptext->SelLength=47;
        WindowFr->Picture->LoadFromFile("stack\\stack12.jpg");
        Rich->Lines->Add("\n26. Удаляем элемент из второго стека. На экране высветится число 14");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n26. Удаляем элемент из второго стека. На экране высветится число 14");
        break;}
case 26:{
        Ptext->SelStart=1163;
        Ptext->SelLength=47;
        WindowFr->Picture->LoadFromFile("stack\\stack13.jpg");
        Rich->Lines->Add("\n27. Удаляем элемент из второго стека. На экране высветится число 13");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n27. Удаляем элемент из второго стека. На экране высветится число 13");
        break;}
case 27:{
        Ptext->SelStart=1214;
        Ptext->SelLength=47;
        WindowFr->Picture->LoadFromFile("stack\\stack14.jpg");
        Rich->Lines->Add("\n28. Удаляем элемент из второго стека. На экране высветится число 12");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n28. Удаляем элемент из второго стека. На экране высветится число 12");
        break;}
case 28:{
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n28. Вот и все.");
        Rich->Lines->Add("\n28. Вот и все.");
        if (Application->MessageBoxA("Желаите посмотреть еще раз?","",MB_ICONQUESTION|MB_YESNO)==IDNO) Close();
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
        Comment->Lines->Add(" Эта простая программа показывает\nработу с очередью, для краткости рассмотрим только формирование очереди удаление из очереди, указатели q1 и q2 - это указатели на начало очереди 1 и 2 соответственно.");
        Rich->Lines->Add(" Эта простая программа показывает\nработу с очередью, для краткости рассмотрим только формирование очереди удаление из очереди, указатели q1 и q2 - это указатели на начало очереди 1 и 2 соответственно.");
        break;}
case 1:{
        Ptext->SelStart=88;
        Ptext->SelLength=41;
        Frame->Refresh();
        Rich->Lines->Add("\n1. Структура Queue в которой содержится информационная часть(число info типа int) и указатель на следующий элемент");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n1. Структура Queue в которой содержится информационная часть(число info типа int) и указатель на следующий элемент");
        break;}
case 2:{
        Ptext->SelStart=908;
        Ptext->SelLength=19;
        Frame->Refresh();
        WindowFr->Picture->LoadFromFile("queue\\queue1.jpg");
        Rich->Lines->Add("\n2. Задаем два указателя на начало очередей q1 и q2, которые указывают на NULL.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n2. Задаем два указателя на начало очередей q1 и q2, которые указывают на NULL.");
        break;}
case 3:{
        Ptext->SelStart=930;
        Ptext->SelLength=16;
        WindowFr->Picture->LoadFromFile("queue\\queue1.jpg");
        Rich->Lines->Add("\n3. Вызываем функцию 'void insert(&q1,12)' - добавляем в очередь q1 значение 12 ...\n знак '&' обязателен т.к мы будем изменять значение указателя q1!!!");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n3. Вызываем функцию 'void insert(&q1,12)' - добавляем в очередь q1 значение 12 ...\n знак '&' обязателен т.к мы будем изменять значение указателя q1!!!");
        break;}
case 4:{
        Ptext->SelStart=257;
        Ptext->SelLength=68;
        WindowFr->Picture->LoadFromFile("queue\\queue1.jpg");
        Rich->Lines->Add("\n4. Объявляем 3 указателя на структуру QUEUE:\n\n  current-текущий и присваиваем ему значение q (сейчас оно равно NULL, т.к списка нет, если бы он был, то он бы указывал на первый елемент  очереди)\n previous=0 - это указатель на последний элемент.\n new_node- это указатель на новый элемент.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n4. Объявляем 3 указателя на структуру QUEUE:\n\n  current-текущий и присваиваем ему значение q (сейчас оно равно NULL, т.к списка нет, если бы он был, то он бы указывал на первый елемент  очереди)\n previous=0 - это указатель на последний элемент.\n new_node- это указатель на новый элемент.");
        break;}
case 5:{
        Ptext->SelStart=325;
        Ptext->SelLength=79;
        WindowFr->Picture->LoadFromFile("queue\\queue1.jpg");
        Rich->Lines->Add("\n5. Пока текущий элемент не ноль последний присваивается текущему, а текущий идет дальше по очереди (current = current -> next;).");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n5. Пока текущий элемент не ноль последний присваивается текущему, а текущий идет дальше по очереди (current = current -> next;).");
        break;}
case 6:{
        Ptext->SelStart=404;
        Ptext->SelLength=78;
        WindowFr->Picture->LoadFromFile("queue\\queue2.jpg");
        Rich->Lines->Add("\n6. Выделяем память под новый элемент и присваиваем его информационной части число, переданное в функцию.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n6. Выделяем память под новый элемент и присваиваем его информационной части число, переданное в функцию.");
        break;}
case 7:{
        Ptext->SelStart=484;
        Ptext->SelLength=95;
        WindowFr->Picture->LoadFromFile("queue\\queue2.jpg");
        Rich->Lines->Add("\n7. Вставка в конец очереди. Если последний элемент указавает не на NULL, тогда следующий элемент у нового будет указывать на следующий последнего, а после этого, следующий элемент у бывшего последнего (он уже предпоследний) будет указывать на новый элемент. PS. Можно заметить, что previos->next всегда NULL и записать: \nprevios->next=current;\n current->next=NULL;");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n7. Вставка в конец очереди. Если последний элемент указавает не на NULL, тогда следующий элемент у нового будет указывать на следующий последнего, а после этого, следующий элемент у бывшего последнего (он уже предпоследний) будет указывать на новый элемент. PS. Можно заметить, что previos->next всегда NULL и записать: \nprevios->next=current;\n current->next=NULL;");
        break;}
case 8:{
        Ptext->SelStart=579;
        Ptext->SelLength=55;
        WindowFr->Picture->LoadFromFile("queue\\queue3.jpg");
        Rich->Lines->Add("\n8. Вставка первого элемента. Если последний элемент указавает на NULL, то q(указатель на начало очереди) будет указывать на новый элемент, а следующий будет NULL.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n8. Вставка первого элемента. Если последний элемент указавает на NULL, то q(указатель на начало очереди) будет указывать на новый элемент, а следующий будет NULL.");
        break;}
case 9:{
        Ptext->SelStart=948;
        Ptext->SelLength=19;
        WindowFr->Picture->LoadFromFile("queue\\queue3.jpg");
        Rich->Lines->Add("\n9. Вставка в очередь нового элемента.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n9. Вставка в очередь нового элемента.");
        break;}
case 10:{
        Ptext->SelStart=484;
        Ptext->SelLength=59;
        WindowFr->Picture->LoadFromFile("queue\\queue4.jpg");
        Rich->Lines->Add("\n10. Выделив память под новый элемент, задаем что указатель на следующий равен previous->next (т.е NULL).");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n10. Выделив память под новый элемент, задаем что указатель на следующий равен previous->next (т.е NULL).");
        break;}
case 11:{
        Ptext->SelStart=543;
        Ptext->SelLength=31;
        WindowFr->Picture->LoadFromFile("queue\\queue5.jpg");
        Rich->Lines->Add("\n11. Связываем новый элемент с очередью.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n11. Связываем новый элемент с очередью.");
        break;}
case 12:{
        Ptext->SelStart=967;
        Ptext->SelLength=17;
        WindowFr->Picture->LoadFromFile("queue\\queue6.jpg");
        Rich->Lines->Add("\n12. Вставка в очередь нового элемента");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n12. Вставка в очередь нового элемента");
        break;}
case 13:{
        Ptext->SelStart=987;
        Ptext->SelLength=39;
        WindowFr->Picture->LoadFromFile("queue\\queue6.jpg");
        Rich->Lines->Add("\n13. Вставка во вторую очередь нового элемента с изъятием элемента из первой очереди.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n13. Вставка во вторую очередь нового элемента с изъятием элемента из первой очереди.");
        break;}
case 14:{
        Ptext->SelStart=682;
        Ptext->SelLength=45;
        WindowFr->Picture->LoadFromFile("queue\\queue6.jpg");
        Rich->Lines->Add("\n14. Функция 'int take_out(QUEUE  **q, int *error )':\n Объявляем переменную value в кторой будет храниться возвращаемое значение удаляемого элемента, и  указатель на этот элемент указывающий на начало очереди.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n14. Функция 'int take_out(QUEUE  **q, int *error )':\n Объявляем переменную value в кторой будет храниться возвращаемое значение удаляемого элемента, и  указатель на этот элемент указывающий на начало очереди.");
        break;}
case 15:{
        Ptext->SelStart=727;
        Ptext->SelLength=43;
        WindowFr->Picture->LoadFromFile("queue\\queue6.jpg");
        Rich->Lines->Add("\n15. Если очередь существует (q!=NULL), то переменной value присваивается значение удаляемого элемента");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n15. Если очередь существует (q!=NULL), то переменной value присваивается значение удаляемого элемента");
        break;}
case 16:{
        Ptext->SelStart=772;
        Ptext->SelLength=18;
        WindowFr->Picture->LoadFromFile("queue\\queue7.jpg");
        Rich->Lines->Add("\n16. Смещаем начало очереди на один элемент вперед.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n16. Смещаем начало очереди на один элемент вперед.");
        break;}
case 17:{
        Ptext->SelStart=792;
        Ptext->SelLength=38;
        WindowFr->Picture->LoadFromFile("queue\\queue8.jpg");
        Rich->Lines->Add("\n17. Удаляем элемент old_header из очереди, и присваиваем переменной error значение 0 (т.е ошибок нет).");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n17. Удаляем элемент old_header из очереди, и присваиваем переменной error значение 0 (т.е ошибок нет).");
        break;}
case 18:{
        Ptext->SelStart=835;
        Ptext->SelLength=22;
        WindowFr->Picture->LoadFromFile("queue\\queue8.jpg");
        Rich->Lines->Add("\n18. А если очереди нет (q=NULL), то переменной error присваиваем единицу собщая об ощибке.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n18. А если очереди нет (q=NULL), то переменной error присваиваем единицу собщая об ощибке.");
        break;}
case 19:{
        Ptext->SelStart=857;
        Ptext->SelLength=17;
        WindowFr->Picture->LoadFromFile("queue\\queue9.jpg");
        Rich->Lines->Add("\n19. Возвращаем значение удаленного элемента, или 0 при наличии ошибки.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n19. Возвращаем значение удаленного элемента, или 0 при наличии ошибки.");
        break;}
case 20:{
        Ptext->SelStart=1027;
        Ptext->SelLength=39;
        WindowFr->Picture->LoadFromFile("queue\\queue10.jpg");
        Rich->Lines->Add("\n20. Вставка во вторую очередь нового элемента с изъятием элемента из первой очереди.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n20. Вставка во вторую очередь нового элемента с изъятием элемента из первой очереди.");
        break;}
case 21:{
        Ptext->SelStart=1067;
        Ptext->SelLength=39;
        WindowFr->Picture->LoadFromFile("queue\\queue11.jpg");
        Rich->Lines->Add("\n21. Вставка во вторую очередь нового элемента с изъятием элемента из первой очереди.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n21. Вставка во вторую очередь нового элемента с изъятием элемента из первой очереди.");
        break;}
case 22:{
        Ptext->SelStart=1106;
        Ptext->SelLength=57;
        WindowFr->Picture->LoadFromFile("queue\\queue12.jpg");
        Rich->Lines->Add("\n22. Удаление элемента из второй очереди и вывод его значения на экран. На экране будет число 12.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n22. Удаление элемента из второй очереди и вывод его значения на экран. На экране будет число 12.");
        break;}
case 23:{
        Ptext->SelStart=1163;
        Ptext->SelLength=57;
        WindowFr->Picture->LoadFromFile("queue\\queue13.jpg");
        Rich->Lines->Add("\n23. Удаление элемента из второй очереди и вывод его значения на экран. На экране будет число 13.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n23. Удаление элемента из второй очереди и вывод его значения на экран. На экране будет число 13.");
        break;}
case 24:{
        Ptext->SelStart=1220;
        Ptext->SelLength=57;
        WindowFr->Picture->LoadFromFile("queue\\queue14.jpg");
        Rich->Lines->Add("\n24. Удаление элемента из второй очереди и вывод его значения на экран. На экране будет число 14.");
        Comment->Lines->Clear();
        Comment->Lines->Add("\n24. Удаление элемента из второй очереди и вывод его значения на экран. На экране будет число 14.");
        break;}
case 25:{
        WindowFr->Picture=NULL;
        Comment->Lines->Clear();
        Comment->Lines->Add("\n25. Вот и все.");
        Rich->Lines->Add("\n25. Вот и все.");
        if (Application->MessageBoxA("Желаите посмотреть еще раз?","",MB_ICONQUESTION|MB_YESNO)==IDNO) Close();
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

