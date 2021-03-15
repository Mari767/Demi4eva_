#include <iostream>

void Bubble(int* massiv, int Size) {
	int t, i, j;
	for (i = 0; i < Size ; i++) { 
		for (j = 0; j < Size; j++) {
			if (*(massiv + i) < * (massiv + j)) {
				t = *(massiv + i);
				*(massiv + i) = *(massiv + j);
				*(massiv + j) = t;
			}
		}
	}
}
