#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	system("chcp 1251");
	system("cls");
	srand(time(NULL));
	printf("Разместить все элементы с положительными значениями в левой части массива, элементы с отрицательными значениями - в правой, а нули - между ними.\nРазмерность массива 100, диапазон значений от -100 до 100\n\n");
	printf("Первоначальный массив\n\n");

	const int m = 100;//Количество элементов в массиве
	int t, i, k;// t-для обмена   i, k- индексы в массиве 
	int mas[m];

	//заполнение массива случайными числами
	for (int i = 0; i < m; i++) {
		mas[i] = rand() % 201 - 100;
		printf("%5d", mas[i]);
	}
	printf("\n\n");

	//    ОБМЕН
	
	for (i=0; i<m-1; i++) {
		for (k = i; k < m; k++) {
			if (mas[i] < mas[k]) {
				t = mas[i];
				mas[i] = mas[k];
				mas[k] = t;
			}
		}
	}
	printf("\n\n");

	printf("Отредактированный массив\n\n");
	for (i = 0; i < m ; i++) {
		printf("%5d", mas[i]);
	}
	printf("\n\n");
}