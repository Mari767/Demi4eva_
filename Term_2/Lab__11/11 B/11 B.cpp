//ЛАБОРАТОРНАЯ РАБОТА №11Б
//Создать класс Figure для вычисления площади фигур(круга и треугольника).В конструкторе использовать аргумент по умолчанию.
#define _USE_MATH_DEFINES 
#include <cmath>
#include <iostream>
using namespace std;

class Figure {
	float m_square;
public:
	Figure() :m_square(0) {}
	void Square(int a = 1, int b = 1, int c = 1);
	void Print() { cout << "Square = " << m_square << endl; }
};

void Figure::Square(int a, int b, int c)
{
	if (b != 1 && c != 1) { // triangle
		int P = (a + b + c) / 2;
		m_square = sqrt(P * (P - a) * (P - b) * (P - c));
	}
	else
		m_square = M_PI * a * a;
}


int main()
{
	Figure triangle, circle;

	circle.Square(5);
	circle.Print();

	triangle.Square(9, 8, 7);
	triangle.Print();


	return 0;
}

