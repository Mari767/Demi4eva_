//Вставить в массив в любое место k элементов.
//Удалить из массива из любого места k элементов.
//Проверка на правильность ввода позиции и количества вставляемых / удаляемых элементов
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int main() {
	system("chcp 1251");
	system("cls");
	//srand(time(/*NULL*/));

	int mas[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int a = 0;//индекс
	int k;//   кол-во переставных елементов
	int k_;// позиция переставных елементов
	int i;
	for (i = 0; i < N; i++) {// Печать изначального масиива с резервом.
		printf("%4d", mas[i]);
	}
	printf("\n\n\n\n\n");

	//k = 1;      //        УДАЛЯЮ кол-во елементов           c 0 gjpbwbb
	//k_ = 0;     //        c позиции 
	//for (i = 0; i < N-1 ; i++) {
	//	mas[i] = mas[i + 1];
	//	printf("%4d", mas[i]);
	//}
	printf("\n\n");

	k = 1;      //        УДАЛЯЮ елемент
	k_ = 5;     //        c позиции 
	for (i = 0; i < N - 1; i++) {
		printf("%4d", mas[i]);
		
		/*if (i == k_) {
			mas[i] = mas[i + 1];
			printf("%4d", mas[i]);
		}*/
		/*else {
			printf("%4d", mas[i]);
		}*/


	}
	printf("\n\n\n\n\n");

	










	printf("\n\n\n\n\n");
 }
//printf("Первоначальный массив\n");
	//for (int i = 0; i < A; i++) {
	//	mas[i] = rand() % 101 - 45;// -20  20
	//	printf("%5d",mas[i]);
	//}
