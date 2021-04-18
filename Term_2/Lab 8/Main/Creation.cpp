#include "Struct.h"

//information Rand(information vedom);
//information Rand_Name(information vedom);
void Free_List(struct List** head);
void clearStdIn();

struct List* Creation_List(int* Size) {
	//information vedom;   //������ ���������
	int a = 5;
	List* head = NULL;
	List* tail = NULL;
	List* temp = NULL;
	char list_create;
	list_create = 'y';
	while (list_create == 'y') {
		++(*Size);
		temp = (struct List*)malloc(sizeof(struct List));
		if (head == NULL) {      //������ ������
			head = tail = temp;  // ��������� ������  � �����
		}
		else {                   //������ �� ������
			tail->next = temp;   //����� ����������
			tail = temp;         //��������� �����
		}
		//printf("\n������� �����.\n");
		temp->Data.sort = a++;
		clearStdIn();
		/* ���������� ������ ������ ������� �� ���������
		Rand(vedom);
		temp->Data.name = vedom.name;
		temp->Data.typ = vedom.typ;
		temp->Data.colvo = vedom.colvo;
		temp->Data.nom = vedom.nom;
		temp->Data.sort = vedom.sort;*/

		temp->next = NULL;       // ���� ������� - ���������

		printf("\n�����������? (y/n):");
		scanf_s("%c", &list_create);
	}
	return head;
}

void Print_List(struct List* head) {

	struct List* temp = head;
	if (head == NULL) {
		printf("������ ����.\n");
		return;
	}
	printf("\nThe List of numbers:\n");
	while (temp) {
		printf("%3d ", temp->Data.sort);
		temp = temp->next;
	}
	printf("\n");
}

void add_first_element(struct List** head, int* Size) {
	++(*Size);
	int a = 40;
	struct List* temp = (struct List*)malloc(sizeof(struct List));
	temp->Data.sort = a++;
	temp->next = *head;
	*head = temp;
}
void add_middle_element(struct List* head, int* Size, int Location) {
	++(*Size);
	int a = -10;
	struct List* temp = head, * tail = temp;
	for (int i = 0; temp != NULL; i++) {                      //����� �� �� ����� ������ ��������------------------------------

		if (i == Location) {
			tail = temp;
			temp = (struct List*)malloc(sizeof(struct List));
			temp->next = tail->next;
			tail->next = temp;
			temp->Data.sort = a++;
			break;
		}
		else {
			tail = temp;
			temp = temp->next;
		}
	}
}
void add_last_element(struct List* head, int* Size) {
	++(*Size);
	int a = 60;
	struct List* temp = head, * tail = NULL;
	while (temp) {
		tail = temp;
		temp = temp->next;
	}
	temp = (struct List*)malloc(sizeof(struct List));
	tail->next = temp;
	temp->Data.sort = a++;
	temp->next = NULL;
}

void free_first_element(struct List** head, int* Size) {           //  ����������?
	if (*Size <= 0) { return; }; --(*Size);

	struct List* temp = *head;
	*head = temp->next;
	free(temp);
}
void free_middle_element(struct List* head, int* Size, int Location) {
	//if (head) { return; } //���� ������ ����-- �������� ����������
	if (*Size <= 0) { return; };
	--(*Size);
	struct List* temp = head, * tail = temp;
	for (int i = 0; temp != NULL; i++)                              //����� �� �� ����� ������ ��������------------------------------
	{
		if (i == Location) {
			tail->next = temp->next;
			free(temp);
			temp = tail->next;
		}
		else {
			{
				tail = temp;
				temp = temp->next;
			}
		}
	}
}
void free_last_element(struct List* head, int* Size) {
	if (*Size <= 0) { return; };
	--(*Size);

	struct List* temp = head, * tail = NULL;
	if (temp->next) {
		return;
	}
	while (temp->next) {
		tail = temp;
		temp = temp->next;
	}
	tail->next = NULL;
	free(temp);
}

//int Sort(struct List* head, int* Size) {
//	struct List* temp = head, * tail = NULL;
//	while (temp) {
//		temp->Data.sort = strlen(temp->Data.name);
//		tail = temp;
//		temp = temp->next;
//	}
//
//	struct information a;
//	for (int i = 0; i < *Size; i++) {
//	}
//	for (int i = 0; i < *Size - 1; i++) {
//		for (int j = i; j < *Size; j++) {
//			if (vedom[i].sort > vedom[j].sort) {
//				a = vedom[i];
//				vedom[i] = vedom[j];
//				vedom[j] = a;
//			}
//		}
//	}
//	cout << "������ ������������." << endl;
//
//	return N;
//}

void Recording_List_to_FILE(struct List* head, char* name) {
	FILE* file = NULL;
	fopen_s(&file, name, "wt");  // file opened
	if (file == NULL) {
		exit(0);
	}
	struct List* temp = head, * tail = NULL;
	while (temp) {
		fprintf(file, "%4d", temp->Data.sort);
		tail = temp;
		temp = temp->next;
	}
	fclose(file);
}


void Free_List(struct List** head) {
	struct List* temp = *head;
	while (temp)
	{
		*head = (*head)->next;
		free(temp);
		temp = *head;
	}
}

//
//information Rand(information vedom) {       //	���� ��������� ������� � 
//	//���� �������������
//	for (int i = 0; ; i++) {
//		vedom = Rand_Name(vedom);
//		vedom.typ = 'A' + rand() % ('Z' - 'A');
//		vedom.nom = rand() % 1000;
//		vedom.colvo = rand() % 100;
//	}
//	return vedom;
//}
//information Rand_Name(information vedom) { // ��������� Name  ���  vedom.name
//	char masname[20][M] = { "RT-11-24", "TRU4", "MNU-8", "OP-20", "P", "BORR", "POR-H", "BUTMB-K", "PTK", "RTY", "BROM-6", "TURP-08", "GHJ-0", "BERMUDO", "PRTYMB-2", "NO-3", "YIR-15", "CGU-RT-12", "ST", "CGU-12K" };
//	int Randsign = rand() % 20;
//	strcpy_s(vedom.name, masname[Randsign]);
//	return vedom;
//}
void clearStdIn() { // �������� ������ Stdin
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}