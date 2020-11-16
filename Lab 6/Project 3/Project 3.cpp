//Проверка знаний таблицы умножения(10 примеров, случайным образом; выставляется оценка).
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "Russian");
	int n, a, b, c, k;
	int sum=0, g=10;
	srand(time(NULL));
	printf("Проверь себя\n");

	for (n = 1; ; n++) {
		a = rand() % 10+2;
		b = rand() % 10+3;
		k = a * b;
		printf("\n%d) %d*%d=", n, a, b);
		scanf_s("%d", &c);
		if (c == k) {
			++sum;
		}
		if (n == g) {
			printf("\nПравильных ответов %d из %d. Ваша оценка %d\n\n", sum, g, sum);
			break;
		}
	}
	return 0;
}
