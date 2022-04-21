/* Файлы v.1 2022 Алексей Харин
* Вариант 14
* Написать программу, которая считывает текст из файла, находит самое длинное слово и определяет, сколько раз оно встретилось в тексте.
*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    char file_string[500];
    char file_name[20];
    bool return_mark;
    char word[20] = "", tmp_word[20];
    int count = 0;

    cout << "Введите название файла (по умолчанию: \"default.txt\"): "; //Вводим название файла
    cin >> noskipws;
    cin >> file_name;

    if (strcmp(file_name, "") == 0) { //Если нажали "enter" ничего не введя
        strcpy_s(file_name, "default.txt");
    }

    cout << "Назвние файла: " << file_name << endl; //Эхо контроль

    fstream file_create; //Создаем/открываем файл и вводим строку
    file_create.open(file_name, fstream::out | fstream::trunc);
    file_create << "This string is default you can't change it if you want\n"
        "This is second string multistring yeah\n"
        "This is third multistring string lets go\n"
        "Строчка по-русски";
    file_create.close();

    fstream finput; //Открываем файл
    finput.open(file_name, fstream::in);

    if (finput.is_open()) { //если файл открыт
        cout << "\nТекст из файла:\n"; //Эхо контроль
        while (finput.getline(file_string, sizeof(file_string))) {
            cout << file_string << endl;
        }

        finput.clear();
        finput.seekg(0);

        do { //поиск самого длинного слова
            finput >> tmp_word;
            if (strlen(tmp_word) >= strlen(word)) {
                strcpy_s(word, tmp_word);
            }
        } while (!finput.eof());

        finput.clear();
        finput.seekg(0);

        do { //счёт слов
            finput >> tmp_word;
            if (strcmp(tmp_word, word) == 0) {
                count++;
            }
        } while (!finput.eof());

        cout << "\nНаибольшее последнее слово: " << word << "\nДлина слова: " << strlen(word) << " символов" << "\nКоличество слов в тексте: " << count << "\n\n";
        return_mark = 0;
    }

    else { //если файл не открыт
        cout << "\nФайл не может быть открыт или его не существует!";
        return_mark = -1;
    }

    finput.close();
    return return_mark;
}