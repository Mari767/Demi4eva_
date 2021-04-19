#pragma once
#ifndef FUNCTION_H_
#define FUNCTION_H_
#include "Struct.h"

struct List* Creation_List(int *Size);

void Free_List(struct List** head);

void Print_List(struct List* head);

void free_first_element(struct List** head, int* Size);
void free_middle_element(struct List* head, int* Size, int Location);
void free_last_element(struct List* head, int* Size);

void add_first_element(struct List** head, int* Size);
void add_middle_element(struct List* head,  int* Size, int Location);
void add_last_element(struct List* head,  int* Size );

void Sort(struct List* head);

void Recording_List_to_FILE(struct List* head, char* name);
struct List* Creation_New_List_from_File(char* name, int* Size);

void Alphabet(struct List* head, char Symbol);
void Search_Typ(struct List* head, char Symbol);
void Search_Nom(struct List* head, int number);
void Search_Colvo(struct List* head, int number);

void clearStdIn();

#endif
