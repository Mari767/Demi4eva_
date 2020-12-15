#include <chrono>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#define N 45
#define P 820

using namespace std;

void Gnome_sort(int mas[]);

int main()
{
	setlocale(LC_ALL, "Ru");

	int j, i;
	double p;
	cout << "Размер массива ->" << N << endl;
	int mas[N];
	double time[P];
	for (int u = 0; u < P; u++) {

		////cout << "Упорядоченный массив: " << endl;
		//for (i = 0; i < N; i++) {
		//	mas[i] = i + 1;
		//}

		//auto start = chrono::high_resolution_clock::now();
		//Gnome_sort(mas); //вызов функции сортировки
		//auto end = chrono::high_resolution_clock::now();
		//chrono::duration<double> duration = end - start;
		
		

		////cout << "\nМассив, упорядоченный в обратном порядке: " << endl;
		//int a = 1;
		//for (i = 0; i < N; i++) {//ввод массива
		//	mas[i] = N - i;
		//}
		//auto start = chrono::high_resolution_clock::now();
		//Gnome_sort(mas); //вызов функции сортировки
		//auto end = chrono::high_resolution_clock::now();
		//chrono::duration<double> duration = end - start;
		


		//cout << "\nНеотсортированный массив: " << endl;
		for (i = 0; i < N; i++) {//ввод массива
			mas[i] = rand() % 100 - 30;
		}
		auto start = chrono::high_resolution_clock::now();
		Gnome_sort(mas); //вызов функции сортировки
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> duration = end - start;
	
		time[u] = duration.count();;
		cout << u << "   " << time[u] << endl;
	}
	double sum = 0;
	double result;
	sort(time, time + P);

	for (int u = 10	; u < P-10; u++) {
		sum += time[u];
	}
	cout << "Sum" <<sum << endl;
	result = sum / (P - 20);
	cout << "Result " <<result << endl;
	return 0;
}

void Gnome_sort(int mas[]) {
	int i = 1;
	int j = 2;
	while (i < N)
	{
		if (mas[i - 1] <= mas[i]) { i = j; j++; }
		else
		{
			int t = mas[i];
			mas[i] = mas[i - 1]; mas[i - 1] = t;
			i--;
			if (i == 0) { i = j; j++; }
		}
	}
	return;
}