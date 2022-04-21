//Functions file. It keeps functions

#include <math.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

//struct result_struct {
//    double res; //result
//    int n; //number of interations
//};

float input_accuracy() { //Input function
    string accuracy;
    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    float acc;
    unsigned int i, j;

    do {
        cout << "Input accuracy (default = 0.00001) (0 < accuracy < 32767): ";
        getline(cin, accuracy);

        bool char_check = false;
        for (i = 0; i < accuracy.length(); i++) {
            for (j = 0; j < chars.length(); j++) {
                if (accuracy[i] == chars[j]) {
                    char_check = true;
                }
            }
        }
        if (char_check) {
            cout << "Wrong input! Used default value.\n";
        }

        acc = atof(accuracy.c_str());
        if (acc == NULL) {
            acc = 0.00001;
        }
        if (acc < 0 || acc > 32767) {
            cout << "Wrong input!\n";
        }
    } while (acc < 0 || acc > 32767);
    cout << "You printed: " << acc << "\n\n";
    return acc;
}

//result_struct solution(double accuracy) { //Solution function
//    static double x_prev;
//    static double x_next;
//    static double n = 1;
//
//    result_struct recursive;
//
//    if (n == 1) {
//        x_prev = 1;
//    }
//
//    x_next = (2 - pow(x_prev, 3)) / 5;
//
//    if (abs(x_next - x_prev) < accuracy) {
//        recursive.res = x_next;
//        recursive.n = n;
//        n = 1;
//        return recursive;
//    }
//    else {
//        x_prev = x_next;
//        n++;
//        solution(accuracy); //recursion
//    }
//}
//
//result_struct verification(double accuracy) { //verification function
//    double x_prev = 1;
//    double x_next = 0;
//    int n = 0;
//
//    result_struct ver_res;
//
//    do {
//        n++;
//        if (n != 1) x_prev = x_next;
//        x_next = (2 - pow(x_prev, 3)) / 5;
//    } while (abs(x_next - x_prev) >= accuracy);
//
//    ver_res.res = x_next;
//    ver_res.n = n;
//    return ver_res;
//}

void oc_file() { //file creation check
    fstream file;
    file.open("results.txt", fstream::app);
    if (!file.is_open()) {
        file.open("results.txt", fstream::trunc);
    }
    file.close();
}

void write_in_file(double res, int n, float accuracy) { //input in file
    oc_file();
    fstream file;
    file.open("results.txt", fstream::out | fstream::app);
    file << "Result with accuracy = " << accuracy << " is: x(" << n << ") = " << res << endl;
    file.close();
}

void read_from_file() { //output in console from file
    oc_file();
    string line;
    fstream file;
    file.open("results.txt", fstream::in | fstream::app);
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void menu_output() { //menu print function
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

int menu() { //console clear and menu manager
    int point;
    while (!_kbhit());
    point = _getch() - 48;
    system("cls"); //clears the console
    menu_output();
    return point;
}