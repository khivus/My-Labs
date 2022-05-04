// Functions file. It keeps functions

#include <math.h> // includes for functions
#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

double input_accuracy() { // input function
    string accuracy;
    string chars = "abcdfghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; // chars check for input // symbol 'e' didn't there because you can print like "1e-5"
    double acc;
    unsigned int i, j;

    do {
        cout << "Input accuracy (default = 0.00001) (0 < accuracy < 1): ";
        getline(cin, accuracy);

        bool char_check = false;
        for (i = 0; i < accuracy.length(); i++) { // input check for chars
            for (j = 0; j < chars.length(); j++) {
                if (accuracy[i] == chars[j]) {
                    char_check = true;
                }
            }
        }

        acc = atof(accuracy.c_str()); // convert to double
        if (acc == NULL) {
            acc = 0.00001;
        }
        if (char_check) { // if chars was used
            cout << "Wrong input! Used default value.\n";
        }
        else if (acc < 0 || acc > 1) {
            cout << "Wrong input!\n";
        }
    } while (acc < 0 || acc > 1);
    cout << "You printed: " << acc << "\n\n";
    return acc;
}

void oc_file() { // file creation check function (open/close file)
    fstream file;
    file.open("results.txt", fstream::app);
    if (!file.is_open()) {
        file.open("results.txt", fstream::trunc);
    }
    file.close();
}

void write_in_file(double res, int n, double accuracy) { // input in file
    oc_file(); // file existing check
    fstream file;
    file.open("results.txt", fstream::out | fstream::app);
    file << "Result with accuracy = " << accuracy << " is: x(" << n << ") = " << res << endl;
    file.close();
}

void read_from_file() { // output in console from file
    oc_file(); // file existing check
    string line;
    fstream file;
    file.open("results.txt", fstream::in | fstream::app);
    while (getline(file, line)) {
        cout << line << endl; // simple one by one output lines
    }
    file.close();
}

void menu_output() { // menu print function
    cout << "=========================\n"
        "Menu: \n"
        "[1] Input\n"
        "[2] Solution by recursion\n"
        "[3] Verification\n"
        "[4] Output from file\n"
        "[5] About program\n"
        "[6] Help\n"
        "[7] Exit\n"
        "=========================\n\n";
}

int menu() { // console clear and menu manager
    int point;
    while (!_kbhit()); // waits for input
    point = _getch() - 48;
    system("cls"); // clears the console
    menu_output();
    return point;
}