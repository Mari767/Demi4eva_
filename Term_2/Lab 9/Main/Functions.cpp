#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "Struct.h"

information Rand();
information Rand_Name(information vedom);

void  Creation_List(int* Size, List*& head, List*& tail) {
	information vedom;
	List* temp = NULL;
	int i = 0;
	while (i != *Size) {
		i++;
		temp = (struct List*)malloc(sizeof(struct List));
		if (head == NULL) {      //список пустой
			temp->prev = NULL;
			head = tail = temp;  // указатели начала  и конца
		}
		else {                   //список не пустой
			tail->next = temp;   //адрес предпоследнего
			temp->prev = tail;   //адрес последнего
			tail = temp;         //указатель конца
		}
		//Заполнение ячейки списка данными со структуры
		vedom = Rand();
		strcpy_s(temp->Data.name, vedom.name);
		temp->Data.typ = vedom.typ;
		temp->Data.colvo = vedom.colvo;
		temp->Data.nom = vedom.nom;
		temp->Data.sort = 0;
		temp->next = NULL;       // этот элемент - последний
	}
}

void Print_List(List* head, List* tail, List* edge) {
	if (head == NULL) { printf("Список пуст.\n"); 	return; }

	printf("----------------------------------------------\n");
	printf("|         Ведомость комплектующих            |\n");
	printf("|--------------------------------------------|\n");
	printf("| Обозначение | Тип |  Номинал  | Количество |\n");
	printf("|-------------|-----|-----------|------------|\n");

	if (edge == head)
		while (edge)
		{
			printf("|%-13s", edge->Data.name, 20);
			printf("|%-5c", edge->Data.typ);
			printf("|%-11d", edge->Data.nom);
			printf("|%-12d|\n", edge->Data.colvo);
			printf("|--------------------------------------------|\n");
			edge = edge->next;
		}
	else if (edge == tail)
		while (edge)
		{
			printf("|%-13s", edge->Data.name, 20);
			printf("|%-5c", edge->Data.typ);
			printf("|%-11d", edge->Data.nom);
			printf("|%-12d|\n", edge->Data.colvo);
			printf("|--------------------------------------------|\n");
			edge = edge->prev;
		}
	printf("\n\n");
}

void add_first_element(List*& head, int* Size) {
	++(*Size);
	information vedom;
	List* temp = (struct List*)malloc(sizeof(struct List));
	temp->prev = NULL;
	temp->next = head;
	head->prev = temp;
	head = temp;

	vedom = Rand();
	strcpy_s(temp->Data.name, vedom.name);
	temp->Data.typ = vedom.typ;
	temp->Data.colvo = vedom.colvo;
	temp->Data.nom = vedom.nom;
	temp->Data.sort = 0;
}
void add_middle_element(List* head, int* Size, int Location) {
	++(*Size);
	information vedom;
	List* temp = head, * tail = temp;
	for (int i = 1; temp != NULL; i++) {

		if (i == Location) {
			tail = temp;
			temp = (struct List*)malloc(sizeof(struct List));
			temp->next = tail->next;
			tail->next->prev = temp;

			tail->next = temp;
			temp->prev = tail;

			vedom = Rand();
			strcpy_s(temp->Data.name, vedom.name);
			temp->Data.typ = vedom.typ;
			temp->Data.colvo = vedom.colvo;
			temp->Data.nom = vedom.nom;
			temp->Data.sort = 0;
			break;
		}
		else {
			tail = temp;
			temp = temp->next;
		}
	}
}
void add_last_element(List* head, int* Size) {
	++(*Size);
	information vedom;
	List* temp = head, * tail = NULL;
	while (temp) {
		tail = temp;
		temp = temp->next;
	}
	temp = (struct List*)malloc(sizeof(struct List));
	tail->next = temp;
	temp->prev = tail;
	temp->next = NULL;
	tail = temp;
	vedom = Rand();
	strcpy_s(temp->Data.name, vedom.name);
	temp->Data.typ = vedom.typ;
	temp->Data.colvo = vedom.colvo;
	temp->Data.nom = vedom.nom;
	temp->Data.sort = 0;
}

