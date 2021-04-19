#include <iostream>
#include "Struct.h"

information Rand();
information Rand_Name(information vedom);

struct List* Creation_List(int* Size) {
	information vedom;
	List* head = NULL;
	List* tail = NULL;
	List* temp = NULL;
	int i = 0;
	while (i != *Size) {
		i++;
		temp = (struct List*)malloc(sizeof(struct List));
		if (head == NULL) {      //список пустой
			head = tail = temp;  // указатели начала  и конца
		}
		else {                   //список не пустой
			tail->next = temp;   //адрес последнего
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
	return head;
}

void Print_List(struct List* head) {
	struct List* temp = head;
	if (head == NULL) {
		printf("Список пуст.\n");
		return;
	}
	printf("----------------------------------------------\n");
	printf("|         Ведомость комплектующих            |\n");
	printf("|--------------------------------------------|\n");
	printf("| Обозначение | Тип |  Номинал  | Количество |\n");
	printf("|-------------|-----|-----------|------------|\n");

	while (temp) {
		printf("|%-13s", temp->Data.name, 20);
		printf("|%-5c", temp->Data.typ);
		printf("|%-11d",temp->Data.nom);
		printf("|%-12d|\n", temp->Data.colvo);
		printf("|--------------------------------------------|\n");
		temp = temp->next;
	}
	printf("\n\n");
}

void add_first_element(struct List** head, int* Size) {
	++(*Size);
	information vedom;
	struct List* temp = (struct List*)malloc(sizeof(struct List));

	vedom = Rand();
	strcpy_s(temp->Data.name, vedom.name);
	temp->Data.typ = vedom.typ;
	temp->Data.colvo = vedom.colvo;
	temp->Data.nom = vedom.nom;
	temp->Data.sort = 0;

	temp->next = *head;
	*head = temp;
}
void add_middle_element(struct List* head, int* Size, int Location) {
	++(*Size);
	information vedom;
	 List* temp = head, * tail = temp;
	for (int i = 0; temp != NULL; i++) {                      //нужно ли до конца списка доходить------------------------------

		if (i == Location) {
			tail = temp;
			temp = (struct List*)malloc(sizeof(struct List));
			temp->next = tail->next;
			tail->next = temp;
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
void add_last_element(struct List* head, int* Size) {
	++(*Size);
	information vedom;
	struct List* temp = head, * tail = NULL;
	while (temp) {
		tail = temp;
		temp = temp->next;
	}
	temp = (struct List*)malloc(sizeof(struct List));
	tail->next = temp;
	vedom = Rand();
	strcpy_s(temp->Data.name, vedom.name);
	temp->Data.typ = vedom.typ;
	temp->Data.colvo = vedom.colvo;
	temp->Data.nom = vedom.nom;
	temp->Data.sort = 0;
	temp->next = NULL;
}

void free_first_element(struct List** head, int* Size) {           //  рекурсивно?
	if (*Size <= 0) { return; }; --(*Size);

	struct List* temp = *head;
	*head = temp->next;
	free(temp);
}
void free_middle_element(struct List* head, int* Size, int Location) {
	if (*Size <= 0) { return; };//если список пуст-- удаление невозможно
	--(*Size);
	struct List* temp = head, * tail = temp;
	for (int i = 0; temp != NULL; i++)                              //нужно ли до конца списка доходить------------------------------
	{
		if (i == Location) {
			tail->next = temp->next;
			free(temp);
			temp = tail->next;
		}
		else {
			{
				tail = temp;
				temp = temp->next;
			}
		}
	}
}
void free_last_element(struct List* head, int* Size) {
	if (*Size <= 0) { return; };//если список пуст-- удаление невозможно
	--(*Size);

	struct List* temp = head, * tail = NULL;
	while (temp->next) {
		tail = temp;
		temp = temp->next;
	}
	tail->next = NULL;
	free(temp);
}

void Sort(struct List* head) {
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

void Recording_List_to_FILE(struct List* head, char* name) {
	if (head == NULL) {
		printf("Список пуст.\n");
		return;
	}
	FILE* file = NULL;
	fopen_s(&file, name, "wt");  // file opened
	if (file == NULL) {
		exit(0);
	}
	struct List* temp = head, * tail = NULL;
	while (temp) {
		fprintf(file, "%s %c %d %d\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
		tail = temp;
		temp = temp->next;
	}
	fclose(file);
}

struct List* Creation_New_List_from_File(char* name, int* Size) {
	char symbol_from_file;
	int i = 0;
	FILE* file = NULL;
	fopen_s(&file, name, "rt");  // file opened
	if (file == NULL) {
		exit(0);
	}
	while (true) {  // Подсчет количества строк
		symbol_from_file = fgetc(file);
		if (symbol_from_file == '\n') {
			(*Size)++;
		}
		else if (symbol_from_file == EOF) {
			break;
		}
	}printf("Size = %d\n\n", *Size);

	List* head = NULL;
	List* tail = NULL;
	List* temp = NULL;

	fseek(file, 0, SEEK_SET);
	while (i < *Size) {
		i++;
		temp = (struct List*)malloc(sizeof(struct List));
		if (head == NULL) {      //список пустой
			head = tail = temp;  // указатели начала  и конца
		}
		else {                   //список не пустой
			tail->next = temp;   //адрес последнего
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
	return head;
}

void Free_List(struct List** head) {
	struct List* temp = *head;
	while (temp)
	{
		*head = (*head)->next;
		free(temp);
		temp = *head;
	}
}

information Rand() {       //	Ввод случайным образом //  заполнение  элеммента структуры vedom. 
	information vedom;
	vedom = Rand_Name(vedom);//Ввод рандомайзером
	vedom.typ = 'A' + rand() % ('Z' - 'A');
	vedom.nom = rand() % 1123;
	vedom.colvo = rand() % 100 + 1;
	vedom.sort = 0;
	return vedom;
}

information Rand_Name(information vedom) { // Рандомный Name  для  vedom.name
	char masname[20][M] = { "RT-11-24", "TRU4", "MNU-8", "OP-20", "P", "BORR", "POR-H", "BUTMB-K", "PTK", "RTY",
		"BROM-6", "TURP-08", "GHJ-0", "BERMUDO","ST", "PRTYMB-2", "NO-3", "YIR-15", "CGU-RT-12",  "CGU-12K" };
	int Randsign = rand() % 20;
	strcpy_s(vedom.name, masname[Randsign]);
	return vedom;
}
void clearStdIn() { // Очищение буфера Stdin
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

