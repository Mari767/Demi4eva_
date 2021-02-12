#include "include.h"


void Rand(int N) {
    //Ввод рандомайзером
    string masname[] = { "RT-11-24", "CGU-12K", "YIR-15", "NO-3", "MNU-8", "OP-20", "ST", "P", "BORR", "GHJ-0", "POR-H", "PRTYMB-2", "CGU-RT-12", "TURP-08" , "BUTMB-K", "PTK", "RTY", "BROM-6", "BERMUDO", "AHJU", "Rip-.." };

    for (int i = 0; i < N; i++) {
        int Randsign = rand() % 21;
        vedom[i].name = masname[Randsign];
        vedom[i].typ = 'A' + rand() % ('Z' - 'A');
        vedom[i].nom = rand() % 1000;
        vedom[i].colvo = rand() % 100;
    }
    cout << "Массив заполнен." << endl;
    cout << "Выберите дальнейшее действие.\n" << endl;
}
