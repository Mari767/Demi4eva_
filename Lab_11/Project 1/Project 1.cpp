//Напишите рекурсивную функцию, которая вычисляет сумму цифр натурального числ# N.

#include <iostream>
#include <iomanip>
using namespace std;

int Score(int N) {
	if (N < 10) {
		return N;
	}
	int a = N % 10;
	N = N / 10;

	return a + Score(N);
}

int main() {
	int N;
	setlocale(LC_ALL, "ru");

	cout << "Введите число N= ";
	cin >> N;

	cout<<"Сумма цифр натурального числа N равна "<<Score(N);

	return 0;
}
