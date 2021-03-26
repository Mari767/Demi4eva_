#include <stdio.h>

void clearStdIn() { // ќчищение буфера Stdin
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void Input(char* Mas_1, char* mas_2, int Size_2, int symbol) { //symbol = Size дл€ первого массива в функции
	int i, b;
	int j = (Size_2 - symbol) / 2; // вычисл€ем позицию(втора€ строка), с которой начинаетс€ копирование первой строки
	// «аполнение второй строки
	for (b = 0, i = 0; i < Size_2; i++) {

		if (i >= j && b < symbol) {       // копирование первой строки в середину второй  
			*(mas_2 + i) = *(Mas_1 + b);
			b++;
		}
		else if (i < j || i >= j + b) {   // заполнение начала и конца второй строки пробелом
			*(mas_2 + i) = ' ';
		}
		if (i == Size_2 - 1) {            //  онец строки. ќчистка дальнейшего мусора
			*(mas_2 + i) = '\0';
		}
	}
}