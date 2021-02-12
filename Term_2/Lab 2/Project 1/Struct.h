#ifndef STRUCT_H_
#define STRUCT_H_

#include <string>
using namespace std;

struct information {
	string name;     //Обозначение
	char typ;        //Тип
	float nom;       //Номинал
	int colvo;       //Количество
	short sort;      //Длинна строки(для сортировки)
}vedom[10];
#endif 