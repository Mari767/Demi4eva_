//ЛАБОРАТОРНАЯ РАБОТА № 8 Однонаправленные списки
//Используя наработки ЛР №2 организовать работу со списком по следующему МЕНЮ :
//1.  Создание списка.
//2.  Печать списка.
//3. Поиск по критерию(осуществить выбор критерия).
//4.  Добавление элемента(в любое заданное место).
//5.  Удаление любого элемента.
//6. Сортировка.
//7.  Запись списка в файл.
//8. Создание нового списка из файла.
//9.  Выход из программы.
//Все в отдельных функциях, с макроопределениями и раздельной компиляцией.
//#define _CRT_SECURE_NO_WARNINGS

#include "Function.h"
#include "Struct.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main() {
	setlocale(LC_ALL, "ru");
	srand(time_t(NULL));
	bool is_file_full = false;  // заполнен файл или пуст
	int menu;          // выбор в меню
	int elements;      // кол-во добавляемых елементов
	int Location;      // позиция, на которой нужно распечатать элемент
	int Size = 0;      // кол-во объектов структуры  (Ведомость комплектующих)
	char* name = new char[20]{ "File_lab_main_8.txt" }; // Имя файла ( с указаьелем file)

	int choose;
	List* head = NULL;

	//Меню
	do {
		printf("Выберите действие: \n  1-> Создание списка. \n  2-> Печать списка.\n  3-> Поиск по критерию(осуществить выбор критерия)\n  4-> Добавление элемента(в любое заданное место).\n  5-> Удаление любого элемента.\n  6-> Сортировка.\n  7-> Запись списка в файл.\n  8-> Создание нового списка из файла.\n  9-> Выход из программы. \n");
		scanf_s("%d", &menu);
		switch (menu) {
		case 1:    // Создание списка с  выбором ранд или экран
			printf("Выберите способ заполнения таблицы\n 1) Ввод вручную. \n 2) Ввод с экрана.\n");
			//scanf_s("%d", choose);
			head=Creation_List(&Size);

			printf("Список создан.\n");
			printf("Size = %d \n\n", Size);
			break;

		case 2:    // Печать списка.
			Print_List(head);
			break;

		case 3:    // Поиск по критерию(осуществить выбор критерия).
			//printf("Сколько элементов добавить в начало файла\n");
			//scanf_s("%d", &elements);
			//if (elements < 0) {
			//	printf("Некорректный ввод.\n");
			//	break;
			//}
			////Add_to_Start(name, vedom, &Size, elements);
			//Size += elements;
			//is_file_full = true;
			//printf("\n\nДобавлена запись в начало файла.\n");
			//break;

		case 4:    // Добавление элемента(в любое заданное место).
			printf("Выберите позицию для добавления строки. Номерация с нуля.\n");
			scanf_s("%d", &Location);
			
			if (Location == 0) {
				add_first_element(&head, &Size);
			}
			else if (Location > 0 && Location < Size ) {
			add_middle_element(head, &Size, Location);
			}
			else if (Location == Size) {  // end
				add_last_element(head, &Size);
			}
			else {
				printf("Такой позиции нет.\n\n");
				break;
			}
			printf("Строка добавлена.\n");
			printf("Size = %d \n\n", Size);

			//printf("Сколько элементов добавить в конец файла\n");
			//scanf_s("%d", &elements);
			//if (elements < 0) {
			//	printf("Некорректный ввод.\n");
			//	break;
			//}
			////Add_to_End(name, vedom, elements);
			//Size = Size + elements;
			//is_file_full = true;
			//printf("Добавлена запись в конец файла. \n");
			break;

		case 5:    // Удаление любого элемента.
			printf("Выберите номер строки для удаления. Номерация с нуля.\n");
			scanf_s("%d", &Location);
			if (Size == 0) {
				printf("Список пуст. Удаление строки невозможно.\n\n");
				break;
			}
			if (Location == 0) {
				free_first_element(&head, &Size);
			}
			else if (Location > 0 && Location < Size-1) {
				free_middle_element(head, &Size ,Location);
			}
			else if (Location==Size-1) {  // end
			    free_last_element(head, &Size);
			}
			else {
				printf("Такой строки в таблице нет.\n\n");
				break;
			}
			printf("Строка удалена.\n\n");
			printf("Size = %d \n\n", Size);

			/*if (is_file_full == false) {
				printf("Файл пуст. Печать невозможна.\n");
				break;
			}*/
		/*	printf("Введите номер элемента для печати. Номерация с нуля.\n");
			scanf_s("%d", &Location);
			if (Location >= Size || Location < 0) {
				printf("Такого номера в файле нет.\n\n");
				break;
			}*/
			//Print_One_Note(name, vedom, Location);
			break;

		case 6:     // Сортировка.
			/*if (is_file_full == false) {
				printf("Файл пуст. Печать невозможна.\n");
				break;
			}*/
			//Print(name, vedom, &Size);
			break;

		case 7:    // Запись списка в файл.
			Recording_List_to_FILE(head, name);
			break;
		case 8:    // Создание нового списка из файла.
			break;
		case 9:    // Выход из программы.
			Free_List(&head);
			break;
		default:
			printf("Некорректный ответ. Попробуйте ещй раз.\n");
		}
	} while (menu != 9);

	delete[] name;
	return 0;
}

