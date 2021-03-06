#include <iostream>

using namespace std;

void Child(int* arr, int Size, int i);

void heapSort(int *arr, int Size)
{
    // ���������� ���� (�������������� ������)
    for (int i = Size / 2 - 1; i >= 0; i--)
        Child(arr, Size, i);

    // ���� �� ������ ��������� �������� �� ����
    for (int i = Size - 1; i >= 0; i--) {

        swap(*arr, *(arr+i));

        // �������� ��������� heapify �� ����������� ����
        Child(arr, i, 0);
    }
    return;
}

void Child(int * arr, int Size, int i)
{
    int largest = i;
    // �������������� ���������� ������� ��� ������
    int l = 2 * i + 1; // ����� = 2*i + 1
    int r = 2 * i + 2; // ������ = 2*i + 2

 // ���� ����� �������� ������� ������ �����
    if (l < Size && *(arr+l) > *(arr+largest))
        largest = l;

    // ���� ������ �������� ������� ������, ��� ����� ������� ������� �� ������ ������
    if (r < Size && *(arr+r) > *(arr+largest))
        largest = r;

    // ���� ����� ������� ������� �� ������
    if (largest != i)
    {
        swap(*(arr+i), *(arr + largest));

        // ���������� ����������� � �������� ���� ���������� ���������
        Child(arr, Size, largest);
    }
    return;
}