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

	MASTER first("Джейс Вейд Моргерштерн", 32, 2);
	first.setDog_of_master_with_creation("Chery", 8, 9, 1);
	first.setDog_of_master_with_creation("Kira ", 5, 2, 2);
	first.Print();

	MASTER second;
	second.setName("Тесса Грей Фэирчайлд  ");
	second.setColvo_dogs(1);
	second.setDog_nickname("Jora ");
	second.setDog_weight(3);
	second.setDog_age(6);
	second.Print();

	return 0;
}