//выводится на экран таблица - сразу же после ввода и после сортировки ее по значениям в первом столбце.
//Сделать МЕНЮ для различного заполнения списка структур(1 – ввод с экрана, 2 – случайным образом),
//а также действия над структурами(3 – сортировка, 4 – печать).Все оформить в виде 4 - х функций
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int Screen();
void Rand(int N);
int randomRange(int low, int high);
void Print(int N);
void Sort(int N);

struct information {
    string name;     //Обозначение
    char typ;        //Тип
    float nom;       //Номинал
    int colvo;       //Количество
    short sort;      //Длинна строки(для сортировки)
}vedom[10];

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int a;
    int N;
    do {
        cout << "Выберите действие: \n Заполнение таблицы \n  1 –> ввод с экрана  \n  2 –> случайным образом  \n Операция над структурами\n  3-> сортировка таблицы\n  4-> печать таблицы\n  5-> виход из программы" << endl;
        cin >> a;
        switch (a) {
        case 1:  //Ввод данных вручную
            N = Screen();
            break;
        case 2:  //Ввод рандомайзером
            cout << "Введите количество строк таблицы которое Вы хотите заполнить. Максимальное количество строк 10." << endl;
            cin >> N;
            if (N > 10 || N < 1) {
                cout << "Вы ввели некорректные данные. Попробуйте с начала.\n" << endl;
                break;
            }
            Rand(N);
            break;
        case 3:  // Сортировка
            if (vedom[0].name == "") {
                cout << "Таблица пуста. Пожалуйста заполните сперва таблицу.\n" << endl;
                break;
            }
            Sort(N);
            break;
        case 4:  // Печать
            if (vedom[0].name == "") {
                cout << "Таблица пуста. Пожалуйста заполните сперва таблицу.\n" << endl;
                break;
            }
            Print(N);
            break;
        case 5:
            break;
        default:
            cout << "Некорректный ответ. Попробуйте ещй раз." << endl;
        }
    } while (a != 5);

    return 0;
}

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
int randomRange(int low, int high) {
    return rand() % (high - low + 1) + low;
}

void Print(int N) {
    cout << setiosflags(ios::left);
    cout << "----------------------------------------------" << endl;
    cout << "|         Ведомость комплектующих            |" << endl;
    cout << "|--------------------------------------------|" << endl;
    cout << "| Обозначение | Тип |  Номинал  | Количество |" << endl;
    cout << "|-------------|-----|-----------|------------|" << endl;
    for (int i = 0; i < N; i++) {
        cout << "|" << setw(13) << vedom[i].name << "|" << setw(5) << vedom[i].typ << "|" << setw(11) << vedom[i].nom << "|" << setw(12) << vedom[i].colvo << "|" << endl;
        cout << "|--------------------------------------------|" << endl;
    }
    cout << "Выберите дальнейшее действие.\n" << endl;
}
void Sort(int N) {
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
    cout << "Массив отсортирован." << endl;
    cout << "Выберите дальнейшее действие.\n" << endl;
}