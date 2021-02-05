#include <iostream>
int main()
{
	setlocale(LC_ALL, "Russian");

	int a, b, c;
	printf("Способ обмена местами значения 2-х переменных через дополнительную переменную \n");
	printf("Введите значения а и b\n");

	printf("\na=");
	scanf_s("%d", &a);
	printf("b=");
	scanf_s("%d", &b);

	c = a;
	a = b;
	b = c;
	printf("\na=%d\nb=%d\n", a, b);

	printf("\n Способ обмена местами значения 2-х переменных не используя дополнительной переменной\n");

	b = a + b;
	a = b - a;
	b = b - a;
	printf("\na=%d \nb=%d\n", a, b);
}