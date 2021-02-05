#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    double a, b, c, p, S;
    printf("Введите стороны a, b,c.\n а=");
    scanf_s("%lf", &a);
    printf(" b=");
    scanf_s("%lf", &b);
    printf(" c=");
    scanf_s("%lf", &c);

    p = (a + b + c) / 2;
    printf("p=%lf \n", p);

    S = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("S=%lf", S);
}