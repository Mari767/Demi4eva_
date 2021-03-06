#include <stdio.h>
#include <stdlib.h>

void quickSort(int* numbers, int left, int right);

//������� ������ ������� ����������.   ����� �� �� main ��-�� �������������� ���������� ���� � ������ ������� ����������
void Quick(int* massiv, int Size) {
    quickSort(massiv, 0, Size - 1);
}

// ������� ������� ����������
void quickSort(int* numbers, int left, int right)
{    // numbers---massiv
    int pivot; // ����������� �������
    int l_hold = left; //����� �������
    int r_hold = right; // ������ �������
    pivot = *(numbers+left);
    while (left < right) // ���� ������� �� ���������
    {
        while ((*(numbers + right) >= pivot) && (left < right))
            right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
        if (left != right) // ���� ������� �� ����������
        {
            *(numbers + left) = *(numbers + right); // ���������� ������� [right] �� ����� ������������
            left++; // �������� ����� ������� ������
        }
        while ((*(numbers + left) <= pivot) && (left < right))
            left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
        if (left != right) // ���� ������� �� ����������
        {
            *(numbers + right) = *(numbers + left); // ���������� ������� [left] �� ����� [right]
            right--; // �������� ������ ������� ������
        }
    }
    *(numbers + left) = pivot; // ������ ����������� ������� �� �����
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
        quickSort(numbers, left, pivot - 1);
    if (right > pivot)
        quickSort(numbers, pivot + 1, right);
}
