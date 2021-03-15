//В одномерном массиве найти сумму и количество отрицательных элементов через :
//а) относительный адрес;
//б) через абсолютный адрес;
//в) не использовать индексацию;
//г) через массив указателей;
//д) через указатель на указатель.
//е) оформить в виде функции с параметрами указателями.


#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int Size, i;
	int* ptr;
	int Sum;
	const int Size_ptr = 30;
	int* Pointer[Size_ptr];
	cout << "Введите размер массива. Максимальное количество -- 30 элементов." << endl;
	cin >> Size;
	int* mas = (int*)malloc(Size * sizeof(int));
	for (i = 0; i < Size; i++) {
		*(mas + i) = rand() % 200 - 70;
	}
	for (i = 0; i < Size; i++) {
		cout << setw(4) << *(mas + i);
	}
	for (i = 0; i < Size; i++) {
		Pointer = mas;
	}


	//cout << " \nOтносительный адрес " << endl;
	//ptr = mas;
	//for (i = 0, Sum = 0; i < Size; i++) {
	//	if (*(ptr + i) < 0) {
	//		Sum += *(ptr + i);
	//	}
	//}cout << "Sum = " << Sum << endl;

	//cout << "через абсолютный адрес" << endl;
	////ptr = mas;
	//for (i = 0, Sum = 0; i < Size; i++, ptr++) {
	//	if (*ptr < 0) {
	//		Sum += *ptr;
	//	}
	//}cout << "Sum = " << Sum << endl;

	//cout << "Не использовуя индексацию" << endl;
	//for (ptr = mas, Sum = 0; ptr < mas + Size; ptr++) {
	//	if (*ptr < 0) {
	//		Sum += *ptr;
	//	}
	//}cout << "Sum = " << Sum << endl;


	cout << "Через массив указателей" << endl;

	/*for (i = 0, Sum = 0; i < Size; i++) {
		if (*(Pointer + i) < 0) {
			Sum += *(Pointer + i);
		}
	}cout << "Sum = " << Sum << endl;*/



	//cout << "через указатель на указатель" << endl;
	//ptr = mas;
	//for (i = 0, Sum = 0; i < Size; i++/*, P_ptr++*/) {
	//	if (**++P_ptr < 0) {
	//		Sum += **P_ptr;
	//	}
	//}cout << "Sum = " << Sum << endl;



	free(mas);
	return 0;
}

////Абсолютная адресация
//p = A;
//for (int i = 0; i < N; i++, p++)
//    cout << *p << " ";
//
////Относительная адресация
//p = A;
//for (int i = 0; i < N; i++)
//    cout << *(p + i) << " "; //*(A+i)
//
//  //Без индексов (без переменной цикла i)
//for (p = A; p < A + N; p++)
//    cout << *p << " ";
