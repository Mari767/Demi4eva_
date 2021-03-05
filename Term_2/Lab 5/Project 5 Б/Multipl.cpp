#include <iostream>

int Multiplication(int* Massiv, int Size) {
	int  multiplicat_negativ = 1;
	for (int i = 0; i < Size; i++) {
		if (*(Massiv + i) < 0) {
			multiplicat_negativ *= *(Massiv + i);
		}
	}
	return multiplicat_negativ;
}