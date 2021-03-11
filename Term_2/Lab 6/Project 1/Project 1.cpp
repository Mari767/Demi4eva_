//Функция копирует строку в другую строку заданной длины и размещает текст первой строки по центру второй строки.

#include <iostream>

int main() {
	setlocale(LC_ALL, "ru");
	int Size;
	scanf_s("%d", &Size);
	char* str1 = (char*)malloc(sizeof(char) * Size);
	char* str2 = (char*)malloc(sizeof(char) * Size);
	if (Size < 25) {
		printf("Строка слишком коротка. Для выполнения данной задачи выберете большую длинну строки\n");
	}
	printf("Введите строку\n");
}