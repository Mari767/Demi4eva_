//ЛАБОРАТОРНАЯ РАБОТА №11Г
//Разработать классы DOG и MASTER
//1. DOG(Кличка, вес, возраст).MASTER(ФИО; ID клуба – константа; Собаки – возможно несколько!; count – статический счетчик создаваемых членов клуба).
//Также реализовать следующие пункты.
//2. Наличие множества конструкторов для инициализации объектов класса.
//3. Реализовать инкапсуляцию(методы set / get) для изменения сведений о собаках и их владельцах.
//
//Для тестирования программы создать двух владельцев собак.У первого – две собаки, у второго – одна.
//Для каждого вывести ФИО, ID клуба и информацию по всем собакам.А также – количество членов клуба.

#include <iostream>
#include "Dog.h"
using namespace std;

class MASTER {
	string m_name;
	int m_ID;
	int m_colvo_dogs;
	int m_count;

public:

	MASTER() : m_name(""), m_ID(0), m_colvo_dogs(0), m_count(0) {}
	MASTER(string name, int ID, int colvo_dogs, int count): m_name(name), m_ID(ID), m_colvo_dogs(colvo_dogs), m_count(count) {}
	MASTER(MASTER& other) {
		this->m_name = other.m_name;
		this->m_ID = other.m_ID;
		this->m_colvo_dogs = other.m_colvo_dogs;
	}

	void setName(string name) { m_name = name; }
	void setID(int ID) { m_ID = ID; }
	void setColvo_dogs(int colvo_dogs) { m_colvo_dogs = colvo_dogs; }
	void setCount(int count) { m_count = count; }

	void Print() {
		cout << "ФИО: " << m_name << "\t  ID клуба " << m_ID << "\t" << m_colvo_dogs << " собак\t " << m_count << "- номер в клубе. \n\n";
	}
};

int main() {
	setlocale(LC_ALL, "ru");

	//DOG first("Mike", 10, 5);
	//first.Print();
	//DOG second;
	//second.setNickname("Keri");
	//second.setWeight(3);
	//second.setAge(2);
	//second.Print();

	MASTER first("Джейс Вейланд Моргерштерн", 32, 2, 1);
	first.Print();

	MASTER second;
	second.setName("Тесса Грей Фэирчайлд ");
	second.setID(51);
	second.setColvo_dogs(1);
	second.setCount(2);
	second.Print();


	return 0;
}