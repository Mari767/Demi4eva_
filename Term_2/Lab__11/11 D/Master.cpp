#include "Master.h"

int MASTER::m_count = 0;

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
void MASTER::creation_dog(int number) {
	number--;
	DOG temp_dog;
	m_dog_of_master[number] = temp_dog;
}

void MASTER::setDog_nickname(string nickname) {
	m_dog_of_master->setNickname(nickname);
}
void MASTER::setDog_weight(int weight) {
	m_dog_of_master->setWeight(weight);
}
void MASTER::setDog_age(int age) {
	m_dog_of_master->setAge(age);
}

string MASTER::getName() { return m_name; }
int MASTER::getID() { return m_ID; }
int MASTER::getColvo_dogs() { return m_colvo_dogs; }
//static int MASTER::getCount() { 
//	//int count = m_count;
//	return m_count; }
DOG MASTER::getDog_of_master(int number) { return m_dog_of_master[number]; }
string MASTER::getDog_nickname() { return m_dog_of_master->getNickname(); }
int MASTER::getDog_weight() { return m_dog_of_master->getWeight(); }
int MASTER::getDog_age() { return m_dog_of_master->getAge(); }

void MASTER::Print() {
	cout << "№" << m_count << "   ФИО: " << m_name << "\t  ID клуба " << m_ID << "\t" << m_colvo_dogs << " собак\n";
	for (int i = 0; i < m_colvo_dogs; i++) {
		m_dog_of_master[i].Print();
	}cout << endl;
}