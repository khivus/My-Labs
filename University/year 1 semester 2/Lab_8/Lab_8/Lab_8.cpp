// Pointers to functions
// Version 1.0.0
// 2022
// Kharin Aleksey
// Variant 14: Sum = 1 / i^2 and Sum = -2^i / i!

#include <iostream>
#include <conio.h>
#include <string>
#include <math.h>

using namespace std;

int n;

double factorial(int num) {
    double sum = 1;
    for (int i = 1; i < num; i++) {
        sum *= i;
    }
    return sum;
}

double func_1(void) {
    double sum = 0;
    for (int i = 1; i < n; i++) {
        sum += 1 / ((double)i * i);
    }
    return sum;
}

double func_2(void) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(-2, i) / factorial(i);
    }
    return sum;
}

double (*menu(void))(void) {
    int choice;
    double (*menu_items[])() = { func_1, func_2 };

    cout << "Pick the menu item  (1 or 2): ";
    cin >> choice;
    cout << "You printed: " << choice << endl;

    if (choice < 3 && choice > 0) {
        return menu_items[choice - 1];
    }
    else {
        return NULL;
    }
}

int main() {
    string get;
    char c_exit;
    double (*point)(void);
    double go;

    do {
        do {
            cout << "Input n (0 < n < " << INT_MAX << "): ";
            cin >> get;
            cout << "You printed: " << get << endl;
            n = atoi(get.c_str());
        } while (n <= 0 || n >= INT_MAX);

        point = menu();

        if (point == NULL) {
            cout << "Wrong input!\n";
        }
        else {
            go = (*point)();
            cout << "Answer is: " << go;
        }

        cout << "\nDo you want to quit? [Y/n]: ";
        cin >> c_exit;
        cout << endl;
    } while (c_exit == 'n');

    cout << "Press any key to continue...";
    while (!_kbhit());

    return 0;
}