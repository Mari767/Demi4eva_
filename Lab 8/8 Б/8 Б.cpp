//Вставить в массив в любое место k элементов.
//Удалить из массива из любого места k элементов.
//Проверка на правильность ввода позиции и количества вставляемых / удаляемых элементов
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define N 15
#define M 50// rezerv
int mask[M];
int mas[N + M];

int main() {
	system("chcp 1251");
	system("cls");
	srand(time(NULL));

	int a;// ответ пользователя 
	int k;//   кол-во переставных елементов
	int k_;// позиция переставных елементов
	int K;   //какой елемент добавляю
	int u;// для массива Добавляемых елементов
	int i;

	for (i = 0; i < N; i++) {      // задаю массив
		mas[i] = i + 1;
	}
	//for (i = 0; i < N; i++) {      // задаю массив РАНДОМАЙЗЕР
	//	mas[i] = rand()%71-20;//-20  50
	//}
	printf("Первоначальный массив: ");
	for (i = 0; i < N; i++) {//     Печать изначального масиива с резервом. ===========================
		printf("%4d", mas[i]);
	}
	printf("\n");
	printf("\n\nИндекс элемента:       ");
	
	//Ввод данных
	printf("Вы хотите удалить или добавить елементы массива\n");
	printf("1) удалить\n");
	printf("2) добавить\n");
	scanf_s("%d", &a);
	if (a != 1 && a != 2) {
		printf("Вы некоректно ответили.\n");
	}

	//   Добавление и удаление
	switch (a) {
	case 1:
		printf("Сколько елементов \nk=");  	//  Ввод данных
		scanf_s("%d", &k);
		if (k > N || k < 0) {
			printf("Вы некоректно ответили.\n");
			break;
		}
		else if (k == 0) {
			printf("\nИзмененный массив: ");
			for (i = 0; i < N; i++) {//     Печать изначального масиива
				printf("%4d", mas[i]);
			}
			printf("\nИндексы элементов: ");
			for (i = 1; i < N + 1; i++) {//     Печать индексов
				printf("%4d", i);
			}
			break;
		}
		printf("С какой позиции ");
		scanf_s("%d", &k_);
		k_ = k_ - 1;
		if (k_ > N||k_<1) {
			cout << "Такой позиции нет." << endl;
			break;
		}
		if ((k + k_ ) > N) {
			cout << "Удаление "<<k<<" елементов  начиная с этой позиции невозможно\nИзмененный массив:" << endl;
			int p = N - k_;
			for (i = 0; i < k_; i++) {
				printf("%4d", mas[i]);
			}
			cout << endl << "Удалено "<<p<<" элементов" << endl;
			break;
		}
		printf("\nПервоначальный массив: ");
		for (i = 0; i < N; i++) {
			printf("%4d", mas[i]);
		}
		printf("\nИндексы элементов      ");
		for (i = 1; i < N + 1; i++) {//     Печать индексов
			printf("%4d", i);
		}cout << endl;
		printf("\nИзмененный массив:     ");
		for (i = 0; i < N - k; i++) {
			if (i < k_) {
				printf("%4d", mas[i]);
			}
			else {
				mas[i] = mas[i + k];
				printf("%4d", mas[i]);
			}
		}
		printf("\nИндексы элементов      ");
		for (i = 1; i < N -k+1; i++) {//     Печать индексов
			printf("%4d", i);
		}
		printf("\n\n");
		break;

	case 2:
		printf("Сколько елементов \nk="); //    Ввод данных
		scanf_s("%d", &k);
		if (k > M || k < 0) {
			printf("Вы не коректно ответили.\n");
			break;
		}
		printf("На какую позицию ");
		scanf_s("%d", &k_);

		if (k_ > N) {
			printf("Такой позиции нет.\n");
			break;
		}

		k_ = k_ - 1;
		
		if (k_ > N  || k_ < 0) {
			printf("Вы не коректно ответили.\n");
			break;
		}
		

		printf("Введите элемент(ы) \n");
		for (u = 0; u <= k - 1; u++) {// Заполнение массива, который содержит  добавляемые елементы
			printf("%d) ", u + 1);
			scanf_s("%d", &K);
			mask[u] = K;
		}
		u = u - 1;//u= u+1 при выходе из цикла

		printf("Первоначальный массив: ");
		for (i = 0; i < N; i++) {//     Печать изначального масcива 
			printf("%4d", mas[i]);
		}
		printf("\nИндексы элементов      ");
		for (i = 1; i < N + 1; i++) {//     Печать индексов
			printf("%4d", i);
		}cout << endl;
		for (i = N + k - 1; i > -1; i--) {//  MAS[N+k]        добавляет и переворачивает  ++++++++++++++++++++++++
			if (i > k_ + k - 1) {
				mas[i] = mas[i - k];
				//printf("%4d", mas[i]);
			}
			else if (i == k_ + k - 1) {

				for (int j = 0; u >= 0; j++, u--) {
					mas[i - j] = mask[u];
					//printf("%4d", mas[i]);
				}
			}
			else if (i < k_) {
				//printf("%4d", mas[i]);
			}
		}
		printf("\n\nИзмененный массив:     ");

		for (i = 0; i < N + k; i++) {//  Печать конечного масиива. ==========================
			printf("%4d", mas[i]);
		}
		printf("\nИндексы элементов      ");
			for (i = 1; i < N+k+1; i++) {//     Печать индексов
				printf("%4d", i);
		}
		printf("\n\n");
		break;
	}
	return 0;
}