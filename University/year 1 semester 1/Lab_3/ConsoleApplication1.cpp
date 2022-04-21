#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    float a, b, x, result;
    cout << "Лабораторная работа №3. Вариант 23 \nВыполнил: Харин Алексей\n";
    cout << "Введите a, b, x\na = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "x = ";
    cin >> x;
    cout << "Введены переменные: а=" << a << " b=" << b << " x=" << x;
    result = pow( fabs( sin(x) * cos( 2 * x ) ), 1 / a) + sqrt(abs(b + x));
    cout << "\nРезультат = " << result << "\n";
    system("pause");
    return 0;
}

