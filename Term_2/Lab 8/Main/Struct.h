#pragma once
#ifndef STRUCT_H_
#define STRUCT_H_
#define _CRT_SECURE_NO_WARNINGS
#define M 20

struct information {
	char name[M] = "";     //�����������
	char typ;        //���
	int nom;       //�������
	int colvo;       //����������
	short sort;      //������ ������(��� ����������)
};

struct List {
	information Data;
	struct List* next;
};

#endif