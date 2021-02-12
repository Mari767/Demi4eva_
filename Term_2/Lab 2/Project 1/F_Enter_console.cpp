#include "include.h"


int Screen() {
    //Ввод данных вручную
    int N;
    float nomn;// переменная для номинала
    for (N = 0; ; N++) {
        if (N == 10) {
            cout << "Таблица заполнена. \nВыберите дальнейшее действие.\n" << endl;
            break;
        }
        cout << "Введите обозначение, тип, номинал, количество > \n(для завершения заполнения таблицы введите в обозначение ***)" << endl;
        cin >> vedom[N].name;
        if (vedom[N].name == "***") break;
        cin >> vedom[N].typ >> nomn >> vedom[N].colvo;
        vedom[N].nom = nomn;
    }
    cout << "Массив заполнен." << endl;
    cout << "Выберите дальнейшее действие.\n" << endl;
    return N;
}
