// Error handler
// v1.0.3
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

int main() {
    double A, B, C;
    cin.exceptions(istream::failbit | istream::badbit);
    try {
        cout << "Input A (-1e100 < A < 1e100) = ";
        cin >> A;
        cout << "You printed: " << A << endl;
        cout << "Input B (-1e100 < A < 1e100) = ";
        cin >> B;
        cout << "You printed: " << B << endl;
        C = (-B * B - 3 * B + 8) / (-A * A + 4 * A + 7);
        if (A == 5.3166 || A == -1.3166)  throw 2;
        if (C == INFINITY)                throw 3;
        if (A < -1e100 || B < -1e100)     throw 4;
        if (A > 1e100 || B > 1e100)       throw 5;
    }
    catch (istream::failure e) {
        cerr << "Wrong input!\n";
        cout << "Press any key to continue...";
        while (!_kbhit());
        return 1;
    }
    catch (int a) {
        cout << "Error " << a << ": ";
        switch (a) {
        case 2:
            cout << "Division by zero!\n";
            break;
        case 3:
            cout << "Overflow!\n";
            break;
        case 4:
            cout << "Input is too small!\n";
            break;
        case 5:
            cout << "Input is too big!\n";
            break;
        }
        cout << "Press any key to continue...";
        while (!_kbhit());
        return a;
    }
    cout << "C = " << C << endl;
    cout << "No exceptions found!\nPress any key to continue...";
    while (!_kbhit());
    return 0;
}