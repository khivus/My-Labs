// Phone book manager by Linked list
// version 1.0.1
// 2022
// Kharin Aleksey
// Variant 14

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include<algorithm>

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
    QUEUE* next;
    QUEUE* prev;
};

void insert(QUEUE** i, QUEUE** start, QUEUE** last, queue n) {
    QUEUE* new_node;
    new_node = (QUEUE*)malloc(sizeof(QUEUE));
    new_node->items = n;
    if (*start == NULL) {
        *start = new_node;
        *last = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
        *i = new_node;
    }
    if ((*i)->next != NULL) {
        new_node->next = (*i)->next;
        (*i)->next->prev = new_node;
        new_node->prev = *i;
        (*i)->next = new_node;

    }
    else {
        (*last)->next = new_node;
        new_node->prev = *last;
        new_node->next = NULL;
        (*last) = new_node;
        *i = new_node;
    }
}

queue take_out(QUEUE** i, QUEUE** start, QUEUE** last, int* error) {
    QUEUE* old_node = *i;
    queue value;
    if ((*start == NULL) || (*last == NULL) || (*i == NULL)) *error = 1;
    else {
        value = old_node->items;
        if (*i == *start) {
            *i = (*i)->next;
            *start = *i;
            if (*i) (*i)->prev = NULL;
        }
        else {
            if (*i == *last) {
                (*i) = (*i)->prev;
                *last = *i;
                (*i)->next = NULL;
            }
            else {
                (*i)->prev->next = (*i)->next;
                (*i)->next->prev = (*i)->prev;
                (*i) = (*i)->next;
            }
        }
        *error = 0;
        free(old_node);
    }
    return value;
}

void sort_list(QUEUE** q, QUEUE** start, QUEUE** last, int* error, unsigned int persons) {
    QUEUE* current = *q;
    QUEUE* i_sort = NULL, * start_sort = NULL, * last_sort = NULL;
    queue person;
    int cur_min, index, remain = persons;
    string str, num;
    unsigned int i, j, k, s;

    for (j = 0; j < persons; j++) {
        if (remain > 1) {
            for (i = 0; i < remain; i++) {
                num.clear();
                person = take_out(&*start, &*start, &*last, &*error);
                insert(&*last, &*start, &*last, person);
                str = to_string(person.phone_number);
                for (s = 0; s < 3; s++) {
                    num += str[s];
                }
                if (i == 0) cur_min = atoi(num.c_str());
                if (cur_min >= atoi(num.c_str())) {
                    cur_min = atoi(num.c_str());
                    index = i;
                }
            }
            for (k = 0; k < remain; k++) {
                person = take_out(&*start, &*start, &*last, &*error);
                if (k == index) {
                    insert(&i_sort, &start_sort, &last_sort, person);
                    remain--;
                }
                else {
                    insert(&*last, &*start, &*last, person);
                }
            }
        }
        else if (remain == 1) {
            insert(&i_sort, &start_sort, &last_sort, take_out(&*start, &*start, &*last, &*error));
            remain--;
        }
    }
    for (i = 0; i < persons; i++) {
        insert(&*last, &*start, &*last, take_out(&start_sort, &start_sort, &last_sort, &*error));
    }
    free(current);
}

