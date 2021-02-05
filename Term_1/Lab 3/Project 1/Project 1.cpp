#include <math.h>
#include <stdio.h>
#include <iostream>
int main(void) {
    setlocale(LC_ALL, "Russian");

    double a, b, x, t1, t2;
    double ax, a2, a3;

    printf("Ведите x=");
    scanf_s("%lf", &x);

    a = 2.2, b = -6.7;
    a2 = 2 * a;
    a3 = a * a * a;
    ax = x * a * 3.14 / 180;

    if (x == 0)
    {
        printf("t1 t2 не существует");
    }
    else {

        t1 = 1 / a3 * (log(x) + 2 * b / x - b * b / (2 * x * x));

        t2 = cos(ax) / (a2 * sin(ax) * sin(ax)) + 1 / a2 * log(tan(ax / 2));

        printf("\nt1=%lg, \nt2=%lg\n", t1, t2);
    }

    /* Ограничения
    * x>0    (ОДЗ логарифма);
    * x!=0   (на ноль делить нельзя);
    * sin(ax)!=0   ax!=πn, nєZ    (на ноль делить нельзя);
    * tg(ax/2)>0  (ОДЗ логарифма);
    */
}