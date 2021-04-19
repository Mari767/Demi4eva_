#pragma once
#ifndef STRUCT_H_
#define STRUCT_H_

struct information {
	char name[20] = "";     //Обозначение
	char typ;              //Тип
	int nom;             //Номинал
	int colvo;             //Количество
	short sort;            //Длинна строки(для сортировки)
};
#endif