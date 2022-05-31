// Classes
// Version 0.1.0
// 2022
// Kharin Aleksey

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

class person_info {
public:
    char first_name[20];
    char last_name[20];
    double phone_number;
    int birthday_date[3];
    int old;
};

class stack {
private:
    vector <person_info> vec;
    person_info tmp;

public:
    void push(person_info info) {
        vec.push_back(info);
    }

    person_info pop() {
        tmp = vec.back();
        vec.pop_back();
        return tmp;
    }
};

void rewrite(stack s_from, stack s_to, unsigned int persons) {
    person_info person;
    for (unsigned int i = 0; i < persons; i++) {
        person = s_from.pop();
        s_to.push(person);
    }
}

int is_old(person_info person, int date[]) {
    int old;
    if (date[1] > person.birthday_date[1]) {
        old = 1;
    }
    else if (date[1] < person.birthday_date[1]) {
        old = 0;
    }
    else {
        if (date[0] > person.birthday_date[0]) {
            old = 1;
        }
        else {
            old = 0;
        }
    }
    return old;
}

bool is_normal(string word, string mode) {
    string sym0 = "qwertyuiopasdfghjklzxcvbnm";
    string sym1 = "0123456789";
    unsigned int i, j;
    bool check = NULL, mark;
    
    if (mode == "str") {
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
    }
    else if (mode == "num") {
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
    }
    return check;
}

