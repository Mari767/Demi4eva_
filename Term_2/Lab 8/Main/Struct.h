#pragma once
#ifndef STRUCT_H_
#define STRUCT_H_
#define _CRT_SECURE_NO_WARNINGS

struct information {
	char name[20] = "";     //�����������
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