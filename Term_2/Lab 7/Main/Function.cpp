#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#include <iostream>
#include <stdio.h>
#include "Struct.h"
using namespace std;

information Rand_Name(information vedom);
void clearStdIn();

void Screen(char* name, information vedom, int* Size) {  //Ввод с экрана и запись в файл.
	FILE* file;
	fopen_s(&file, name, "wt");  // file opened
	if (file == NULL) {
		exit(0);
	}
	printf("Введите обозначение, тип, номинал, количество > \n(для завершения заполнения таблицы введите в обозначение ***)\n");
	char rand_name[20];
	for (; ; (*Size)++) {
		if (*Size == 10) {  //B=10
			break;
		}
		clearStdIn();
		cin.getline(vedom.name, 20);
		if (!strcmp(vedom.name, "***")) {
			break;
		}
		scanf_s(" %c", &vedom.typ);
		scanf_s(" %d %d", &vedom.nom, &vedom.colvo);
		fprintf(file, "%s %c %d %d\n", vedom.name, vedom.typ, vedom.nom, vedom.colvo);
	}
	fclose(file);  //  file closed
}

void Rand(char* name, information vedom, int* Size) {       //	Ввод случайным образом и запись в файл
	//Ввод рандомайзером
	*Size = 10;  // Size = 10
	FILE* file = NULL;
	fopen_s(&file, name, "wt");  // file opened
	if (file == NULL) {
		exit(0);
	}
	for (int i = 0; i < *Size; i++) {
		vedom = Rand_Name(vedom);
		vedom.typ = 'A' + rand() % ('Z' - 'A');
		vedom.nom = rand() % 1000;
		vedom.colvo = rand() % 100;
		fprintf(file, "%s %c %d %d\n", vedom.name, vedom.typ, vedom.nom, vedom.colvo);
	}
	fclose(file);  //  file closed
}

void Add_to_Start(char* name, information vedom, int* Size_file_1, int add_to_start) { //Добавить запись в начало файла.
	FILE* file = NULL;
	FILE* file_2 = NULL;
	fopen_s(&file_2, "File_for_adding.txt", "wt");  // file_2 opened
	if (file_2 == NULL) {
		exit(0);
	}
	for (int i = 0; i < add_to_start; i++) {  //Добавляются новые элементы в file_2
		vedom = Rand_Name(vedom);
		vedom.typ = 'A' + rand() % ('Z' - 'A');
		vedom.nom = rand() % 1000;
		vedom.colvo = rand() % 100;
		fprintf(file_2, "%s %c %d %d\n", vedom.name, vedom.typ, vedom.nom, vedom.colvo);
	}
	fclose(file_2);
	file_2 = NULL;
	fopen_s(&file, name, "rt");  // file opened
	if (file == NULL) {
		exit(0);
	}
	fopen_s(&file_2, "File_for_adding.txt", "at");  // file_2 opened
	if (file_2 == NULL) {
		exit(0);
	}
	for (int i = 0; i < *Size_file_1; i++) {  // из file копируем данные в file_2   (дозаполнение file_2)
		fscanf_s(file, "%s", vedom.name, 20);
		fseek(file, 1, SEEK_CUR);
		fscanf_s(file, "%c", &vedom.typ);
		fseek(file, 1, SEEK_CUR);
		fscanf_s(file, "%d", &vedom.nom);
		fseek(file, 1, SEEK_CUR);
		fscanf_s(file, "%d", &vedom.colvo);
		fprintf(file_2, "%s %c %d %d\n", vedom.name, vedom.typ, vedom.nom, vedom.colvo);
	}
	fclose(file);    //  file closed
	fclose(file_2);  //  file_2 closed
	*Size_file_1 += add_to_start;             // Увеличение Size, так как добавлены новые элементы
	file = NULL;
	file_2 = NULL;
	fopen_s(&file, name, "wt");                    // file opened
	fopen_s(&file_2, "File_for_adding.txt", "rt");     // file_2 opened
	if (file == NULL) {
		exit(0);
	}if (file_2 == NULL) {
		exit(0);
	}
	for (int i = 0; i < *Size_file_1; i++) {  // переносим все данные из filr_2 в file (в результате у нас есть file с добавленными элементами в начало)
		fscanf_s(file_2, "%s", vedom.name, 20);
		fseek(file_2, 1, SEEK_CUR);
		fscanf_s(file_2, "%c", &vedom.typ);
		fseek(file_2, 1, SEEK_CUR);
		fscanf_s(file_2, "%d", &vedom.nom);
		fseek(file_2, 1, SEEK_CUR);
		fscanf_s(file_2, "%d", &vedom.colvo);
		fprintf(file, "%s %c %d %d\n", vedom.name, vedom.typ, vedom.nom, vedom.colvo);
	}
	fclose(file);    //  file closed
	fclose(file_2);  //  file_2 closed
}

