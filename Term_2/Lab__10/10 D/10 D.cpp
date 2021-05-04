//ЛАБОРАТОРНАЯ РАБОТА № 10Г
//Создать класс TIMER(переменная, хранящая количество секунд), с тремя перегруженными конструкторами :
//– К1 – инициализация переменной с помощью целого числа(количества секунд);
//– К2 – с помощью двух целых переменных(количество минут и секунд);
//– К3 – конструктор копирования.
//В классе должна быть функция вывода количества секунд.

#include <iostream>
using namespace std;

class TIMER {
private:

	int m_colvo_seconds;

public:

	TIMER() :m_colvo_seconds(0) {}
	TIMER(int colvo_seconds) : m_colvo_seconds(colvo_seconds) {} // К1 – инициализация переменной с помощью целого числа(количества секунд);
	TIMER(int colvo_minutes, int colvo_seconds);                 //– К2 – с помощью двух целых переменных(количество минут и секунд);
	TIMER(const TIMER& object);                                  //– К3 – конструктор копирования.
	void Show() { cout << "Time: " << m_colvo_seconds << " seconds.\n\n"; }
};

TIMER::TIMER(int colvo_minutes, int colvo_seconds) {               
	m_colvo_seconds = colvo_minutes * 60 + colvo_seconds;
}

TIMER::TIMER(const TIMER& object) {
	this->m_colvo_seconds = object.m_colvo_seconds;
}


int main()
{
	TIMER first(123);
	first.Show();

	TIMER second(10, 35);
	second.Show();

	TIMER third(first);
	third.Show();

	return 0;
}

