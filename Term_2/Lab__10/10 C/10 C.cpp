//ЛАБОРАТОРНАЯ РАБОТА № 10В
//Создать класс SUM, в котором описаны 2 целые переменные(x, y) и их сумма(s).
//Написать методы класса :
//– конструкторы с параметром и по умолчанию;
//– функция инициализации x, y;
//– функция вывода всех переменных класса;
//– ф.подсчета суммы s и вывода результата на экран.
//Осуществить обращения к элементам класса через объекты и через указатели.

#include <iostream>
using namespace std;

class SUM {
	int x, y;
	int s;
public:

	SUM() : x(0), y(0), s(0) {}                       // конструктор по умолчанию
	SUM(int x_, int y_) :x(x_), y(y_), s(x_+y_) {}    // конструктор  с параметрами
	void set_x_y(int x_, int y_) {
		x = x_;
		y = y_;
	}
	void show() {
		cout <<"x = "<< x <<"\ty = "<< y <<"\tsum = "<< s << endl;
	}
	void sum() {
		s = x + y;
		cout << "sum = " << s << endl;
	}
};

int main()
{
	// конструктор  с параметрами
	SUM first(10, -8);
	first.show();
	first.set_x_y(5, 20);
	first.show();
	first.sum();
	first.show();

	cout << "\n-----------------------------\n";
	// конструктор по умолчанию
	SUM second;
	SUM* ptr_second = &second;
	ptr_second->show();
	ptr_second->set_x_y(-2, 15);
	ptr_second->show();
	ptr_second->sum();
	ptr_second->show();

	return 0;
}

