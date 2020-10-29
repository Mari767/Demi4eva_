#include <iostream>
int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, c;


	printf("Эта программа считает, сколько секунд в текущем году. \nВведите количество лет для расчета. \n ");
	scanf_s("%lf", &a);
	c = 60 * 60 * 24 * 365;
	b = c * a;
	printf("В %.lf лет %.lf секунд.\n", a, b);

}