#include <iostream>
#include <locale.h>
#include <math.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double x, n, s = 0, i;
	cout << "Лабортаторная работа №5, вариант 23\n"
			"Выполнил: Харин Алексей\n"
			"Введите n > 0: ";
	cin >> n;
	cout << "Введите x: ";
	cin >> x;
	s = x;
	for (i = 1; i <= n; i++) {
		s += pow(-1, n) * pow(x, 2 * n + 1) / (2 * n + 1);
	}
	cout << "Результат: " << s << endl;
	system("pause");
	return 0;
}