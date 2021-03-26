//// сделать все возможные проверки на корректный ввод данных.
////функция копирует строку в другую строку заданной длины и размещает текст первой строки по центру второй строки.

#include <iostream>
#include "Function.h"

int main() {
	setlocale(LC_ALL, "ru");
	int Size_1 = 20, Size_2 = 35, i;
	int Size = 200;
	int symbol;   // кол-во введенных символов
	if (Size_2 < Size_1) {
		return 0;
	}
	printf("Размерность первой строки %d єлементоов, а второй - %d\n", Size_1, Size_2);
	char* String = new char[Size];
	char* Str_1 = new char[Size_1];
	char* Str_2 = new char[Size_2];
	// очищаем строкy от мусора
	*String = '\0';
	//Заполнение пробной строки  //  типо первой, но это от переполнения (если пользователь вводит строку большую, чем задана, то мы просто копируем  то, что влазит в первую)
	printf("Введите строку  ");
	scanf_s("%[^\n]s", String, Size);
	clearStdIn(); //Вызов функции очистки буфера

	// заполняем первую строку   Str_1
	for (i = 0; i < Size_1; i++) {
		*(Str_1 + i) = *(String + i);
		if (i == Size_1 - 1) {
			*(Str_1 + i) = '\0';
		}
	}

	printf("\nПервая строка: %s", Str_1);
	printf("\n\n");
	//подсчет кол-во введенных символов
	for (symbol = 0; *(Str_1 + symbol) != '\0'; symbol++) {}

	// Вызов функции заполнения второй строки элементами первой
	Input(Str_1, Str_2, Size_2, symbol); 

	printf("\nВторая строка:  |%s|", Str_2);

	delete[] Str_1;
	delete[] Str_2;
	return 0;
}






