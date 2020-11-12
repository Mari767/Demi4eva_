#include <iostream>
#include <stdio.h>
// найти корни квадратного уравнения
int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, c, x, y, D, a2, x1, x2;
	printf("Введите a, b и c  \na=");
	scanf_s("%lf", &a);
	printf("b=");
	scanf_s("%lf", &b);
	printf("c=");
	scanf_s("%lf\n", &c);
	

	//a = 3, b = -5, c = -7.4;
	// формулы решения
	a2 = 2 * a;
	D = sqrt(b * b - 4 * a * c);
	if (D < 0){
	     printf("x не существует");
	}
	else {
		x1 = (-b - D) / a2;
		x2 = (-b + D) / a2;
		printf("x1=%.2lf \nx2=%.2lf\n", x1, x2);
	}
	return main();
}

