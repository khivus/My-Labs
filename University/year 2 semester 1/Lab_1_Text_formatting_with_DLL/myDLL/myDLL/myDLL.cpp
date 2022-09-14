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
    char vowels[] = "aeyuioAEYUIOóåûàîıÿèşÓÅÀÎİßÈŞÛ";
    while (s[i] != '\0') {
        for (unsigned int j = 0; j < strlen(vowels); j++) {
            if (s[i] == vowels[j])
                counter++;
        }
        i++;
    }
    return counter;
}

int RadioButtonSelection(int mode) {
    switch (mode) {
    case 1:
        return 1;
        break;
    case 2:
        return 2;
        break;
    case 3:
        return 3;
        break;
    default:
        return 4;
        break;
    }
}

