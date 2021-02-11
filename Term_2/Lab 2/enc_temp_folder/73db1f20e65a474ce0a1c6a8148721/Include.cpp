/*
Пример #define 5
Макроподстановки и макроопределения

Написать программу, которая позволяет включать и выключать
промежуточную печать в процессе отладки
с помощью операторов условной компиляции
*/
#include <iostream>

using namespace std;
//#define PRINT	// Может быть любой идентификатор (DEB, DEBUG, TT_, DEBUG_1) 
// (не обязательно такой)

int Sum(int a, int b)
{
	return a + b;
}

int main()
{
	setlocale(LC_ALL, "ru");

	int a = 2;
	int b = 2;
	int sum = Sum(2, 2);
	// Первый способ
#if defined PRINT
	cout << "Промежуточная печать включена \nСумма " << a << " и " << b << " равна " << sum << endl;
#else
	cout << "Промежуточная печать выключена" << endl;
#endif // PRINT

	// Второй способ
#ifdef PRINT
	cout << "Промежуточная печать включена (второй способ) \nСумма " << a << " и " << b << " равна " << sum << endl;
#endif

#ifndef PRINT
	cout << "Промежуточная печать выключена (второй способ)" << endl;
#endif // !PRINT

	return 0;
}