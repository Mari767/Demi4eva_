#pragma once
#ifndef MASTER_H
#define MASTER_H

#include <iostream>
using namespace std;
#include "Dog.h"

#define Max_colvo_dogs 10

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
	void creation_dog(int number);
	void setDog_nickname(string nickname);
	void setDog_weight(int weight);
	void setDog_age(int age);

	// int getCount();
	string getName();
	int getID();
	int getColvo_dogs();
	DOG getDog_of_master(int number);
	string getDog_nickname();
	int getDog_weight();
	int getDog_age();

	void Print();
};
#endif // !MASTER_H
