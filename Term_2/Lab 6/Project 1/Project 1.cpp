//// сделать все возможные проверки на корректный ввод данных.
////функция копирует строку в другую строку заданной длины и размещает текст первой строки по центру второй строки.

#include <iostream>
#include "Function.h"

int main() {
	setlocale(LC_ALL, "ru");
	int Size_1 = 30, Size_2 = 45, i;
	int symbol;   // кол-во введенных символов
	if (Size_2 < Size_1) {
		return 0;
	}
	printf("Размерность первой строки %d єлементоов, а второй - %d\n", Size_1, Size_2);
	char* String = new char[Size_1];
	char* Str_2 = new char[Size_2];
	// очищаем строкy от мусора
	*String = '\0';
	// Заполнение первой строки
	printf("Введите строку  ");
	scanf_s("%[^\n]s", String, Size_1);
	//Вызов функции очистки буфера
	clearStdIn();

	printf("\nПервая строка: %s", String);
	printf("\n\n");
	//подсчет кол-во введенных символов
	for (symbol = 0; *(String + symbol) != '\0'; symbol++) {}

	// Вызов функции заполнения второй строки элементами первой
	Input(String, Str_2, Size_2, symbol); 

	printf("\nВторая строка:  |%s|", Str_2);

	delete[] String;
	delete[] Str_2;
	return 0;
}






