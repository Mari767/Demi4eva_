#pragma once
#ifndef FUNCTION_H_
#define FUNCTION_H_
#include "Struct.h"

int Screen(char* name, information vedom);
void Rand(char* name, information vedom);
void Add_to_Start(char* name, information vedom, int Size_file_1, int add_to_start);
void Add_to_End(char* name, information vedom, int Add_elements);   
void Print_One_Note(char* name, information vedom, int Location);
void Print(char* name, information vedom, int Size);

#endif
