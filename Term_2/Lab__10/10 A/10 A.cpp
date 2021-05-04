// Программа расчета площади прямоугольника и площади квадрата.
// Написать одну функцию расчета площади с использованием аргументов по умолчанию(для прямоугольника вводить 2 аргумента, для квадрата - 1 аргумент).

#include <iostream>

class Figure {

private:

	int figure_square;

public:

	void Square(int valueX, int valueY = 0);
};

void Figure::Square(int valueX, int valueY) {

	if (valueY == 0)
	{
		valueY = valueX;
	}

	figure_square = valueX * valueY;
	printf("Square = %d\n", figure_square);
}



int main() {

	Figure rectangle;
	rectangle.Square(5, 8);

	Figure kvadr;
	kvadr.Square(10);

	return 0;
}