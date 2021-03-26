#include <stdio.h>

void clearStdIn() { // �������� ������ Stdin
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void Input(char* Mas_1, char* mas_2, int Size_2, int symbol) { //symbol = Size ��� ������� ������� � �������
	int i, b;
	int j = (Size_2 - symbol) / 2; // ��������� �������(������ ������), � ������� ���������� ����������� ������ ������
	// ���������� ������ ������
	for (b = 0, i = 0; i < Size_2; i++) {

		if (i >= j && b < symbol) {       // ����������� ������ ������ � �������� ������  
			*(mas_2 + i) = *(Mas_1 + b);
			b++;
		}
		else if (i < j || i >= j + b) {   // ���������� ������ � ����� ������ ������ ��������
			*(mas_2 + i) = ' ';
		}
		if (i == Size_2 - 1) {            // ����� ������. ������� ����������� ������
			*(mas_2 + i) = '\0';
		}
	}
}