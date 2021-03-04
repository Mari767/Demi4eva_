#include "Function.h"
#include <iomanip>
#include "Struct.h"
#define DEBUG

int Screen() {
	//���� ������ �������
	int N;
	float nomn;// ���������� ��� ��������
	for (N = 0; ; N++) {
		if (N == B) {  //B=10
			cout << "������� ���������. \n�������� ���������� ��������.\n" << endl;
			break;
		}
		cout << "������� �����������, ���, �������, ���������� > \n(��� ���������� ���������� ������� ������� � ����������� ***)" << endl;
		cin >> vedom[N].name;
		if (!strcmp(vedom[N].name,"***")) {
			break;
		}
		cin >> vedom[N].typ >> nomn >> vedom[N].colvo;
		vedom[N].nom = nomn;
	}
	cout << "������ ��������." << endl;
	cout << "�������� ���������� ��������.\n" << endl;
	return N;
#ifdef DEBUG
	cout << "����: " << __DATE__ << endl;
	cout << "�����  " << __TIME__ << endl;
	cout << "��� �������� ����� " << __FILE__ << endl;
	cout << "��� ������� ������� " << __FUNCTION__ << endl;
	cout << endl << endl;
#endif  // DEBUG

}
void Rand() {
	//���� �������������
	char masname[20][M] = { "RT-11-24", "TRU4", "MNU-8", "OP-20", "P", "BORR", "POR-H", "BUTMB-K", "PTK", "RTY", "BROM-6", "TURP-08", "GHJ-0", "BERMUDO", "PRTYMB-2", "NO-3", "YIR-15", "CGU-RT-12", "ST", "CGU-12K" };
	int N = B; //N=10
	for (int i = 0; i < N; i++) {
		int Randsign = rand() % 20;
		strcpy_s(vedom[i].name, masname[Randsign]);
		vedom[i].typ = 'A' + rand() % ('Z' - 'A');
		vedom[i].nom = rand() % 1000;
		vedom[i].colvo = rand() % 100;
	}
	cout << "������ ��������." << endl;
	cout << "�������� ���������� ��������.\n" << endl;
#ifdef DEBUG
	cout << "����: " << __DATE__ << endl;
	cout << "�����: " << __TIME__ << endl;
	cout << "��� �������� ����� " << __FILE__ << endl;
	cout << "��� ������� ������� " << __FUNCTION__ << endl << endl << endl;
#endif // DEBUG
	return;
}

int Sort(int N) {

	if (vedom[0].name != "") {
		struct information a;
		for (int i = 0; i < N; i++) {
			vedom[i].sort = strlen(vedom[i].name); /////////////////////////////////////
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
#ifdef DEBUG
		cout << "����: " << __DATE__ << endl;
		cout << "�����: " << __TIME__ << endl;
		cout << "��� �������� ����� " << __FILE__ << endl;
		cout << "��� ������� ������� " << __FUNCTION__ << endl << endl << endl;
#endif  // DEBUG
	}
	else {
		cout << "������� �����. ���������� ��������� ������ �������.\n" << endl;
	}return N;
}

int Print(int N) {

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
#ifdef DEBUG
		cout << "����: " << __DATE__ << endl;
		cout << "�����: " << __TIME__ << endl;
		cout << "��� �������� ����� " << __FILE__ << endl;
		cout << "��� ������� ������� " << __FUNCTION__ << endl << endl << endl;
#endif // DEBUG
	}
	else {
		cout << "������� �����. ���������� ��������� ������ �������.\n" << endl;
	}

	return N;
}