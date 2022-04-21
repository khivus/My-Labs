// 2D array ver. 3.0 2021 Aleksey Kharin ©
#include <iostream>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <typeinfo>

using namespace std;
double arr[100][100]; //Global arr parameter
int collumns, rows; //Global collumns and rows parameters

void foutput(const char str[256]) {
    cout << str;
}

void arrgenerator() { //Array generetion
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < collumns; j++) {
            arr[i][j] = rand() - rand();
        }
    }
}

void arrinput() { //Input array by kb
    int i, j;
    foutput("Введите массив поэлементно:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < collumns; j++) {
            cout << "Элемент [" << i << "][" << j << "] = ";
            cin >> arr[i][j];
        }
    }
}

void arrprint(double arr[100][100]) { //Output array
    int i, j;
    for (i = 0; i < rows; i++) {
        foutput("[");
        for (j = 0; j < collumns; j++) {
            if (j != collumns - 1) { cout << "[" << arr[i][j] << "], "; }
            else { cout << "[" << arr[i][j] << "]"; }
        }
        foutput("]\n");
    }
}

void first_task() { //First task
    int i, j;
    double ftarr[100][100]; //first task array
    for (i = 0; i < rows; i++) {
        for (j = 0; j < collumns; j++) {
            ftarr[i][j] = arr[i][j];
            if (i != j) {
                ftarr[i][j] = 0;
            }
        }
    }
    foutput("Array with \"0\" element instead of elements of main diagonal:\n");
    arrprint(ftarr);
}

void second_task() { //Second task
    int i, j, max_index;
    double max_el, starr[100][100]; //second task array
    for (i = 0; i < rows; i++) {
        max_el = 0;
        for (j = 0; j < collumns; j++) {
            starr[i][j] = arr[i][j];
            if (max_el <= abs(starr[i][j])) {
                max_el = starr[i][j];
                max_index = j;
            }
        }
        if (starr[i][max_index] > 0) { starr[i][max_index] = 0 - starr[i][max_index]; }
        else { starr[i][max_index] = abs(starr[i][max_index]); }
    }
    foutput("Array with reversed max elements in a rows:\n");
    arrprint(starr);
}

int menu_1() { //Menu with editing array
    int point;
    foutput("Choose way to create array:\n"
        "1. Input number of collumns and rows\n"
        "2. Generate random\n"
        "3. Input from keyboard\n"
        "> ");
    cin >> point;
    return point;
}

int menu_2() { //Output menu with tasks and exit
    int point;
    foutput("Programm menu:\n"
        "1. Return to creating an array\n"
        "2. Output array\n"
        "3. First task\n"
        "4. Second task\n"
        "5. Exit programm\n"
        "> ");
    cin >> point;
    return point;
}

int get_num(const char str[256]) { //Inout collumns and rows
    int x;
    try_again:
    cout << str;
    cin >> x;
    if (x <= 0 || x > 100) {
        foutput("Wrong input!\n");
        goto try_again;
    }
    return x;
}

void menu() { //Menu with tasks and exit
    int point;
    point = menu_1();
    switch (point) {
    case 1:
        collumns = get_num("Input number of collumns (0 < collumns <= 100): ");
        rows = get_num("Input number of rows (0 < rows <= 100): ");
        menu();
        break;
    case 2:
        arrgenerator();
        break;
    case 3:
        arrinput();
        break;
    default:
        foutput("Wrong input!\n");
        break;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand((unsigned)time(0));
    //declaring variables
    int point;
    //welcome screen
    foutput("Лабортаторная работа №7,8\nвариант 13\nВыполнил: Харин Алексей\n");
    collumns = get_num("Input number of collumns (0 < collumns <= 100): ");
    rows = get_num("Input number of rows (0 < rows <= 100): ");
    menu();
    do { //Main menu
        point = menu_2();
        switch (point) {
        case 1:
            menu();
            break;
        case 2:
            foutput("Array is:\n");
            arrprint(arr);
            break;
        case 3:
            first_task();
            break;
        case 4:
            second_task();
            break;
        case 5:
            foutput("Programm completed.\n");
            return 0;
        default: //If input will be > 5
            foutput("Wrong input!\n");
            break;
        }
    } while (true);
}