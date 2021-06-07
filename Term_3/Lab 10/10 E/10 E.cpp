//ЗАДАНИЕ 10 Е.
//Создать класс, описывающий двумерную матрицу.Реализовать функции :
//– генерация массива(заполнение случайными числами);
//– вывод массива на экран;
//– поиск координат элемента с минимальными значениями;
//– получение элемента по позиции и запись по заданным координатам;
//– получение подматрицы по начальным позициям заданного размера.

#include <time.h>
#include "Matrix.h"
using namespace std;

int main() {

	setlocale(LC_ALL, "Ru");
	srand(time(NULL));

	int rows, columns;
	int i, j, number;

	cout << "Enter the dimension of the matrix" << endl;
	cin >> rows >> columns;

	Matrix matrix_1(rows, columns);
	matrix_1.printMatrix();

	cout << "\nFinding element coordinates with minimum values" << endl;
	matrix_1.searchElementCoordinatesWithMinimumValues();

	cout << "\nEnter the coordinates of the desired element" << endl;
	cin >> i >> j;
	
	cout << matrix_1.getElementByPosition(i, j) ;
	cout << "Enter the coordinates of the desired element and its value" << endl;
	cin >> i >> j >> number;
	matrix_1.setElementByPosition(i, j, number);
	matrix_1.printMatrix();

	cout << "\nTo get a submatrix, enter its number of rows, columns and coordinates" << endl;
	cin >> rows >> columns >> i >> j;
	Matrix submatrixM1(rows, columns);
	matrix_1.getSubmatrix(submatrixM1, i, j);
	submatrixM1.printMatrix();

	return 0;
}