#include "class_Information.h"

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
	cout << "����������� \t" << m_name << endl;
	cout << "��� \t\t" << m_typ << endl;
	cout << "������� \t" << m_nom << endl;
	cout << "���������� \t" << m_colvo << endl;
}
