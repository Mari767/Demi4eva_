#include <iostream>
#include <math.h>
#include <stdio.h>
int main() {
	setlocale(LC_ALL, "Russian");

	int n, i, h, k;
	k = 0;
	i = 1;//-1
	h = 1;//2
	double t, st;
	double con = 0.000001;
	long double sum = 0;
	

	for (n = 0; ; n++, h *= 2, i *= -1) {
		//printf("n=%d", n);
		st = pow(n, k=n+1);
		t = i * (h / (st + 1));
		
		 if(n == 9) {
			printf("sum(10)=%.7lf\n\n",sum);
		}
		
		else if (fabs(t) >= con) {
			sum += t;
		}
		else {
			 printf("Сумма членов ряда  sum=%.7lf",sum);
			 break;
	    }
	}
	return 0;

}



















/*int st, n;
double term;
double sum = 0;
double a;

a = 0.000001;
int i = 1;//(-1)^n     *-1;
int h = 1;//2^n
n = 0;
for (; ; ) {

	i = i * 2;
	h = -1 * h;
	n = n + 1;

	st = pow(n, ++n);
	term = i *( h / (st + 1));

	printf("n=%lf   h=%d      i=%d     term=%lf  \n", n, h, i, term);

	if (fabs(term) >= a) {
		sum += term;
		break;
	}

	if (n == 9) {
			printf("Сумма 10 членов ряда = %10.7lf\n", sum);
		}

}*/
