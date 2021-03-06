#include <iostream>

void Chose_Sort(int* massiv, int Size, void (*Sort)(int*, int))
{
	Sort(massiv, Size);
}

void Print_massiv(int* massiv, int Size) {
	for (int i = 0; i < Size; i++) {
		printf("%4d", *(massiv + i));
	}printf("\n\n");
}