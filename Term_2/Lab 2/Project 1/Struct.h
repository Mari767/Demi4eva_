#ifndef STRUCT_H_
#define STRUCT_H_

#include <string>
using namespace std;
#define B 10
int N;

struct information {
	string name;     //Обозначение
	char typ;        //Тип
	float nom;       //Номинал
	int colvo;       //Количество
	short sort;      //Длинна строки(для сортировки)
}vedom[B];
#endif 