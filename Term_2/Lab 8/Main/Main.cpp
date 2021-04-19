//ЛАБОРАТОРНАЯ РАБОТА № 8 Однонаправленные списки
//Используя наработки ЛР №2 организовать работу со списком по следующему МЕНЮ :
//1.  Создание списка.
//2.  Печать списка.
//3.  Поиск по критерию(осуществить выбор критерия).
//4.  Добавление элемента(в любое заданное место).
//5.  Удаление любого элемента.
//6. Сортировка.
//7.  Запись списка в файл.
//8.  Создание нового списка из файла.
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
	int Location;      // позиция, на которой нужно распечатать элемент
	int Size = 0;      // кол-во объектов структуры  (Ведомость комплектующих)
	char* name = new char[20]{ "File_lab_main_8.txt" }; // Имя файла ( с указаьелем file)

	int search_criteria; // выбор, где несколько вариантов ответа
	char Symbol;
	int number_to_search;
	List* head = NULL;

	//Меню
	do {
		printf("Выберите действие:\n");
		printf("  1-> Создание списка.\n");
		printf("  2-> Печать списка.\n");
		printf("  3-> Поиск по критерию.\n");
		printf("  4-> Добавление элемента.\n");
		printf("  5-> Удаление любого элемента.\n");
		printf("  6-> Сортировка.\n");
		printf("  7-> Запись списка в файл.\n");
		printf("  8-> Создание нового списка из файла.\n");
		printf("  9-> Выход из программы. \n\n");

		scanf_s("%d", &menu);
		switch (menu) {
		case 1:    
			printf("Введите количество строк.\n");
			scanf_s("%d", &Size);
		//	Size = 4;
			head = Creation_List( &Size);
			printf("Список создан.\n");
			printf("Size = %d \n\n", Size);
			break;

		case 2:    // Печать списка.
			Print_List(head);
			break;

		case 3:    // Поиск по критерию(осуществить выбор критерия).
			if (head == NULL) {
				printf("Поиск невозможен. Список пуст.\n");
				break;
			}
			printf("Выберите критерий поиска:\n");
			printf("  1) По первой букве обозначения (англ. алфавит) \n");
			printf("  2) По типу.\n");
			printf("  3) По номиналу.\n");
			printf("  4) По количеству.\n\n");
			printf("Выберите критерий поиска:\n");
			scanf_s("%d", &search_criteria);
			clearStdIn();

			if (search_criteria > 5 || search_criteria < 1) {
				printf("Некорректный ввод.\n");
			}

			switch (search_criteria) {
			case 1:                             //По первой букве обозначения
				printf("Введите букву.\n");
				scanf_s("%c", &Symbol);
				Alphabet(head, Symbol);
				break;

			case 2:                             // По типу.
				printf("Введите букву (тип задается английской буквой). \n");
				scanf("%c", &Symbol);
				Search_Typ(head, Symbol);
					break;
			case 3:                             // По номиналу.
				printf("Введите число. Результатом поиска являются комплектующий элемент ведомости с номиналом больше, нежели заданное число. \n");
				scanf("%d", &number_to_search);
				Search_Nom(head, number_to_search);
				break;
			case 4:                             // По количеству.
				printf("Введите число. Результатом поиска являются комплектующий элемент ведомости с количеством менее, нежели заданное число. \n");
				scanf("%d", &number_to_search);
				Search_Colvo(head, number_to_search);
				break;
			}
			break;
		case 4:    // Добавление элемента(в любое заданное место).
			printf("Выберите позицию для добавления строки. Номерация с нуля.\n");
			scanf_s("%d", &Location);

			if (Location == 0) {
				add_first_element(&head,  &Size);
			}
			else if (Location > 0 && Location < Size) {
				add_middle_element(head,  &Size, Location);
			}
			else if (Location == Size) {  // end
				add_last_element(head,  &Size);
			}
			else {
				printf("Такой позиции нет.\n\n");
				break;
			}
			printf("Строка добавлена.\n");
			printf("Size = %d \n\n", Size);
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
			else if (Location > 0 && Location < Size - 1) {
				free_middle_element(head, &Size, Location);
			}
			else if (Location == Size - 1) {  // end
				free_last_element(head, &Size);
			}
			else {
				printf("Такой строки в таблице нет.\n\n");
				break;
			}
			printf("Строка удалена.\n\n");
			printf("Size = %d \n\n", Size);
			break;

		case 6:     // Сортировка.
			if (head == NULL) {
				printf("Сортировка невозможна. Список пуст.\n");
				break;
			}
			Sort(head);
			break;

		case 7:    // Запись списка в файл.
			Recording_List_to_FILE(head, name);
			is_file_full = true;
			break;
		case 8:    // Создание нового списка из файла.
			if (is_file_full = false) {
				printf("Файл пуст. Создание нового списка из файла невозможно.\n");
				break;
			}
			Free_List(&head);
			Size = 0;
			head = Creation_New_List_from_File(name, &Size);
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