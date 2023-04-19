#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include "Color.h"

void gotoxy(int x, int y);
void DrawRect(int xPos, int yPos, int width, int height, char TopAndBottomSymbols, char SideSymbols, int curPosX, int curPosY);
void DrawRectEx(int xPos, int yPos, int width, int height, char TopSymbols, char BottomSymbols, char LeftSymbols, char RightSymbols, char fillsymbol, int curPosX, int curPosY, bool fill, int fillcolor, int leftcolor, int rightcolor, int topcolor, int bottomcolor);
void DrawTriangle(int xPos, int yPos, int sides, bool flip, char Symbols, int curPosX, int curposY);
void DrawTriangleEx(int xPos, int yPos, int sides, bool flip, bool fill, char Symbols1,char Symbols2, char Symbols3, char Symbols4 ,int color1, int color2, int color3, int color4, int curPosX, int curposY);//tomorrow practice some art and also do collision detection
void Clear();
void ChangeFont(int width, int height, const wchar_t* fontname);
static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void SetColor(int color);