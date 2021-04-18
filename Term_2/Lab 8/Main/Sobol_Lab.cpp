//
///*
//Пример создания и просмотра односвязного списка.
//По материалам КРАВЧУК А.И., КРАВЧУК А.С.
//СБОРНИК ЛАБОРАТОРНЫХ РАБОТ
//С ПРИМЕРАМИ РЕШЕНИЯ ЗАДАЧ ПО АЛГОРИТМИЗАЦИИ
//И ПРОГРАММИРОВАНИЮ НА ЯЗЫКЕ СИ
//(из файла "Посмотреть файлы и списки.pdf")
//Лабораторная работа №.22
//Тема: «Динамические структуры данных. Односвязный список»
//*/
//#include <iostream>
//#include <stdio.h>
//
//#include <conio.h>
//#include <stdlib.h>
//#define TRUE 1
//struct List
//{
//	int x;
//	struct List* Next;
//};
//struct List* CreateList(void);
//void DisplayList(struct List*);
//void RemoveTermBegin(struct List**);
//void RemoveTermTag(struct List*);
//void RemoveTermEnd(struct List*);
//void AddTermBegin(struct List**);
//void AddTermEnd(struct List*);
//void AddTermTag(struct List*);
//void FreeList(struct List**);
//int main(void)
//{
//	struct List* Begin = NULL;
//	char Key;
//	while (TRUE)
//	{
//		printf("\nEnter the number- the mode of "
//			"operations with Lists : "
//			"\n 1 - FORMATION OF THE LIST"
//			"\n 2 - VIEWING OF CONTENTS OF"
//			"THE LIST"
//			"\n 3 - REMOVE THE ELEMENT FROM "
//			"THE BEGIN OF LIST"
//			"\n 4 - REMOVE THE ELEMENT FROM "
//			"THE MIDLE OF LIST"
//			"\n 5 - REMOVE THE ELEMENT FROM "
//			"THE END OF LIST"
//			"\n 6 - ADD THE ELEMENT IN THE "
//			"BEGIN OF LIST"
//			"\n 7 - ADD THE ELEMENT IN THE "
//			"END OF LIST"
//			"\n 8 - ADD THE ELEMENT AFTER "
//			"ELEMENT - KEY OF LIST"
//			"\n 9 - END OF WORK\n");
//		fflush(stdin);
//		scanf("%c", &Key);
//		system("cls");
//		switch (Key)
//		{
//		case '1':
//			system("cls");
//			Begin = CreateList();
//			printf("\n\nPress any key to return in "
//				"the menu...\n");
//			_getch();
//			system("cls");
//			break;
//		case '2':
//			system("cls");
//			DisplayList(Begin);
//			printf("\n\nPress any key to return in "
//				"the menu...\n");
//			_getch();
//			system("cls");
//			break;
//		case '3':
//			system("cls");
//			RemoveTermBegin(&Begin);
//			printf("\n\nPress any key to return in "
//				"the menu...\n");
//			_getch();
//			system("cls");
//			break;
//		case '4':
//			system("cls");
//			RemoveTermTag(Begin);
//			printf("\n\nPress any key to return in "
//				"the menu...\n");
//			_getch();
//			system("cls");
//			break;
//		case '5':
//			system("cls");
//			RemoveTermEnd(Begin);
//			printf("\n\nPress any key to return in "
//				"the menu...\n");
//			_getch();
//			system("cls");
//			break;
//		case '6':
//			system("cls");
//			AddTermBegin(&Begin);
//			printf("\n\nPress any key to return in "
//				"the menu...\n");
//			_getch();
//			system("cls");
//			break;
//		case '7':
//			system("cls");
//			AddTermEnd(Begin);
//			printf("\n\nPress any key to return in "
//				"the menu...\n");
//			_getch();
//			system("cls");
//			break;
//		case '8':
//			system("cls");
//			AddTermTag(Begin);
//			printf("\n\nPress any key to return in "
//				"the menu...\n");
//			_getch();
//			system("cls");
//			break;
//		case '9':
//			FreeList(&Begin);
//			DisplayList(Begin);
//			printf("\n\nPress any key to "
//				"exit...\n");
//			_getch();
//			return 0;
//		default:
//			system("cls");
//			printf("\nIncorrect input!!! Try "
//				"again!!!\n");
//			printf("\n\nPress any key to return in "
//				"the menu...\n");
//			_getch();
//			system("cls");
//			break;
//		}
//		// очистка буфера ввода
//		scanf("%*[^\n]");
//		scanf("%*c");
//	}
//}
//struct List* CreateList(void)
//{
//	struct List* Begin = NULL, * Previos = NULL,
//		* Current = NULL;
//	char Ok = 'y';
//	while (Ok == 'y')
//	{
//		printf("\nEnter the numbers of List: ");
//		Current =
//			(struct List*)malloc(sizeof(struct List));
//		if (Begin == NULL)
//			Begin = Current;
//		else
//			Previos->Next = Current;
//		Previos = Current;
//		scanf("%d", &Current->x);
//		//fflush(stdin);
//		// очистка буфера ввода
//		scanf("%*[^\n]");
//		scanf("%*c");
//		printf("\nContinue? (Y/N):");
//		scanf("%c", &Ok);
//	}
//	Previos->Next = NULL;
//	return Begin;
//}
//void DisplayList(struct List* Begin)
//{
//	struct List* Current = Begin;
//	if (Begin == NULL)
//	{
//		printf("List is empty\n");
//		return;
//	}
//	printf("\nThe List of numbers:\n");
//	while (Current)
//	{
//		printf("%d ", Current->x);
//		Current = Current->Next;
//	}
//	printf("\n");
//}

