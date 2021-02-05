#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;
int N;

void Gnome_sort(int i, int j, int* mas);

int main() {
	setlocale(LC_ALL, "Ru");
	srand(time(NULL));
	int j, i;
	cout << "Введите размер массива ->"; cin >> N;
	int* mas = new int[N];
	cout << "Неотсортированный массив: " << endl;
	for (i = 0; i < N; i++) {//ввод массива
		mas[i] = rand() % 100 - 30;
		cout << setw(4) << mas[i];
	}cout << endl << endl;
	i = 1; j = 2;

	Gnome_sort(i, j, mas); //вызов функции сортировки


	delete[]mas;
	return 0;
}

void Gnome_sort(int i, int j, int* mas) {
	while (i < N)
	{
		if (mas[i - 1] <= mas[i]) { i = j; j++; }
		else
		{
			int t = mas[i];
			mas[i] = mas[i - 1];
			mas[i - 1] = t;
			i--;
			if (i == 0) { i = j; j++; }
		}
	}
	cout << "Отсортированный массив : " << endl;
	for (i = 0; i < N; i++) {//вывод массива
		cout << setw(4) << mas[i];
	}cout << endl << endl;
	return;
}
