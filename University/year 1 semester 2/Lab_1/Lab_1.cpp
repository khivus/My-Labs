/*Структуры v1 2022 Харин Алексей вариант 14
1.)	Описать структуру с именем NOTE, содержащую следующие поля:
•	фамилия, имя;
•	номер телефона;
•	день рождения(массив из трех чисел).
2.)	Написать программу, выполняющую следующие действия :
•	ввод с клавиатуры данных в массив, состоящий из n элементов типа NOTE, записи должны быть упорядочены по трем первым цифрам  номера телефона;
•	вывод на дисплей информации о человеке, чья фамилия введена с клавиатуры;
•	если такого нет, выдать на дисплей соответствующее сообщение.
*/

#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
using namespace std;

struct NOTE {
    char first_name[20]; //Имя
    char second_name[20]; //Фамилия
    double phone_number; //Номер мобильного телефона (без +7)
    int birthday_date[3]; //Дата дня рождения
};

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    const int max_n = 20;
    int i, j, n_array, count = 0;
    double temp1, temp2;
    char name[20];
    bool search = TRUE;
    NOTE* array;
    NOTE tmp;
    do {
        cout << "Введите количество людей (<20): ";
        cin >> n_array;
    } while (n_array > max_n || n_array < 0);
    cout << "Введенное количество: " << n_array << "\n\n";
    array = (NOTE*)malloc(sizeof(NOTE) * n_array);

    for (i = 0; i < n_array; i++) { //Ввод
        cout << "Введите имя: ";
        cin >> array[i].first_name;
        cout << "Введите фамилию: ";
        cin >> array[i].second_name;
        cout << "Введите номер телефона: ";
        cin >> array[i].phone_number;
        cout << "Введите день рождения: ";
        cin >> array[i].birthday_date[0];
        cout << "Введите месяц рождения: ";
        cin >> array[i].birthday_date[1];
        cout << "Введите год рождения: ";
        cin >> array[i].birthday_date[2];
        cout << "\n";
    }

    cout << "Неотсортированный: \n";
    for (i = 0; i < n_array; i++) {
        printf_s("%d.\n"
            "Имя:            %s\n"
            "Фамилия:        %s\n"
            "Номер телефона: %-11.0lf\n"
            "Дата рождения:  %d.%d.%d\n\n", i + 1, array[i].first_name, array[i].second_name, array[i].phone_number, array[i].birthday_date[0], array[i].birthday_date[1], array[i].birthday_date[2]);
    }
    cout << endl;

    for (i = 0; i < n_array; i++) {
        for (j = (n_array - 1); j >= (i + 1); j--) {
            if (array[j - 1].phone_number < array[j].phone_number) {
                tmp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = tmp;
            }
        }
    }

    cout << "Отсортированный:\n";
    for (i = 0; i < n_array; i++) {
        printf_s("%d.\n"
            "Имя:            %s\n"
            "Фамилия:        %s\n"
            "Номер телефона: %-11.0lf\n"
            "Дата рождения:  %d.%d.%d\n\n", i + 1, array[i].first_name, array[i].second_name, array[i].phone_number, array[i].birthday_date[0], array[i].birthday_date[1], array[i].birthday_date[2]);
    }

    do {
        count = 0;
        cout << "\nВведите фамилию человека: ";
        cin >> name;
        for (i = 0; i < n_array; i++) {
            if (strcmp(name, array[i].second_name) == 0) {
                printf_s("Имя:            %s\n"
                    "Фамилия:        %s\n"
                    "Номер телефона: %-11.0lf\n"
                    "Дата рождения:  %d.%d.%d\n\n", array[i].first_name, array[i].second_name, array[i].phone_number, array[i].birthday_date[0], array[i].birthday_date[1], array[i].birthday_date[2]);                count++;
            }
        }
        if (count == 0) {
            cout << "Людей с такой фамилией нет!\n";
        }
        cout << "Продолжить поиск (0 или 1): ";
        cin >> search;
    } while (search == TRUE);

    free(array);
    cout << "Программа завершена!\n";
}