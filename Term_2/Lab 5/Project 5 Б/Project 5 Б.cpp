/*ЛАБОРАТОРНАЯ РАБОТА № 5Б
Создать 2 функции с одинаковыми параметрами(одна считает сумму положительных,
	вторая – произведение отрицательных).
	Создать указатель на функцию для вызова этих функций.*/

#include <iostream>
#include <iomanip>
#include "Sum.h"
#include "Multipl.h"

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int sum, mult;
	int Size;
	int(*Pointer_Func)(int* Massiv, int Size);           //Создание указателя  Pointer_Func

	printf("Введите размер массива\n");
	scanf_s("%d", &Size);

	//создание массива и печать
	int* Mas = (int*)malloc(sizeof(int) * Size);
	for (int i = 0; i < Size; i++) {
		*(Mas + i) = rand() % 100 - 50;
		printf("%4d", *(Mas + i));
	}printf("\n\n");

	Pointer_Func = Sum;                          // Указатель на ф-цию Sum
	sum = Pointer_Func(Mas, Size);         // вызов функций и присваевание возвращаемых элементов

	Pointer_Func = Multiplication;               // Указатель на ф-цию Multiplication
	mult = Pointer_Func(Mas, Size);
	
	printf("Сумма положительных элементов %3d \nПроизведение отрицательных элементов %3d\n", sum, mult);

	free(Mas);
	return 0;
}