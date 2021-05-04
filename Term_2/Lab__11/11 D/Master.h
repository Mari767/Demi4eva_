#pragma once
#ifndef MASTER_H
#define MASTER_H

#include <iostream>
using namespace std;

class MASTER {
	string m_name;
	int m_ID;
	int m_colvo_dogs;
	int m_count;

public:

	MASTER();
	MASTER(string name, int ID, int colvo_dogs, int count);
	MASTER(MASTER& other);

	void setName(string name);
	void setID(int ID);
	void setColvo_dogs(int colvo_dogs);
	void setCount(int count);

 //   MASTER getName();
	//void getID();
	//void getColvo_dogs();
	//void getCount();

	void Print();
};

#endif // !MASTER_H
