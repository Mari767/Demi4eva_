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

	int(*Pointer_Sum)(int* Massiv, int Size);           //Создание указателя  Pointer_Sum
	int(*Pointer_Multiplicat)(int* Massiv, int Size);   //Создание указателя  Pointer_Multiplicat

	Pointer_Sum = Sum;                                  // Указатель на ф-цию Sum
	Pointer_Multiplicat = Multiplication;               // Указатель на ф-цию Multiplication

	int sum, mult;

	int Size;
	printf("Введите размер массива\n");
	scanf_s("%d", &Size);

	//создание массива и печать
	int* Mas = (int*)malloc(sizeof(int) * Size);
	for (int i = 0; i < Size; i++) {
		*(Mas + i) = rand() % 100 - 50;
		printf("%4d", *(Mas + i));
	}printf("\n\n");

	sum = Pointer_Sum(Mas, Size);         // вызов функций и присваевание возвращаемых элементов
	mult = Pointer_Multiplicat(Mas, Size);
	
	printf("%3d   %3d", sum, mult);

	free(Mas);
	return 0;
}