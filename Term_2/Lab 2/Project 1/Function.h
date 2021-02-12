#pragma once

#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;
#include "Struct.h"
#ifndef FUNCTION_H_
#define FUNCTION_H_
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
void Rand(int N) {
    //���� �������������
    string masname[] = { "RT-11-24", "CGU-12K", "YIR-15", "NO-3", "MNU-8", "OP-20", "ST", "P", "BORR", "GHJ-0", "POR-H", "PRTYMB-2", "CGU-RT-12", "TURP-08" , "BUTMB-K", "PTK", "RTY", "BROM-6", "BERMUDO", "AHJU", "Rip-.." };

    for (int i = 0; i < N; i++) {
        int Randsign = rand() % 21;
        vedom[i].name = masname[Randsign];
        vedom[i].typ = 'A' + rand() % ('Z' - 'A');
        vedom[i].nom = rand() % 1000;
        vedom[i].colvo = rand() % 100;
    }
    cout << "������ ��������." << endl;
    cout << "�������� ���������� ��������.\n" << endl;
}


void Print(int N) {

    if (vedom[0].name != "") {
        cout << setiosflags(ios::left); //��� ������ �� ����� �������, ������ �����
        cout << "----------------------------------------------" << endl;
        cout << "|         ��������� �������������            |" << endl;
        cout << "|--------------------------------------------|" << endl;
        cout << "| ����������� | ��� |  �������  | ���������� |" << endl;
        cout << "|-------------|-----|-----------|------------|" << endl;
        for (int i = 0; i < N; i++) {
            cout << "|" << setw(13) << vedom[i].name << "|" << setw(5) << vedom[i].typ << "|" << setw(11) << vedom[i].nom << "|" << setw(12) << vedom[i].colvo << "|" << endl;
            cout << "|--------------------------------------------|" << endl;
        }
        cout << "�������� ���������� ��������.\n" << endl;
    }
    else {
        cout << "������� �����. ���������� ��������� ������ �������.\n" << endl;
    }
}


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

#endif