bool check_file_data(string word, int mode) {
    string sym0 = "qwertyuiopasdfghjklzxcvbnm";
    string sym1 = "0123456789";
    unsigned int i, j;
    bool check = NULL, mark;
    switch (mode) {
    case 0: // word mode
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        for (i = 0; i < word.length(); i++) {
            mark = false;
            for (j = 0; j < sym0.length(); j++) {
                if (word[i] == sym0[j]) {
                    mark = true;
                }
            }
            if (mark) check = true;
            else check = false;
        }
        break;
    case 1: // number mode
        for (i = 0; i < word.length(); i++) {
            mark = false;
            for (j = 0; j < sym1.length(); j++) {
                if (word[i] == sym1[j]) {
                    mark = true;
                }
            }
            if (mark) check = true;
            else check = false;
        }
        break;
    }
    return check;
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
        "[2] Delete info about person by birthday date\n"
        "[3] Output all info\n"
        "[4] Output info by person's last name\n"
        "[5] About program\n"
        "[6] Save and exit\n"
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
    int for_delete[3], error;
    bool first_read = true, person_deleted, mark = false, person_found;
    char search_last_name[20];
    string word;
    queue person;
    QUEUE* q = NULL, * start = NULL, * last = NULL;
    ifstream file;

    menu_output();

    file.open("phone_book.txt", ifstream::in);
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
            try {
                file >> word;
                if (!check_file_data(word, 0)) throw NULL;
                strcpy_s(person.first_name, word.c_str());
                file >> word;
                if (!check_file_data(word, 0)) throw NULL;
                strcpy_s(person.last_name, word.c_str());
                file >> word;
                if (!check_file_data(word, 1)) throw NULL;
                person.phone_number = atof(word.c_str());
                file >> word;
                if (!check_file_data(word, 1)) throw NULL;
                person.birthday_date[0] = atoi(word.c_str());
                file >> word;
                if (!check_file_data(word, 1)) throw NULL;
                person.birthday_date[1] = atoi(word.c_str());
                file >> word;
                if (!check_file_data(word, 1)) throw NULL;
                person.birthday_date[2] = atoi(word.c_str());
            }
            catch (...) {
                cout << "File is broken.\n"
                    "You need to use \"[1] Input info\" first.\n";
                mark = true;
            }
            if (!mark) {
                insert(&last, &start, &last, person);
                persons++;
                file.seekg(2, ios_base::cur);
            }
            else file.seekg(0, ios_base::end);
        } while (file.peek() != EOF);
        if (!mark) {
            if (persons > 1) sort_list(&q, &start, &last, &error, persons);
            cout << "Found saved data.\n"
                "There are " << persons << " saved persons\n";
        }
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
            do {
                cout << "Input first name:     ";
                cin >> person.first_name;
            } while (!check_file_data(person.first_name, 0));
            do {
                cout << "Input last name:      ";
                cin >> person.last_name;
            } while (!check_file_data(person.last_name, 0));
            do {
                cout << "Input phone number:   ";
                cin >> word;
                person.phone_number = atof(word.c_str());
            } while (atof(word.c_str()) < 1 || atof(word.c_str()) > 1e10 || !check_file_data(word, 1));
            do {
                cout << "Input birthday day:   ";
                cin >> word;
                person.birthday_date[0] = atoi(word.c_str());
            } while (atoi(word.c_str()) < 1 || atoi(word.c_str()) > 31 || !check_file_data(word, 1));
            do {
                cout << "Input birthday month: ";
                cin >> word;
                person.birthday_date[1] = atoi(word.c_str());
            } while (atoi(word.c_str()) < 1 || atoi(word.c_str()) > 12 || !check_file_data(word, 1));
            do {
                cout << "Input birthday year:  ";
                cin >> word;
                person.birthday_date[2] = atoi(word.c_str());
            } while (atoi(word.c_str()) < 1900 || atoi(word.c_str()) > 2022 || !check_file_data(word, 1));

            cout << "\nYou printed:\n\n";
            output_person(person);
            insert(&last, &start, &last, person);
            persons++;
            if (persons > 1) sort_list(&q, &start, &last, &error, persons);
            break;

        case 2: // Delete a person by birth date case

            if (persons != 0) {
                person_deleted = false;
                tmp_minus = 0;

                do {
                    cout << "Input birthday day:   ";
                    cin >> word;
                    for_delete[0] = atoi(word.c_str());
                } while (atoi(word.c_str()) < 1 || atoi(word.c_str()) > 31 || !check_file_data(word, 1));
                do {
                    cout << "Input birthday month: ";
                    cin >> word;
                    for_delete[1] = atoi(word.c_str());
                } while (atoi(word.c_str()) < 1 || atoi(word.c_str()) > 12 || !check_file_data(word, 1));
                do {
                    cout << "Input birthday year:  ";
                    cin >> word;
                    for_delete[2] = atoi(word.c_str());
                } while (atoi(word.c_str()) < 1900 || atoi(word.c_str()) > 2022 || !check_file_data(word, 1));

                cout << "\nYou printed:\n"
                    "Birthday day:   " << for_delete[0] << endl <<
                    "Birthday month: " << for_delete[1] << endl <<
                    "Birthday year:  " << for_delete[2] << endl << endl;
                cout << "Deleted person(s):\n\n";

                for (i = 0; i < persons; i++) {
                    person = take_out(&start, & start, &last, &error);
                    if (for_delete[0] == person.birthday_date[0] && for_delete[1] == person.birthday_date[1] && for_delete[2] == person.birthday_date[2]) {
                        person_deleted = true;
                        output_person(person);
                        tmp_minus++;
                    }
                    else {
                        insert(&last, &start, &last, person);
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
                    person = take_out(&start, &start, &last, &error);
                    output_person(person);
                    insert(&last, &start, &last, person);
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
                
                for (i = 0; i < persons; i++) {
                    person = take_out(&start, &start, &last, &error);
                    insert(&last, &start, &last, person);
                    if (strcmp(search_last_name, person.last_name) == 0) {
                        person_found = true;
                    }
                }
                if (person_found) {
                    cout << "Found person:\n\n";
                    for (i = 0; i < persons; i++) {
                        person = take_out(&start, &start, &last, &error);
                        insert(&last, &start, &last, person);
                        if (strcmp(search_last_name, person.last_name) == 0) {
                            output_person(person);
                        }
                    }
                }
                else {
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
                "Version 1.0.1\n"
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
        person = take_out(&start, &start, &last, &error);
        to_file << person.first_name << ' ' << person.last_name << ' ' << person.phone_number << ' ' << person.birthday_date[0] << ' ' << person.birthday_date[1] << ' ' << person.birthday_date[2] << '\n';
    }

    to_file.close();

    cout << "Press any key to continiue...\n";
    while (!_kbhit());

    return 0;
}