#pragma once
#pragma warning(disable:4996)
#include <iostream>
//#using <System.dll>
//#using <system.drawing.dll>
//#using <system.windows.forms.dll>
//using namespace System;
//using namespace System::Drawing;
//using namespace System::Windows::Forms;
#ifndef	 _MYDLLH
#define  _MYDLLH
#ifdef  MYDLL_EXPORTS
#define MYDLL_API __declspec(dllexport) 
#else
#define MYDLL_API __declspec(dllimport)
#endif
extern "C" MYDLL_API int VowelCount(char* s);
extern "C" MYDLL_API char* Code_Dec(std::string s);
//extern "C" void __clrcall DoBoldFont(TextBox^ txt);
#endif
