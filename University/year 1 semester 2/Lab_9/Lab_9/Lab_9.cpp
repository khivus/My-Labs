// Error handler
// v1.1.0
// 2022
// Aleksey Kharin
// Variant 9
// C = (- b ^ 2 - 3 * b + 8) / (- a ^ 2 + 4 * a + 7) 

#include <conio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>

using namespace std;

bool check(string a) {
    bool mark, mark1 = false;
    string symb = "0123456789.e";

    for (int i = 0; i < a.length(); i++) {
        mark = false;
        for (int j = 0; j < symb.length(); j++) {
            if (a[i] == symb[j]) {
                mark = true;
            }
        }
        if (!mark)  mark1 = true;
    }
    return mark1;
}

int main() {
    string a, b;
    double A, B, C;
    char c_exit;
    bool w_exceptions;
    int error;

    do {
        w_exceptions = false;

        cout << "Input A (-1e100 < A < 1e100) = ";
        cin >> a;
        cout << "You printed: " << a << endl;
        cout << "Input B (-1e100 < A < 1e100) = ";
        cin >> b;
        cout << "You printed: " << b << endl;
    
        try {
            if (check(a) || check(b))   throw 2;
            else {
                A = atof(a.c_str());
                B = atof(b.c_str());

                if (A == 5.3166 || A == -1.3166)  throw 3;
                if (A < -1e100 || B < -1e100)     throw 4;
                if (A > 1e100 || B > 1e100)       throw 5;

                C = (-B * B - 3 * B + 8) / (-A * A + 4 * A + 7);
                
                if (C == INFINITY)                throw 6;
            }
        }
        catch (int a) {
            cout << "Error " << a << ": ";
            switch (a) {
            case 2:
                cout << "Wrong input!\n";
                break;
            case 3:
                cout << "Division by zero!\n";
                break;
            case 4:
                cout << "Input is too small!\n";
                break;
            case 5:
                cout << "Input is too big!\n";
                break;
            case 6:
                cout << "Overflow!\n";
                break;
            }
            
            w_exceptions = true;
            error = a;
        }
        if (!w_exceptions) {
            cout << "C = " << C << endl;
            cout << "No exceptions found!\n";
            error = 0;
        }
        cout << "Do you want to quit? [Y/n]: ";
        cin >> c_exit;
        cout << endl;
    } while (c_exit == 'n');

    cout << "Press any key to continue...";
    while (!_kbhit());

    return error;
}