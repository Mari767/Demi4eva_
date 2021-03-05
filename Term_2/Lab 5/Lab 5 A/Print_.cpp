#include <iostream>
#include <iomanip>
using namespace std;

void Print_DVumer(int Size, int** Massiv) { //Это пока заполнение
	int i = 0, j = 0;
	for (; i < Size; i++) {
		for (j = 0; j < Size; j++) {
			*(*(Massiv + i) + j) = rand() % 100 - 50;
			cout << setw(4) << *(*(Massiv + i) + j);
		}cout << endl;
	}cout << endl << endl;
}

void Print_ODnomer(int Size, int* Massiv) {
	int i = 0;
	for (; i < Size; i++) {
		cout << setw(4) << *(Massiv + i);
	}cout << endl << endl;
}