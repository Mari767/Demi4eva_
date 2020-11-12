#include <iostream>
#include <stdio.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int k;
    printf("\nВведите число  \nk=");
    scanf_s("%d", &k);
    printf("У меня %d", k);

    if ((k % 100 == 11) || (k % 100 == 12) || (k % 100== 13) || (k % 100 == 14))
    {
        printf(" грибов\n");
    }
    
    else if ((k % 10 == 1) && (k != 11))
    {
        printf(" гриб\n");
    }
    else if ((k % 10 == 2) && (k != 12))
    {
        printf(" грибa\n");
    }
    else if ((k % 10 == 3) && (k != 13))
    {
        printf(" грибa\n");
    }
    else if ((k % 10 == 4) && (k != 14))
    {
        printf(" грибa\n");
    }
    else {
        printf(" грибов\n");
    }
        return main();
 }

      


    


