#pragma once
#ifndef CLASS_INFORMATION_H
#define CLASS_INFORMATION_H

#include <iostream>
using namespace std;

class Information {
	string m_name = "";
	char m_typ;
	float m_nom;
	int m_colvo;

public:

	void set_inform(string name, char typ, float nom, int colvo);
	void get_inform(string& name, char& typ, float& nom, int& colvo);
	void show_inform();
};
#endif