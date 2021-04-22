//ЛАБОРАТОРНАЯ РАБОТА № 9 Двунаправленные списки
//Используя наработки ЛР №8 организовать работу со списком по следующему МЕНЮ :
//1.    Создание списка.
//2.    Печать списка с начала.
//3.    Печать списка с конца.
//4.  Поиск по критерию с начала списка.
//5.  Поиск по критерию с конца списка.
//6.    Добавление элемента(в любое заданное место).
//7.    Удаление любого элемента.
//8.    Сортировка.
//9.    Запись нового списка в файл.
//10.   Создание нового списка файла.
//11.   Выход из программы

#include "Functions.h"
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
	int Size ;      // кол-во объектов структуры  (Ведомость комплектующих)
	char* name = new char[20]{ "File_lab_main_9.txt" }; // Имя файла ( с указаьелем file)

	int search_criteria; // выбор, где несколько вариантов ответа
	char Symbol;
	int number_to_search;
	List* head = NULL;
	List* tail = NULL;

	//Меню
	do {
		printf("Выберите действие:\n");
		printf("  1->  Создание списка.\n");
		printf("  2->  Печать списка с начала.\n");
		printf("  3->  Печать списка с конца.\n");
		printf("  4->  Поиск по критерию с начала.\n");
		printf("  5->  Поиск по критерию с конца.\n");
		printf("  6->  Добавление элемента.\n");
		printf("  7->  Удаление любого элемента.\n");
		printf("  8->  Сортировка.\n");
		printf("  9->  Запись нового списка в файл.\n");
		printf("  10-> Создание нового списка из файла.\n");
		printf("  11-> Выход из программы. \n\n");

		scanf_s("%d", &menu);

		switch (menu) {
		case 1:
			printf("Введите количество строк.\n");
			scanf_s("%d", &Size);

			Creation_List(&Size, head, tail);
			printf("Список создан.\n");
			printf("Size = %d \n\n", Size);
			break;

		case 2:    // Печать списка с начала.
			Print_List(head, tail, head);
			break;

		case 3:    // Печать списка с конца.
			Print_List(head, tail, tail);
			break;

		case 4:    // Поиск по критерию с начала.
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
				break;
			}

			switch (search_criteria) {
			case 1:                             //По первой букве обозначения
				printf("Введите букву.\n");
				scanf_s("%c", &Symbol);
				Alphabet(head, Symbol, tail, head);
				break;

			case 2:                             // По типу.
				printf("Введите букву (тип задается английской буквой). \n");
				scanf("%c", &Symbol);
				Search_Typ(head, Symbol, tail, head);
				break;
			case 3:                             // По номиналу.
				printf("Введите число. Результатом поиска являются комплектующий элемент ведомости с номиналом больше, нежели заданное число. \n");
				scanf("%d", &number_to_search);
				Search_Nom(head, number_to_search, tail, head);
				break;
			case 4:                             // По количеству.
				printf("Введите число. Результатом поиска являются комплектующий элемент ведомости с количеством менее, нежели заданное число. \n");
				scanf("%d", &number_to_search);
				Search_Colvo(head, number_to_search, tail, head);
				break;
			}
			break;

		case 5:
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
				break;
			}

			switch (search_criteria) {
			case 1:                             //По первой букве обозначения
				printf("Введите букву.\n");
				scanf_s("%c", &Symbol);
				Alphabet(head, Symbol, tail, tail);
				break;

			case 2:                             // По типу.
				printf("Введите букву (тип задается английской буквой). \n");
				scanf("%c", &Symbol);
				Search_Typ(head, Symbol, tail, tail);
				break;

			case 3:                             // По номиналу.
				printf("Введите число. Результатом поиска являются комплектующий элемент ведомости с номиналом больше, нежели заданное число. \n");
				scanf("%d", &number_to_search);
				Search_Nom(head, number_to_search, tail, tail);
				break;
			case 4:                             // По количеству.
				printf("Введите число. Результатом поиска являются комплектующий элемент ведомости с количеством менее, нежели заданное число. \n");
				scanf("%d", &number_to_search);
				Search_Colvo(head, number_to_search, tail, tail);
				break;
			}

			break;
		case 6:    // Добавление элемента(в любое заданное место).
			printf("Выберите позицию для добавления строки. Номерация с нуля.\n");
			scanf_s("%d", &Location);

			if (Location == 0) {
				add_first_element(head, &Size);
			}
			else if (Location > 0 && Location < Size) {
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
			break;

		case 7:    // Удаление любого элемента.			
			if (Size == 0) {
				printf("Список пуст. Удаление строки невозможно.\n\n");
				break;
			}
			printf("Выберите номер строки для удаления. Номерация с нуля.\n");
			scanf_s("%d", &Location);

			if (Location == 0) {
				free_first_element(head, &Size);
			}
			else if (Location > 0 && Location < Size - 1) {
				free_middle_element(head, &Size, Location);
			}
			else if (Location == Size - 1) {  // end
				free_last_element(tail, &Size);
			}
			else {
				printf("Такой строки в таблице нет.\n\n");
				break;
			}
			printf("Строка удалена.\n\n");
			printf("Size = %d \n\n", Size);
			break;

		case 8:     // Сортировка.
			if (head == NULL) {
				printf("Сортировка невозможна. Список пуст.\n");
				break;
			}
			Sort(head);
			break;

		case 9:    // Запись списка в файл.
			Recording_List_to_FILE(head, name);
			is_file_full = true;
			break;
		case 10:    // Создание нового списка из файла.
			if (is_file_full == false) {
				printf("Файл пуст. Создание нового списка из файла невозможно.\n");
				break;
			}
			Free_List(head);
			Size = 0;
			head = NULL;
			tail = NULL;
			Creation_New_List_from_File(name, &Size, head, tail);
			break;
		case 11:    // Выход из программы.
			Free_List(head);
			break;
		default:
			printf("Некорректный ответ. Попробуйте ещй раз.\n");
		}
	} while (menu != 11);

	delete[] name;
	return 0;
}