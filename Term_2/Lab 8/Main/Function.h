#pragma once
#ifndef FUNCTION_H_
#define FUNCTION_H_
#include "Struct.h"

//void Screen(char* name, information vedom, int* Size);
//void Add_to_Start(char* name, information vedom, int* Size_file_1, int add_to_start);
//void Add_to_End(char* name, information vedom, int Add_elements);
//void Print_One_Note(char* name, information vedom, int Location);
//void Print(char* name, information vedom, int* Size);

struct List* Creation_List(int *Size);
void Free_List(struct List** head);
void clearStdIn();
void Print_List(struct List* head);
void Free_List(struct List** head);
void free_first_element(struct List** head, int* Size);
void free_middle_element(struct List* head, int* Size, int Location);
void free_last_element(struct List* head, int* Size);
void add_first_element(struct List** head, int* Size);
void add_middle_element(struct List* head, int* Size, int Location);
void add_last_element(struct List* head, int* Size);
void Recording_List_to_FILE(struct List* head, char* name);


#endif
