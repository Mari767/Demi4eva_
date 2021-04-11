//ЛАБОРАТОРНАЯ РАБОТА № 7А
//Записать в файл(f1) массив(mas1) 10 чисел.Переписать из(f1) в другой массив(mas2) и в другой файл(f2).
//Распечатать(mas2).Из файла(f2) переписать данные последовательно в переменную х и распечатать(fprintf(), fscanf())

#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	srand(time_t(NULL));
	int x, i;
	int Size = 10;
	int* mas_1 = new int[Size];
	int* mas_2 = new int[Size];
	FILE* f1;
	FILE* f2;

	for (i = 0; i < Size; i++) {
		*(mas_1 + i) = rand() % 100;
	}

	// 1   Запись в файл(f1) массив(mas1) 10 чисел
	printf("1 -> Запись в файл(f1) массив(mas_1) 10 чисел\n");
	fopen_s(&f1, "f1.txt", "w");
	for (i = 0; i < Size; i++) {
		fprintf(f1, "%4d", *(mas_1 + i));
	}
	fclose(f1);

	//Перепись из(f1) в другой массив(mas2) и в другой файл(f2).
	printf("\n2 -> Перепись из(f1) в другой массив(mas2) и в другой файл(f2).\n");
	fopen_s(&f1, "f1.txt", "r");
	fopen_s(&f2, "f2.txt", "w");
	for (i = 0; i < Size; i++) {
		fscanf_s(f1, "%4d", (mas_1 + i));
		*(mas_2 + i) = *(mas_1 + i);
		fprintf(f2, "%4d", *(mas_1 + i));
	}
	fclose(f1);
	fclose(f2);

	printf("\n3 -> Печать второго массива \n");
	for (i = 0; i < Size; i++) {
		printf("%4d", *(mas_2 + i));
	}printf("\n");
	
	//Глушу массивы для проверки
	for (i = 0; i < Size; i++) {
		*(mas_1 + i) = 0;
		*(mas_2 + i) = 0;
	}
	//Из файла(f2) переписать данные последовательно в переменную х и распечатать
	printf("\n4 -> Из файла(f2) переписать данные последовательно в переменную х и распечатать.\n");
	fopen_s(&f2, "f2.txt", "r");

	for (i = 0; i < Size; i++) {
		fscanf_s(f2, "%4d", (mas_2 + i));
		x = *(mas_2 + i);
		printf("%4d", x);
	}
	fclose(f2);
	printf("\n\n");
	return 0;
}
