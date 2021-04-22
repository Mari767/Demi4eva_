#pragma once
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include "Struct.h"

void  Creation_List(int* Size, List*& head, List*& tail);

void Free_List(List*& head);

void Print_List(List* head, List* tail, List* edge);

void free_first_element(List*& head, int* Size);
void free_middle_element(List* head, int* Size, int Location);
void free_last_element(List*& head, int* Size);

void add_first_element(List*& head, int* Size);
void add_middle_element(List* head, int* Size, int Location);
void add_last_element(List* head, int* Size);

void Sort(List* head);

void Recording_List_to_FILE(List* head, char* name);
void Creation_New_List_from_File(char* name, int* Size, List*& head, List*& tail);

void Alphabet(List* head, char Symbol, List* tail, List* edge);
void Search_Typ(List* head, char Symbol, List* tail, List* edge);
void Search_Nom(List* head, int number, List* tail, List* edge);
void Search_Colvo(List* head, int number, List* tail, List* edge);

void clearStdIn();

#endif