void free_first_element(List*& head, int* Size) {
	if (*Size <= 0) { return; }; --(*Size);

	List* temp = head;
	head = temp->next;
	free(temp);
	head->prev = NULL;
}
void free_middle_element(List* head, int* Size, int Location) {
	if (*Size <= 0) { return; };//если список пуст-- удаление невозможно
	--(*Size);
	List* temp = head, * tail = temp;
	for (int i = 0; temp != NULL; i++)
	{
		if (i == Location)
		{
			tail->next = temp->next;
			tail->next->prev = tail;
			free(temp);
			temp = tail->next;
			return;
		}
		else
		{
			tail = temp;
			temp = temp->next;

		}
	}
}
void free_last_element(List*& tail, int* Size) {
	if (*Size <= 0) { return; };//если список пуст-- удаление невозможно
	--(*Size);

	List* temp = tail;
	tail = temp->prev;
	tail->next = NULL;
	free(temp);
}

void Sort( List* head) {
	if (head == NULL) {
		printf("Список пуст.\n");
		return;
	}
	information vedom;
	List* tail = NULL;
	List* dop, * temp, * stabilnno;
	stabilnno = dop = temp = head;

	while (temp) {// Подсчет количество символов в name
		temp->Data.sort = strlen(temp->Data.name);
		temp = temp->next;
	}

	while ((temp = stabilnno->next)) {
		while (temp) {
			if (temp->Data.sort < stabilnno->Data.sort) {
				vedom = temp->Data;
				temp->Data = stabilnno->Data;
				stabilnno->Data = vedom;
			}
			temp = temp->next;
		}
		stabilnno = stabilnno->next;
	}
	return;
}

void Recording_List_to_FILE(List* head, char* name) {
	if (head == NULL) {
		printf("Список пуст.\n");
		return;
	}
	FILE* file = NULL;
	fopen_s(&file, name, "wt");  // file opened
	if (file == NULL) {
		exit(0);
	}
	List* temp = head;
	while (temp) {
		fprintf(file, "%s %c %d %d\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
		temp = temp->next;
	}
	fclose(file);
}

void Creation_New_List_from_File(char* name, int* Size, List*& head, List*& tail) {
	char symbol_from_file;
	int i = 0;
	FILE* file = NULL;
	fopen_s(&file, name, "rt");  // file opened
	if (file == NULL) {
		exit(0);
	}
	while (true) {  // Подсчет количества строк    (ситаем Size)
		symbol_from_file = fgetc(file);
		if (symbol_from_file == '\n') {
			(*Size)++;
		}
		else if (symbol_from_file == EOF) {
			break;
		}
	}printf("Size = %d\n\n", *Size);

	List* temp = NULL;

	fseek(file, 0, SEEK_SET);
	while (i < *Size) {
		i++;
		temp = (struct List*)malloc(sizeof(struct List));
		if (head == NULL) {      //список пустой
			temp->prev = NULL;
			head = tail = temp;  // указатели начала  и конца
		}
		else {                   //список не пустой
			tail->next = temp;   //адрес предпоследнего
			temp->prev = tail;   //адрес последнего
			tail = temp;         //указатель конца
		}
		fscanf_s(file, "%s", temp->Data.name, 20);
		fseek(file, 1, SEEK_CUR);
		fscanf_s(file, "%c", &temp->Data.typ);
		fseek(file, 1, SEEK_CUR);
		fscanf_s(file, "%d", &temp->Data.nom);
		fseek(file, 1, SEEK_CUR);
		fscanf_s(file, "%d", &temp->Data.colvo);

		temp->next = NULL;       // этот элемент - последний
	}
	fclose(file);
}

void Free_List(List*& head) {
	List* temp = head;
	while (temp)
	{
		head = head->next;
		free(temp);
		temp = head;
	}
}

information Rand() {       //	Ввод случайным образом //  заполнение  элеммента структуры vedom. 
	information vedom;
	vedom = Rand_Name(vedom);//Ввод рандомайзером}
	vedom.typ = 'A' + rand() % ('Z' - 'A');
	vedom.nom = rand() % 1123;
	vedom.colvo = rand() % 100 + 1;
	vedom.sort = 0;
	return vedom;
}

information Rand_Name(information vedom) { //  vedom.name
	/*char masname[20][20] = { "RT-11-24", "TRU4", "MNU-8", "OP-20", "P", "BORR", "POR-H", "BUTMB-K", "PTK", "RTY",
		"BROM-6", "TURP-08", "GHJ-0", "BERMUDO","ST", "PRTYMB-2", "NO-3", "YIR-15", "CGU-RT-12",  "CGU-12K" };*/
	int Randsign = rand() % 20;

	FILE* file = NULL;
	file = fopen("Rand_name.dat", "rb");
	fseek(file, Randsign * sizeof(information), SEEK_SET);
	fread(vedom.name, sizeof(information), 1, file);
	fclose(file);

	return vedom;
}
void clearStdIn() { // Очищение буфера Stdin
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

