//ЛАБОРАТОРНАЯ РАБОТА № 5А
//Написать функцию, которая имеет следующие параметры :
//– динамический двумерный массив;
//– одномерный динамический массив, содержащий минимальные элементы в каждом столбце;
//– одномерный динамический массив, содержащий максимальные элементы в каждой строке;
//– указатель – сумма на ГД;
//– указатель – произведение на ПД.
//Функция возвращает динамический одномерный массив, в котором находятся сумма на ГД и произведение на ПД, рассчитанные внутри функции.

#include <iostream>
#include <iomanip>
#include <windows.h> //Для указателеy ** ???
#include "Print_.h"
#include "Function.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int Size, i, j, R, b;
	int k = 0;
	int Size_2 = 2;
	int far** DVmas; /* указатель на массив указателей */
	cout << "Введите размер динамического двумерного массива" << endl;
	cin >> Size;
	int* ODmin = (int*)malloc(Size * sizeof(int));// одномерный динамический массив, содержащий минимальные элементы в каждом столбце;
	int* ODmax = (int*)malloc(Size * sizeof(int));//  одномерный динамический массив, содержащий максимальные элементы в каждой строке;
	int* Result = (int*)malloc(Size_2 * sizeof(int));//динамический одномерный массив, в котором находятся сумма на ГД и произведение на ПД, 

	DVmas = (int far**)malloc(sizeof(int*) * Size);//Двумерный мас
	/* выделение памяти для каждой строки и заполнение массива указателей */
	for (i = 0; i < Size; i++) {
		*(DVmas + i) = (int far*)malloc(Size * sizeof(int));
	}
	//Заполнение двум мас
	Print_DVumer(Size, DVmas);
	
	//одномерный динамический массив, содержащий минимальные элементы в каждом столбце;
	for (j = 0, b = 0; j < Size; j++) {
		int min = INT_MAX;
		for (i = 0; i < Size; i++) {
			if (*(*(DVmas + i) + j) < min) {
				min = *(*(DVmas + i) + j);
			}
		}
		*(ODmin + b++) = min;
	}
	//Печать одномерный динамический массив, содержащий минимальные элементы в каждом столбце;
	cout << "Mini" << endl;
	Print_ODnomer(Size, ODmin);
	// заполнение одномерный динамический массив, содержащий максимальные элементы в каждой строке;
	for (i = 0, b = 0; i < Size; i++) {
		int max = INT_MIN;
		for (j = 0; j < Size; j++) {
			if (*(*(DVmas + i) + j) > max) {	//Заполнение одном мас max
				max = *(*(DVmas + i) + j);
			}
		}
		*(ODmax + b++) = max;
	}
	//Печать одномерный динамический массив, содержащий максимальные элементы в каждой строке;
	cout << "Max" << endl;
	Print_ODnomer(Size, ODmax);
	cout << endl;	cout << endl;	cout << endl;
	//сумма на ГД   произведение на ПД.
	int sum = 0, multiplicat = 1;
	for (i = 0; i < Size; i++) {
		for (j = 0; j < Size; j++) {
			if (i == j) {
				sum += *(*(DVmas + i) + j);
			}
			if ((i + j) == Size - 1) {
				multiplicat *= *(*(DVmas + i) + j);
			}
		}
	}
	cout << sum << "  " << multiplicat << endl;
	*Result= sum;
	*(Result+1) = multiplicat;
	cout << "динамический одномерный массив, в котором находятся сумма на ГД и произведение на ПД " << endl;
	cout << *Result << "  " << *(Result + 1) << endl;


	return 0;
}

