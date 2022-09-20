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

double Calculate(char mode, double num_main, double num_res) {
	double num = 0;
	switch (mode) {
	case '+':
		num = num_res + num_main;
		break;
	case '-':
		num = num_res - num_main;
		break;
	case '*':
		num = num_res * num_main;
		break;
	case '/':
		num = num_res / num_main;
		break;
	case 's': // sin
		num = sin(num_main);
		break;
	case 'c': // cos
		num = cos(num_main);
		break;
	case 't': // tan
		num = tan(num_main);
		break;
	case 'q': // ^2
		num = num_main * num_main;
		break;
	case 'r': // ^1/2
		num = sqrt(num_main);
		break;
	default:
		break;
	}
	return num;
}