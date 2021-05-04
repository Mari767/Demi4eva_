//ЛАБОРАТОРНАЯ РАБОТА №11Г
//Разработать классы DOG и MASTER
//1. DOG(Кличка, вес, возраст).MASTER(ФИО; ID клуба – константа; Собаки – возможно несколько!; count – статический счетчик создаваемых членов клуба).
//Также реализовать следующие пункты.
//2. Наличие множества конструкторов для инициализации объектов класса.
//3. Реализовать инкапсуляцию(методы set / get) для изменения сведений о собаках и их владельцах.
//
//Для тестирования программы создать двух владельцев собак.У первого – две собаки, у второго – одна.
//Для каждого вывести ФИО, ID клуба и информацию по всем собакам.А также – количество членов клуба.

#include <iostream>
#include "Dog.h"
#include "Master.h"

int main() {
	setlocale(LC_ALL, "ru");

	//DOG first("Mike", 10, 5);
	//first.Print();
	//DOG second;
	//second.setNickname("Keri");
	//second.setWeight(3);
	//second.setAge(2);
	//second.Print();

	MASTER first("Джейс Вейланд Моргерштерн", 32, 2, 1);
	first.Print();

	MASTER second;
	second.setName("Тесса Грей Фэирчайлд ");
	second.setID(51);
	second.setColvo_dogs(1);
	second.setCount(2);
	second.Print();


	return 0;
}