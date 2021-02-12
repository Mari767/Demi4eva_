#pragma once

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#define B 10

using namespace std;

struct information {
	string name;     //Обозначение
	char typ;        //Тип
	float nom;       //Номинал
	int colvo;       //Количество
	short sort;      //Длинна строки(для сортировки)
}vedom[B];

int Screen();
void Rand(int N);
void Print(int N);
void Sort(int N);