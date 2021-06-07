#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
private:
	int colvoRows;
	int colvoColumns;
	int** matrix;
	int elementX;
	int elementY;
public:
	Matrix();
	Matrix(int colvoRows, int colvoColumns);
	Matrix(Matrix* object);
	~Matrix();
	void inputMatrix();
	void printMatrix();
	void createMatrix();
	void deleteMatrix();
	void setColvoRows(int colvoRows);
	void setColvoColums(int colvoColumns);
	void searchElementCoordinatesWithMinimumValues();
	int getElementByPosition(int i, int j);
	void setElementByPosition(int i, int j, int elementValue);
	void getSubmatrix(Matrix& submatrix, int firstRow, int firstColumn);
};
#endif
