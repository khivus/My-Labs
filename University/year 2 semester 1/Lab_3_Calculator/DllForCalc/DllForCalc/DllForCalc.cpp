#include "pch.h"
#include "DllForCalc.h"
#include <string>


using namespace std;

bool TextBoxCheck(char* str) {
	string txt = str;
	string nums = "0123456789.-eE+";
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

double calculate(double num1, double num2, char sign) {
	double num = 0;
	switch (sign)
	{
	case '+':
		num = num1 + num2;
		break;
	case '-':
		num = num1 - num2;
		break;
	case '*':
		num = num1 * num2;
		break;
	case '/':
		num = num1 / num2;
		break;
	case 's':
		num = sin(num1);
		break;
	case 'c':
		num = cos(num1);
		break;
	case 't':
		num = tan(num1);
		break;
	case 'q':
		num = num1 * num1;
		break;
	case 'r':
		num = sqrt(num1);
		break;
	default:
		break;
	}
	return num;
}