#include "include.h"


void Sort(int N) {
   
    if (vedom[0].name != "") {
        struct information a;
        for (int i = 0; i < N; i++) {
            vedom[i].sort = vedom[i].name.length();
        }
        for (int i = 0; i < N - 1; i++) {
            for (int j = i; j < N; j++) {
                if (vedom[i].sort > vedom[j].sort) {
                    a = vedom[i];
                    vedom[i] = vedom[j];
                    vedom[j] = a;
                }
            }
        }
        cout << "������ ������������." << endl;
        cout << "�������� ���������� ��������.\n" << endl;
    }
    else {
        cout << "������� �����. ���������� ��������� ������ �������.\n" << endl;
    }return;
}
