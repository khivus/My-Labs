#pragma once
#pragma warning(disable:4996)
#include <iostream>

#ifndef	 _MYDLLH
#define  _MYDLLH
#ifdef  MYDLL_EXPORTS
#define MYDLL_API __declspec(dllexport) 
#else
#define MYDLL_API __declspec(dllimport)
#endif

extern "C" MYDLL_API int VowelCount(char* s);
extern "C" MYDLL_API int RadioButtonSelection(int mode);

#endif
