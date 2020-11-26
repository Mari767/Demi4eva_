#include <iostream>
#include <stdio.h>
#include <math.h>
int main() {
	setlocale(LC_ALL, "Russian");
	int n, f, p;
	short h;
	double x, y, g;
	y = 0;
	n = 0;

	printf("|---------|-----------|\n");
	printf("|    X    |     Y     |\n");
	printf("|---------|-----------|\n");
	for (n = 0; n < 5; n++) {
		for (x = 0; x < 4; x += 0.25) {
	
			if (x < 2) {
				y = sqrt(4 * x - x * x);
			}
			else if (x == 2) {
				y = 0;
			}
			else {
				y = -sqrt(4 * x - x * x);
			}
			//вывод строки таблицы
			printf("| %-7.2lf | %-9lf |", x + (n * 4), y);

			//округление
			g = (y + 2) * 10.5;
			f = g * 10;
			if (f % 10 > 4) {
				g++;
			}
			h = g;
			// Вывод точки
			for (; h > 0; h--) {
				printf(" ");
			}
			printf("*\n");
		}
		printf("Нажмите клавишу Enter. ");
		getchar();
	}
	return 0;
}