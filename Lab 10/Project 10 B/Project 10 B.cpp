//Для двумерного массива сделать :
//1.	Функции заполнения и печати двумерного массива
//2.	Функцию, которая принимает двумерный массив, и возвращает количество положительных элементов в одной любой строке
//В функции main применить функцию 2 к каждой строке двумерного массива

#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
#define N 10
#define M 6

void filling(int massiv[][M]);
void print(int massiv[][M]);
int arr(int massiv[][M], int i);

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int i;
	int mas[N][M];
	filling(mas);
	print(mas);

	cout << "Введите число от 0  до " << N - 1 << endl;
	cin >> i;
	if (i < 0 || i >= N) {
		cout << "Такой строки нет." << endl;
	}

	else {
		cout << "В  строке " << i << " находится " << arr(mas, i) << "  положительных элемента." << endl << endl;
	}
	cout << "Применнение функции arr к каждой строке двумерного массива: " << endl;
	for (int i = 0; i < N; i++) {
		cout << "В  строке " << i << " находится " << arr(mas, i) << "  положительных элемента." << endl;
	}




	return 0;
}

void filling(int massiv[][M]) {// Заполнение
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			massiv[i][j] = rand() % 60 - 20;
		}
	}
	return;
}

void print(int massiv[][M]) {// Печать
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << setw(4) << massiv[i][j];
		}cout << endl;
	}cout << endl;
	cout << endl;
	return;
}

int arr(int massiv[][M], int i) {// кол-во положительных чисел в строке

	int p = 0;//считает элементы
	for (int j = 0; j < M; j++) {
		int k = massiv[i][j];
		if (k >= 0) {
			p = p + 1;
		}
	}
	return  p;
}


