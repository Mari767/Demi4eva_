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
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//#include <alloc.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int Size, i, j, R, b;
	int k = 0;

	int far** DVmas; /* указатель на массив указателей */
	cout << "Введите размер динамического двумерного массива" << endl;
	cin >> Size;
	int* ODmin = (int*)malloc(Size * sizeof(int));// Одномерный. минимальные значения
	int* ODmax = (int*)malloc(Size * sizeof(int));// Одномерный. максимальные значения
	DVmas = (int far**)malloc(sizeof(int*) * Size);//Двумерный мас
	/* выделение памяти для каждой строки и заполнение массива указателей */
	for (i = 0; i < Size; i++) {
		*(DVmas + i) = (int far*)malloc(Size * sizeof(int));
	}
	//Заполнение двум мас
	for (i = 0; i < Size; i++) {
		for (j = 0; j < Size; j++) {
			*(*(DVmas + i) + j) = rand() % 100 - 50;
			cout << setw(4) << *(*(DVmas + i) + j);
		}cout << endl;
	}cout << endl << endl;

	for (j = 0, b = 0; j < Size; j++) {
		int min = INT_MAX;
		for (i = 0; i < Size; i++) {
			if (*(*(DVmas + i) + j) < min) {	//Заполнение одном мас mini
				min = *(*(DVmas + i) + j);
			}
		}
	*(ODmin + b++) = min;
	}
	//Печать одном мас
	cout << "Mini" << endl;
	for (i = 0; i < Size; i++) {
		cout << setw(4) << *(ODmin + i);
	}cout << endl << endl;

	for (i = 0, b = 0; i < Size; i++) {
		int max = INT_MIN;
		for (j = 0; j < Size; j++) {
			if (*(*(DVmas + i) + j) > max) {	//Заполнение одном мас max
				max = *(*(DVmas + i) + j);
			}
		}
		*(ODmax + b++) = max;
	}
	//Печать одном мас
	cout << "Max" << endl;
	for (i = 0; i < Size; i++) {
		cout << setw(4) << *(ODmax + i);
	}

	return 0;
}