void output_person(person_info person) {
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
        "[5] Change date\n"
        "[6] About program\n"
        "[7] Save and exit\n"
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

    unsigned int persons = 0, persons_old = 0, persons_young = 0, point, i, tmp_minus, tmp_old_minus, tmp_young_minus;
    int for_delete[3], date[3] = { 1, 6, 2022 };
    bool first_read = true, person_deleted, person_found, found_old, found_young;
    char search_last_name[20];
    string word;
    person_info person;
    stack person_tmp, person_old, person_young;

    menu_output();

    do { // menu
        point = menu();
        switch (point) {

        case 1: // Input case

            cout << "Input first name:     ";
            cin >> person.first_name;
            cout << "Input last name:      ";
            cin >> person.last_name;
            cout << "Input phone number:   ";
            cin >> word;
            person.phone_number = atof(word.c_str());
            cout << "Input birthday day:   ";
            cin >> word;
            person.birthday_date[0] = atoi(word.c_str());
            cout << "Input birthday month: ";
            cin >> word;
            person.birthday_date[1] = atoi(word.c_str());
            cout << "Input birthday year:  ";
            cin >> word;
            person.birthday_date[2] = atoi(word.c_str());

            person.old = is_old(person, date);
            
            cout << "\nYou printed:\n\n";
            output_person(person);
            if (person.old == 1) {
                person_old.push(person);
                persons_old++;
            }
            else if (person.old == 0) {
                person_young.push(person);
                persons_young++;
            }
            persons++;

            break;

        case 2: // Delete a person by birth date case

            if (persons != 0) {
                person_deleted = false;
                tmp_minus = 0;
                tmp_old_minus = 0;
                tmp_young_minus = 0;

                cout << "Input birthday day:   ";
                cin >> word;
                for_delete[0] = atoi(word.c_str());
                cout << "Input birthday month: ";
                cin >> word;
                for_delete[1] = atoi(word.c_str());
                cout << "Input birthday year:  ";
                cin >> word;
                for_delete[2] = atoi(word.c_str());

                cout << "\nYou printed:\n"
                    "Birthday day:   " << for_delete[0] << endl <<
                    "Birthday month: " << for_delete[1] << endl <<
                    "Birthday year:  " << for_delete[2] << endl << endl;
                cout << "Deleted person(s):\n\n";

                if (persons_old != 0) {
                    for (i = 0; i < persons_old; i++) {
                        person = person_old.pop();
                        if (for_delete[0] == person.birthday_date[0] && for_delete[1] == person.birthday_date[1] && for_delete[2] == person.birthday_date[2]) {
                            person_deleted = true;
                            output_person(person);
                            tmp_minus++;
                            tmp_old_minus++;
                        }
                        else {
                            person_tmp.push(person);
                        }
                    }
                    persons_old = persons_old - tmp_old_minus;
                    rewrite(person_tmp, person_old, persons_old);
                }
                
                if (persons_young != 0) {
                    for (i = 0; i < persons_young; i++) {
                        person = person_young.pop();
                        if (for_delete[0] == person.birthday_date[0] && for_delete[1] == person.birthday_date[1] && for_delete[2] == person.birthday_date[2]) {
                            person_deleted = true;
                            output_person(person);
                            tmp_minus++;
                            tmp_young_minus++;
                        }
                        else {
                            person_tmp.push(person);
                        }
                    }
                    persons_young = persons_young - tmp_young_minus;
                    rewrite(person_tmp, person_young, persons_young);
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

                cout << "\nDate is: \n" << date[0] << '.' << date[1] << '.' << date[2] << "\n\n";

                if (persons_old != 0) {
                    cout << "Persons which already had birthday:\n\n";
                    for (i = 0; i < persons_old; i++) {
                        person = person_old.pop();
                        output_person(person);
                        person_tmp.push(person);
                    }
                    rewrite(person_tmp, person_old, persons_old);
                }
                else cout << "There is no persons which already had birthday.\n\n";
                if (persons_young != 0) {
                    cout << "Persons which didn't have birthday yet:\n\n";
                    for (i = 0; i < persons_young; i++) {
                        person = person_young.pop();
                        output_person(person);
                        person_tmp.push(person);
                    }
                    rewrite(person_tmp, person_young, persons_young);
                }
                else cout << "There is no persons which didn't have birthday yet.\n\n";
            }
            else {
                cout << "There is no data!\n"
                    "Please use the \"[1] Input info\" first";
            }
            break;

        case 4: // Output info by last name
            if (persons != 0) {
                person_found = false;
                found_old = false;
                found_young = false;

                cout << "\nDate is: \n" << date[0] << '.' << date[1] << '.' << date[2] << "\n\n";
                cout << "Input last name for search: ";
                cin >> search_last_name;
                cout << "\nYou printed:\n"
                    "Last name: " << search_last_name << "\n\n";

                if (persons_old != 0) {
                    for (i = 0; i < persons_old; i++) {
                        person = person_old.pop();
                        if (strcmp(search_last_name, person.last_name) == 0) {
                            person_found = true;
                            found_old = true;
                        }
                        person_tmp.push(person);
                    }
                    rewrite(person_tmp, person_old, persons_old);
                }

                if (persons_young != 0) {
                    for (i = 0; i < persons_young; i++) {
                        person = person_young.pop();
                        if (strcmp(search_last_name, person.last_name) == 0) {
                            person_found = true;
                            found_old = true;
                        }
                        person_tmp.push(person);
                    }
                    rewrite(person_tmp, person_young, persons_young);
                }

                if (person_found) {
                    if (found_old) {
                        cout << "Found persons which already had birthday:\n\n";
                        for (i = 0; i < persons_old; i++) {
                            person = person_old.pop();
                            if (strcmp(search_last_name, person.last_name) == 0) {
                                output_person(person);
                            }
                            person_tmp.push(person);
                        }
                        rewrite(person_tmp, person_old, persons_old);
                    }
                    else cout << "There is no persons which already had birthday with this last name.\n\n";
                    if (found_young) {
                        cout << "Found persons which didn't have birthday yet:\n\n";
                        for (i = 0; i < persons_young; i++) {
                            person = person_young.pop();
                            if (strcmp(search_last_name, person.last_name) == 0) {
                                output_person(person);
                            }
                            person_tmp.push(person);
                        }
                        rewrite(person_tmp, person_young, persons_young);
                    }
                    else cout << "There is no persons which didn't have birthday yet with this last name.\n\n";
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

        case 5:
            cout << "Input day:   ";
            cin >> date[0];
            cout << "Input month: ";
            cin >> date[1];
            cout << "Input year:  ";
            cin >> date[2];
            cout << "\nDate is: \n" << date[0] << '.' << date[1] << '.' << date[2] << endl;
            break;

        case 6: // About program
            cout << "Phone book manager\n"
                "Version 0.1.0\n"
                "2022\n"
                "Aleksey Kharin\n";
            break;

        case 7: // Exit
            cout << "Program succsessfully completed.\n";
            break;

        default:
            cout << "Wrong input!\n";
            break;
        }
    } while (point != 7);

    cout << "Press any key to continiue...\n";
    while (!_kbhit());

    return 0;
}