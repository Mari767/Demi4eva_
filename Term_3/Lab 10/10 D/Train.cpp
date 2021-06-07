#include <iostream>
#include "Train.h"

Train::Train() {
	this->destination = " ";
	this->trainNumber = NULL;
	this->departureTimeHours = NULL;
	this->departureTimeMinutes = NULL;
}

Train::Train(string destination, int trainNumber, int  departureTimeHours, int  departureTimeMinutes) {
	this->destination = destination;
	this->trainNumber = trainNumber;
	this->departureTimeHours = departureTimeHours;
	this->departureTimeMinutes = departureTimeMinutes;
}
Train::Train(Train* object) {
	this->destination = object->destination;
	this->trainNumber = object->trainNumber;
	this->departureTimeHours = object->departureTimeHours;
	this->departureTimeMinutes = object->departureTimeMinutes;
}
string Train::getDestination() {
	return this->destination;
}
int Train::getTrainNumber() {
	return this->trainNumber;
}
int Train::getDepartureTimeHours() {
	return this->departureTimeHours;
}
int Train::getDepartureTimeMinutes() {
	return this->departureTimeMinutes;
}

void Train::orderTrainsByNumber(Train* masTrain, int size) {

	Train temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if ((masTrain + i)->trainNumber < (masTrain + j)->trainNumber) {
				temp = *(masTrain + i);
				*(masTrain + i) = *(masTrain + j);
				*(masTrain + j) = temp;
			}
		}
	}
}

void Train::displayInformationAboutTrainBySpecifiedNumber(Train* masTrain, int size, int number) {
	for (int i = 0; i < size; i++) {
		if ((masTrain + i)->getTrainNumber() == number) {
			cout << "Train number " << (masTrain + i)->getTrainNumber() << " arrives in " << (masTrain + i)->getDestination() << " at " << (masTrain + i)->getDepartureTimeHours() << ":" << (masTrain + i)->getDepartureTimeMinutes() << endl;
			return;
		}
	}
	cout << "No train with this number was found" << endl;
}

void Train::sortArrayByDestination(Train* masTrain, int size, string destination) {
	Train temp;
	// Сортировка по алфавиту
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if ((masTrain + i)->destination < (masTrain + j)->destination) {
				temp = *(masTrain + i);
				*(masTrain + i) = *(masTrain + j);
				*(masTrain + j) = temp;
			}
		}
	}
	// Сортировка по часам (одинаковый пункт назначения)
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if ((masTrain + i)->destination == (masTrain + j)->destination) {
				if ((masTrain + i)->departureTimeHours < (masTrain + j)->departureTimeHours) {
					temp = *(masTrain + i);
					*(masTrain + i) = *(masTrain + j);
					*(masTrain + j) = temp;
				}
			}
		}
	}
	// Сортировка по минутам (одинаковый пункт назначения и часы прибытия)
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if ((masTrain + i)->destination == (masTrain + j)->destination) {
				if ((masTrain + i)->departureTimeHours == (masTrain + j)->departureTimeHours) {
					if ((masTrain + i)->departureTimeMinutes < (masTrain + j)->departureTimeMinutes) {
						temp = *(masTrain + i);
						*(masTrain + i) = *(masTrain + j);
						*(masTrain + j) = temp;
					}
				}
			}
		}
	}
}

void printArrayTrain(Train* masTrain, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Train number " << (masTrain + i)->getTrainNumber() << " arrives in " << (masTrain + i)->getDestination() <<" at " << (masTrain + i)->getDepartureTimeHours() << ":" << (masTrain + i)->getDepartureTimeMinutes() << endl;
	}cout << endl << endl;
}