//ЛАБОРАТОРНАЯ РАБОТА № 3Б
//Из одномерного массива А сформировать массивы B < 0, C>0, D = 0. 
//Переписать в массив А сначала нулевые элементы, потом отрицательные и положительные.

#include <iostream>
#include <iomanip>
//#include <>
#define N 30
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int A[N];
	int b = 0, c = 0, d = 0;
	for (int i = 0; i < N; i++) {
		A[i] = rand() % 6;
		if (A[i] < 0) { ++b; }
		if (A[i] > 0) { ++c; }
		if (A[i] == 0) { ++d; }
	}

	cout << "b=" << b << " c=" << c << " d=" << d << endl;

	cout << "Задан массив А " << endl;
	for (int i = 0; i < N; i++) {
		cout << setw(4) << A[i];
	}cout<<endl<<endl;
	int* B = new int[b];
	int* C = new int[c];
	int* D = new int[d];
	for (int i = 0; i < N; i++) {

		if (A[i] < 0) { 
			int j = 0;
			B[j]=A[i]; 
			//cout << setw(4) << B[j];
			j++;
		}
		if (A[i] > 0) {
			int j = 0;
			C[j] = A[i];
			//cout << setw(4) << C[j];
			j++;
		}
		if (A[i] == 0) {
			int j = 0;
			D[j] = A[i];
			//cout << setw(4) << D[j];
			j++; 
		}
	}
	cout << "Массив В" << endl;
	for (int i = 0; i < b; i++) {
		cout << setw(4) << B[i];
	}cout << endl << endl;

	cout << "Массив С" << endl;
	for (int i = 0; i < c; i++) {
		cout << setw(4) << C[i];
	}cout << endl << endl;
	
	cout << "Массив D" << endl;
	for (int i = 0; i < d; i++) {
		cout << setw(4) << D[i];
	}cout << endl << endl;


	delete[] B;
	delete[] C;
	delete[] D;
	return 0;
}