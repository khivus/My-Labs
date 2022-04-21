/* Flow - forms v1 2022 Kharin Aleksey variant 14
Дано не менее 3-х различных натуральных чисел, за которыми следует 0.
Определить 3 наибольших числа в последовательности. */

#include <iostream>
#include <windows.h>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    unsigned int i, j;
    int tmp_num, index, tmp;
    string programm_continiue;
    vector <int> vec_arr;
    bool to_begin;

    do {
        i = 0;
        cout << "Введите целочисленный массив (должен заканчиваться нулем)(-2147483648 < число < 2147483648):\nВведите [" << i << "] элемент массива: ";
        while (cin >> tmp && tmp != 0) {
            i++;
            cout << "Введите [" << i << "] элемент массива: ";
            vec_arr.push_back(tmp);
        }
        vec_arr.push_back(0);

        cout << "Введенные числа (до нуля): ";
        for (i = 0; i < vec_arr.size(); i++) {
            cout << vec_arr[i] << " ";
        }

        cout << "\n3 максимальных числа: ";
        for (j = 0; j < 3; j++) {
            index = 0;
            tmp_num = 0;
            for (i = 0; i < vec_arr.size(); i++) {
                if (tmp_num <= vec_arr[i]) {
                    tmp_num = vec_arr[i];
                    index = i;
                }
            }
            vec_arr.erase(vec_arr.begin() + index);
            cout << tmp_num << " ";
        }
        cout << "\nПродолжить? (да/нет): ";
        cin >> programm_continiue;
        if (programm_continiue == "да") {
            to_begin = TRUE;
        }
        else {
            to_begin = FALSE;
        }
        vec_arr.erase(vec_arr.begin(), vec_arr.end());
    } while (to_begin == TRUE);
    return 0;
}