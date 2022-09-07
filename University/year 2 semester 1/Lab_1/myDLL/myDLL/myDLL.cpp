#include "pch.h"
#include "MyDLL.h"
#include <iostream>
#include <cstdio>

//#using <System.dll>
//#using <system.drawing.dll>
//#using <system.windows.forms.dll>
//using namespace System;
//using namespace System::Drawing;
//using namespace System::Windows::Forms;

using namespace std;

int VowelCount(char* s) {
    int i = 0, counter = 0;
    char vowels[] = "aeyuioAEYUIO¸óåàîıÿèşû¨ÓÅÀÎİßÈŞÛ";
    while (s[i] != '\0') {
        for (unsigned int j = 0; j < strlen(vowels); j++) {
            if (s[i] == vowels[j])
                counter++;
        }
        i++;
    }
    return counter;
}

//char* Code_Dec(string s) {
//    char* ch = new char[s.length() + 1];
//    strcpy(ch, s.c_str());
//    sprintf(ch, "\x1b[32m%s", ch);
//    return ch;
//    delete[] ch;
//}

// void DoBoldFont(TextBox^ txt) {
//    System::Drawing::Font^ bold_font;
//    bold_font = gcnew System::Drawing::Font(txt->Font->FontFamily, txt->Font->Size, System::Drawing::FontStyle::Bold);
//    txt->Font = bold_font;
//}
