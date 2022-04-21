#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double x, y;
    cout << "Лабораторная работа №4 вариант 23 \n"
            "Выполнил: Харин Алексей \n"
            "Введите x : ";
    cin >> x;
    if (x <= -5.1)
        y = 1.5 * sin(sqrt(pow(fabs(x), 3))) + pow(fabs(x + 0.5), 1 / 3);
    else if (-5.1 <= x && x <= 0)
        y = 2;
    else if (0 < x && x <= 3.4)
        y = (log(x)/log(1.5)) / pow(2, x);
    else
        y = 5.25;
    cout << "Результат: " << y << endl;
    system("pause");
    return 0;
}