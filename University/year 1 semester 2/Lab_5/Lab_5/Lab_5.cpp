// Queue
// v 0.12
// 2022
// Kharin Aleksey
// Variant 14 ...

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

#define QUEUE struct list

using namespace std;

struct queue {
    string first_name;
    string second_name;
    double phone_number;
    int birthday_date[3];
};

QUEUE{
    queue items;
    //int info;
    QUEUE *next;
};

void insert(QUEUE** q, queue item) {
    QUEUE* current = *q;
    QUEUE* previous = 0;
    QUEUE* new_node;
    while (current) {
        previous = current;
        current = current->next;
    }
    new_node = (QUEUE*)malloc(sizeof(QUEUE));
    new_node->items = item;
    if (previous) {
        new_node->next = previous->next;
        previous->next = new_node;
    }
    else {
        *q = new_node;
        (*q)->next = 0;
    }
}

queue take_out(QUEUE** q, int* error) {
    queue value;
    QUEUE* old_header = *q;
    if (*q) {
        value = old_header->items;
        *q = (*q)->next;
        free(old_header);
        *error = 0;
    }
    else {
        *error = 1;
    }
    return value;
}

void oc_file() {
    fstream file;
    file.open("book_data.txt", fstream::app);
    if (!file.is_open()) {
        file.open("book_data.txt", fstream::trunc);
    }
    file.close();
}

void write_in_file(string first_name, string second_name, double phone_number, int birthday_date[]) { // input in file
    oc_file(); // file existing check
    fstream file;
    file.precision(10);
    file.open("book_data.txt", fstream::out | fstream::app);
    file << phone_number << ' ' << first_name << ' ' << second_name << ' ' << birthday_date[0] << ' ' << birthday_date[1] << ' ' << birthday_date[2] << endl;
    file.close();
}

void person_from_file(double number) {
    oc_file();
    string word;
    fstream file;
    file.precision(10);
    int i = 1;
    bool marker = false;
    queue person;
    file.open("book_data.txt", fstream::in | fstream::app);
    while (!file.eof() && !marker) {
        file >> word;
        if (number == atof(word.c_str())) {
            marker = true;
        }
        if (i == 1) i = i + 6;
        else i = i + 7;
    }
    if (!marker) cout << "There's no such phone number!";
    else {
        person.phone_number = atof(word.c_str());
        file >> person.first_name;
        file >> person.second_name;
        file >> word;
        person.birthday_date[0] = atoi(word.c_str());
        file >> word;
        person.birthday_date[1] = atoi(word.c_str());
        file >> word;
        person.birthday_date[2] = atoi(word.c_str());
        cout << person.phone_number << ' ' << person.first_name << ' ' << person.second_name << ' ' << person.birthday_date[0] << '.' << person.birthday_date[1] << '.' << person.birthday_date[2] << endl;
    }
    file.close();
}

void numbers_from_file() {
    oc_file();
    string word;
    fstream file;
    file.precision(10);
    int i = 1;
    file.open("book_data.txt", fstream::in | fstream::app);
    cout << "All numbers: \n";
    while (!file.eof()) {
        file >> word;
        if (i == 1 || (i - 1) % 6 == 0) {
            cout << word << endl;
        }
        i++;
    }
    file.close();
}

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
    cout.precision(10);
    int point, error;
    double number;
    queue phone_book;
    QUEUE* q1 = 0, * q2 = 0;
    menu_output();
    do {
        point = menu();
        switch (point) {
        case 1:
            cout << "Input first name: ";
            cin >> phone_book.first_name;
            cout << "Input second name: ";
            cin >> phone_book.second_name;
            cout << "Input phone number: ";
            cin >> phone_book.phone_number;
            cout << "Input birthday day: ";
            cin >> phone_book.birthday_date[0];
            cout << "Input birthday month: ";
            cin >> phone_book.birthday_date[1];
            cout << "Input birthday year: ";
            cin >> phone_book.birthday_date[2];
            insert(&q1, phone_book);
            write_in_file(phone_book.first_name, phone_book.second_name, phone_book.phone_number, phone_book.birthday_date);
            break;
        case 2:
            break;
        case 3:
            numbers_from_file();
            break;
        case 4:
            cout << "Input phone number for search: ";
            cin >> number;
            person_from_file(number);
            break;
        case 5:
            break;
        case 6:
            
            break;
        default:
            cout << "Wrong input!";
            break;
        }
    } while (point != 6);
    return 0;
}