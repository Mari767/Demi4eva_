#include <iostream>

void Input_mas(int* Massiv, int* Size) {
	int i;
	for (i = 0; i < *Size; i++) {
		*(Massiv + i) = rand() % 10;
	}
}

void Print_mas(int* Massiv, int* Size) {
	int i;
	for (i = 0; i < *Size; i++) {
		printf("%4d", *(Massiv + i));
	}
}

void Check(FILE* fptr) {
	if (fptr == NULL) {
		exit(0);
		printf("Ошибка открытия файла");
	}
}
