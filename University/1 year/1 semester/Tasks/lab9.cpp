
#include <iostream>
#include <locale.h>
#include <math.h>
#include <string.h>
using namespace std;

int main() {
	setlocale(LC_ALL,"Russian");
	char stroka1[256],stroka2[256];
	int i;
	int z; //Количество символов в строке
	cout<<"Введите строку 1:";
	cin >> stroka1;
	cout<<"Введите строку 2:";
	cin >> stroka2;
	//Сравнить строки
	cout <<"Вы ввели строку 1: "<<stroka1<<endl;
	cout <<"Вы ввели строку 2: "<<stroka2<<endl;
	if(strcmp(stroka1,stroka2)==0)//=0 совпадают >0 <0 какая из строк раньше по алфавиту
		cout <<"Введенные строки совпадают"<<endl;
	else if(strcmp(stroka1,stroka2)>0)
		cout <<"Строка 2 раньше по алфавиту"<<endl;
	else cout <<"Строка 1 раньше по алфавиту"<<endl;
	strcat(stroka1,stroka2);
	cout<<"Сумма строк = " <<stroka1<<endl;
	cout<< "Введите сколько символов оставить в строке: ";
	cin >>z;
	stroka1[z]=0;
	for(i=0;i<strlen(stroka1);i++)// Пройти строку от начала к концу
	{
		cout << "Символ №"<<i+1<<" :"<<stroka1[i]<<endl;
	}
	//Поменять каждый 3-й символ на a
	for(i=2;i<strlen(stroka1);i=i+3)
	{
	stroka1[i]='A';
	}
	cout <<"Новая строка после замены каждого третьего символа на A: "<<stroka1<<endl;
	//Найти номер последнего символа x в строке
	for(i=strlen(stroka1)-1;i>=0;i--)//Пройти строку от конца к началу
	{
		if(stroka1[i]=='x')//Проверяем являетсяли очередной символ x
		{
			cout << "Последний x стоит на позиции " << i+1 << endl;
			break;
		}
	}
}
