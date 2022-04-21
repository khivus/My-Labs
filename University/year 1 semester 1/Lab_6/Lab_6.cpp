#include <iostream>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <typeinfo>
using namespace std;

void arrprint(double x[], int n);

int main()
{
    setlocale(LC_ALL, "Russian");
    srand((unsigned) time(0));
    /* Variables */
    double x[50], mult = 1, z;
    int n, i;
    char gen;
    cout << "Лабортаторная работа №6, вариант 23\n"
            "Выполнил: Харин Алексей\n"
            "Введите количество элементов массива 0 < n <= 50: ";
    cin >> n;
    if (!(n > 0 && n <= 50)) {
        cout << "Wrong input!\n";
        exit(EXIT_FAILURE);
    }
    cout << "Сгенерировать массив? Y/N\n";
    cin >> gen;
    if (gen == 'Y') { //Генерируем массив
        for (i = 0; i < n; i++) {
            x[i] = rand() - rand();
        }
        cout << "Сгенерированный массив: [";
        arrprint(x, n);
        cout << "]\n";
    }
    else if (gen == 'N') { //Вводим массив вручную
        cout << "Введите массив с количество элементов " << n << ": " << endl;
        for (i = 0; i < n; i++) {
            cout << "x [ " << i + 1 << " ] = ";
            cin >> x[i];
        }
    }
    else { //Если ввод неправильный
        cout << "Пожалуйста, перезапустите программу и введите Y или N\n";
        system("pause");
        return 0;
    }
    cout << "Введите заданное значение z = ";
    cin >> z;
    if (strcmp(typeid(z).name(), "double") == 1) { 
        cout << "Wrong input type!\n";
        exit(EXIT_FAILURE); 
    }
    for (i = 0; i < n; i++) {
        if (x[i] > 0) { //Произведение положительных элементов
            mult *= x[i];
        }
        if (i%2 != 0) { //Каждый второй элемент умножить на z
            x[i] *= z;
        }
    }
    cout << "Произведение положительных элементов: " << mult << endl <<
            "Массив: [";
    arrprint(x, n);
    cout << "]\n";
    system("pause");
    return 0;
}

void arrprint(double x[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << x[i];
            break;
        }
        cout << x[i] << ", ";
    }
}