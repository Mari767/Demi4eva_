#pragma once
#ifndef DECLARATION_H
#define DECLARATION_H
#define _CRT_SECURE_NO_WARNINGS

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

#define Window_Width  780
#define Window_Height 600
#define Playing_Field_Width  780

#define Ball_Radius 15.f
#define Ball_Speed 5.f

#define Racket_Width  75.f
#define Racket_Height 18.f
#define Racket_Speed  10.f

#define Brick_Width 60.f
#define Brick_Height 26.f

#define Height_Map  24
#define Width_Map   14


#define  WHITE  setTextureRect(IntRect(320,   10, Brick_Width, Brick_Height)) 
#define  PINK   setTextureRect(IntRect(310,   90, Brick_Width, Brick_Height)) 
#define  PURPUR setTextureRect(IntRect(310,  180, Brick_Width, Brick_Height)) 
#define  GREEN  setTextureRect(IntRect(310,  270, Brick_Width, Brick_Height))  
#define  SALAT  setTextureRect(IntRect(310,  350, Brick_Width, Brick_Height)) 
#define  GREY   setTextureRect(IntRect(310,  440, Brick_Width, Brick_Height)) 

struct Figure {
	float x, y;
	float left, right, top, bottom;
};

struct List_Bricks {
	char color;
	int colvo_touch;
	int score;
	int number;
	struct List_Bricks* next;
};

#endif