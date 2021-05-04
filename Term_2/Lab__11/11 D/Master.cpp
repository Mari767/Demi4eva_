#include "Master.h"

MASTER::MASTER() : m_name(""), m_ID(0), m_colvo_dogs(0), m_count(0) {}

MASTER::MASTER(string name, int ID, int colvo_dogs, int count) : m_name(name), m_ID(ID), m_colvo_dogs(colvo_dogs), m_count(count) {}

MASTER::MASTER(MASTER& other) {
	this->m_name = other.m_name;
	this->m_ID = other.m_ID;
	this->m_colvo_dogs = other.m_colvo_dogs;
}


void MASTER::setName(string name) { m_name = name; }

void MASTER::setID(int ID) { m_ID = ID; }

void MASTER::setColvo_dogs(int colvo_dogs) { m_colvo_dogs = colvo_dogs; }

void MASTER::setCount(int count) { m_count = count; }

//MASTER MASTER:: getName() { return m_name; }

//void getID() { return m_ID; }
//void getColvo_dogs() { return m_colvo_dogs; }
//void getCount() { return m_count; }




void MASTER::Print() {
	cout << "ФИО: " << m_name << "\t  ID клуба " << m_ID << "\t" << m_colvo_dogs << " собак\t " << m_count << "- номер в клубе. \n";
}