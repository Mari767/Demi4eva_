
#include <iostream>
#include "Struct.h"
using namespace std;
//char Rand_Name();

int Screen(char* name, information vedom) {  //Ввод с экрана и запись в файл.
	FILE* file;
	fopen_s(&file, name, "wb");  // file opened
	int Size;
	float nomn;// переменная для номинала
	for (Size = 0; ; Size++) {
		if (Size == B) {  //B=10
			break;
		}
		printf("Введите обозначение, тип, номинал, количество > \n(для завершения заполнения таблицы введите в обозначение ***)\n");
		scanf_s("&s", vedom.name);
		if (!strcmp(vedom.name, "***")) {
			break;
		}
		scanf_s(" %c %f %d", &vedom.typ, &nomn, &vedom.colvo);
		vedom.nom = nomn;
		fwrite(&vedom, sizeof(information), 1, file);
	}
	fclose(file);  //  file closed
	return Size;
}

void Rand(char* name, information vedom/*, char (*Rand_Name)()*/) {       //	Ввод случайным образом и запись в файл
	//Ввод рандомайзером
	int Size = B;  // Size = 10
	char masname[20][M] = { "RT-11-24", "TRU4", "MNU-8", "OP-20", "P", "BORR", "POR-H", "BUTMB-K", "PTK", "RTY", "BROM-6", "TURP-08", "GHJ-0", "BERMUDO", "PRTYMB-2", "NO-3", "YIR-15", "CGU-RT-12", "ST", "CGU-12K" };
	FILE* file;
	fopen_s(&file, name, "wb");  // file opened
	for (int i = 0; i < Size; i++) {
		/*char rand_name[M];
		*rand_name = '\0';
		//rand_name[M] = { Rand_Name() };
		//strcpy_s(vedom.name, rand_name);*/
		int Randsign = rand() % 20;
		strcpy_s(vedom.name, masname[Randsign]);
		vedom.typ = 'A' + rand() % ('Z' - 'A');
		vedom.nom = rand() % 1000;
		vedom.colvo = rand() % 100;
		fwrite(&vedom, sizeof(information), 1, file);
	}
	fclose(file);  //  file closed
}
//char Rand_Name(){
//	char rand_name[M];
//	char masname[20][M] = { "RT-11-24", "TRU4", "MNU-8", "OP-20", "P", "BORR", "POR-H", "BUTMB-K", "PTK", "RTY", "BROM-6", "TURP-08", "GHJ-0", "BERMUDO", "PRTYMB-2", "NO-3", "YIR-15", "CGU-RT-12", "ST", "CGU-12K" };
//	int Randsign = rand() % 20;
//	strcpy_s(rand_name, masname[Randsign]);
//	return rand_name[M];
//}

void Add_to_Start(char* name, information vedom, int Size_file_1, int add_to_start) { //Добавить запись в начало файла.
	FILE* file;
	FILE* file_2;
	fopen_s(&file_2, "File_for_adding", "w");  // file_2 opened

	char masname[20][M] = { "RT-11-24", "TRU4", "MNU-8", "OP-20", "P", "BORR", "POR-H", "BUTMB-K", "PTK", "RTY", "BROM-6", "TURP-08", "GHJ-0", "BERMUDO", "PRTYMB-2", "NO-3", "YIR-15", "CGU-RT-12", "ST", "CGU-12K" };
	for (int i = 0; i < add_to_start; i++) {  //Добавляются новые элементы в file_2

		int Randsign = rand() % 20;
		strcpy_s(vedom.name, masname[Randsign]);
		vedom.typ = 'A' + rand() % ('Z' - 'A');
		vedom.nom = rand() % 1000;
		vedom.colvo = rand() % 100;
		fwrite(&vedom, sizeof(information), 1, file_2);
	}
	fopen_s(&file, name, "r");  // file opened

	for (int i = 0; i < Size_file_1; i++) {  // из file копируем данные в file_2   (дозаполнение file_2)
		fread(&vedom, sizeof(information), 1, file);
		fwrite(&vedom, sizeof(information), 1, file_2);
	}
	fclose(file);    //  file closed
	fclose(file_2);  //  file_2 closed
	Size_file_1 += add_to_start;             // Увеличение Size, так как добавлены новые элементы
	fopen_s(&file, name, "w");                    // file opened
	fopen_s(&file_2, "File_for_adding", "r");     // file_2 opened

	for (int i = 0; i < Size_file_1; i++) {  // переносим все данные из filr_2 в file (в результате у нас есть file с добавленными элементами в начало)
		fread(&vedom, sizeof(information), 1, file_2);
		fwrite(&vedom, sizeof(information), 1, file);
	}
	fclose(file);    //  file closed
	fclose(file_2);  //  file_2 closed
}

