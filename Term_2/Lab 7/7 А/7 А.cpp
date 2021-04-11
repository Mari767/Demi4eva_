//ЛАБОРАТОРНАЯ РАБОТА № 7А
//Записать в файл(f1) массив(mas1) 10 чисел.Переписать из(f1) в другой массив(mas2) и в другой файл(f2).
//Распечатать(mas2).Из файла(f2) переписать данные последовательно в переменную х и распечатать(fprintf(), fscanf())

#include <iostream>
#include <stdio.h>
#include "Function.h"
#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable : 4996)
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	srand(time_t(NULL));
	int x, i;
	int Size = 10;
	int* mas_1 = new int[Size];
	int* mas_2 = new int[Size];
	FILE* f1;
	FILE* f2;
	// Заполнение массива
	Input_mas(mas_1, &Size);

	// 1   Запись в файл(f1) массив(mas1) 10 чисел
	printf("1 -> Запись в файл(f1) массив(mas_1) %d чисел\n", Size);
	f1 = NULL;
	f1 = fopen("f1.txt", "wt");
	Check(f1);

	for (i = 0; i < Size; i++) {
		fprintf(f1, "%4d", *(mas_1 + i));
	}
	fclose(f1);

	//Перепись из(f1) в другой массив(mas2) и в другой файл(f2).
	printf("\n2 -> Перепись из(f1) в другой массив(mas2) и в другой файл(f2).\n");
	f1=f2=NULL;
	f1 = fopen("f1.txt", "r");
	Check(f1);
	f2 = fopen("f2.txt", "w");
	Check(f2);

	for (i = 0; i < Size; i++) {
		fscanf(f1, "%4d", (mas_1 + i));   //Чтение данных из f1
		*(mas_2 + i) = *(mas_1 + i);      // копировние данных из mas_1 B mas_2
		fprintf(f2, "%4d", *(mas_1 + i)); // запись данных в f2
	}
	fclose(f1);
	fclose(f2);

	printf("\n3 -> Печать второго массива \n");
	for (i = 0; i < Size; i++) {
		printf("%4d", *(mas_2 + i));
	}printf("\n");

	//Из файла(f2) переписать данные последовательно в переменную х и распечатать
	printf("\n4 -> Из файла(f2) переписать данные последовательно в переменную х и распечатать.\n");
	f2 = NULL;
	f2 = fopen( "f2.txt", "r");
	Check(f2);

	for (i = 0; i < Size; i++) {
		fscanf_s(f2, "%4d", (mas_2 + i));
		x = *(mas_2 + i);
		printf("%4d", x);
	}
	fclose(f2);
	printf("\n\n");
	return 0;
}
