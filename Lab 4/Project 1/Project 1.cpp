﻿//    Упаковка кода

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
    //Ввод данных
    cout << "Введите код системной области (0-7) ->";
    cin >> s;
    cout << "\nВведите признак грязного буфера (0 / 1) ->";
    cin >> d;
    cout << "\nВведите признак свободного буфера (0 / 1) ->";
    cin >> f;
    cout << "\nВведите номер блока, который отображен в буфере (0 - 255) ->";
    cin >> b;
    //формирование упакованного кода
    Word = (s & 0x7) << 13;
    Word |= (d & 1) << 11;
    Word |= (f & 1) << 9;
    Word |= b & 0xFF;
    // Вывод результата
    printf("Слово состояния устройства = %04x \n", Word);
 
    return 0;
}