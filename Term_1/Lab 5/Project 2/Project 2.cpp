#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
// найти корни квадратного уравнения
int main()
{
	setlocale(LC_ALL, "Russian");
	
	double a, b, c, a2, x1, x2;
	double D;
	printf("\nВведите a, b и c  \na=");
	scanf("%lf", &a);
	printf("b=");
	scanf("%lf", &b);
	printf("c=");
	scanf("%lf", &c);
	
	// формулы решения
	a2 = 2 * a;
	D = (b * b - 4 * a * c);
	if (D < 0) {
		printf("'\nx не существует");
	}
	else
	D = (b * b - 4 * a * c);
	x1 = (-b - sqrt(D) )/ a2;
	x2 = (-b + sqrt(D) )/ a2;
	printf("\nx1=%.2lf \nx2=%.2lf\n", x1, x2);

	return main();
}

