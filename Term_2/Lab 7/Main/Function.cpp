#include <iostream>
#include <stdio.h>
#include "Struct.h"
using namespace std;

information Rand_Name(information vedom);
void clearStdIn();

void Screen(char* name, information vedom, int* Size) {  //���� � ������ � ������ � ����.
	FILE* file;
	fopen_s(&file, name, "wb");  // file opened
	if (file == NULL) {
		exit(0);
	}
	printf("������� �����������, ���, �������, ���������� > \n(��� ���������� ���������� ������� ������� � ����������� ***)\n");
	char rand_name[M];
	for (; ; (*Size)++) {
		if (*Size == B) {  //B=10
			break;
		}
		clearStdIn();
		cin.getline(vedom.name, M);
		if (!strcmp(vedom.name, "***")) {
			break;
		}
		scanf_s(" %c", &vedom.typ);
		scanf_s(" %d %d", &vedom.nom, &vedom.colvo);
		fwrite(&vedom, sizeof(information), 1, file);
	}
	fclose(file);  //  file closed
}

void Rand(char* name, information vedom, int* Size) {       //	���� ��������� ������� � ������ � ����
	//���� �������������
	 *Size = B;  // Size = 10
	FILE* file = NULL;
	fopen_s(&file, name, "wb");  // file opened
	if (file == NULL) {
		exit(0);
	}
	for (int i = 0; i < *Size; i++) {
		vedom = Rand_Name(vedom);
		vedom.typ = 'A' + rand() % ('Z' - 'A');
		vedom.nom = rand() % 1000;
		vedom.colvo = rand() % 100;
		fwrite(&vedom, sizeof(information), 1, file);
	}
	fclose(file);  //  file closed
}

void Add_to_Start(char* name, information vedom, int* Size_file_1, int add_to_start) { //�������� ������ � ������ �����.
	FILE* file = NULL;
	FILE* file_2 = NULL;
	fopen_s(&file_2, "File_for_adding", "w");  // file_2 opened
	if (file_2 == NULL) {
		exit(0);
	}
	for (int i = 0; i < add_to_start; i++) {  //����������� ����� �������� � file_2
		vedom = Rand_Name(vedom);
		vedom.typ = 'A' + rand() % ('Z' - 'A');
		vedom.nom = rand() % 1000;
		vedom.colvo = rand() % 100;
		fwrite(&vedom, sizeof(information), 1, file_2);
	}
	fopen_s(&file, name, "r");  // file opened
	if (file == NULL) {
		exit(0);
	}
	for (int i = 0; i < *Size_file_1; i++) {  // �� file �������� ������ � file_2   (������������ file_2)
		fread(&vedom, sizeof(information), 1, file);
		fwrite(&vedom, sizeof(information), 1, file_2);
	}
	fclose(file);    //  file closed
	fclose(file_2);  //  file_2 closed
	*Size_file_1 += add_to_start;             // ���������� Size, ��� ��� ��������� ����� ��������
	fopen_s(&file, name, "w");                    // file opened
	fopen_s(&file_2, "File_for_adding", "r");     // file_2 opened
	if (file == NULL) {
		exit(0);
	}if (file_2 == NULL) {
		exit(0);
	}
	for (int i = 0; i < *Size_file_1; i++) {  // ��������� ��� ������ �� filr_2 � file (� ���������� � ��� ���� file � ������������ ���������� � ������)
		fread(&vedom, sizeof(information), 1, file_2);
		fwrite(&vedom, sizeof(information), 1, file);
	}
	fclose(file);    //  file closed
	fclose(file_2);  //  file_2 closed
}

void Add_to_End(char* name, information vedom, int Add_elements) {   //�������� ������ � ����� �����.

	FILE* file = NULL;
	fopen_s(&file, name, "ab");  // file opened
	if (file == NULL) {
	exit(0);
}
	for (int i = 0; i < Add_elements; i++) {            //������������ ��������
		vedom = Rand_Name(vedom);
		vedom.typ = 'A' + rand() % ('Z' - 'A');
		vedom.nom = rand() % 1000;
		vedom.colvo = rand() % 100;

		fwrite(&vedom, sizeof(information), 1, file);    // ������ ��������������� ��������� � ����� �����
	}
	fclose(file);
}

void  Print_One_Note(char* name, information vedom, int Location) {   //������ ����� ������ �� ����� �� ������.
	FILE* file = NULL;
	fopen_s(&file, name, "rb");  // file opened
	if (file == NULL) {
		exit(0);
	}
	printf("----------------------------------------------\n");
	printf("|         ��������� �������������            |\n");
	printf("|--------------------------------------------|\n");
	printf("| ����������� | ��� |  �������  | ���������� |\n");
	printf("|-------------|-----|-----------|------------|\n");

	fseek(file, Location * sizeof(information), SEEK_SET);  // ������� �� �������� ������� Location
	fread(&vedom, sizeof(information), 1, file);            // ���������� �������� � �������� �������

	printf("|%-13s|%-5c|%-11d|%-12d|\n", vedom.name, vedom.typ, vedom.nom, vedom.colvo);
	printf("--------------------------------------------\n");
	fclose(file);  //  file closed
}

void Print(char* name, information vedom, int* Size) {
	FILE* file = NULL;
	fopen_s(&file, name, "rb");  // file opened
	if (file == NULL) {
		exit(0);
	}

	printf("----------------------------------------------\n");
	printf("|         ��������� �������������            |\n");
	printf("|--------------------------------------------|\n");
	printf("| ����������� | ��� |  �������  | ���������� |\n");
	printf("|-------------|-----|-----------|------------|\n");
	
	for (int i = 0; i < *Size; i++) {
		fread(&vedom, sizeof(information), 1, file);
		printf("|%-13s|%-5c|%-11d|%-12d|\n", vedom.name, vedom.typ, vedom.nom, vedom.colvo);
		printf("|--------------------------------------------|\n");
	}
	fclose(file);  //  file closed
}

information Rand_Name(information vedom) { // ��������� Name  ���  vedom.name
	char masname[20][M] = { "RT-11-24", "TRU4", "MNU-8", "OP-20", "P", "BORR", "POR-H", "BUTMB-K", "PTK", "RTY", "BROM-6", "TURP-08", "GHJ-0", "BERMUDO", "PRTYMB-2", "NO-3", "YIR-15", "CGU-RT-12", "ST", "CGU-12K" };
	int Randsign = rand() % 20;
	strcpy_s(vedom.name, masname[Randsign]);
	return vedom;
}
void clearStdIn() { // �������� ������ Stdin
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}
