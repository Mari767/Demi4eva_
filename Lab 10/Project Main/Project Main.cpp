//Общее задание :
//•  Создать функцию, которая на вход принимает одномерный массив.Из одномерного массива размером M x N элементов
//    создается двухмерный массив с M столбцами и N строками.Данный двухмерный массив обрабатывается согласно варианту.
//     7 B                   Сделать зеркальное отображение матрицы по горизонтали(не обязательно квадратной)
//    Потом этот двухмерный массив преобразовывается обратно в одномерный и возвращается из функции.

//•  Одномерный массив печатается в основной программе, двумерный – в функции.

#include <iomanip>
#include <iostream>
using namespace std;
#define N 5
#define M 4

void changarray (int mas[]);

int main() {
	setlocale(LC_ALL, "ru");
	
	int i, j;
	int a = 0;
	int mas0[N * M];

	cout << "Массив напечатанный из основной программы:" << endl;
	for (i = 0; i < N * M; i++) {
		mas0[i] = i + 1;
		cout << setw(4) << mas0[i];
	}cout << endl;
	cout << endl;
		
	changarray(mas0);
	cout << "Массив напечатанный из основной программы " << endl;
	
	for (i = 0; i < N * M; i++) {
		cout << setw(4) << mas0[i];
	}
	cout << endl;

	return 0;
}



void changarray(int mas[]) {
	int i, j, k;
	int mas1[N][M];
	cout << "Работа в функции" << endl;
	cout << "Массив преобразован в двумерный." << endl;
	for (i = 0; i < N; i++) {// из одномерного в двумерный
		for (j = 0; j < M; j++) {
			k = i * M + j;
			mas1[i][j] = mas[k];
			cout << setw(4) << mas1[i][j];
		}cout << endl;
	}cout << endl;


	/*for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cout << setw(4) << mas1[i][j];
		}cout << endl;
	}cout << endl;*/

	cout << "Зеркальное отображение матрицы по горизонтали" << endl;
	int t;   
	for (i = 0; i < N / 2; i++) {//зеркальное отображение матрицы по горизонтали
		for (j = 0; j < M; j++) {
			t = mas1[i][j];
			mas1[i][j] = mas1[N - i - 1][j];
			mas1[N - i - 1][j] = t;
		}
	}
	for (i = 0; i < N; i++) {  //Печать зеркального массива
		for (j = 0; j < M; j++) {
			cout << setw(4) << mas1[i][j];
		}cout << endl;
	}cout << endl;


	for (i = 0; i < N; i++) {  // Пребразование двумерного мас. в одномерный
		for (j = 0; j < M; j++) {
			mas[i * M + j] = mas1[i][j];
			//cout << setw(4) << mas2[i * M + j];
		}
	}
	/*for (i = 0; i < N * M; i++) { //  Печать измененного массива 
		cout << setw(4) << mas[i];
	}cout << endl;*/
	return;
}
