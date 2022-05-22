#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

struct queue {
    string first_name;
    string second_name;
    double phone_number;
    int birthday_date[3];
};

void menu_output() {
    cout << "=============================================\n"
        "Menu: \n"
        "[1] Input info\n"
        "[2] Delete info about person by birtday date\n"
        "[3] Output info of all phone numbers\n"
        "[4] Output info by phone number\n"
        "[5] About program\n"
        "[6] Exit\n"
        "=============================================\n\n";
}

int menu() {
    int point;
    while (!_kbhit());
    point = _getch() - 48;
    system("cls");
    menu_output();
    return point;
}

int main() {
    int point;
    menu_output();
    do {
        point = menu();
        switch (point) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            break;
        }
    } while (point != 6);
    return 0;

}