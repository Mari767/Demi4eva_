#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int main(bool is_menu = true);

int  Update_Ball(CircleShape& ball, Figure& direction);
void Update_Racket(RectangleShape& racket, Figure& direction);

bool Is_Intersection(Figure& ball, Figure& racket);
void Intersection(Figure& ball, Figure& racket);

void Ball_changes_directions_after_hitting_blocks(Figure& ball, Figure& brick);

void Intersection_Ball_With_Bricks(CircleShape& ball, Figure& direction, char** Map_Current_Level, int* Score_by_destroying_bricks, List_Bricks* head);

bool All_Bricks_Destroyed(char** Map_Current_Level, bool* LvL_is_up);

void LvL_Up(char** Map_Current_Level, int LvL = 1);

List_Bricks* Creation_List_Bricks(char** Map_Current_Level);
void Rree_List_Bricks(List_Bricks*& head);

bool Menu(RenderWindow& window, bool player_lose = false);

#endif // !FUNCTIONS_H

