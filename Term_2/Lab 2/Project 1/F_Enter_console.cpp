#include "include.h"


int Screen() {
    //���� ������ �������
    int N;
    float nomn;// ���������� ��� ��������
    for (N = 0; ; N++) {
        if (N == 10) {
            cout << "������� ���������. \n�������� ���������� ��������.\n" << endl;
            break;
        }
        cout << "������� �����������, ���, �������, ���������� > \n(��� ���������� ���������� ������� ������� � ����������� ***)" << endl;
        cin >> vedom[N].name;
        if (vedom[N].name == "***") break;
        cin >> vedom[N].typ >> nomn >> vedom[N].colvo;
        vedom[N].nom = nomn;
    }
    cout << "������ ��������." << endl;
    cout << "�������� ���������� ��������.\n" << endl;
    return N;
}
