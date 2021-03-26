//В одномерном массиве найти сумму и количество отрицательных элементов через :
//а) относительный адрес;
//б) через абсолютный адрес;
//в) не использовать индексацию;
//г) через массив указателей;
//д) через указатель на указатель.
//е) оформить в виде функции с параметрами указателями.

#include <iostream>
#include <iomanip>    // for  	srand(time(NULL))
#include "FSum.h"

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int Size, i;
	int* ptr;             // указатель на элемент массива
	int** Pointer = NULL; // указатель на указатель
	int Sum, negative;

	printf("Введите размер массива.'\n");
	scanf_s("%d", &Size);
	int* mas = new int[Size];         // массив, с которым работаем
	int** Ptr_mas = new int* [Size];  // массив указателей

	//---------------------------------------------
	//  Заполнение массива
	for (i = 0; i < Size; i++) {
		*(mas + i) = rand() % 200 - 70;
	}
	for (i = 0; i < Size; i++) {
		printf("%4d", *(mas + i));
	}printf("\n\n");

	//---------------------------------------------

	printf("Нахождение количества отрицательных элементов в одномерном динамическом массиве через:\n\n");
	printf(" Oтносительный адрес.\n");
	ptr = mas;
	for (i = 0, Sum = 0, negative = 0; i < Size; i++) {
		if (*(ptr + i) < 0) {
			Sum += *(ptr + i);
			++negative;
		}
	}printf("    Sum = %d    Negative = %d \n", Sum, negative);

	//---------------------------------------------

	printf(" Через абсолютный адрес.\n");
	ptr = mas;
	for (i = 0, Sum = 0, negative = 0; i < Size; i++, ptr++) {
		if (*ptr < 0) {
			Sum += *ptr;
			++negative;
		}
	}printf("    Sum = %d    Negative = %d \n", Sum, negative);

	//---------------------------------------------

	printf(" Не использовуя индексацию.\n");
	for (ptr = mas, Sum = 0, negative = 0; ptr < mas + Size; ptr++) {
		if (*ptr < 0) {
			Sum += *ptr;
			++negative;
		}
	}printf("    Sum = %d    Negative = %d \n", Sum, negative);

	//---------------------------------------------

	printf(" Через массив указателей.\n");
	for (i = 0, Sum = 0, negative = 0; i < Size; i++) {
		*(Ptr_mas + i) = (mas + i);          // * - арифметика указателей
		if (**(Ptr_mas + i) < 0) {          // ** - арифметика указателей + разыменование указателя
			Sum += **(Ptr_mas + i);
			++negative;
		}
	}printf("    Sum = %d    Negative = %d \n", Sum, negative);

	//---------------------------------------------

	printf(" Через указатель на указатель.\n");
	ptr = mas;
	Pointer = &ptr;
	for (i = 0, Sum = 0, negative = 0; i < Size; i++, (*Pointer)++) {
		if (**Pointer < 0) {
			Sum += **Pointer;
			++negative;
		}
	}printf("    Sum = %d    Negative = %d \n", Sum, negative);

	//---------------------------------------------

	printf(" В виде функции с параметрами указателями.\n");
	ptr = mas;
	Sum = 0;
	negative = 0;
	Fsum(mas, &Sum, &Size, &negative);
	printf("    Sum = %d    Negative = %d \n", Sum, negative);


	delete[] mas;
	delete[] Ptr_mas;
	return 0;
}