#include "Declare.h"

int Sum(int* massiv, int Size) {     // ����� ����� ��������� ������� �������
	if (Size == 3)
		return 0;
	return Sum(massiv, --Size) + massiv[Size];
}
void Arr_input(int* array, int Size) { //  ���������� ��������� �������
	for (int i = 0; i < Size; i++) {
		*(array + i) = i + 1; /*rand() % 100;*/
	}
}
void Print(int* array, int Size) {        //  ������ �������
	for (int i = 0; i < Size; i++) {
		cout << setw(4) << *(array + i);
	}cout << endl;
}
void Arr2_input(int* array1, int* array2, int Size) { //���������� ������� ���������� ��������� 
	for (int i = 0; i < Size; i++) {        //  �������  Size_2
		*(array2 + i) = *(array1 + i + 3);
	}
}