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
//#include "Dog.h"
#include "Master.h"
#define Max_colvo_dogs 5


class DOG {
	string m_nickname = "";
	int m_weight;
	int m_age;
public:
	DOG();
	DOG(string nickname, int weight, int age);
	DOG(DOG& other);

	void setNickname(string nickname);
	void setWeight(int weight);
	void setAge(int age);

	string getNickname();
	int getWeight();
	int getAge();

	void Print();
};

class MASTER {
private:

	static int m_count;
	string m_name;
	int m_ID;
	int m_colvo_dogs;
	DOG m_dog_of_master[Max_colvo_dogs];

public:

	MASTER();
	MASTER(string name, int ID, int colvo_dogs);
	MASTER(MASTER& other);

	void setName(string name);
	void setID(int ID);
	void setColvo_dogs(int colvo_dogs);
	void setDog_of_master_with_creation(string nickname, int weight, int age, int number);
	void creation_dog();
	void setDog_nickname(string nickname);
	void setDog_weight(int weight);
	void setDog_age(int age);
	void setDog_number(int number);


	string getName();
	int getID();
	int getColvo_dogs();
	//static int getCount() {	return m_count;	}

	void Print();
};
int MASTER::m_count = 0;




int main() {
	setlocale(LC_ALL, "ru");

	//DOG first("Mike", 10, 5);
	//first.Print();
	//DOG second;
	//second.setNickname("Keri");
	//second.setWeight(3);
	//second.setAge(2);
	//second.Print();

	MASTER first("Джейс Вейланд Моргерштерн", 32, 2);
	first.setDog_of_master_with_creation("Chery", 10, 9, 1);
	first.setDog_of_master_with_creation("Kira", 5, 2, 2);
	first.Print();

	MASTER second;
	second.setName("Тесса Грей Фэирчайлд ");
	second.setID(51);
	second.setColvo_dogs(1);
	second.Print();


	MASTER d;

	d.Print();


	return 0;
}


DOG::DOG() : m_nickname(""), m_weight(0), m_age(0) {}

DOG::DOG(string nickname, int weight, int age) : m_nickname(nickname), m_weight(weight), m_age(age) {}

DOG::DOG(DOG& other) {
	this->m_nickname = other.m_nickname;
	this->m_weight = other.m_weight;
	this->m_age = other.m_age;
}


void DOG::setNickname(string nickname) {
	m_nickname = nickname;
}

void DOG::setWeight(int weight) {
	m_weight = weight;
}

void DOG::setAge(int age) {
	m_age = age;
}


string DOG::getNickname() {
	return m_nickname;
}

int DOG::getWeight() {
	return m_weight;
}

int DOG::getAge() {
	return m_age;
}

void DOG::Print() {
	cout << "Dog: " << m_nickname << "   " << m_age << " years   " << m_weight << " kg\n";
}



















MASTER::MASTER()
{
	m_name = "";
	m_ID = 0;
	m_colvo_dogs = 0;
	m_count++;
}
MASTER::MASTER(string name, int ID, int colvo_dogs)
{
	m_name = name;
	m_ID = ID;
	m_colvo_dogs = colvo_dogs;
	m_count++;
}
MASTER::MASTER(MASTER& other) {
	this->m_name = other.m_name;
	this->m_ID = other.m_ID;
	this->m_colvo_dogs++;
	this->m_count++;
}

void MASTER::setName(string name) { m_name = name; }
void MASTER::setID(int ID) { m_ID = ID; }
void MASTER::setColvo_dogs(int colvo_dogs) { m_colvo_dogs = colvo_dogs; }

void MASTER::setDog_of_master_with_creation(string nickname, int weight, int age, int number) {
	number--;
	DOG temp_dog(nickname, weight, age);
	m_dog_of_master[number] = temp_dog;
}
void MASTER::creation_dog(){
	DOG temp_dog;
	int number = 0;
	m_dog_of_master[0] = temp_dog;
}

void MASTER::setDog_nickname(string nickname){}
void MASTER::setDog_weight(int weight){}
void MASTER::setDog_age(int age){}
void MASTER::setDog_number(int number){}


string MASTER::getName() { return m_name; }
int MASTER::getID() { return m_ID; }
int MASTER::getColvo_dogs() { return m_colvo_dogs; }
//static int MASTER::getCount() { 
//	//int count = m_count;
//	return m_count; }

void MASTER::Print() {
	cout << "№" << m_count << /*" номер в клубе  " <<*/ "   ФИО: " << m_name << "\t  ID клуба " << m_ID << "\t" << m_colvo_dogs << " собак\n";
	for (int i = 0; i < m_colvo_dogs; i++) {
		m_dog_of_master[i].Print();
	}cout << endl;
}