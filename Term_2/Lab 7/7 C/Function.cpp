#include <iostream>
#pragma warning(disable : 4996)

void Check(FILE* fptr) {
	if (fptr == NULL) {
		exit(0);
		printf("Ошибка открытия файла\n");
	}
}

void Read_Sum(FILE* file,int Location, int*Sum){
	int number;
	file = NULL;
	file = fopen("file.dat", "r+b");
	Check(file);

	fseek(file, Location * sizeof(int), SEEK_SET); // поиск позиции
	fread(&number, sizeof(int), 1, file);          // чтение с этой позиции
	*Sum += number;
	fclose(file);
}