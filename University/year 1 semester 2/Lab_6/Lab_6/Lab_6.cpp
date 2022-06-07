// Classes
// Version 1.0.1
// 2022
// Kharin Aleksey

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

#define STACK class stack

class person_info {
public:
    char first_name[20];
    char last_name[20];
    double phone_number;
    int birthday_date[3];
    int old;
};

STACK {

private:

  person_info info;
  STACK* next;

public:

  void push(STACK** s, person_info item) {
      STACK* new_item;
      new_item = (STACK*)malloc(sizeof(STACK));
      new_item->info = item;
      new_item->next = *s;
      *s = new_item;
  }

  person_info pop(STACK** s) {
      STACK* old_item = *s;
      person_info old_info;
      old_info = old_item->info;
      *s = (*s)->next;
      free(old_item);
      return old_info;
  }

  void rewrite(STACK** s_from, STACK** s_to, unsigned int persons) {
      person_info person;
      for (unsigned int i = 0; i < persons; i++) {
          person = pop(&*s_from);
          push(&*s_to, person);
      }
  }
};

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
        "[7] Exit\n"
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

    unsigned int persons = 0, persons_old = 0, persons_young = 0, point, i, tmp_minus;
    int for_delete[3], date[3] = { 1, 6, 2022 }, index, minus, num_for_del;
    bool first_read = true, person_found, found_old, found_young, for_stop_seek, old_person_detected, young_person_detected, all_deleted;
    char search_last_name[20], sure;

    stack person_tmp_, person_old_, person_young_;
    string word;
    person_info person;

    STACK* person_tmp, * person_old, * person_young;

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
                person_old_.push(&person_old, person);
                persons_old++;
            }
            else if (person.old == 0) {
                person_young_.push(&person_young, person);
                persons_young++;
            }
            persons++;

            break;

        case 2: // Delete a person by birth date case

            if (persons != 0) {
                old_person_detected = false;
                young_person_detected = false;
                tmp_minus = 0;
                index = 1;
                minus = 0;
                for_stop_seek = false;
                all_deleted = false;

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

                if (persons_old != 0) {
                    //cout << "Persons which already had birthday:\n\n";
                    for (i = 0; i < persons_old; i++) {
                        person = person_old_.pop(&person_old);
                        if (for_delete[0] == person.birthday_date[0] && for_delete[1] == person.birthday_date[1] && for_delete[2] == person.birthday_date[2]) {
                            old_person_detected = true;
                            cout << "[" << tmp_minus + 1 << "] Person\n\n";
                            output_person(person);
                            tmp_minus++;
                        }
                        person_tmp_.push(&person_tmp, person);
                    }
                    person_old_.rewrite(&person_tmp, &person_old, persons_old);
                }
                //else cout << "There is no persons which already had birthday.\n\n";

                if (persons_young != 0) {
                    //cout << "Persons which didn't have birthday yet:\n\n";
                    for (i = 0; i < persons_young; i++) {
                        person = person_young_.pop(&person_young);
                        if (for_delete[0] == person.birthday_date[0] && for_delete[1] == person.birthday_date[1] && for_delete[2] == person.birthday_date[2]) {
                            young_person_detected = true;
                            cout << "[" << tmp_minus + 1 << "] Person\n\n";
                            output_person(person);
                            tmp_minus++;
                        }
                        person_tmp_.push(&person_tmp, person);
                    }
                    person_young_.rewrite(&person_tmp, &person_young, persons_young);
                }
                //else cout << "There is no persons which didn't have birthday yet.\n\n";

                if (old_person_detected) {

                    cout << "Whom you want to delete?\n"
                        "Print [0] if you want to delete all people in this list.\n"
                        "Print person's number to delete him.\n\n";
                    while (!_kbhit());
                    num_for_del = _getch() - 48;

                    for (i = 0; i < persons_old; i++) {
                        if (!for_stop_seek) {
                            person = person_old_.pop(&person_old);
                            if (for_delete[0] == person.birthday_date[0] && for_delete[1] == person.birthday_date[1] && for_delete[2] == person.birthday_date[2]) {
                                if (num_for_del == 0) {
                                    minus++;
                                    index++;
                                    all_deleted = true;
                                }
                                else if (num_for_del == index) {
                                    cout << "[" << index << "] Person\n\n";
                                    output_person(person);
                                    cout << "Are you sure you want to delete this person? [y/n]: ";
                                    cin >> sure;
                                    if (sure == 'y') {
                                        cout << "Person succesfully deleted.\n";
                                        minus++;
                                    }
                                    else {
                                        cout << "\nPerson won't be deleted.";
                                        person_tmp_.push(&person_tmp, person);
                                    }
                                    for_stop_seek = true; // person is deleted and no need to seek farther
                                }
                                else {
                                    person_tmp_.push(&person_tmp, person);
                                    index++;
                                }
                            }
                            else {
                                person_tmp_.push(&person_tmp, person);
                            }
                        }
                        else {
                            person = person_old_.pop(&person_old);
                            person_tmp_.push(&person_tmp, person);
                        }
                    }
                    if (all_deleted) {
                        cout << "Persons succesfully deleted.\n";
                    }
                    persons_old = persons_old - minus;
                    person_old_.rewrite(&person_tmp, &person_old, persons_old);
                }

                else if (young_person_detected) {

                    cout << "Who you want to delete?\n"
                        "Print person's number to delete him.\n\n";
                    while (!_kbhit());
                    num_for_del = _getch() - 48;

                    for (i = 0; i < persons_young; i++) {
                        if (!for_stop_seek) {
                            person = person_young_.pop(&person_young);
                            if (for_delete[0] == person.birthday_date[0] && for_delete[1] == person.birthday_date[1] && for_delete[2] == person.birthday_date[2]) {
                                if (num_for_del == 0) {
                                    minus++;
                                    index++;
                                    all_deleted = true;
                                }
                                else if (num_for_del == index) {
                                    cout << "[" << index << "] Person\n\n";
                                    output_person(person);
                                    cout << "Are you sure you want to delete this person? [y/n]: ";
                                    cin >> sure;
                                    if (sure == 'y') {
                                        cout << "Person succesfully deleted.\n";
                                        minus++;
                                    }
                                    else {
                                        cout << "\nPerson won't be deleted.";
                                        person_tmp_.push(&person_tmp, person);
                                    }
                                    for_stop_seek = true; // person is deleted and no need to seek farther
                                }
                                else {
                                    person_tmp_.push(&person_tmp, person);
                                    index++;
                                }
                            }
                            else {
                                person_tmp_.push(&person_tmp, person);
                            }
                        }
                        else {
                            person = person_young_.pop(&person_young);
                            person_tmp_.push(&person_tmp, person);
                        }
                    }
                    if (all_deleted) {
                        cout << "Persons succesfully deleted.\n";
                    }
                    persons_young = persons_young - minus;
                    person_young_.rewrite(&person_tmp, &person_young, persons_young);
                }

                else {
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
                        person = person_old_.pop(&person_old);
                        output_person(person);
                        person_tmp_.push(&person_tmp, person);
                    }
                    person_old_.rewrite(&person_tmp, &person_old, persons_old);
                }
                else cout << "There is no persons which already had birthday.\n\n";
                if (persons_young != 0) {
                    cout << "Persons which didn't have birthday yet:\n\n";
                    for (i = 0; i < persons_young; i++) {
                        person = person_young_.pop(&person_young);
                        output_person(person);
                        person_tmp_.push(&person_tmp, person);
                    }
                    person_young_.rewrite(&person_tmp, &person_young, persons_young);
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
                        person = person_old_.pop(&person_old);
                        if (strcmp(search_last_name, person.last_name) == 0) {
                            person_found = true;
                            found_old = true;
                        }
                        person_tmp_.push(&person_tmp, person);
                    }
                    person_old_.rewrite(&person_tmp, &person_old, persons_old);
                }

                if (persons_young != 0) {
                    for (i = 0; i < persons_young; i++) {
                        person = person_young_.pop(&person_young);
                        if (strcmp(search_last_name, person.last_name) == 0) {
                            person_found = true;
                            found_young = true;
                        }
                        person_tmp_.push(&person_tmp, person);
                    }
                    person_young_.rewrite(&person_tmp, &person_young, persons_young);
                }

                if (person_found) {
                    if (found_old) {
                        cout << "Found persons which already had birthday:\n\n";
                        for (i = 0; i < persons_old; i++) {
                            person = person_old_.pop(&person_old);
                            if (strcmp(search_last_name, person.last_name) == 0) {
                                output_person(person);
                            }
                            person_tmp_.push(&person_tmp, person);
                        }
                        person_old_.rewrite(&person_tmp, &person_old, persons_old);
                    }
                    else cout << "There is no persons which already had birthday with this last name.\n\n";
                    if (found_young) {
                        cout << "Found persons which didn't have birthday yet:\n\n";
                        for (i = 0; i < persons_young; i++) {
                            person = person_young_.pop(&person_young);
                            if (strcmp(search_last_name, person.last_name) == 0) {
                                output_person(person);
                            }
                            person_tmp_.push(&person_tmp, person);
                        }
                        person_young_.rewrite(&person_tmp, &person_young, persons_young);
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

            tmp_minus = 0;
            if (persons_old != 0) {
                for (i = 0; i < persons_old; i++) {
                    person = person_old_.pop(&person_old);
                    person.old = is_old(person, date);
                    if (person.old == 1) {
                        person_tmp_.push(&person_tmp, person);
                    }
                    else if (person.old == 0) {
                        person_young_.push(&person_young, person);
                        persons_young++;
                        tmp_minus++;
                    }
                }
                persons_old -= tmp_minus;
                person_old_.rewrite(&person_tmp, &person_old, persons_old);
            }
            tmp_minus = 0;
            if (persons_young != 0) {
                for (i = 0; i < persons_young; i++) {
                    person = person_young_.pop(&person_young);
                    person.old = is_old(person, date);
                    if (person.old == 1) {
                        person_old_.push(&person_old, person);
                        persons_old++;
                        tmp_minus++;
                    }
                    else if (person.old == 0) {
                        person_tmp_.push(&person_tmp, person);
                    }
                }
                persons_young -= tmp_minus;
                person_young_.rewrite(&person_tmp, &person_young, persons_young);
            }
            break;

        case 6: // About program
            cout << "Phone book manager\n"
                "Version 1.0.1\n"
                "2022\n"
                "Aleksey Kharin\n";
            break;

        case 7: // Exit

            if (persons_old != 0) {
                for (i = 0; i < persons_old; i++) {
                    person = person_old_.pop(&person_old);
                }
            }
            if (persons_young != 0) {
                for (i = 0; i < persons_young; i++) {
                    person = person_young_.pop(&person_young);
                }
            }

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