void Add_to_End(char* name, information vedom, int Add_elements) {   //Добавить запись в конец файла.

	char masname[20][M] = { "RT-11-24", "TRU4", "MNU-8", "OP-20", "P", "BORR", "POR-H", "BUTMB-K", "PTK", "RTY", "BROM-6", "TURP-08", "GHJ-0", "BERMUDO", "PRTYMB-2", "NO-3", "YIR-15", "CGU-RT-12", "ST", "CGU-12K" };
	FILE* file;
	fopen_s(&file, name, "ab");  // file opened
	for (int i = 0; i < Add_elements; i++) {            //Генерируются элементы

		int Randsign = rand() % 20;
		strcpy_s(vedom.name, masname[Randsign]);
		vedom.typ = 'A' + rand() % ('Z' - 'A');
		vedom.nom = rand() % 1000;
		vedom.colvo = rand() % 100;

		fwrite(&vedom, sizeof(information), 1, file);    // Запись сгенерированных элементов в конец файла
	}
	fclose(file);
}

void  Print_One_Note(char* name, information vedom, int Location) {   //Печать одной записи из файла по номеру.
	FILE* file;
	fopen_s(&file, name, "rb");  // file opened

	printf("----------------------------------------------\n");
	printf("|         Ведомость комплектующих            |\n");
	printf("|--------------------------------------------|\n");
	printf("| Обозначение | Тип |  Номинал  | Количество |\n");
	printf("|-------------|-----|-----------|------------|\n");

	fseek(file, Location * sizeof(information), SEEK_SET);  // переход на заданную позицию Location
	fread(&vedom, sizeof(information), 1, file);            // Считывание элемента с заданной позиции

	printf("|%-13s|%-5c|%-11.f|%-12d|\n", vedom.name, vedom.typ, vedom.nom, vedom.colvo);
	printf("|--------------------------------------------|\n");
	fclose(file);  //  file closed
}

int Print(char* name, information vedom, int Size) {
	FILE* file;
	fopen_s(&file, name, "rb");  // file opened

	printf("----------------------------------------------\n");
	printf("|         Ведомость комплектующих            |\n");
	printf("|--------------------------------------------|\n");
	printf("| Обозначение | Тип |  Номинал  | Количество |\n");
	printf("|-------------|-----|-----------|------------|\n");
	for (int i = 0; i < Size; i++)
	{
		fread(&vedom, sizeof(information), 1, file);
		printf("|%-13s|%-5c|%-11.f|%-12d|\n", vedom.name, vedom.typ, vedom.nom, vedom.colvo);
		printf("|--------------------------------------------|\n");
	}
	/*while (!feof(file)) {
			fread(&vedom, sizeof(information), 1, file);
			printf("|%-13s|%-5c|%-11.f|%-12d|\n", vedom.name, vedom.typ, vedom.nom, vedom.colvo);
			printf("|--------------------------------------------|\n");
	}*/
	fclose(file);  //  file closed
	/*else {
		cout << "Таблица пуста. Пожалуйста заполните сперва таблицу.\n" << endl;
	}*/
	return Size;
}