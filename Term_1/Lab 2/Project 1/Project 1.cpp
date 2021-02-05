#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 1251");
    system("cls");

    const int SIZE = 15;
    /*char name1[SIZE], name2[SIZE], name3[SIZE];
    char typ1, typ2, typ3;
    int  nom1, nom2;
    float nom3;
    int qua1, qua2, qua3;*/
    printf(" Лабораторноя работа №2    Вариант 7\n");

    char name1[SIZE] = "TR-11-24 ", name2[SIZE] = "TR-11-24", name3[SIZE] = "CGU-11K";
    char typ1 = 'R', typ2 = 'R', typ3 = 'C';
    int nom1 = 100000, nom2 = 50000;
    float nom3 = 17.5;
    int qua1 = 12, qua2 = 10, qua3 = 3;
    //Введение фактических данных


       /* printf("\n1. Введите обозначение, тип, номинал, количество >");
    scanf("%s %c %d %d", name1, &typ1, &nom1, &qua1);
    system("cls");

    printf("2. Введите обозначение, тип, номинал, количество >");
    scanf("%s %c %d %d", name2, &typ2, &nom2, &qua2);
    system("cls");

    printf("3. Введите обозначение, тип, номинал, количество >");
    scanf("%s %c %f %d", name3, &typ3, &nom3, &qua3);
    system("cls");*/

    //Вывод таблицы 
    // вывод заголовков
    printf("______________________________________________\n");
    printf("|Ведомость комплектующих                     |\n");
    printf("|____________________________________________|\n");
    printf("| Обозначение | Тип |  Номинал  | Количество |\n");
    printf("|_____________|_____|___________|____________|\n");

    // вывод строк фактических данных 
    printf("| %-11s | %-3c | %-9d | %-10d |\n", name1, typ1, nom1, qua1);
    printf("| %-11s | %-3c | %-9d | %-10d |\n", name2, typ2, nom2, qua2);
    printf("| %-11s | %-3c | %-9.1f | %-10d |\n", name3, typ3, nom3, qua3);

    //вывод примечаний
    printf("|____________________________________________|\n");
    printf("|Примечание: R - резистор; C - конденсатор   |\n");
    printf("|____________________________________________|\n");
    return 0;
}