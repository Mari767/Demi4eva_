#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Тип данных int занимает %d байта. \n", sizeof(int));
    printf("Тип данных short занимает %d байта. \n", sizeof(short));
    printf("Тип данных long занимает %d байта. \n", sizeof(long));
    printf("Тип данных char занимает %d байт. \n", sizeof(char));
    printf("Тип данных float занимает %d байта. \n", sizeof(float));
    printf("Тип данных double занимает %d байтов. \n", sizeof(double));

    return 0;
}