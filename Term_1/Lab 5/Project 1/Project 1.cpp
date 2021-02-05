#include <iostream>
#include <stdio.h>
int main()
{//  Попадание точки в область    Вариант 7
	setlocale(LC_ALL, "Russian");
	
	double x, y;
	printf("\nВведите координаты точки   \nx=");
	scanf_s("%lf", &x);
	printf("y=");
	scanf_s("%lf", &y);

	//Проверка 
	if ((x * x + y * y <= 1) || ((x <= 0 && x >= -1) && (y <= 0 && y >= -1)))
	{
		printf("Точка попадает в область\n");
	}
	else {
		printf("Точка не попадает в область\n");
	}

	return main();
}

