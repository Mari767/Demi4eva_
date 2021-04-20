#pragma once
#ifndef FUNCTION_H_
#define FUNCTION_H_
#include "Struct.h"

struct List* Creation_List(int *Size);

void Free_List( List*& head);

void Print_List( List* head);

void free_first_element( List*& head, int* Size);
void free_middle_element( List* head, int* Size, int Location);
void free_last_element( List* head, int* Size);

void add_first_element( List*& head, int* Size);
void add_middle_element( List* head,  int* Size, int Location);
void add_last_element( List* head,  int* Size );

void Sort( List* head);

void Recording_List_to_FILE( List* head, char* name);
struct List* Creation_New_List_from_File(char* name, int* Size);

void Alphabet( List* head, char Symbol);
void Search_Typ( List* head, char Symbol);
void Search_Nom( List* head, int number);
void Search_Colvo( List* head, int number);

void clearStdIn();

#endif
