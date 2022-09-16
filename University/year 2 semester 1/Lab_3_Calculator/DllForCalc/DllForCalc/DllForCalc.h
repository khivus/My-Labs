#pragma once

#ifdef DLLFORCALC_EXPORTS
#define DLLFORCALC_API __declspec(dllexport)
#else
#define DLLFORCALC_API __declspec(dllimport)
#endif


extern "C" DLLFORCALC_API char* Calculate(int mode, char* str_main, char* str_res, char sign);