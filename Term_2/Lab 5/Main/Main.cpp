//ЛАБОРАТОРНАЯ РАБОТА № 5
//Лабораторная работа № 13 из методички.Двумерный динамический массив и функции
//Используя директивы процессора реализовать выбор одной из реализованных функций(функция принимает и возвращает массив) :
//	– работа с одномерным массивом, как с двумерным(*А);
//– работа с двумерным массивом, как с двумерным(**А).
#define Print_1
#include "Declaration.h"
#include <stdlib.h>
#include <windows.h>

//void Input_2(int far** Array, int Size);


int main() {
	setlocale(LC_ALL, "ru");
	cout << "Ввыедите размерность квадратной матрицы. Размерность не должена привышать числа 24. " << endl;
	cin >> Size;
	if (Size < 1) {
		cout << "Размер матрицы слишком мал" << endl;
		return 0;
	}
	if (Size > 24) {
		cout << "Размерность матрицы слишком велика." << endl;
		return 0;
	}
	//Заполнение матрицы
#ifdef Print_1
	int* Mas = (int*)malloc(Size * Size * sizeof(int));
	fill( Mas, Size);
	//Input_1(Mas, Size);  //  работа с одномерным массивом, как с двумерным(*А);
	//Вывод матрицы
	for (I = Mas, i = 0; i < Size * Size; i++, I++) {
		cout << setw(4) << *I;
		if (i % Size == Size - 1) {
			cout << endl;
		}
	}
	free(Mas);
#else
	int** Arr;/* указатель на массив указателей */
	int far** Arr; /* указатель на массив указателей */
	Arr = (int far**)malloc(Size * sizeof(int*));
	/* выделение памяти для каждой строки и заполнение массива указателей */
	for (i = 0; i < Size; i++) {
		*(Arr++) = (int far*)malloc(Size * sizeof(int));
	}
	Input_2(Arr, Size);  //  работа с двумерным массивом, как с двумерным(**А).
	/* вывод матрицы */
	for (i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			cout << setw(4) << Arr[i][j++]; // REMAKE!!!!!
		}cout << endl;
	}
	/* освобождение памяти строк */
	for (i = 0; i < Size; i++) {
		free(*(Arr++));
	}    
	/* освобождение памяти массива указателей */
	free(Arr);
#endif

	return 0;
}