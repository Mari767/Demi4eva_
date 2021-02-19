#include "Declare.h"

int Sum(int* massiv, int Size) {     // сумма части элементов первого массива
	if (Size == 3)
		return 0;
	return Sum(massiv, --Size) + massiv[Size];
}
void Arr_input(int* array, int Size) { //  Заполнение исходного массива
	for (int i = 0; i < Size; i++) {
		*(array + i) = i + 1; /*rand() % 100;*/
	}
}
void Print(int* array, int Size) {        //  Печать массива
	for (int i = 0; i < Size; i++) {
		cout << setw(4) << *(array + i);
	}cout << endl;
}
void Arr2_input(int* array1, int* array2, int Size) { //заполнение массива элементами исходного 
	for (int i = 0; i < Size; i++) {        //  передаю  Size_2
		*(array2 + i) = *(array1 + i + 3);
	}
}