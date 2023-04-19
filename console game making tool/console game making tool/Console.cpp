#include "Console.h"

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hConsole, coord);
}

void DrawRect(int xPos, int yPos, int width, int height, char TopAndBottomSymbols, char SideSymbols, int curPosX = 0, int curPosY = 0)
{
	gotoxy(xPos, yPos);
	bool f = false;
	for (int t = 0; t < height; t++)
	{
		for (int q = 0; q < width; q++)
		{
			if (t == 0) {
				gotoxy(xPos + q, yPos);
				std::cout << TopAndBottomSymbols;
			}
			else if (t == height - 1)
			{
				if (f == false) {
					q = 0;
					f = true;
				}
				gotoxy(xPos + q, yPos + t);
				std::cout << TopAndBottomSymbols;
			}
			else {
				gotoxy(xPos, yPos + t);
				std::cout << SideSymbols;
				gotoxy(xPos + width - 1, yPos + t);
				std::cout << SideSymbols;
				t++;
			}
		}
	}
	gotoxy(curPosX, curPosY);
}

void DrawRectEx(int xPos, int yPos, int width, int height, char TopSymbols, char BottomSymbols, char LeftSymbols, char RightSymbols, char fillsymbol, int curPosX, int curPosY, bool fill, int fillcolor, int leftcolor, int rightcolor, int topcolor, int bottomcolor) {
	if (fill == false) {
		gotoxy(xPos, yPos);
		bool f = false;
		for (int t = 0; t < height; t++)
		{
			for (int q = 0; q < width; q++)
			{
				if (t == 0) {
					SetColor(topcolor);
					gotoxy(xPos + q, yPos);
					std::cout << TopSymbols;
				}
				else if (t == height - 1)
				{
					if (f == false) {
						q = 0;
						f = true;
					}
					SetColor(bottomcolor);
					gotoxy(xPos + q, yPos + t);
					std::cout << BottomSymbols;
				}
				else {
					SetColor(leftcolor);
					gotoxy(xPos, yPos + t);
					std::cout << LeftSymbols;
					SetColor(rightcolor);
					gotoxy(xPos + width - 1, yPos + t);
					std::cout << RightSymbols;
					t++;
				}
			}
		}
		gotoxy(curPosX, curPosY);
	}
	else if(fill == true) {
		gotoxy(xPos, yPos);
		bool f = false;
		for (int t = 0; t < height; t++)
		{
			for (int q = 0; q < width; q++)
			{
				if (t == 0) {
					SetColor(topcolor);
					gotoxy(xPos + q, yPos);
					std::cout << TopSymbols;
				}
				else if (t == height - 1)
				{
					if (f == false) {
						q = 0;
						f = true;
					}
					SetColor(bottomcolor);
					gotoxy(xPos + q, yPos + t);
					std::cout << BottomSymbols;
				}
				else {
					SetColor(leftcolor);
					gotoxy(xPos, yPos + t);
					std::cout << LeftSymbols;
					SetColor(rightcolor);
					gotoxy(xPos + width - 1, yPos + t);
					std::cout << RightSymbols;
					int g = xPos + width - 1;
					for (int u = xPos + 1; u < g; u++)
					{
						SetColor(fillcolor);
						gotoxy(u, yPos + t);
						std::cout << fillsymbol;
					}
					t++;
				}
			}
		}
		gotoxy(curPosX, curPosY);
	}
}

void Clear()
{
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(hConsole, &screen);
	FillConsoleOutputCharacterA(hConsole, ' ', screen.dwSize.X * screen.dwSize.Y, { 0, 0 }, &written);
	FillConsoleOutputAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, { 0, 0 }, &written);
}

void SetColor(int color)
{
	SetConsoleTextAttribute(hConsole, color);
}

void ChangeFont(int width, int height, const wchar_t* fontname)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = width;                   // Width of each character in the font
	cfi.dwFontSize.Y = height;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, fontname); //or Consolas// Choose your font
	SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}

void DrawTriangle(int xPos, int yPos, int sides, bool flip, char Symbols, int curPosX, int curposY) {
	if (flip == false)
	{
		gotoxy(xPos, yPos);
		std::cout << Symbols;
		int j;
		for (int f = 0; f < sides; f++)
		{
			gotoxy(xPos + f, yPos + f);
			std::cout << Symbols;
			gotoxy(xPos - f, yPos + f);
			std::cout << Symbols;
			j = f;
		}
		for (int g = xPos - j; g < xPos + j; g++)
		{
			gotoxy(g, yPos + j);
			std::cout << Symbols;
		}
	}
	else if (flip == true)
	{
		gotoxy(xPos, yPos);
		std::cout << Symbols;
		int j;
		for (int f = 0; f < sides; f++)
		{
			gotoxy(xPos + f, yPos - f);
			std::cout << Symbols;
			gotoxy(xPos - f, yPos - f);
			std::cout << Symbols;
			j = f;
		}
		for (int g = xPos + j; g > xPos - j; g--)
		{
			gotoxy(g, yPos - j);
			std::cout << Symbols;
		}
	}
	gotoxy(curPosX, curposY);
}
void DrawTriangleEx(int xPos, int yPos, int sides, bool flip, bool fill, char Symbols1, char Symbols2, char Symbols3, char Symbols4, int color1, int color2, int color3, int color4, int curPosX, int curposY) {
	if (flip == false)
	{
		SetColor(color1);
		gotoxy(xPos, yPos);
		std::cout << Symbols1;
		int j;
		for (int f = 0; f < sides; f++)
		{
			if (fill == true) {
				for (int y = xPos - f + 1; y < xPos + f; y++) {
					SetColor(color4);
					gotoxy(y, yPos + f);
					std::cout << Symbols4;
				}
			}
			SetColor(color1);
			gotoxy(xPos + f, yPos + f);
			std::cout << Symbols1;
			gotoxy(xPos - f, yPos + f);
			SetColor(color2);
			std::cout << Symbols2;
			j = f;
		}
		for (int g = xPos - j; g < xPos + j; g++)
		{
			SetColor(color3);
			gotoxy(g, yPos + j);
			std::cout << Symbols3;
		}
	}
	else if (flip == true)
	{
		SetColor(color1);
		gotoxy(xPos, yPos);
		std::cout << Symbols1;
		int j;
		for (int f = 0; f < sides; f++)
		{
			if (fill == true) {
				for (int y = xPos + f - 1; y > xPos - f; y--) {
					SetColor(color4);
					gotoxy(y, yPos - f);
					std::cout << Symbols4;
				}
			}
			SetColor(color1);
			gotoxy(xPos + f, yPos - f);
			std::cout << Symbols1;
			SetColor(color2);
			gotoxy(xPos - f, yPos - f);
			std::cout << Symbols2;
			j = f;
		}
		for (int g = xPos + j; g > xPos - j; g--)
		{
			SetColor(color3);
			gotoxy(g, yPos - j);
			std::cout << Symbols3;
		}
	}
	gotoxy(curPosX, curposY);
}