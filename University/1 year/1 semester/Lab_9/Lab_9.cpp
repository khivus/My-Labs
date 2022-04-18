//String manager v2 2021 Aleksey Kharin
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstring>
#include <locale.h>

using namespace std;

bool vowel(char a) {
	char point[] = { 'а','ы','у','о','е','э','я','и','ю','А','Ы','У','О','Е','Э','Я','И','Ю','a','e','i','o','u','y','A','E','I','O','U','Y' };
	for (unsigned i = 0; i < strlen(point); i++) {
		if ((a == point[i]))  return true;
	}
	return false;
}

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	cout << " Лабораторная работа №9 вариант 23\n"
		" Выполнил: Харин Алексей\n";
	
	char str[256], word[32];
	int i;

	cout << " Введите строчку:\n >";
	cin.getline(str, sizeof(str));
	
	cout << " Введите заданное слово: ";
	cin.getline(word, sizeof(word));

	size_t n = 0;
	size_t len = strlen(word);

	for (const char* src = str; (src = strstr(src, word)) != nullptr; src += len) {
		n++;
	}
	cout << " Заданное слово встречается " << n << " раз в тексте\n";

	for (i = strlen(str); i >= 0; i--) {
		if (((str[i - 1] == ' ' || str[i - 1] == '\0' || str[i - 1] == '\n' || str[i - 1] == '\t') && vowel(str[i]) == true) || (vowel(str[i]) == true && i == 0)) {
			cout << " ";
			while (str[i] != ' ' && str[i] != '\0' && str[i] != '\n' && str[i] != '\t') {
				cout << str[i];
				i++;
			}
			cout << endl;
			break;
		}
		else if (i == 0 && vowel(str[i]) == false) cout << " В тексте нет слов начинающихся на гласную букву\n";
	}
	return 0;
}