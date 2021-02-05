// ЛАБОРАТОРНАЯ РАБОТА № 9Б   
//Перемножение двух матриц.Размер матриц вводить с экрана.Осуществить проверку на 	возможность перемножения.

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");
	srand(time(NULL));
	int a, b, c, d, i, j, n, sum, p;

	printf("Задайте размеры матриц.\na-количество строк первой матрицы;\nb-количество столбцов первой матрицы; \nc-количество строк второй матрицы;\nd-количество столбцов второй матрицы;\na=");
	scanf_s("%d", &a);
	printf("b=");
	scanf_s("%d", &b);
	printf("c=");
	scanf_s("%d", &c);
	printf("d=");
	scanf_s("%d", &d);

	//проверкa на 	возможность перемножения.

	if (b != c) {
		printf("Умножение этих двух матриц невозможно.\n");
	}

	// Заполнение матриц

	else if (a&b&c&d>0)  {
		printf("Заполните первую матрицу \n");
		int** mat1 = new int* [a];
		for (i = 0; i < a; i++) {// creation 
			mat1[i] = new int[b];
		}
		for (i = 0; i < a; i++) {
			for (j = 0; j < b; j++) {
				//mat1[i][j] = ++n;
				//mat1[i][j] = rand() % 20 - 10;
				cin >> mat1[i][j];
			}
		}
		cout << endl;
		cout << "Заполните вторую матрицу" << endl;
		int** mat2 = new int* [b];
		for (i = 0; i < b; i++) {// creation 
			mat2[i] = new int[d];
		}
		for (i = 0; i < b; i++) {
			for (j = 0; j < d; j++) {
				cin >> mat2[i][j];
				//mat2[i][j] = ++n;
				//mat2[i][j] = rand() % 20 - 10;
			}
		}
		cout << "Первая матрица: " << endl;//   Вывод матриц
		for (i = 0; i < a; i++) {
			for (j = 0; j < b; j++) {
				cout << setw(4) << mat1[i][j];
			}cout << endl;
		}
		cout << endl;
		cout << "Вторая матрица: " << endl;
		for (i = 0; i < c; i++) {
			for (j = 0; j < d; j++) {
				cout << setw(4) << mat2[i][j];
			}cout << endl;
		}
		cout << endl;

		cout << "Произведение матриц: " << endl;

		int** mat3 = new int* [a];// creation 3
		for (i = 0; i < a; i++) {
			mat3[i] = new int[d];
		}

		for (i = 0; i < a; i++) {
			for (j = 0; j < d; j++) {
				n = 0;
				sum = 0;

				for (int u = 0; u < b; u++) {
					p = mat1[i][n] * mat2[n][j];
					++n;
					sum += p;
				}
				mat3[i][j] = sum;

				cout << setw(4) << mat3[i][j];

			} cout << endl;
		}

		for (i = 0; i < a; i++) {// delete 1
			delete[] mat1[i];
		}
		delete[] mat1;
		for (i = 0; i < c; i++) {// delete 2
			delete[] mat2[i];
		}
		delete[] mat2;
	}
	else {
		cout << "Вы ввели некорректный данные." << endl;
	}
	return 0;
}

