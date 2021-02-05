#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
using namespace std;
#define N 8

void Child(int arr[], int n, int i);
void heapSort(int arr[], int n);
void printArray(int arr[]);

int main() {

    int n = N;
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    int arr[N];
    cout << "Массив до сортировки: " << endl;
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 101 - 50;
        cout << setw(4) << arr[i];
    }cout << endl;

    cout << "Массив после сортировки: " << endl;

    heapSort(arr, n);

    cout << endl;
    printArray(arr);
    return 0;
}

void Child(int arr[], int n, int i)
{
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2

 // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // преобразуем в двоичную кучу затронутое поддерево
        Child(arr, n, largest);
    }
    return;
}

void heapSort(int arr[], int n)
{
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        Child(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--) {

        swap(arr[0], arr[i]);

        // вызываем процедуру heapify на уменьшенной куче
        Child(arr, i, 0);
    }
    return;
}

void printArray(int arr[])
{
    for (int i = 0; i < N; ++i)
        cout << setw(4) << arr[i];
    cout << endl;
    return;
}

