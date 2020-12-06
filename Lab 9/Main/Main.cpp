//Заполнить секторы матрицы, которые лежат влево и вправо от главной и побочной диагоналей,
//ЛП, от левого верхнего угла вниз - вправо.Остаток матрицы заполнить нулями.

#include <iostream>
#include <iomanip>
#define N 9
int mas[N][N];
using namespace std;
int main() {
	setlocale(LC_ALL, "Ru");
	int i, j;
	int a = 0;

	for (j = 0; j < N ; j++) { //  Ввод левой части
		for (i = 0; i < N; i++) {
			if (i > j && i + j < N - 1) {
				mas[i][j] = ++a;

			}
		}
	}

	for (j = 0; j < N ; j++) { //  Ввод правой части
		for (i = 0; i < N; i++) {
			if (i + j > N - 1 && i < j) {
				mas[i][j] = ++a;

			}
		}
	}

	for (i = 0; i < N; i++) {  //   Печать
		for (j = 0; j < N; j++) {
			cout << setw(4) << mas[i][j];

		}
		cout << endl;
	}

}