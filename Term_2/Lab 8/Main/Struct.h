#pragma once
#ifndef STRUCT_H_
#define STRUCT_H_
#define M 20
#include <iostream>

using namespace std;
struct information {
	char name[M] = "";     //�����������
	char typ;        //���
	float nom;       //�������
	int colvo;       //����������
	short sort;      //������ ������(��� ����������)
};

struct List {
	information Data;
	struct List* next;
};

#endif