#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b;

	printf("Введите число a, что бы вознести его в восьмую степень.\n a=");
	scanf_s("%d", &a);

	b = a * a;
	b = b * b;
	b = b * b;

	printf("%d в восьмой степени равно %d", a, b);

	return 0;
}