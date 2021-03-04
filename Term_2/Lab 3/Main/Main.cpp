﻿//ЛАБОРАТОРНАЯ РАБОТА № 3  Одномерные массивы и указатели
//7.	Дан массив из N целых чисел.Определить сумму элементов, расположенных между третьим с начала и третьим с конца массива.
//    Создать второй массив, содержащий элементы, расположенные между третьим с начала и третьим с конца.
#include "Functions.h"

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	//  обЪявление переменных
	int Size_1;
	cout << "Введите размер массива. Размер массива не ментше 7 элементов" << endl;
	cin >> Size_1;
	if (Size_1 < 7) {
		cout << "Массив не заполнен." << endl;
		return 0;
	}
	int Size_2 = Size_1 - 6;
	//  обЪявление динамических массивов
	int* arr = (int*)malloc(Size_1 * sizeof(int));//  Первый массив
	int* arr2 = (int*)malloc(Size_2 * sizeof(int)); //  Второй массив

	Arr_input(arr, Size_1);     //  Заполнение первого массива
	Print(arr, Size_1);         //  Печать
	cout << "Сумма элементов, расположенных между третьим с начала и третьим с конца массива Sum=" << Sum(arr, Size_1 - 3) << endl << endl;
	
	Arr2_input(arr, arr2, Size_2);//  Заполнение втрого массива
	cout << "Массив содержащий элементы, расположенные между третьим с начала и третьим с конца элементами первого массива." << endl;
	Print(arr2, Size_2);         //  Печать

	free(arr2);          //  Удален первый массив
	free(arr);           //  Удален второй массив
	return 0;
}
