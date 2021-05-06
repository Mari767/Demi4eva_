#include "class_Information.h"

Information::Information() :m_name(""), m_typ(0), m_nom(0), m_colvo(0) {}

Information::Information(string name, char typ, float nom, int colvo)
{
	m_name = name;
	m_typ = typ;
	m_nom = nom;
	m_colvo = colvo;
}
Information::Information(Information& other)
{
	this->m_name = other.m_name;
	this->m_typ = other.m_typ;
	this->m_nom = other.m_nom;
	this->m_colvo = other.m_colvo;
}

void  Information::set_inform(string name, char typ, float nom, int colvo)
{
	m_name = name;
	m_typ = typ;
	m_nom = nom;
	m_colvo = colvo;
}

void Information::get_inform(string& name, char& typ, float& nom, int& colvo)
{
	name = m_name;
	typ = m_typ;
	nom = m_nom;
	colvo = m_colvo;
}

void Information::show_inform()
{
	cout << "Обозначение \t" << m_name << endl;
	cout << "Тип \t\t" << m_typ << endl;
	cout << "Номинал \t" << m_nom << endl;
	cout << "Количество \t" << m_colvo << endl;
}
