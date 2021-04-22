#include <iostream>
#include "Functions.h"
#include "Struct.h"

void Alphabet(List* head, char Symbol, List* tail, List* edge ) { //edge = head   ||   edge = tile
	List* temp = edge;
	int Search_Result = 0;

	if (edge == head) { // если с головы
		while (temp) {
			if (*(temp->Data.name) == Symbol) {  // Считаем количесво результов поиска
				Search_Result++;
			}
			temp = temp->next;
		}
	}
	else if (edge == tail) {  // если с конца
		while (temp) {
			if (*(temp->Data.name) == Symbol) {  // Считаем количесво результов поиска
				Search_Result++;
			}
			temp = temp->prev;
		}
	}
	// Вывод наличия резульатов
	if (Search_Result == 0) {
		printf("Ничего не найдено. \n\n");  return;
	}
	else if (Search_Result != 0) {
		printf("\nРезультатов: %d\n", Search_Result);
	}
	// Вывод самих результатов
	printf("----------------------------------------------\n");
	printf("|         Ведомость комплектующих            |\n");
	printf("|--------------------------------------------|\n");
	printf("| Обозначение | Тип |  Номинал  | Количество |\n");
	printf("|-------------|-----|-----------|------------|\n");
	
	temp = edge;
	if (edge == head) { // если с головы
		while (temp) {
			if (*(temp->Data.name) == Symbol) {
				printf("|%-13s|%-5c|%-11d|%-12d|\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
				printf("----------------------------------------------\n");
			}
			temp = temp->next;
		}
	}
	else if (edge == tail) { // если с конца
		while (temp) {
			if (*(temp->Data.name) == Symbol) {
				printf("|%-13s|%-5c|%-11d|%-12d|\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
				printf("----------------------------------------------\n");
			}
			temp = temp->prev;
		}
	}printf("\n\n");
}

void Search_Typ(List* head, char Symbol, List* tail, List* edge) { //edge = head   ||   edge = tile {
	List* temp = edge;
	int Search_Result = 0;

	if (edge == head) { // если с головы
		while (temp) {
			if (temp->Data.typ == Symbol) {  // Считаем количесво результов поиска
				Search_Result++;
			}
			temp = temp->next;
		}
	}
	else if (edge == tail) {  // если с конца
		while (temp) {
			if (temp->Data.typ == Symbol) {  // Считаем количесво результов поиска
				Search_Result++;
			}
			temp = temp->prev;
		}
	}
	// Вывод наличия резульатов
	if (Search_Result == 0) {
		printf("Ничего не найдено.\n\n");  return;
	}
	else if (Search_Result != 0) {
		printf("\nРезультатов: %d\n", Search_Result);
	}
	// Вывод самих результатов
	printf("----------------------------------------------\n");
	printf("|         Ведомость комплектующих            |\n");
	printf("|--------------------------------------------|\n");
	printf("| Обозначение | Тип |  Номинал  | Количество |\n");
	printf("|-------------|-----|-----------|------------|\n");
	temp = edge;
	if (edge == head) { // если с головы
		while (temp) {
			if (temp->Data.typ == Symbol) {
				printf("|%-13s|%-5c|%-11d|%-12d|\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
				printf("----------------------------------------------\n");
			}
			temp = temp->next;
		}
	}
	else if (edge == tail) { // если с конца
		while (temp) {
			if (temp->Data.typ == Symbol) {
				printf("|%-13s|%-5c|%-11d|%-12d|\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
				printf("----------------------------------------------\n");
			}
			temp = temp->prev;
		}
	}printf("\n\n");
}

void Search_Nom( List* head, int number, List* tail, List* edge) {//Введите число.Результатом поиска являются комплектующий элемент ведомости с номиналом больше, нежели заданное число.
	List* temp = edge;
	int Search_Result = 0;
	if (edge == head) { // если с головы
		while (temp) {
			if (temp->Data.nom > number){
				Search_Result++;
			}
			temp = temp->next;
		}
	}
	else if (edge == tail) {  // если с конца
		while (temp) {
			if (temp->Data.nom > number) {  // Считаем количесво результов поиска
				Search_Result++;
			}
			temp = temp->prev;
		}
	}
	// Вывод наличия резульатов
	if (Search_Result == 0) {
		printf("Ничего не найдено.\n\n");  return;
	}
	else if (Search_Result != 0) {
		printf("\nРезультатов: %d\n", Search_Result);
	}
	// Вывод самих результатов
	printf("----------------------------------------------\n");
	printf("|         Ведомость комплектующих            |\n");
	printf("|--------------------------------------------|\n");
	printf("| Обозначение | Тип |  Номинал  | Количество |\n");
	printf("|-------------|-----|-----------|------------|\n");
	temp = edge;
	if (edge == head) { // если с головы
		while (temp) {
			if (temp->Data.nom > number) {
				printf("|%-13s|%-5c|%-11d|%-12d|\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
				printf("----------------------------------------------\n");
			}
			temp = temp->next;
		}
	}
	else if (edge == tail) { // если с конца
		while (temp) {
			if (temp->Data.nom > number) {
				printf("|%-13s|%-5c|%-11d|%-12d|\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
				printf("----------------------------------------------\n");
			}
			temp = temp->prev;
		}
	}printf("\n\n");
}

void Search_Colvo(struct List* head, int number, List* tail, List* edge) {
	List* temp = edge;
	int Search_Result = 0;
	if (edge == head) { // если с головы
		while (temp) {
			if (temp->Data.colvo < number) {  // Считаем количесво результов поиска
				Search_Result++;
			}
			temp = temp->next;
		}
	}
	else if (edge == tail) {  // если с конца
		while (temp) {
			if (temp->Data.colvo < number) {  // Считаем количесво результов поиска
				Search_Result++;
			}
			temp = temp->prev;
		}
	}
	// Вывод наличия резульатов
	if (Search_Result == 0) {
		printf("Ничего не найдено.\n\n");  return;
	}
	else if (Search_Result != 0) {
		printf("\nРезультатов: %d\n", Search_Result);
	}
	// Вывод самих результатов
	printf("----------------------------------------------\n");
	printf("|         Ведомость комплектующих            |\n");
	printf("|--------------------------------------------|\n");
	printf("| Обозначение | Тип |  Номинал  | Количество |\n");
	printf("|-------------|-----|-----------|------------|\n");
	temp = edge;
	if (edge == head) { // если с головы
		while (temp) {
			if (temp->Data.colvo < number) {
				printf("|%-13s|%-5c|%-11d|%-12d|\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
				printf("----------------------------------------------\n");
			}
			temp = temp->next;
		}
	}
	else if (edge == tail) { // если с конца
		while (temp) {
			if (temp->Data.colvo < number) {
				printf("|%-13s|%-5c|%-11d|%-12d|\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
				printf("----------------------------------------------\n");
			}
			temp = temp->prev;
		}
	}printf("\n\n");
}
