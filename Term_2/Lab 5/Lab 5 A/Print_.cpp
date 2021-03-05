#include <iostream>
#include <iomanip>
//using namespace std;

void Input_DVumer(int Size, int** Massiv) { //Это пока заполнение
	int i = 0, j = 0;
	for (; i < Size; i++) {
		for (j = 0; j < Size; j++) {
			*(*(Massiv + i) + j) = rand() % 100 - 50;
		}
	}
}
void Print_DVumer(int Size, int** Massiv) {
	int i = 0, j = 0;
	for (; i < Size; i++) {
		for (j = 0; j < Size; j++) {
			printf("%5d", *(*(Massiv + i) + j) );
		}printf("\n");
	}printf("\n\n");
}


void Print_ODnomer(int Size, int* Massiv) {
	int i = 0;
	for (; i < Size; i++) {
		printf("%5d", *(Massiv + i));
	}printf("\n\n");
}