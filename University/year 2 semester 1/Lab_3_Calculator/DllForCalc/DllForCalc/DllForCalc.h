#pragma once

#ifdef DLLFORCALC_EXPORTS
#define DLLFORCALC_API __declspec(dllexport)
#else
#define DLLFORCALC_API __declspec(dllimport)
#endif


extern "C" DLLFORCALC_API double Calculate(char mode, double str_main, double str_res);
extern "C" DLLFORCALC_API bool TextBoxCheck(char* str);