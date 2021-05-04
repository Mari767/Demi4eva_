//ЋјЅќ–ј“ќ–Ќјя –јЅќ“ј є11ј
//—оздать класс Point(2 переменные х и у).–еализовать функции класса :
//Ц  онструктор по умолчанию;
//Ц  онструктор с параметром;
//Ц  онструктор копировани€;
//Ц функци€ инициализации переменных х и у(set());
//Ц функци€, котора€ возвращает сумму и произведение переменных(передача параметров через ссылки);
//Ц вывод результатов.

#include <iostream>
using namespace std;

class Point {
private:
	int m_x, m_y;

public:
	Point() : m_x(0), m_y(0) {}
	Point(int x, int y) : m_x(x), m_y(y) {}
	Point(Point& other);
	void set_x_y(int x, int y) { m_x = x; m_y = y; }
	void Sum_and_Multiplication(int& x, int& y);
	void Print_result(int sum, int multiplication);
};

Point::Point(Point& other)
{
	this->m_x = other.m_x;
	this->m_y = other.m_y;
}

void Point::Sum_and_Multiplication(int& sum, int& multiplication) {
	sum = m_x + m_y;
	multiplication = m_x * m_y;
}

void Point::Print_result(int sum, int multiplication) {
	cout << "x(" << m_x << ") + y(" << m_y << ") = " << sum << endl;
	cout << "x(" << m_x << ") * y(" << m_y << ") = " << multiplication << endl << endl;
}

int main() {

	Point A, B(3, 6), C(B);

	int sum = 0, multiplication = 0;

	A.Sum_and_Multiplication(sum, multiplication);
	A.Print_result(sum, multiplication);

	B.Sum_and_Multiplication(sum, multiplication);
	B.Print_result(sum, multiplication);

	C.Sum_and_Multiplication(sum, multiplication);
	C.Print_result(sum, multiplication);

	A.set_x_y(10, -5);
	A.Sum_and_Multiplication(sum, multiplication);
	A.Print_result(sum, multiplication);

	return 0;
}