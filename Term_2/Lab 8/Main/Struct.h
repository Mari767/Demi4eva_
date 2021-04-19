#pragma once
#ifndef STRUCT_H_
#define STRUCT_H_
#define _CRT_SECURE_NO_WARNINGS
#define M 20

struct information {
	char name[M] = "";     //Обозначение
	char typ;        //Тип
	int nom;       //Номинал
	int colvo;       //Количество
	short sort;      //Длинна строки(для сортировки)
};

struct List {
	information Data;
	struct List* next;
};

#endif