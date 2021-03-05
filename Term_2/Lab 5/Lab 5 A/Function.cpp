#include <iostream>
#include <iomanip>
#include <windows.h> //Для указателеy ** 
#include "Print_.h"

int* Function(int** DVmassiv, int* ODmas_min, int* ODmas_max, int* Psum, int* Pmultiplicat, int Size) {
	int i, j; // Строки и столбцы
	int b;    // индексация для одномерных массивов ODmas_min  и ODmas_max
	int Size_Result = 2;
	int* Massiv_Result = (int*)malloc(Size_Result * sizeof(int));//динамический одномерный массив, в котором находятся сумма на ГД и произведение на ПД, 

		//Заполнение двумерного массива
	Input_DVumer(Size, DVmassiv);
	//Вывод двумерного массива
	Print_DVumer(Size, DVmassiv);

	// заполнение одномерный динамический массив, содержащий минимальные элементы в каждом столбце;
	for (j = 0, b = 0; j < Size; j++) {
		int min = INT_MAX;
		for (i = 0; i < Size; i++) {
			if (*(*(DVmassiv + i) + j) < min) {
				min = *(*(DVmassiv + i) + j);
			}
		}
		*(ODmas_min + b++) = min;
	}
	//Печать одномерный динамический массив, содержащий минимальные элементы в каждом столбце;
	printf("Одномерный динамический массив, содержащий минимальные элементы в каждом столбце\n");
	Print_ODnomer(Size, ODmas_min);

	// заполнение одномерный динамический массив, содержащий максимальные элементы в каждой строке;
	for (i = 0, b = 0; i < Size; i++) {
		int max = INT_MIN;
		for (j = 0; j < Size; j++) {
			if (*(*(DVmassiv + i) + j) > max) {	//Заполнение одном мас max
				max = *(*(DVmassiv + i) + j);
			}
		}
		*(ODmas_max + b++) = max;
	}

	//Печать одномерный динамический массив, содержащий максимальные элементы в каждой строке;
	printf("Одномерный динамический массив, содержащий максимальные элементы в каждой строке\n");
	Print_ODnomer(Size, ODmas_max);

	//сумма на ГД   произведение на ПД.
	int sum = 0, multiplicat = 1;
	for (i = 0; i < Size; i++) {
		for (j = 0; j < Size; j++) {
			if (i == j) {
				*Psum += *(*(DVmassiv + i) + j);
			}
			if ((i + j) == Size - 1) {
				*Pmultiplicat *= *(*(DVmassiv + i) + j);
			}
		}
	}
// Записываем  сумму на ГД и произведение на ПД в массив, который вернет функция
	*Massiv_Result = *Psum;
	*(Massiv_Result + 1) = *Pmultiplicat;

	return Massiv_Result;
}