﻿/*ЛАБОРАТОРНАЯ РАБОТА № 2     Структуры и массивы структур.Препроцессорная обработка
•	Используя наработки ЛР №1 разбить проект на файлы(раздельная компиляция).
•	Создать макроопределение(PRINT_TYPE) в зависимости от которого будет выполняться заполнение с экрана или случайным образом.
•	В начале и конце каждой функции проверять, определена ли переменная / макрос DEBUG.Если такова присутствует, то вывести на экран :
1) текущую дату и время;
2) имя текущего файла и текущей функции.*/

using namespace std;
#include "Function.h"

int main() {
    setlocale(LC_ALL, "ru");
    srand(time_t(NULL));
    int a;
    do {
        cout << "Выберите действие: \n 1-> заполнение таблицы \n 2-> сортировка таблицы\n 3-> печать таблицы\n 4-> виход из программы" << endl;
        cin >> a;
        switch (a) {
        case 1: //Enter table
            Enter_table();
            break;
        case 2:  // Сортировка
            Sort(vedom, N);
            break;
        case 3:  // Печать
            Print(vedom, N);
            break;
        case 4:
            break;
        default:
            cout << "Некорректный ответ. Попробуйте ещй раз." << endl;
        }
    } while (a != 4);
return 0;
}