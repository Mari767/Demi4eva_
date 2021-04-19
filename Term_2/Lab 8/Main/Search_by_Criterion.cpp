#include <iostream>
#include "Function.h"
#include "Struct.h"

void Alphabet(struct List* head, char Symbol) {
	List* temp = head;
	int Search_Result = 0;

	while (temp) {
		if (*(temp->Data.name) == Symbol) {  // Считаем количесво результов поиска
			Search_Result++;
		}
		temp = temp->next;
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
	temp = head;
	while (temp) {
		if (*(temp->Data.name) == Symbol) {
			printf("|%-13s|%-5c|%-11d|%-12d|\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
			printf("----------------------------------------------\n");
		}
		temp = temp->next;
	}
	printf("\n\n");
}

void Search_Typ(struct List* head, char Symbol) {
	List* temp = head;
	int Search_Result = 0;

	while (temp) {
		if (temp->Data.typ == Symbol) {  // Считаем количесво результов поиска
			Search_Result++;
		}
		temp = temp->next;
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
	temp = head;
	while (temp) {
		if (temp->Data.typ == Symbol) {
			printf("|%-13s|%-5c|%-11d|%-12d|\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
			printf("----------------------------------------------\n");
		}
		temp = temp->next;
	}
	printf("\n\n");
}

void Search_Nom(struct List* head, int number) {//Введите число.Результатом поиска являются комплектующий элемент ведомости с номиналом больше, нежели заданное число.
	List* temp = head;
	int Search_Result = 0;

	while (temp) {
		if (temp->Data.nom > number) { // Считаем количесво результов поиска
			Search_Result++;
		}
		temp = temp->next;
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
	temp = head;
	while (temp) {
		if (temp->Data.nom > number) {
			printf("|%-13s|%-5c|%-11d|%-12d|\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
			printf("----------------------------------------------\n");
		}
		temp = temp->next;
	}
	printf("\n\n");
}

void Search_Colvo(struct List* head, int number) {
	List* temp = head;
	int Search_Result = 0;

	while (temp) {
		if (temp->Data.colvo < number) {  // Считаем количесво результов поиска
			Search_Result++;
		}
		temp = temp->next;
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
	temp = head;
	while (temp) {
		if (temp->Data.colvo < number) {
			printf("|%-13s|%-5c|%-11d|%-12d|\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
			printf("----------------------------------------------\n");
		}
		temp = temp->next;
	}
	printf("\n\n");

}