//void RemoveTermBegin(struct List** Begin)
//{
//	struct List* Current = *Begin;
//	*Begin = Current->Next;
//	free(Current);
//}

//void RemoveTermTag(struct List* Begin)
//{
//	struct List* Current = Begin, * Previos = Current;
//	int NumberTag;
//	printf("\nEnter number-key: ");
//	scanf("%d", &NumberTag);
//	while (Current)
//	{
//		if (Current->x == NumberTag)
//		{
//			Previos->Next = Current->Next;
//			free(Current);
//			Current = Previos->Next;
//		}
//		else
//		{
//			Previos = Current;
//			Current = Current->Next;
//		}
//	}
//}

//void RemoveTermEnd(struct List* Begin)
//{
//	struct List* Current = Begin, * Previos = NULL;
//	while (Current->Next)
//	{
//		Previos = Current;
//		Current = Current->Next;
//	}
//	Previos->Next = NULL;
//	free(Current);
//}

//void AddTermBegin(struct List** Begin)
//{
//	struct List* Current =
//		(struct List*)malloc(sizeof(struct List));
//	printf("\nEnter number: ");
//	scanf("%d", &Current->x);
//	Current->Next = *Begin;
//	*Begin = Current;
//}

//void AddTermEnd(struct List* Begin)
//{
//	struct List* Current = Begin, * Previos = NULL;
//	while (Current)
//	{
//		Previos = Current;
//		Current = Current->Next;
//	}
//	Current = (struct List*)malloc(sizeof(struct List));
//	Previos->Next = Current;
//	printf("\nEnter the number:\n");
//	scanf("%d", &Current->x);
//	Current->Next = NULL;
//}

//void AddTermTag(struct List* Begin)
//{
//	struct List* Current = Begin, * Previos = Current;
//	int NumberTag;
//	printf("\nEnter number-tag: ");
//	scanf("%d", &NumberTag);
//	while (Current)
//	{
//		if (Current->x == NumberTag)
//		{
//			Previos = Current;
//			Current =
//				(struct List*)malloc(sizeof(struct List));
//			Current->Next = Previos->Next;
//			Previos->Next = Current;
//			printf("\nEnter the number:\n");
//			scanf("%d", &Current->x);
//			break;
//		}
//		else
//		{
//			Previos = Current;
//			Current = Current->Next;
//		}
//	}
//}

//void FreeList(struct List** Begin)
//{
//	struct List* Current = *Begin;
//	while (Current)
//	{
//		*Begin = (*Begin)->Next;
//		free(Current);
//		Current = *Begin;
//	}
//}
