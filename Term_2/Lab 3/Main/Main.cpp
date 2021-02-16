//ЛАБОРАТОРНАЯ РАБОТА № 3  Одномерные массивы и указатели
//7.	Дан массив из N целых чисел.Определить сумму элементов, расположенных между третьим с начала и третьим с конца массива.
//    Создать второй массив, содержащий элементы, расположенные между третьим с начала и третьим с конца.

#include <iostream>
#include <iomanip>
using namespace std;

void Arr_input (int *array, int N);
void Print (int* array, int N);
int Sum (int* array, int i);
void Arr2_input (int* array, int* array2, int B);
int main() {
	setlocale(LC_ALL, "ru");
	int N;
	srand(time(NULL));
	cout << "Введите размер массива " << endl;
	cin >> N;
	int B = N - 6;
	int *arr = new int[N]; //  Первый массив
	Arr_input(arr, N);     //  Заполнение
	Print(arr, N);         //  Печать
	cout << "Сумма элементов, расположенных между третьим с начала и третьим с конца массива Sum=" << Sum(arr, N - 3) << endl << endl << endl << endl;
	
	int* arr2 = new int[B]; //  Второй массив
	Arr2_input(arr, arr2, B);//  Заполнение
	Print(arr2, B);         //  Печать

	delete[] arr2;          //  Удален первый массив
	delete[] arr;           //  Удален второй массив
	return 0;
}
int Sum(int *massiv, int i) {
	if (i == 3) 
		return 0; 
	return Sum(massiv, --i) + massiv[i];
}
void Arr_input(int* array, int N) {
	for (int i = 0; i < N; i++) {
		array[i] = i+1; /*rand() % 100;*/
	}
}
void Print(int* array, int N) {
	for (int i = 0; i < N; i++) {
		cout << setw(4) << *(array + i);
	}cout << endl << endl;
}
void Arr2_input(int* array1, int* array2, int B) {
	for (int i = 0; i < B; i++){
		array2[i] = array1[i+3];
	}
}