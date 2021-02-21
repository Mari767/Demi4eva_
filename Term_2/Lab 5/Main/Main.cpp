﻿//ЛАБОРАТОРНАЯ РАБОТА № 5
//Лабораторная работа № 13 из методички.Двумерный динамический массив и функции
//Используя директивы процессора реализовать выбор одной из реализованных функций(функция принимает и возвращает массив) :
//	– работа с одномерным массивом, как с двумерным(*А);
//– работа с двумерным массивом, как с двумерным(**А).
#define Print_1
#include "Declaration.h"

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
	int* Mas = (int*)malloc(Size * Size * sizeof(int));
	//Заполнение матрицы
#ifdef Print_1
	Input_1(Mas, Size);  //  работа с одномерным массивом, как с двумерным(*А);
#else
	Input_2(Mas, Size);  //  работа с двумерным массивом, как с двумерным(**А).
#endif
	//Вывод матрицы
	for (I = Mas, i = 0; i < Size * Size; i++, I++) {
		cout << setw(4) << *I;
		if (i % Size == Size - 1) {
			cout << endl;
		}
	}
	free(Mas);
	return 0;
}