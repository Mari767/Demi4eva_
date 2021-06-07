#pragma once
#ifndef TRAIN_H
#define TRAIN_H

#include <string.h>
#include <iomanip>
using namespace std;

class Train {
private:
	string  destination;
	int trainNumber;
	int  departureTimeHours;
	int  departureTimeMinutes;
public:
	Train();
	Train(Train* object);
	Train(string destination, int trainNumber, int  departureTimeHours, int  departureTimeMinutes);
	~Train(){}
	string getDestination();
	int getTrainNumber();
	int getDepartureTimeHours();
	int getDepartureTimeMinutes();
	
	//����������� �������� �� ������� �������
	void orderTrainsByNumber(Train* masTrain, int size);

	//����� ���������� � ������, ����� �������� ������ �������������
    void displayInformationAboutTrainBySpecifiedNumber(Train* masTrain, int size, int number);

	//���������� ������� �� ������ ����������, ������ ������ � ����������� �������� ���������� ����������� �� ������� �����������
	void sortArrayByDestination(Train* masTrain, int size, string destination); 
};

void printArrayTrain(Train* masTrain, int size);

#endif