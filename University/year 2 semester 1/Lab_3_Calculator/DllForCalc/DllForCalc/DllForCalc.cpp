#include "pch.h"
#include "DllForCalc.h"
#include <string>


using namespace std;

bool TextBoxCheck(char* str) {
	string txt = str;
	string nums = "0123456789.-";
	bool check = true;
	bool tmp_check;
	for (unsigned int i = 0; i < txt.length(); i++) {
		tmp_check = false;
		for (unsigned int j = 0; j < nums.length(); j++) {
			if (txt[i] == nums[j]) {
				tmp_check = true;
			}
		}
		if (!tmp_check) {
			check = false;
		}
	}
	return check;
}

const char* dtoa(double x) {
	string yy = to_string(x);
	const char* y = yy.c_str();
	//char bruh = *y;
	//int fullx = x;
	//int nfullx = (double)((x * 100000) - (fullx * 100000));
	//char y[20];
	//y = fullx + '.' + nfullx;
	return y;
}

char* Calculate(int mode, char* str_main, char* str_res, char sign) {
	char str[20];
	double num_main, num_res, num;
	bool flag = false;
	try {
		if (!TextBoxCheck(str_main) || !TextBoxCheck(str_res)) throw 0; // Letters in TextBox
		if (strlen(str_main) > 20 || strlen(str_res) > 20) throw 1; // Overflow
		else {
			num_main = atof(str_main);
			num_res = atof(str_res);
		}
		switch (mode) {
		case 0: // =
			// num = num_main sign num_res
			break;
		case 1: // +
			num = num_res + num_main;
			break;
		case 2: // -
			num = num_res - num_main;
			break;
		case 3: // *
			num = num_res * num_main;
			break;
		case 4: // /
			if (num_main == 0) throw 2;
			num = num_res / num_main;
			break;
		case 5: // sin
			num = sin(num_main);
			break;
		case 6: // cos
			num = cos(num_main);
			break;
		case 7: // tan
			num = tan(num_main);
			break;
		case 8: // ^2
			num = num_main * num_main;
			break;
		case 9: // ^1/2
			if (num_main < 0) throw 3;
			num = sqrt(num_main);
			break;
		default:
			break;
		}
	}
	catch (...) {
		strcpy_s(str, "Wrong input");
		flag = true;
	}
	if (!flag) {
		strcpy_s(str, dtoa(num));
	}
	return str;
}