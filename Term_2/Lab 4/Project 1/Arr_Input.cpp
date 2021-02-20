#include "Declare.h"

void Arr_input(int* array, int Size) {// Заполнение массива
	for (int i = 0; i < Size; i++) {
		*(array + i) = i + 1; /*rand() % 100;*/
	}
}
