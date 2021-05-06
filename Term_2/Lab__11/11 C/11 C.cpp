//ЛАБОРАТОРНАЯ РАБОТА №11В
//Создать класс Complex, представляющий комплексное число(вещественная(r) и мнимая(m) часть r + mі = 5 + 4і).Реализовать функции класса :
//– инициализации r и m;
//– добавления к r и m целых чисел;
//– сложить два комплексных числа(второе комплексное число передать как аргумент функции);
//– вывод комплексного числа.

#include <iostream>
using namespace std;

class Complex {
	float m_r;  // вещественная(r)
	float m_m;  // мнимая(m)
public:
	Complex() :m_r(0), m_m(0) {}
	~Complex() {}
	Complex(float r, float m) :m_r(r), m_m(m) {}
	Complex(Complex& other) { this->m_r = other.m_r;  this->m_m = other.m_m; }
	void setR(float r) { m_r = r; }
	void setM(float m) { m_m = m; }
	void addR(float r) { m_r += r; }
	void addM(float m) { m_m += m; }
	void sum(float r, float m) { m_r += r; m_m += m; }
	void print() {
		if (m_m >= 0)
			cout << "Kомплексное число: " << m_r << " + " << m_m << "i\n\n";
		else
			cout << "Kомплексное число: " << m_r << " " << m_m << "i\n\n";
	}

};

int main() {
	setlocale(LC_ALL, "ru");
	Complex A;

	A.setR(5);
	A.setM(-4);
	A.print();

	A.addR(-2);
	A.addM(10);
	A.print();

	A.sum(10, -4);
	A.print();

	return 0;
}