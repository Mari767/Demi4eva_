//Создайте класс с именем train, содержащую поля : название пункта назначения, номер поезда, время отправления.
//Ввести данные в массив из пяти элементов типа train, упорядочить элементы по номерам поездов.
//Добавить возможность вывода информации о поезде, номер которого введен пользователем.
//Добавить возможность сортировки массив по пункту назначения, причем поезда с одинаковыми пунктами назначения должны быть упорядочены по времени отправления.

#include <iostream>
#include <string.h>
#include <iomanip>
#include "Train.h"
using namespace std;

int main()
{
	int size = 5;
	int number;
	string destination= "Tokmak";
	Train* masTrain = new Train[size];

	masTrain[0] = Train("Lviv", 25, 10, 30);
	masTrain[1] = Train("Kuiv", 13, 10, 15);
	masTrain[2] = Train("Tokmak", 105, 23, 50);
	masTrain[3] = Train("Dnipro", 45, 00, 30);
	masTrain[4] = Train("Kharkov", 70, 5, 45);
	//masTrain[5] = Train("Lviv", 205, 18, 20);
	//masTrain[6] = Train("Lviv", 5, 3, 10);
	//masTrain[7] = Train("Kuiv", 3, 12, 45);
	//masTrain[8] = Train("Tokmak", 145, 13, 40);
	cout << "Train list:" << endl;
	printArrayTrain(masTrain, size);

	cout << "Ordered output of an array of trains" << endl;
	masTrain->orderTrainsByNumber(masTrain, size);
	printArrayTrain(masTrain, size);

	cout << "Select train number for displaying information about the train " << endl;
	cin >> number;
	masTrain->displayInformationAboutTrainBySpecifiedNumber(masTrain, size, number);
	cout << endl << endl;

	cout << "Sorting an array of trains by destination:" << endl;
	masTrain->sortArrayByDestination(masTrain, size, destination);
	printArrayTrain(masTrain, size);

	delete[] masTrain;
	return 0;
}