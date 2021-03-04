#pragma once
#ifndef STRUCT_H_
#define STRUCT_H_
#define B 10
#define M 20

using namespace std;
struct information {
	char name[M] = "";     //Обозначение
	char typ;        //Тип
	float nom;       //Номинал
	int colvo;       //Количество
	short sort;      //Длинна строки(для сортировки)
}vedom[B];
#endif