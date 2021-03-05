#include <iostream>

int Sum(int* Massiv, int Size) {
	int Sum_positiv = 0;
	for (int i = 0; i < Size; i++) {
		if (*(Massiv + i) > 0) {
			Sum_positiv += *(Massiv + i);
		}
	}
	return Sum_positiv;
}
