#pragma once

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#define B 10

using namespace std;

struct information {
	string name;     //�����������
	char typ;        //���
	float nom;       //�������
	int colvo;       //����������
	short sort;      //������ ������(��� ����������)
}vedom[B];

int Screen();
void Rand(int N);
void Print(int N);
void Sort(int N);