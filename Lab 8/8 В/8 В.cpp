// Найти сумму цифр в введенном с экрана числе, их количество и напечатать число наоборот.
#include <iostream>
#define N 10 
int cont[N];
int main(){
	system("chcp 1251");
	system("cls");
	int a, b, c, i, u, sum, am;
	sum = 0;
	i = 0;
	u = 0;
	printf("Введите число ");
	scanf_s("%d", &a);
	if (a < 0) {
		c = -a;
	}
	else {
		c = a;
	}
	//     SUM  and AMOUNT
	for ( i ; ; i++) {
		if (c == 0) {
			break;
		}
		b = c % 10;
		sum += b;
		cont[i] = b;
		c = c / 10;
		//printf("%4d", cont[i]);
	}
	am = i;  // amount
	printf("\nКоличество цифр %3d", am);
	printf("\nСумма цифр%3d", sum);
	//число наoборот
	c = 1;
	i = am-1;
	for (; i >=0; --i) {
		b = c * cont[i];
		u += b;
		c *= 10;
	}
	printf("\nЧисло наоборот %d\n\n\n\n", u);
}
