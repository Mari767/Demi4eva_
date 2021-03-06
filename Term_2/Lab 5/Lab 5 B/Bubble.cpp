#include <iostream>

void Bubble(int* massiv, int Size) {
	int t, i, j;
	for (i = 0; i < Size ; i++) { //////////////   тут точно <size,   a ne <size-1
		for (j = 0; j < Size; j++) {
			if (*(massiv + i) < * (massiv + j)) {
				t = *(massiv + i);
				*(massiv + i) = *(massiv + j);
				*(massiv + j) = t;
			}
		}
	}
}
