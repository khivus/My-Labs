// Phone book manager by queue
// version 1.01
// 2022
// Kharin Aleksey
// Variant 14

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

#define QUEUE struct list

using namespace std;

struct queue {
    char first_name[20];
    char last_name[20];
    double phone_number;
    int birthday_date[3];
};

QUEUE{
    queue items;
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

queue take_out(QUEUE** q) {
    queue value;
    QUEUE* old_header = *q;
    value = old_header->items;
    *q = (*q)->next;
    free(old_header);
    return value;
}

void output_person(queue person) {
    cout << "First name:     " << person.first_name << endl <<
            "Last name:      " << person.last_name << endl <<
            "Phone number:   " << person.phone_number << endl <<
            "Birthday day:   " << person.birthday_date[0] << endl <<
            "Birthday month: " << person.birthday_date[1] << endl <<
            "Birthday year:  " << person.birthday_date[2] << endl << endl;
}

void menu_output() {
    cout << "=============================================\n"
        "Menu: \n"
        "[1] Input info\n"
        "[2] Delete info about person by birtday date\n"
        "[3] Output all info\n"
        "[4] Output info by person's last name\n"
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
    unsigned int point, persons = 0, i = 1, tmp_minus;
    int for_delete[3];
    bool first_read = true, person_deleted, person_found;
    char search_last_name[20];
    string word;
    queue phone_book, person;
    QUEUE* q1 = 0;
    ifstream file;
    file.open("phone_book.txt", ifstream::in);
    menu_output();
    file.seekg(0, ios::end);
    if (!file.is_open()) { // file is not open
        cout << "File does not exist!\n"
            "Use \"[1] Input info\" first.\n";
    }
    else if (file.tellg() != 0) { // file is open and not empty
        // get data from file when program is strating
        file.seekg(0, ios_base::beg);
        do {
            if (first_read) first_read = false;
            else file.seekg(-2, ios_base::cur);
            file >> word;
            strcpy_s(person.first_name, word.c_str());
            file >> word;
            strcpy_s(person.last_name, word.c_str());
            file >> word;
            person.phone_number = atof(word.c_str());
            file >> word;
            person.birthday_date[0] = atoi(word.c_str());
            file >> word;
            person.birthday_date[1] = atoi(word.c_str());
            file >> word;
            person.birthday_date[2] = atoi(word.c_str());
            insert(&q1, person);
            persons++;
            file.seekg(2, ios_base::cur);
        } while (file.peek() != EOF);
        cout << "Found saved data.\n"
            "There are " << persons << " saved persons\n";
        file.close();
    }
    else { // file is empty
        cout << "No saved data!\n"
            "You need to use \"[1] Input info\" first.\n";
        file.close();
    }
    do { // menu
        point = menu();
        switch (point) {
        case 1: // Input case
            cout << "Input first name:     ";
            cin >> phone_book.first_name;
            cout << "Input last name:      ";
            cin >> phone_book.last_name;
            cout << "Input phone number:   ";
            cin >> phone_book.phone_number;
            cout << "Input birthday day:   ";
            cin >> phone_book.birthday_date[0];
            cout << "Input birthday month: ";
            cin >> phone_book.birthday_date[1];
            cout << "Input birthday year:  ";
            cin >> phone_book.birthday_date[2];
            cout << "\nYou printed:\n\n";
            output_person(phone_book);
            insert(&q1, phone_book);
            persons++;
            break;
        case 2: // Delete a person by birth date case
            if (persons != 0) {
                person_deleted = false;
                tmp_minus = 0;
                cout << "Input birthday day:   ";
                cin >> for_delete[0];
                cout << "Input birthday month: ";
                cin >> for_delete[1];
                cout << "Input birthday year:  ";
                cin >> for_delete[2];
                cout << "\nYou printed:\n"
                    "Birthday day:   " << for_delete[0] << endl <<
                    "Birthday month: " << for_delete[1] << endl <<
                    "Birthday year:  " << for_delete[2] << endl << endl;
                cout << "Deleted person(s):\n\n";
                for (i = 0; i < persons; i++) {
                    person = take_out(&q1);
                    if (for_delete[0] == person.birthday_date[0] && for_delete[1] == person.birthday_date[1] && for_delete[2] == person.birthday_date[2]) {
                        person_deleted = true;
                        output_person(person);
                        tmp_minus++;
                    }
                    else {
                        insert(&q1, person);
                    }
                }
                persons = persons - tmp_minus;
                if (!person_deleted) {
                    cout << "This person not found!\n";
                }
            }
            else {
                cout << "There is no persons to wipe out!\n"
                    "Please use the \"[1] Input info\" first\n";
            }
            break;
        case 3: // Output all info
            if (persons != 0) {
                cout << "All persons:\n\n";
                for (i = 0; i < persons; i++) {
                    person = take_out(&q1);
                    insert(&q1, person);
                    output_person(person);
                }
            }
            else {
                cout << "There is no data!\n"
                    "Please use the \"[1] Input info\" first";
            }
            break;
        case 4: // Output info by last name
            if (persons != 0) {
                person_found = false;
                cout << "Input last name for search: ";
                cin >> search_last_name;
                cout << "\nYou printed:\n"
                    "Last name: " << search_last_name << "\n\n";
                cout << "Found person:\n\n";
                for (i = 0; i < persons; i++) {
                    person = take_out(&q1);
                    insert(&q1, person);
                    if (strcmp(search_last_name, person.last_name) == 0) {
                        person_found = true;
                        output_person(person);
                    }
                }
                if (!person_found) {
                    cout << "This person not found!\n";
                }
            }
            else {
                cout << "There is no data!\n"
                    "Please use the \"[1] Input info\" first";
            }
            break;
        case 5: // About program
            cout << "Phone book manager\n"
                "Version 1.01\n"
                "2022\n"
                "Aleksey Kharin\n";
            break;
        case 6: // Exit
            cout << "Program succsessfully completed.\n";
            break;
        default:
            cout << "Wrong input!\n";
            break;
        }
    } while (point != 6);
    // write data in file before close the program
    ofstream to_file;   
    to_file.precision(10);
    to_file.open("phone_book.txt", ofstream::trunc | ofstream::out);
    for (i = 0; i < persons; i++) {
        person = take_out(&q1);
        to_file << person.first_name << ' ' << person.last_name << ' ' << person.phone_number << ' ' << person.birthday_date[0] << ' ' << person.birthday_date[1] << ' ' << person.birthday_date[2] << '\n';
    }
    to_file.close();
    cout << "Press any key to continiue...\n";
    while (!_kbhit());
    return 0;
}