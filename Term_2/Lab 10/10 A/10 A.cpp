// Программа расчета площади прямоугольника и площади квадрата.
// Написать одну функцию расчета площади с использованием аргументов по умолчанию(для прямоугольника вводить 2 аргумента, для квадрата - 1 аргумент).

#include <iostream>

class Square {

private:
	int Square_figure;

public:

	void Calculate(int valueX, int valueY = 1) {

		if (valueY == 1) {
			valueY = valueX;
		}
		Square_figure = valueX * valueY;
		printf("Square = %d\n", Square_figure);
	}
};

int main() {

	Square kvadr;
	kvadr.Calculate(10);

	Square rectangle;
	rectangle.Calculate(5, 8);

	return 0;
}