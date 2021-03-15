//ЛАБОРАТОРНАЯ РАБОТА № 5В
//Написать функцию сортировки с параметром указатель на функцию, который будет выбирать различные методы сортировки.

#include <iostream>
#include <iomanip>
#include "Gnome.h"
#include "Bubble.h"
#include "Heap.h"
#include "Quick.h"
#include "Function.h"


int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	//объявление указателей на функции сортировки
	void (*Ptr_Function)(int*, int) = NULL;
	int Size, i;
	int a; //Выбор в менюшке

	printf("Введите размер массива\n");
	scanf_s("%d", &Size);
	if (Size < 1) {
		printf("Некорректный ответ");
		return 0;
	}
	// инициализация динамического массива
	int* Mas = (int*)malloc(sizeof(int) * Size);
	for (i = 0; i < Size; i++) {
		*(Mas + i) = rand() % 100 - 50;
	}


	printf("Выберете метод сортировки массива. \n 1->Сортировка пузырьком \n 2->Гномья сортировка \n 3->Пирамидальная сортировка \n 4->Быстрая сортировка\n\n");
	scanf_s("%d", &a);
	

	switch (a) {
	case 1:
		printf("Сортировка пузырьком.\n");
		Ptr_Function = Bubble;
		break;
	case 2:
		printf("Гномья сортировка.\n");
		Ptr_Function = Gnome_sort;
		break;
	case 3:
		printf("Пирамидальная сортировка .\n");
		Ptr_Function =  heapSort;
		break;
	case 4:
		printf("Быстрая сортировка.\n");
		Ptr_Function = Quick;
		break;
	default:
		printf("Некорректный ответ.\n");
		return 0;
	}
	printf("Исходный массив: \n");
	Print_massiv(Mas, Size);

	Chose_Sort(Mas, Size, Ptr_Function);  //  Вызываем функцию сортировки массива, записпнную в указатель

	printf("Отсортированный массив: \n");
	Print_massiv(Mas, Size);

	free(Mas);
	return 0;
}