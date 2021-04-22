#include <iostream>
#include "Functions.h"
#include "Struct.h"

void Alphabet(List* head, char Symbol, List* tail, List* edge ) { //edge = head   ||   edge = tile
	List* temp = edge;
	int Search_Result = 0;

	if (edge == head) { // ���� � ������
		while (temp) {
			if (*(temp->Data.name) == Symbol) {  // ������� ��������� ��������� ������
				Search_Result++;
			}
			temp = temp->next;
		}
	}
	else if (edge == tail) {  // ���� � �����
		while (temp) {
			if (*(temp->Data.name) == Symbol) {  // ������� ��������� ��������� ������
				Search_Result++;
			}
			temp = temp->prev;
		}
	}
	// ����� ������� ����������
	if (Search_Result == 0) {
		printf("������ �� �������. \n\n");  return;
	}
	else if (Search_Result != 0) {
		printf("\n�����������: %d\n", Search_Result);
	}
	// ����� ����� �����������
	printf("----------------------------------------------\n");
	printf("|         ��������� �������������            |\n");
	printf("|--------------------------------------------|\n");
	printf("| ����������� | ��� |  �������  | ���������� |\n");
	printf("|-------------|-----|-----------|------------|\n");
	
	temp = edge;
	if (edge == head) { // ���� � ������
		while (temp) {
			if (*(temp->Data.name) == Symbol) {
				printf("|%-13s|%-5c|%-11d|%-12d|\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
				printf("----------------------------------------------\n");
			}
			temp = temp->next;
		}
	}
	else if (edge == tail) { // ���� � �����
		while (temp) {
			if (*(temp->Data.name) == Symbol) {
				printf("|%-13s|%-5c|%-11d|%-12d|\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
				printf("----------------------------------------------\n");
			}
			temp = temp->prev;
		}
	}printf("\n\n");
}

void Search_Typ(List* head, char Symbol, List* tail, List* edge) { //edge = head   ||   edge = tile {
	List* temp = edge;
	int Search_Result = 0;

	if (edge == head) { // ���� � ������
		while (temp) {
			if (temp->Data.typ == Symbol) {  // ������� ��������� ��������� ������
				Search_Result++;
			}
			temp = temp->next;
		}
	}
	else if (edge == tail) {  // ���� � �����
		while (temp) {
			if (temp->Data.typ == Symbol) {  // ������� ��������� ��������� ������
				Search_Result++;
			}
			temp = temp->prev;
		}
	}
	// ����� ������� ����������
	if (Search_Result == 0) {
		printf("������ �� �������.\n\n");  return;
	}
	else if (Search_Result != 0) {
		printf("\n�����������: %d\n", Search_Result);
	}
	// ����� ����� �����������
	printf("----------------------------------------------\n");
	printf("|         ��������� �������������            |\n");
	printf("|--------------------------------------------|\n");
	printf("| ����������� | ��� |  �������  | ���������� |\n");
	printf("|-------------|-----|-----------|------------|\n");
	temp = edge;
	if (edge == head) { // ���� � ������
		while (temp) {
			if (temp->Data.typ == Symbol) {
				printf("|%-13s|%-5c|%-11d|%-12d|\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
				printf("----------------------------------------------\n");
			}
			temp = temp->next;
		}
	}
	else if (edge == tail) { // ���� � �����
		while (temp) {
			if (temp->Data.typ == Symbol) {
				printf("|%-13s|%-5c|%-11d|%-12d|\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
				printf("----------------------------------------------\n");
			}
			temp = temp->prev;
		}
	}printf("\n\n");
}

void Search_Nom( List* head, int number, List* tail, List* edge) {//������� �����.����������� ������ �������� ������������� ������� ��������� � ��������� ������, ������ �������� �����.
	List* temp = edge;
	int Search_Result = 0;
	if (edge == head) { // ���� � ������
		while (temp) {
			if (temp->Data.nom > number){
				Search_Result++;
			}
			temp = temp->next;
		}
	}
	else if (edge == tail) {  // ���� � �����
		while (temp) {
			if (temp->Data.nom > number) {  // ������� ��������� ��������� ������
				Search_Result++;
			}
			temp = temp->prev;
		}
	}
	// ����� ������� ����������
	if (Search_Result == 0) {
		printf("������ �� �������.\n\n");  return;
	}
	else if (Search_Result != 0) {
		printf("\n�����������: %d\n", Search_Result);
	}
	// ����� ����� �����������
	printf("----------------------------------------------\n");
	printf("|         ��������� �������������            |\n");
	printf("|--------------------------------------------|\n");
	printf("| ����������� | ��� |  �������  | ���������� |\n");
	printf("|-------------|-----|-----------|------------|\n");
	temp = edge;
	if (edge == head) { // ���� � ������
		while (temp) {
			if (temp->Data.nom > number) {
				printf("|%-13s|%-5c|%-11d|%-12d|\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
				printf("----------------------------------------------\n");
			}
			temp = temp->next;
		}
	}
	else if (edge == tail) { // ���� � �����
		while (temp) {
			if (temp->Data.nom > number) {
				printf("|%-13s|%-5c|%-11d|%-12d|\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
				printf("----------------------------------------------\n");
			}
			temp = temp->prev;
		}
	}printf("\n\n");
}

void Search_Colvo(struct List* head, int number, List* tail, List* edge) {
	List* temp = edge;
	int Search_Result = 0;
	if (edge == head) { // ���� � ������
		while (temp) {
			if (temp->Data.colvo < number) {  // ������� ��������� ��������� ������
				Search_Result++;
			}
			temp = temp->next;
		}
	}
	else if (edge == tail) {  // ���� � �����
		while (temp) {
			if (temp->Data.colvo < number) {  // ������� ��������� ��������� ������
				Search_Result++;
			}
			temp = temp->prev;
		}
	}
	// ����� ������� ����������
	if (Search_Result == 0) {
		printf("������ �� �������.\n\n");  return;
	}
	else if (Search_Result != 0) {
		printf("\n�����������: %d\n", Search_Result);
	}
	// ����� ����� �����������
	printf("----------------------------------------------\n");
	printf("|         ��������� �������������            |\n");
	printf("|--------------------------------------------|\n");
	printf("| ����������� | ��� |  �������  | ���������� |\n");
	printf("|-------------|-----|-----------|------------|\n");
	temp = edge;
	if (edge == head) { // ���� � ������
		while (temp) {
			if (temp->Data.colvo < number) {
				printf("|%-13s|%-5c|%-11d|%-12d|\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
				printf("----------------------------------------------\n");
			}
			temp = temp->next;
		}
	}
	else if (edge == tail) { // ���� � �����
		while (temp) {
			if (temp->Data.colvo < number) {
				printf("|%-13s|%-5c|%-11d|%-12d|\n", temp->Data.name, temp->Data.typ, temp->Data.nom, temp->Data.colvo);
				printf("----------------------------------------------\n");
			}
			temp = temp->prev;
		}
	}printf("\n\n");
}
