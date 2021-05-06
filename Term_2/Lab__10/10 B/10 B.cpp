//ЛАБОРАТОРНАЯ РАБОТА № 10Б
//Написать две функции, каждая из которых меняет местами минимальное и максимальное значения трех чисел(не через массивы).
//Осуществить передачу параметров в функции 2 - мя методами(через ссылки, через указатели).

#include <iostream>
#include <iomanip>
using namespace std;

class Numbers {
private:
	int m_max = INT_MIN;
    int m_min = INT_MAX;
	int* max, * min;

public:

	void exchange_max_min_via_reference(int& value_A, int& value_B, int& value_C);
	void exchange_max_min_via_pointer(int* value_A, int* value_B, int* value_C);
	void print(int value_A, int value_B, int value_C);
};

void Numbers::exchange_max_min_via_reference(int& value_A, int& value_B, int& value_C)
{
	max = &m_max;
	min = &m_min;

	if (*max < value_A) max = &value_A;
	if (*max < value_B) max = &value_B;
	if (*max < value_C) max = &value_C;

	if (*min > value_A)  min = &value_A;
	if (*min > value_B)  min = &value_B;
	if (*min > value_C)  min = &value_C;

	int temp = *max;
	*max = *min;
	*min = temp;
}

void Numbers::exchange_max_min_via_pointer(int* value_A, int* value_B, int* value_C) {

	max = &m_max;
	min = &m_min;

	if (*max < *value_A) max = value_A;
	if (*max < *value_B) max = value_B;
	if (*max < *value_C) max = value_C;

	if (*min > *value_A)  min = value_A;
	if (*min > *value_B)  min = value_B;
	if (*min > *value_C)  min = value_C;

	int temp = *max;
	*max = *min;
	*min = temp;
}

void Numbers::print(int value_A, int value_B, int value_C)
{
	cout <<setw(4)<< value_A << setw(4) << value_B << setw(4) << value_C << endl;

}

int main() {

	Numbers first;
	int a = 1, b = -20, c = 6;

	first.exchange_max_min_via_reference(a, b, c);
	first.print(a, b, c);

	 a = 50, b = -2, c = -23;

	first.exchange_max_min_via_pointer(&a, &b, &c );
	first.print(a, b, c);

	return 0;
}
