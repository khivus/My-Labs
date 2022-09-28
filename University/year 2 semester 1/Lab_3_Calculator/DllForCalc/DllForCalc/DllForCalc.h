#pragma once

#ifdef DLLFORCALC_EXPORTS
#define DLLFORCALC_API __declspec(dllexport)
#else
#define DLLFORCALC_API __declspec(dllimport)
#endif

extern "C" DLLFORCALC_API bool TextBoxCheck(char* str);

extern "C" DLLFORCALC_API double calculate(double num1, double num2, char sign);