void Add_to_End(char* name, information vedom, int Add_elements) {   //Добавить запись в конец файла.

	FILE* file = NULL;
	fopen_s(&file, name, "at");  // file opened
	if (file == NULL) {
		exit(0);
	}
	for (int i = 0; i < Add_elements; i++) {            //Генерируются элементы
		vedom = Rand_Name(vedom);
		vedom.typ = 'A' + rand() % ('Z' - 'A');
		vedom.nom = rand() % 1000;
		vedom.colvo = rand() % 100;
		fprintf(file, "%s %c %d %d", vedom.name, vedom.typ, vedom.nom, vedom.colvo);// Запись сгенерированных элементов в конец файла
	}
	fclose(file);
}

void  Print_One_Note(char* name, information vedom, int Location) {   //Печать одной записи из файла по номеру.
	int i = 0;
	FILE* file = NULL;
	fopen_s(&file, name, "rt");  // file opened
	if (file == NULL) {
		exit(0);
	}
	printf("----------------------------------------------\n");
	printf("|         Ведомость комплектующих            |\n");
	printf("|--------------------------------------------|\n");
	printf("| Обозначение | Тип |  Номинал  | Количество |\n");
	printf("|-------------|-----|-----------|------------|\n");

	while (i != Location + 1) { // переход на заданную позицию Location
		fscanf_s(file, "%s", vedom.name, 20);                  // Считывание элемента с заданной позиции
		fseek(file, 1, SEEK_CUR);
		fscanf_s(file, "%c", &vedom.typ);
		fseek(file, 1, SEEK_CUR);
		fscanf_s(file, "%d", &vedom.nom);
		fseek(file, 1, SEEK_CUR);
		fscanf_s(file, "%d", &vedom.colvo);
		i++;
	}
	printf("|%-13s|%-5c|%-11d|%-12d|\n", vedom.name, vedom.typ, vedom.nom, vedom.colvo);
	printf("--------------------------------------------\n");
	fclose(file);  //  file closed
}

void Print(char* name, information vedom, int* Size) {
	FILE* file = NULL;
	fopen_s(&file, name, "rt");  // file opened
	if (file == NULL) {
		exit(0);
	}

	printf("----------------------------------------------\n");
	printf("|         Ведомость комплектующих            |\n");
	printf("|--------------------------------------------|\n");
	printf("| Обозначение | Тип |  Номинал  | Количество |\n");
	printf("|-------------|-----|-----------|------------|\n");

	for (int i = 0; i < *Size; i++) {
		fscanf_s(file, "%s", vedom.name, 20);
		fseek(file, 1, SEEK_CUR);
		fscanf_s(file, "%c", &vedom.typ);
		fseek(file, 1, SEEK_CUR);
		fscanf_s(file, "%d", &vedom.nom);
		fseek(file, 1, SEEK_CUR);
		fscanf_s(file, "%d", &vedom.colvo);
		printf("|%-13s|%-5c|%-11d|%-12d|\n", vedom.name, vedom.typ, vedom.nom, vedom.colvo);
		printf("|--------------------------------------------|\n");
	}
	fclose(file);  //  file closed
}

information Rand_Name(information vedom) { // Рандомный Name  для  vedom.name
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
