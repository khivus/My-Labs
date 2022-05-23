/* Error handler
* v.1.01
* 2022
* Aleksey Kharin
* Variant 9
* C = (- b ^ 2 - 3 * b + 8) / (- a ^ 2 + 4 * a + 7) */

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
        cout << "Input A = ";
        cin >> A;
        cout << "Input B = ";
        cin >> B;
        if (A == 5.3166 || A == -1.3166)    throw 2;
        C = (-pow(B, 2) - 3 * B + 8) / (-pow(A, 2) + 4 * A + 7);
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