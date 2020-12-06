// ЛАБОРАТОРНАЯ РАБОТА № 9А   
//В двумерном массиве(каждый раз работать с исходным массивом) :
//	а) найти максимальный в каждой строке  и поменять его местами с первым элементом 	этой же строки;
//	б) найти минимальный в каждом столбце и поменять его местами с последним 	элементом этого же столбца;

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#define N 4
#define M 6
using namespace std;
int mas[N][M];
int mas_a[N][M];
int mas_b[N][M];

int main()
{
	setlocale(LC_ALL, "Ru");
	srand(time(NULL));

	int i, j, b, c, I, J;
	int max, min;
	int a = 0;
	for (i = 0; i < N; i++) {              // Изначальный массив
		for (j = 0; j < M; j++) {
			//mas[i][j] = ++a;
			mas[i][j] = rand() % 101 - 50;
		}
	}
	cout << "а) найти максимальный в каждой строке  и поменять его местами с первым элементом 	этой же строки;  \nб) найти минимальный в каждом столбце и поменять его местами с последним 	элементом этого же столбца;" << endl;
	cout <<"\nИсходный массив" << endl;
	for (i = 0; i < N; i++) {              //печать
		for (j = 0; j < M; j++) {
			cout << setw(4) << mas[i][j];
		}cout << endl;
	}
	cout << endl; 
	for (i = 0; i < N; i++) {              //копирование исходного массива
		for (j = 0; j < M; j++) {
			mas_b[i][j] = mas_a[i][j] = mas[i][j];
		}
	}

	for (i = 0; i < N; i++) { //            наибольшее в строке/////
		max = INT_MIN;
		for (j = 0; j < M; j++) {
			c = mas_a[i][j];
			if (max < c) {
				max = c;
				I = i;
				J = j;
			}
		}
		mas_a[I][J] = mas_a[i][0];
		mas_a[i][0] = max;
	}
	cout<<"Задание А"<<endl;
	for (i = 0; i < N; i++) {//           print
		for (j = 0; j < M; j++) {
			cout << setw(4) << mas_a[i][j];
		}cout << endl;
	}cout << endl;

	a = 0;
	
	for (j = 0; j < M; j++) { //             наименьшее в столбике////////////////////////////////////////
		min = INT_MAX;
		for (i = 0; i < N; i++) {
			b = mas_b[i][j];
			if (min > b) {
				min = b;
				I = i;
				J = j;
			}
		}
		mas_b[I][J] = mas_b[N-1][j];
		mas_b[N - 1][j] = min;
	}
	cout << "Задание Б" << endl;
	for (i = 0; i < N; i++) {//             print
		for (j = 0; j < M; j++) {
			cout << setw(4) << mas_b[i][j];
		}cout << endl;
	}

	return 0;
}

