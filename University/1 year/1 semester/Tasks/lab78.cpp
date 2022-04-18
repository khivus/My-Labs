#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std;

int vvod_n(const char stroka_vvoda[256])//Функция ввода числа
{
	int N;
	cout<<stroka_vvoda;//вывод на экран
	cin>>N;//ввод с клавиатуры
	return N;
}

void vvod_massiv_keyboard(int N,int M, int A[20][20])
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)//ввод двумерного массива с клавиатуры
		{
			cout<<"Введите элемент массива M["<<i+1<<"]["<<j+1<<"]=";
			cin>>A[i][j];
		}
	}
}

void vvod_massiv_random(int N,int M, int A[20][20])
{
	int i,j;
	for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)//ввод двумерного массива случайно
			{
				//A[i][j] = (rand() / RAND_MAX)*20 - 10;//Вещественные числа
				A[i][j] = rand() % 21 +1;//Целые числа
			}
		}
}

void vyvod_massiv_ekran(int N, int M, int A[20][20])
{
int i,j;
for(i=0;i<N;i++)
	{
			for(j=0;j<M;j++)//вывод двумерного массива на экран
			{
				cout<< A[i][j]<<"\t";
			}
			cout<<endl;
	}
}

void obrabotka1 (int N, int M, int A[20][20])
{
	int i,j;
	//обработка массива (подсчитать в каждом столбце количество элементов кратных номеру столбца + 2)
		int kke[20];//количество кратных элементов в столбце (одномерный массив)
		for(j=0;j<M;j++)
			kke[j]=0;//обнуление значений

		for(i=0;i<N;i++)
			{
					for(j=0;j<M;j++)
					{
						if(A[i][j]%(j+2)==0)//проверка остатка при делении элемента массива на номер столбца + 2
							kke[j]++;//если остаток =0 увеличиваем количество кратны элементов
					}
			}

		for(j=0;j<M;j++)
		{
			cout << "в столбце №" <<j+1<<" "<<kke[j] <<" элементов, кратных " <<j+2 <<"\n";
		}
}

void obrabotka2 (int N, int M, int A[20][20], int B[20][20])
{
	int i,j;
	//обработка массива (циклически сдвинуть вправо в каждой строке элементы на заданное количество позиций)
		int k;//количество элементов на которое нужно сжвинуть строки
		cout<<"Введите величину сдвига: ";//вывод на экран
			cin>>k;//ввод с клавиатуры
			for(i=0;i<N;i++)
					{
							for(j=0;j<M;j++)
							{
								B[i][j]=A[i][(M+(j-k))%M];//сдвиг элементов на k позиций, % остаток от деления
							}
					}
}

int menu ()
{
	int k;
	cout <<"Меню:"<<endl;
	cout <<"1. Ввод"<<endl;
	cout <<"2. Вывод"<<endl;
	cout <<"3. Обработка 1"<< endl;
	cout <<"4. Обработка 2"<< endl;
	cout <<"5. Выход"<< endl;
	cout << "Выберите пункт меню: ";
	cin >> k;
	return k;
}

int main() {
	setlocale(LC_ALL,"Russian");
	int mas[20][20];//Двумерный массив максимальный размер 20x20
	int mas2[20][20];//массив после сдвига
	int N;//Количество строк
	int M;//Количество столбцов
	int p;//Выбранный Пункт Меню
    do
    {
    	p=menu();
    	switch(p)
    	{
    	case 1:
    		N=vvod_n("Введите количество строк в массиве: ");
    		M=vvod_n("Введите количество столбцов в массиве: ");
    		vvod_massiv_keyboard(N,M,mas);
    		break;
    	case 2:
    		vyvod_massiv_ekran(N,M,mas);
    		break;
    	case 3:
    		obrabotka1(N,M,mas);
    		break;
    	case 4:
    		obrabotka2(N,M,mas,mas2);
    		vyvod_massiv_ekran(N,M,mas2);
    		break;
    	case 5:cout <<"Программа завершена";
    		return 0;
    	}
    }
    while (true);//Бесконечный цикл
}
