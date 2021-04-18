//ЛАБОРАТОРНАЯ РАБОТА № 7 Структуры и файлы
//Используя наработки ЛР №2 реализовать работу со структурой по следующему МЕНЮ :
//1. Ввод с экрана и запись в файл.
//2. Ввод случайным образом и запись в файл.
//3. Добавить запись в начало файла.
//4. Добавить запись в конец файла.
//5. Печать одной записи из файла по номеру.
//6. Печать всех записей из файла.
//7. Выход из программы.
//Не работать с массивом структур.Все операции делать в файле(через одну переменную типа структура)

#include "Function.h"
#include "Struct.h"
#include <iostream>
#include <stdio.h>

int main() {
	setlocale(LC_ALL, "ru");
	srand(time_t(NULL));
	information vedom;   //объект структуры
	bool is_file_full = false;  // заполнен файл или пуст
	int a;         // выбор в меню
	int elements;  // кол-во добавляемых елементов
	int Location;  // позиция, на которой нужно распечатать элемент
	int Size = 0;      // кол-во объектов структуры  (Ведомость комплектующих)
	char* name = new char[20]{ "File_lab_main_7.txt" }; // Имя файла ( с указаьелем file)
	 //Меню
	do {
		printf("Выберите действие: \n  1-> Ввод с экрана и запись в файл. \n");
		printf("  2-> Ввод случайным образом и запись в файл.\n");
		printf("  3-> Добавить запись в начало файла.\n");
		printf("  4-> Добавить запись в конец файла.\n");
		printf("  5-> Печать одной записи из файла по номеру.\n");
		printf("  6-> Печать всех записей из файла.\n");
		printf("  7-> Выход из программы. \n");
		scanf_s("%d", &a);
		switch (a) {
		case 1:    // Ввод с экрана и запись в файл.
			Screen(name, vedom, &Size);
			is_file_full = true;
			printf("Таблица заполнена.\n");
			break;

		case 2:    // Ввод случайным образом и запись в файл
			Rand(name, vedom, &Size);
			Size = B;
			is_file_full = true;
			printf("Таблица заполнена. \n");
			break;

		case 3:    // Добавить запись в начало файла.
			printf("Сколько элементов добавить в начало файла\n");
			scanf_s("%d", &elements);
			if (elements < 0) {
				printf("Некорректный ввод.\n");
				break;
			}
			Add_to_Start(name, vedom, &Size, elements);
			is_file_full = true;
			printf("\n\nДобавлена запись в начало файла.\n");
			break;

		case 4:    // Добавить запись в конец файла.
			printf("Сколько элементов добавить в конец файла\n");
			scanf_s("%d", &elements);
			if (elements < 0) {
				printf("Некорректный ввод.\n");
				break;
			}
			Add_to_End(name, vedom, elements);
			Size = Size + elements;
			is_file_full = true;
			printf("Добавлена запись в конец файла. \n");
			break;

		case 5:    // Печать одной записи из файла по номеру.
			if (is_file_full == false) {
				printf("Файл пуст. Печать невозможна.\n");
				break;
			}
			printf("Введите номер элемента для печати. Номерация с нуля.\n");
			scanf_s("%d", &Location);
			if (Location >= Size || Location < 0) {
				printf("Такого номера в файле нет.\n\n");
				break;
			}
			Print_One_Note(name, vedom, Location);
			break;

		case 6:
			if (is_file_full == false) {
				printf("Файл пуст. Печать невозможна.\n");
				break;
			}
			Print(name, vedom, &Size);
			break;

		case 7:    // Выход из программы.
			break;
		default:
			printf("Некорректный ответ. Попробуйте ещй раз.\n");
		}
	} while (a != 7);
	delete[] name;
	return 0;
}

