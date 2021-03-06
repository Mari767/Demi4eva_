#include <iostream>

using namespace std;

void Child(int* arr, int Size, int i);

void heapSort(int *arr, int Size)
{
    // Построение кучи (перегруппируем массив)
    for (int i = Size / 2 - 1; i >= 0; i--)
        Child(arr, Size, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = Size - 1; i >= 0; i--) {

        swap(*arr, *(arr+i));

        // вызываем процедуру heapify на уменьшенной куче
        Child(arr, i, 0);
    }
    return;
}

void Child(int * arr, int Size, int i)
{
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2

 // Если левый дочерний элемент больше корня
    if (l < Size && *(arr+l) > *(arr+largest))
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < Size && *(arr+r) > *(arr+largest))
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swap(*(arr+i), *(arr + largest));

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        Child(arr, Size, largest);
    }
    return;
}