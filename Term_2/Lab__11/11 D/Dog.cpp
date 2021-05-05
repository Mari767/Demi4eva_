#include "Dog.h"

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