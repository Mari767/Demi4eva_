//   Распаковка кода

#include <stdio.h>
#include <iostream>
using namespace std;
int main(void) {
    setlocale(LC_ALL, "ru");

    short s; //код системной области
    short d; //признак "грязного" буфера
    short f;// признак свободного буфера
    unsigned short b;// номер блока, который отображен в буфере
    unsigned int Word;
    //Ввод слова состояния устройства
    cout << "Введите cлово состояния устройства" << endl;
    cout << "16-ричное число от 0 до 0xFFFF -> ";
    scanf_s("%x", &Word);
    //   Выделение составных частей
    s = (Word >> 13) & 0x7;
    d = (Word >> 11) & 1;
    f = (Word >> 9) & 1;
    b = Word & 0xFF;
    //  Вывод результатов
    cout << "Код системной области " << s << endl;
    cout << "Признак грязного буфера " << d << endl;
    cout << "Признак свободного буфера " << f << endl;
    cout << "Номер блока, который отображен в буфере " << b << endl;
    return 0;
}
    