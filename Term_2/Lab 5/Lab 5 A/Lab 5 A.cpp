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
#include <windows.h> //Для указателей ** 
#include "Print_.h"
#include "Function.h"

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int Size;
	int far** DVmas; /* указатель на массив указателей */
	//Указатели на сумму на ГД и произведение на ПД
	int Sum = 0, multiplicat = 1;
	int* Psum = &Sum, * Pmultiplicat = &multiplicat;

	printf( "Введите размер динамического двумерного массива\n" );
	scanf_s("%d", &Size);

	int* ODmin = (int*)malloc(Size * sizeof(int));// одномерный динамический массив, содержащий минимальные элементы в каждом столбце;
	int* ODmax = (int*)malloc(Size * sizeof(int));//  одномерный динамический массив, содержащий максимальные элементы в каждой строке;

	DVmas = (int far**)malloc(sizeof(int*) * Size);//Двумерный мас соцдание
	/* выделение памяти для каждой строки и заполнение массива указателей */
	for (int i = 0; i < Size; i++) {
		*(DVmas + i) = (int far*)malloc(Size * sizeof(int));
	}

	int* Mas_result = Function(DVmas, ODmin, ODmax, Psum, Pmultiplicat, Size);

	printf("динамический одномерный массив, в котором находятся сумма на ГД и произведение на ПД\n ");
	printf("%3d   %3d", *Mas_result, *(Mas_result + 1));
	
	//освобожение памяти
	free(ODmin);
	free(ODmax);
	free(Mas_result);
	for (int i = 0; i < Size; i++) {
		free(*(DVmas + i));
	}
	free(DVmas);

	return 0;
}

