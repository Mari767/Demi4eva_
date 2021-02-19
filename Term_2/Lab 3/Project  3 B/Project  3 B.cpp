//ЛАБОРАТОРНАЯ РАБОТА № 3Б
//Из одномерного массива А сформировать массивы B < 0, C > 0, D = 0. 
//Переписать в массив А сначала нулевые элементы, потом отрицательные и положительные.

#include <iostream>
#include <iomanip>
#define N 30
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int A[N];
	int c_ = 0, b_ = 0, d_ = 0;// Для подсчета итераций
	int b = 0, c = 0, d = 0;  // кол-во элементов в массивах

	for (int i = 0; i < N; i++) { // заполнение массива А и подсчет количества элементов в остальных массивах
		*(A + i) = rand() % 101 - 50;
		if (*(A + i) < 0) { ++b; }
		if (*(A + i) > 0) { ++c; }
		if (*(A + i) == 0) { ++d; }
	}
	cout << "Массив В содержит " << b << " элемент(ов) \nМассив С содержит " << c << " элемент(ов) \nМассив D содержит " << d <<" элемент(ов)\n"<< endl;
	//cout << "b=" << b << ", c=" << c << ", d=" << d << endl;

	cout << "Задан массив А " << endl;
	for (int i = 0; i < N; i++) {//  печать массива А
		cout << setw(4) << *(A + i);
	}cout << endl << endl;
	int* B = (int*)malloc(b * sizeof(int));
	int* C = (int*)malloc(c * sizeof(int));
	int* D = (int*)malloc(d * sizeof(int));

	for (int i = 0; i < N; i++) { //Раскидываю элементы исходного массива А по массивам B, С, D  

		if (*(A + i) < 0) {

			*(B + b_) = *(A + i);
			b_++;
		}
		if (*(A + i) > 0) {

			*(C + c_) = *(A + i);
			c_++;
		}
		if (*(A + i) == 0) {

			*(D + d_) = *(A + i);
			d_++;
		}
	}
	cout << "Массив В" << endl; // Вывод массива B
	for (int i = 0; i < b; i++) {
		cout << setw(4) << *(B + i);
	}cout << endl  << endl;

	cout << "Массив С" << endl; // Вывод массива C
	for (int i = 0; i < c; i++) {
		cout << setw(4) << *(C + i);
	}cout << endl << endl;

	cout << "Массив D" ; // Вывод массива D
	if (*D != 0) {
		cout << " пуст " << endl << endl;
	}
	else {
		cout << endl;
		for (int i = 0; i < d; i++) {
			cout << setw(4) << *(D + i);
		}cout << endl << endl;
	}

	cout << "Массив А, в который переписаны сначала нулевые элементы, потом отрицательные и положительные." << endl;
	int i; int j = 0; int n = 0;
	for (i = 0; i < b; i++) {
		*(A + i) = *(B + i);
	}
	for ( ; i < b + c; i++, j++) {
		*(A + i) = *(C + j);
	}
	for ( ; i < b + c + d; i++, n++) {
		*(A + i) = *(D + n);
	}
	for (int i = 0; i < N; i++) {//  печать массива А
		cout << setw(4) << *(A + i);
	}cout << endl << endl;

	free(B);
	free(C);
	free(D);
	return 0;
}