//Functions file. It keeps functions

#include <math.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

/*struct result_struct {
    double res; //result
    int n; //number of interations
};*/

float input_accuracy() { //Input function
    string accuracy;
    float acc;
    do {
        cout << "Input accuracy (default = 0.00001) (0 < num < 32767): ";
        getline(cin, accuracy);
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

/*result_struct solution(double accuracy) { //Solution function
    static double x_prev;
    static double x_next;
    static double n = 1;

    result_struct recursive;

    if (n == 1) {
        x_prev = 1;
    }

    x_next = (2 - pow(x_prev, 3)) / 5;

    if (abs(x_next - x_prev) < accuracy) {
        recursive.res = x_next;
        recursive.n = n;
        n = 1;
        return recursive;
    }
    else {
        x_prev = x_next;
        n++;
        solution(accuracy); //recursion
    }
}

result_struct verification(double accuracy) { //verification function
    double x_prev = 1;
    double x_next = 0;
    int n = 0;

    result_struct ver_res;

    do {
        n++;
        if (n != 1) x_prev = x_next;
        x_next = (2 - pow(x_prev, 3)) / 5;
    } while (abs(x_next - x_prev) >= accuracy);

    ver_res.res = x_next;
    ver_res.n = n;
    return ver_res;
}*/

void oc_file() { //file creation check
    fstream file;
    file.open("results.txt", fstream::app);
    if (!file.is_open()) {
        file.open("results.txt", fstream::trunc);
    }
    file.close();
}

void write_in_file(double res, int n) { //input in file
    oc_file();
    fstream file;
    file.open("results.txt", fstream::out | fstream::app);
    file << res << '\n' << n << '\n';
    file.close();
}

void read_from_file() { //output in console from file
    oc_file();
    int i = 0;
    string word, tmp_word = "";
    fstream file;
    file.open("results.txt", fstream::in | fstream::app);
    file >> word;
    if (word == "") {
        cout << "File is empty!";
    }
    else {
        file.clear();
        file.seekg(0);
        cout << "Solutions from file:\n\n";
        while (!file.eof()) {
            file >> word;
            if (tmp_word != word) {
                cout << "Result [" << i << "] is: " << word << endl;
                file >> word;
                cout << "Number of iterations is: " << word << "\n\n";
            }
            tmp_word = word;
            i++;
        }
    }
    file.close();
}

bool compare_from_file(double res, int n) { //compare for double numbers in file
    oc_file();
    bool mark = true;
    double data;
    int dton, dta, dres;
    fstream file;
    file.open("results.txt", fstream::in | fstream::app);
    while (!file.eof() && mark) {
        file >> data;
        dta = data * 1000000; //rounding for compare
        dres = res * 1000000; //same as well
        if (dta == dres) {
            file >> data;
            dton = data;
            if (dton == n) {
                mark = false;
            }
        }
    }
    file.close();
    return mark;
}

void menu_output() { //menu print function
    cout << "=========================\n"
        "Menu: \n"
        "[1] Input\n"
        "[2] Solution by recursion\n"
        "[3] Verification\n"
        "[4] Output\n"
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