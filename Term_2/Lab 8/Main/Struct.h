#pragma once
#ifndef STRUCT_H_
#define STRUCT_H_
#define M 20
#include <iostream>

using namespace std;
struct information {
	char name[M] = "";     //Обозначение
	char typ;        //Тип
	float nom;       //Номинал
	int colvo;       //Количество
	short sort;      //Длинна строки(для сортировки)
};

struct List {
	information Data;
	struct List* next;
};

#endif