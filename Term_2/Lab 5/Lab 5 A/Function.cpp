#include <iostream>
#include <iomanip>
#include <windows.h> //��� ���������y ** 
#include "Print_.h"

int* Function(int** DVmassiv, int* ODmas_min, int* ODmas_max, int* Psum, int* Pmultiplicat, int Size) {
	int i, j; // ������ � �������
	int b;    // ���������� ��� ���������� �������� ODmas_min  � ODmas_max
	int Size_Result = 2;
	int* Massiv_Result = (int*)malloc(Size_Result * sizeof(int));//������������ ���������� ������, � ������� ��������� ����� �� �� � ������������ �� ��, 

		//���������� ���������� �������
	Input_DVumer(Size, DVmassiv);
	//����� ���������� �������
	Print_DVumer(Size, DVmassiv);

	// ���������� ���������� ������������ ������, ���������� ����������� �������� � ������ �������;
	for (j = 0, b = 0; j < Size; j++) {
		int min = INT_MAX;
		for (i = 0; i < Size; i++) {
			if (*(*(DVmassiv + i) + j) < min) {
				min = *(*(DVmassiv + i) + j);
			}
		}
		*(ODmas_min + b++) = min;
	}
	//������ ���������� ������������ ������, ���������� ����������� �������� � ������ �������;
	printf("���������� ������������ ������, ���������� ����������� �������� � ������ �������\n");
	Print_ODnomer(Size, ODmas_min);

	// ���������� ���������� ������������ ������, ���������� ������������ �������� � ������ ������;
	for (i = 0, b = 0; i < Size; i++) {
		int max = INT_MIN;
		for (j = 0; j < Size; j++) {
			if (*(*(DVmassiv + i) + j) > max) {	//���������� ����� ��� max
				max = *(*(DVmassiv + i) + j);
			}
		}
		*(ODmas_max + b++) = max;
	}

	//������ ���������� ������������ ������, ���������� ������������ �������� � ������ ������;
	printf("���������� ������������ ������, ���������� ������������ �������� � ������ ������\n");
	Print_ODnomer(Size, ODmas_max);

	//����� �� ��   ������������ �� ��.
	int sum = 0, multiplicat = 1;
	for (i = 0; i < Size; i++) {
		for (j = 0; j < Size; j++) {
			if (i == j) {
				*Psum += *(*(DVmassiv + i) + j);
			}
			if ((i + j) == Size - 1) {
				*Pmultiplicat *= *(*(DVmassiv + i) + j);
			}
		}
	}
// ����������  ����� �� �� � ������������ �� �� � ������, ������� ������ �������
	*Massiv_Result = *Psum;
	*(Massiv_Result + 1) = *Pmultiplicat;

	return Massiv_Result;
}