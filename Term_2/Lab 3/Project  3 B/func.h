#pragma once

#ifndef FUNC_H_
#define FUNC_H_

#include <iostream>
#include <iomanip>
#define Size_1 20
using namespace std;

void Print(int* massiv, int colvo) {
	int iter = 0;
	if (colvo == 0) {
		cout << " ���� " << endl << endl; // ���� ne ����������� ______���������!!!!!!!
		return;
	}
	cout << endl;
	for (; iter < colvo; iter++) {
		cout << setw(4) << *(massiv + iter);
	}cout << endl << endl;
}

//���������� ������� � ���������� �������� D, B, C 
int Input(int* mas1, int* mas2, int iter_mas1, int colvo_mas2) { // ������� A[],  D[]/B[]/C[],    i,   d/ d+b/ d+b+c
	int j = 0;  // �������� ������� �������
	for (; iter_mas1 < colvo_mas2; j++) { // ���������� ������� �������� � ������� D
		*(mas1 + iter_mas1) = *(mas2 + j);
		iter_mas1++;
	}
	return iter_mas1;
}
#endif