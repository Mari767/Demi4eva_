#include "Matrix.h"

Matrix::Matrix() {
	this->colvoRows = NULL;
	this->colvoColumns = NULL;
}
Matrix::Matrix(int colvoRows, int colvoColumns) {
	if (colvoRows < 1 || colvoColumns < 1) {
		cout << "Incorrect data" << endl;
		return;
	}
	this->colvoRows = colvoRows;
	this->colvoColumns = colvoColumns;
	this->createMatrix();
	this->inputMatrix();
}
Matrix::Matrix(Matrix* object) {
	this->colvoRows = object->colvoRows;
	this->colvoColumns = object->colvoColumns;
	this->createMatrix();
	for (int i = 0; i < this->colvoRows; i++) {
		for (int j = 0; j < this->colvoColumns; j++) {
			this->matrix[i][j] = object->matrix[i][j];
		}
	}
}
Matrix::~Matrix() {
	this->deleteMatrix();
}
void Matrix::inputMatrix() {
	int a = 0;
	for (int i = 0; i < this->colvoRows; i++) {
		for (int j = 0; j < this->colvoColumns; j++) {
			//this->matrix[i][j] = a++;
			this->matrix[i][j] = rand() % 100 - 50;
		}
	}
}
void Matrix::printMatrix() {
	for (int i = 0; i < this->colvoRows; i++) {
		for (int j = 0; j < this->colvoColumns; j++) {
			cout << setw(4) << this->matrix[i][j];
		}cout << endl;
	}
	cout << endl << endl;
}
void Matrix::createMatrix() {
	this->matrix = new int* [this->colvoRows];
	for (int i = 0; i < this->colvoRows; i++) {
		this->matrix[i] = new int[this->colvoColumns];
	}
}
void Matrix::deleteMatrix() {
	for (int i = 0; i < this->colvoRows; i++) {
		delete[] this->matrix[i];
	}
}
void Matrix::setColvoRows(int colvoRows) {
	if (this->colvoRows) {
		this->colvoRows = colvoRows;
	}
	else {
		cout << "This property already has a value" << endl;
	}
}
void Matrix::setColvoColums(int colvoColumns) {
	if (this->colvoColumns) {
		this->colvoColumns = colvoColumns;
	}
	else {
		cout << "This property already has a value" << endl;
	}
}
void Matrix::searchElementCoordinatesWithMinimumValues() {
	int tempValue = INT_MAX;
	for (int i = 0; i < this->colvoRows; i++) {
		for (int j = 0; j < this->colvoColumns; j++) {
			if (this->matrix[i][j] < tempValue) {
				tempValue = this->matrix[i][j];
				this->elementX = i;
				this->elementY = j;
			}
		}
	}
	cout << "Min value = " << tempValue << ", where i = " << this->elementX << "  j = " << this->elementY << endl;
}
int Matrix::getElementByPosition(int i, int j) {
	if (i < 0 || j < 0 || i >= this->colvoRows || j >= this->colvoColumns) {
		cout << "Error. There is no such position" << endl;
		return NULL;
	}
	cout << this->matrix[i][j] << " - element with coordinates i = " << i << ", j = " << j << endl;

	return this->matrix[i][j];
}
void Matrix::setElementByPosition(int i, int j, int elementValue) {
	if (i < 0 || j < 0 || i >= this->colvoRows || j >= this->colvoColumns) {
		cout << "Error. There is no such position" << endl;
		return;
	}
	this->matrix[i][j] = elementValue;
}
void Matrix::getSubmatrix(Matrix& submatrix, int firstRow, int firstColumn) {
	if (firstRow < 0 || firstColumn < 0) {
		cout << "Error. Incorrect submatrix size" << endl;
		return;
	}
	if (firstRow + submatrix.colvoRows > this->colvoRows || firstColumn + submatrix.colvoColumns > this->colvoColumns) {
		cout << "Error. Incorrect submatrix size" << endl;
		return;
	}
	int endRow = submatrix.colvoRows + firstRow;
	int endColumn = submatrix.colvoColumns + firstColumn;

	for (int i = 0, matrixRow = 0; matrixRow < this->colvoRows; matrixRow++) {
		if (matrixRow >= firstRow && matrixRow < endRow) {

			for (int j = 0, matrixColumn = 0; matrixColumn < this->colvoColumns; matrixColumn++) {
				if (matrixColumn >= firstColumn && matrixColumn < endColumn) {
					submatrix.matrix[i][j] = this->matrix[matrixRow][matrixColumn];
					j++;
				}
			}
			i++;
		}
	}
}