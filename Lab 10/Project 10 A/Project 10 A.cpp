//ф-ция сравнивает два числа и возвращает знак сравнения(5 > 2, 7 < 3, 2 = 2)

#include <iostream>
#include <time.h>
using namespace std;

char comparing(int, int);

int main() {
	setlocale(LC_ALL,"Ru");
	srand(time(NULL));
	int a, b;
	a=rand()%50-20;
	b=rand()%50-20;
	/*cout << "Введите два числа для их сравнения.\na=" ;
	cin >> a;
	cout << "b=";
	cin >> b;*/

	cout << a << comparing(a, b)<<  b << endl<<endl;

	return main();
}

char comparing(int a, int b) {
	char c;
	if (a > b) {
		c = '>';
		return c;
	}
	else if (a < b) {
		c = '<';
		return c;
	}
	else c = '=';
	return c;
}