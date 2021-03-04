#include <iostream>
#include <iomanip>
using namespace std;

int Sum(int* massiv, int Size) { //  Вторая функция // Индивидуальное задание
	if (Size == 3)
		return 0;
	return Sum(massiv, --Size) + massiv[Size];
}

void Arr2_input(int* array1, int* array2, int Size) {  
	for (int i = 0; i < Size; i++) {     
		*(array2 + i) = *(array1 + i + 3);
	}
}
void Print(int* array, int Size) {
	for (int i = 0; i < Size; i++) {
		cout << setw(4) << *(array + i);
	}cout << endl;
}