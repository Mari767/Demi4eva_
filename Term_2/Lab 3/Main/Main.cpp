//ЛАБОРАТОРНАЯ РАБОТА № 3  Одномерные массивы и указатели
//7.	Дан массив из N целых чисел.Определить сумму элементов, расположенных между третьим с начала и третьим с конца массива.
//    Создать второй массив, содержащий элементы, расположенные между третьим с начала и третьим с конца.

#include <iostream>
#include <iomanip>
using namespace std;

void Arr_input (int *array, int Size);
void Print (int* array, int Size);
int Sum (int* array, int Size);
void Arr2_input (int* array, int* array2, int Size);
int main() {
	setlocale(LC_ALL, "ru");
	int Size_1;
	srand(time(NULL));
	cout << "Введите размер массива " << endl;
	cin >> Size_1;
	int Size_2 = Size_1 - 6;
	int* arr = (int*)malloc(Size_1 * sizeof(int));//  Первый массив
	Arr_input(arr, Size_1);     //  Заполнение
	Print(arr, Size_1);         //  Печать
	cout << "Сумма элементов, расположенных между третьим с начала и третьим с конца массива Sum=" << Sum(arr, Size_1 - 3) << endl << endl;
	
	int* arr2 = (int*)malloc(Size_2 * sizeof(int)); //  Второй массив
	Arr2_input(arr, arr2, Size_2);//  Заполнение
	cout << "Массив содержащий элементы, расположенные между третьим с начала и третьим с конца элементами первого массива." << endl;
	Print(arr2, Size_2);         //  Печать

	free(arr2);          //  Удален первый массив
	free(arr);           //  Удален второй массив
	return 0;
}
int Sum(int *massiv, int Size) {
	if (Size == 3)
		return 0; 
	return Sum(massiv, --Size) + massiv[Size];
}
void Arr_input(int* array, int Size) {
	for (int i = 0; i < Size; i++) {
		array[i] = i+1; /*rand() % 100;*/
	}
}
void Print(int* array, int Size) {
	for (int i = 0; i < Size; i++) {
		cout << setw(4) << *(array + i);
	}cout << endl;
}
void Arr2_input(int* array1, int* array2, int Size) {
	for (int i = 0; i < Size; i++){
		array2[i] = array1[i+3];
	}
}