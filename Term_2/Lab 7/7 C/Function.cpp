#include <iostream>
#pragma warning(disable : 4996)

void Check(FILE* fptr) {
	if (fptr == NULL) {
		exit(0);
		printf("������ �������� �����\n");
	}
}

void Read_Sum(FILE* file,int Location, int*Sum){
	int number;
	file = NULL;
	file = fopen("file.dat", "r+b");
	Check(file);

	fseek(file, Location * sizeof(int), SEEK_SET); // ����� �������
	fread(&number, sizeof(int), 1, file);          // ������ � ���� �������
	*Sum += number;
	fclose(file);
}