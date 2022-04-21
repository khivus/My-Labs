/*Recursive function
ver 2.2
2022
Kharin Aleksey
Main file*/

#include <iostream>
#include <windows.h>
#include <locale.h>
#include <conio.h>
#include <math.h>

#include "Functions.h"

using namespace std;

//functions solution and verification aren't working from other .cpp file!!!
//idk why, maybe because struct return or what


struct result_struct {
    double res; //result
    int n; //number of interations
};

result_struct solution(double accuracy) { //solution function
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

result_struct verification(double accuracy) { //verification function by loop
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
}

int main() {
    int point, write_in, var_out; //declaring variables
    float accuracy = NULL;

    menu_output(); //first menu output

    do { //menu
        point = menu();
        switch (point) {
        case 1:
            accuracy = input_accuracy();
            break;
        case 2: //recursive solution
            if (accuracy != NULL) {
                result_struct recursive = solution(accuracy);
                cout << "Solution by recursion with accuracy = " << accuracy << " is: x(" << recursive.n << ") = " << recursive.res;
                cout << "\n\nDo you want to write this value in file \"results.txt\"? ([1] for yes)\n";
                while (!_kbhit());
                write_in = _getch() - 48;
                if (write_in == 1) { //double check and write in file
                    write_in_file(recursive.res, recursive.n, accuracy);
                    cout << "Data saved succsessfully in \"results.txt\"!";
                }
                else { //different input
                    cout << "Data won't be saved.";
                }
            }
            else {
                cout << "Firstly, please use input [1]";
            }
            break;
        case 3: //verification solution
            if (accuracy != NULL) {
                result_struct ver_res = verification(accuracy);
                result_struct recursive = solution(accuracy);
                cout << "For compare:\n"
                    "Solution by recursion with accuracy = " << accuracy << " is: x(" << recursive.n << ") = " << recursive.res << endl
                    << "Solution by loop with accuracy = " << accuracy << " is: x(" << ver_res.n << ") = " << ver_res.res;
            }
            else {
                cout << "Firstly, please use input [1]";
            }
            break;
        case 4: //output from file
            cout << "Output from file \"results.txt\":\n";
            read_from_file();
            break;
        case 5: //about program
            cout << "Recursion\n"
                "ver 2.2\n"
                "2022\n"
                "Kharin Aleksey";
            break;
        case 6: //help menu
            cout << "Task is x0 = 1, x(k) = (2-x(k-1)^3), k = 1, 2, ... \n"
                "Find first x(n) with condition: |x(n) - x(n-1)| < accuracy (default 10^-5)\n"
                "Description of all items in menu:\n"
                "[1] Input - Input the accuracy of the equation\n"
                "[2] Solution by recursion - Solution by recursive function\n"
                "[3] Verification - Solution by loop\n"
                "[4] Output from file - Output from file \"results.txt\"\n"
                "[5] About program - About program and developer\n"
                "[6] Help - This paragraph\n"
                "[7] Exit - Close the program\n";
            break;
        case 7:
            cout << "Programm succsessfully completed!\n";
            break;
        default:
            cout << "Wrong input!";
            break;
        }
    } while (point != 7); //when you press '7' programm will be completed
}