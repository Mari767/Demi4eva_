//Компьютер загадывает число. отгадать его (больше-меньше) и посчитать количество попыток.
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));


	int a, n, b;// a=human's number
	b=rand() % 100;//computer's number

	printf("Привет. Давай сыграем с тобой в игру.  Я загадал число от 0 до 100. Попробуй отгадать.\n");
	
	for (n = 1; ; n++) {
		printf("\nВведи своё число ");
		scanf_s("%d", &a);

		if (a > b) {
			printf("Твое число больше \n");
		}
		else if (a < b) {
			printf("Твое число меньше\n");
		}
		else {
			printf("Ты отгадал)\n");
			printf("\nИспользовано %d попыток.\n\n", n);
			break;
		}


	}
	return 0;
}