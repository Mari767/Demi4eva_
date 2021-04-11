//ЛАБОРАТОРНАЯ РАБОТА № 7В
//Записать в файл(не массив) 20 чисел и найти сумму 2, 5, 9 элементов.
//Найти минимальное и на его место записать число 999 (fseek(), fwrite(), fread()).

#include <iostream>
#include <stdio.h>
#include "Function.h"
#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable : 4996)

int main() {
	setlocale(LC_ALL, "ru");
	srand(time_t(NULL));
	int number; // число
	int Size = 20;   // количество чисел
	int Sum = 0;
	int min = INT_MAX;
	int Location;

	FILE* f = NULL;
	f = fopen("file.txt", "wt");
	Check(f);

	printf("Подсчет позиций начинается с нуля.\n");
	for (int i = 0; i < Size; i++) {  //  генерация и запись числа в файл
		number = rand() % 100-30;
		printf("%4d", number);           
		fwrite(&number, sizeof(int), 1, f);
	}printf("\n");
	fclose(f);

	// Нахождение суммы 2, 5, 9 чисел
	Read_Sum(f, 2, &Sum);
	Read_Sum(f, 5, &Sum);
	Read_Sum(f, 9, &Sum);
	printf("\nSum (2, 5, 9) = %d\n", Sum);

	f = NULL;
	f = fopen("file.txt", "r+t");
	Check(f);

	// Поиск минимального числа и его позиции
	for (int i = 0; i<Size; i++) {
		fread(&number, sizeof(int), 1, f);
		if (min > number) {
			min = number;
			Location = i;
		}
	}
	printf("Наименьшее число = %d, число находится на %d позиции.\n", min, Location);
	//замена минимального числа на 999 (запись в файл)
	fseek(f, Location * sizeof(int), SEEK_SET);
	number = 999;
	fwrite(&number, sizeof(int), 1, f);
	// Поиск о позиции и печать из файла обновленного набора чисел
	fseek(f, 0, SEEK_SET);
	printf("\nВывод нового набора чисел.\n");
	for (int i = 0; i < Size; i++) {
		fread(&number, sizeof(int), 1, f);
		printf("%4d", number);
	}printf("\n\n");
	fclose(f);
	return 0;
}