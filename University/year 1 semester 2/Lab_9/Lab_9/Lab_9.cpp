#include <conio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>

using namespace std;

bool check(string a) {
    bool mark, mark1 = false;
    string symb = "0123456789.e";

    for (unsigned int i = 0; i < a.length(); i++) {
        mark = false;
        for (unsigned int j = 0; j < symb.length(); j++) {
            if (a[i] == symb[j]) {
                mark = true;
            }
        }
        if (!mark)  mark1 = true;
    }
    return mark1;
}

int main() {
    string A, B;
    double a, b;
    double c;

    cout << "a = ";
    cin >> A;
    cout << "b = ";
    cin >> B;

    try {
        if (A == "5.3166" || A ==  "- 1.3166")    throw 500;
        if (check(A) || check(B))   throw 501;
        else {
            a = atof(A.c_str());
            b = atof(B.c_str());
            c = (-pow(b, 2) - 3 * b + 8) / (-pow(a, 2) + 4 * a + 7);
        }
    }
    catch (int a) {
        cout << "Error " << a << ": ";
        switch (a) {
        case 500:
            cout << "division by zero!\n";
            break;
        case 501:
            cout << "wrong input!\n";
            break;
        }
        cout << "Press any key to continue...";
        while (!_kbhit());
        return 1;
    }
    cout << "c = " << c << endl;
    cout << "No exceptions found!\nPress any key to continue...";
    while (!_kbhit());
    return 0;
}