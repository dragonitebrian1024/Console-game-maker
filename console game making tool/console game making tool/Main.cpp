#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include "Framerate.h"

using namespace std::chrono;

HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hConsole, coord);
}
bool typing = false;
bool clear = false;
int main()
{
	frame_rater<60> fr;
	int k = 1;
	int x, y;
	typing = false;
	std::cout << "enter x:";
	std::cin >> x;
	std::cout << std::endl << "enter y:";
	std::cin >> y;
	std::cout << std::endl;
	while (true)
	{	
		if (typing == false) {
			gotoxy(x, y);
			char p = _getch();
			SetConsoleTextAttribute(hConsole, k);
			if (p == 'a')
				break;
			std::cout << k << "  " << p;

			k++;
			if (k > 255)
				k = 1;
			typing = true;
			Sleep(1000);
			clear = true;
		}
		if(typing == true) {
			if (clear == true) {
				CONSOLE_SCREEN_BUFFER_INFO screen;
				DWORD written;

				GetConsoleScreenBufferInfo(hConsole, &screen);
				FillConsoleOutputCharacterA(hConsole, ' ', screen.dwSize.X * screen.dwSize.Y, { 0, 0 }, &written);
				FillConsoleOutputAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,screen.dwSize.X * screen.dwSize.Y, { 0, 0 }, &written);
			}
			gotoxy(0, 0);
			std::cout << "enter x:";
			std::cin >> x;
			std::cout << std::endl << "enter y:";
			std::cin >> y;
			std::cout << std::endl;
			typing = false;
			clear = false;
		}
		fr.sleep();
	}
	return 0;
}