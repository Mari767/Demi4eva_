//ЛАБОРАТОРНАЯ РАБОТА № 7Б
//Записать в файл(f1) весь массив(mas1)10 чисел.
//Считать поэлементно в другой массив и найти сумму четных(fread(), fwrite()).

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "Function.h"
 
//#pragma warning(disable : 4996)

int main() {
	setlocale(LC_ALL, "ru");
	srand(time_t(NULL));
	int i;
	int Size = 10;
	int Sum = 0;
	int* mas_1 = new int[Size];
	int* mas_2 = new int[Size];
	FILE* f1 = NULL;
	// Заполнение и печать mas_1
	Input_mas(mas_1, &Size);
	Print_mas(mas_1, &Size);

	//Записать в файл(f1) весь массив(mas_1)10 чисел.
	f1 = fopen("file_1.dat", "wb");
	Check(f1);
	i = 0;
	fwrite((mas_1 + i), sizeof(int), Size, f1);

	fclose(f1);
	printf("\n\n1 -> Массив(mas_1) из %d чисел записан в файл(f1) \n", Size);
	
	//Считать поэлементно в другой массив и найти сумму четных.
	f1 = NULL;
	f1 = fopen("file_1.dat", "rb");
	Check(f1);
	i = 0;
	while (!feof(f1))
	{
		fread((mas_1 + i), sizeof(int), 1, f1);
		*(mas_2 + i) = *(mas_1 + i);

		if (*(mas_1 + i) % 2 == 0) { // Подсчет суммы четных чисел
			Sum += *(mas_2 + i);
		}
		i++;
	}
	printf("\n2 -> Массив(mas_1) считан из  файла(f1) в mas_2  \n\n");
	Print_mas(mas_2, &Size);
	printf("\n\nCуммa четных чисел равна %d\n\n", Sum);

	fclose(f1);
	delete[] mas_1;
	delete[] mas_2;
	return 0;
}