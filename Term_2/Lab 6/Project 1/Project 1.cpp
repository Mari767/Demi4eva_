//// сделать все возможные проверки на корректный ввод данных.
////функция копирует строку в другую строку заданной длины и размещает текст первой строки по центру второй строки.
#include <stdio.h>
#include <iostream>
#define clear_buf a = 0; while (a != EOF && a != '\n') { a = getchar(); }

void Input(char* Mas_1, char* mas_2, int Size_2, int symbol) { //symbol = Size для первого массива в функции
	int i, b; 
	int j = (Size_2 - symbol) / 2; // вычисляем позицию(вторая строка), с которой начинается копирование первой строки
	// Заполнение второй строки
	for (b = 0, i = 0; i < Size_2; i++) {

		if (i >= j && b < symbol) {       // копирование первой строки в середину второй  
			*(mas_2 + i) = *(Mas_1 + b);
			b++;
		}
		else if (i < j || i >= j + b) {   // заполнение начала и конца второй строки пробелом
			*(mas_2 + i) = ' ';
		}
		if (i == Size_2 - 1) {            // Конец строки. Очистка дальнейшего мусора
			*(mas_2 + i) = '\0';
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int Size_1 = 10, Size_2 = 20, i;
	int symbol;   // кол-во введенных символов
int buf, a = 0;        
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
	clear_buf;
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
//
//char ch;
//while ((ch = fgetc(stdin)) == EOF || ch == '\n');









