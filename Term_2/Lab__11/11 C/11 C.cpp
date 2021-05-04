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
	void setR(int r) { m_r = r; }
	void setM(int m) { m_m = m; }
	void addR(int r) { m_r += r; }
	void addM(int m) { m_m += m; }
	void sum(int r, int m) { m_r += r; m_m += m; }
	void print() { cout <<"Kомплексное число: "<< m_r << " + " << m_m <<"i\n\n"; }

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