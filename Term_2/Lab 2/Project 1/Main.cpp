/*ЛАБОРАТОРНАЯ РАБОТА № 2     Структуры и массивы структур.Препроцессорная обработка
•	Используя наработки ЛР №1 разбить проект на файлы(раздельная компиляция).
•	Создать макроопределение(PRINT_TYPE) в зависимости от которого будет выполняться заполнение с экрана или случайным образом.
•	В начале и конце каждой функции проверять, определена ли переменная / макрос DEBUG.Если такова присутствует, то вывести на экран :
1) текущую дату и время;
2) имя текущего файла и текущей функции.*/

#include "Function.h"
#include <iomanip>
#include <stdio.h>
#define PRINT_TYPE 1
//#define PRINT_TYPE 1  //enter with console 
//#define PRINT_TYPE 2  // random enter 
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	srand(time_t(NULL));
	int a;
	int N;

	do {
		cout << "Выберите действие: \n 1-> заполнение таблицы \n 2-> сортировка таблицы\n 3-> печать таблицы\n 4-> виход из программы" << endl;
		cin >> a;
		switch (a) {
		case 1: //Enter table
#if PRINT_TYPE == 1
			N = Screen();
#else
			Rand();
			N = 10;
#endif            
			break;
		case 2:  // Сортировка

			Sort(N);
			break;
		case 3:  // Печать
			Print(N);
			break;
		case 4:
			break;
		default:
			cout << "Некорректный ответ. Попробуйте ещй раз." << endl;
		}
	} while (a != 4);
	return 0;
}