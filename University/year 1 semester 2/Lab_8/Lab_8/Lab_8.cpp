// Pointers to functions
// Version 1.1.0
// 2022
// Kharin Aleksey
// Variant 14: Sum = 1 / i^2 and Sum = -2^i / i!

#include <iostream>
#include <conio.h>
#include <string>
#include <math.h>

using namespace std;

double func_1(int i, int n) {
    double ans;
    if (i > 0) {
        ans = 1 / ((double)i * i);
    }
    else {
        ans = 0;
    }
    return ans;
}

double func_2(int i, int n) {
    double ans;
    static double power = 1;
    static int factor = 1;

        if (i == 0) {
            ans = 1;
        }
        else {
            power *= -2;
            factor *= i;
            ans = power / factor;
            if (i == n - 1) {
                power = 1;
                factor = 1;
            }
        }

    return ans;
}

double fsum(double (*point)(int, int), int n) {
    double answer = 0;
    for (int i = 0; i < n; i++) {
        answer += (*point)(i, n);
    }
    return answer;
}

double (*menu(void))(int, int) {
    int choice;
    double (*menu_items[])(int, int) = { func_1, func_2 };

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
    double (*point)(int, int);
    double go;
    int n;

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
            go = fsum(point, n);
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