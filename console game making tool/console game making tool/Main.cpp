#include "Console.h"
#include "Framerate.h"
#include <cwchar>
#include "Input.h"
#include "Audio.h"
#include <vector>
#include <thread>

using namespace std::chrono;
InputManager* input = new InputManager();
int ballxpos = 40;
int ballypos = 20;
int player1xpos = 2;
int player1ypos = 23;
bool reversed = false;
void clear()
{
	Sleep(333);
	Clear();
}
void ActualUpdateEvents()
{
	input->Update();
	gotoxy(player1xpos, player1ypos);
	std::cout << "0";
	gotoxy(player1xpos, player1ypos + 1);
	std::cout << "0";
	gotoxy(player1xpos, player1ypos + 2);
	std::cout << "0";
	gotoxy(player1xpos, player1ypos + 3);
	std::cout << "0";
	gotoxy(player1xpos, player1ypos + 4);
	std::cout << "0";
	gotoxy(ballxpos, ballypos);
	SetColor(GREEN);
	std::cout << "*";
	if (reversed == false)
		ballxpos -= 2;
	else
		ballxpos += 1;
	if (input->GetInputValue() == wChar) {
		player1ypos -= 1;
		input->reset();
	}
	else if (input->GetInputValue() == sChar) {
		player1ypos += 1;
		input->reset();
	}
	if (ballxpos == player1xpos + 1 && ballypos == player1ypos || ballxpos == player1xpos + 1 && ballypos == player1ypos + 1 || ballxpos == player1xpos + 1 && ballypos == player1ypos + 2 || ballxpos == player1xpos + 1 && ballypos == player1ypos + 3 || ballxpos == player1xpos + 1 && ballypos == player1ypos + 4)
		reversed = true;
	else if (ballxpos == player1xpos && ballypos == player1ypos || ballxpos == player1xpos && ballypos == player1ypos + 1 || ballxpos == player1xpos && ballypos == player1ypos + 2 || ballxpos == player1xpos && ballypos == player1ypos + 3 || ballxpos == player1xpos && ballypos == player1ypos + 4)
		reversed = true;
	gotoxy(0, 0);

}
int main(int argc, const char* argv[])
{
	/*std::vector<std::thread> threads;
	threads.push_back(std::thread(PlayASound));
	threads.push_back(std::thread(PlayAnotherSound));
	for (auto& thread : threads) {
		thread.join();
	}*/
	frame_rater<60> fr;
	ChangeFont(0, 14, L"Consolas");
	
	int k = 1;
	int x, y;
	while (true)
	{	
		/*if (typing == false) {
			gotoxy(x, y);
			SetColor(k);
			std::cout << "Gorp";

			k++;
			if (k > 255)
				k = 1;
			typing = true;
			Sleep(1000);
			clear = true;
		}
		if(typing == true) {
			if (clear == true) {
				Clear();
			}
			input->Update();
			if (input->GetInputValue() == QChar)
			{
				gotoxy(0, 0);

				DrawRectEx(5, 8, 12, 9, '_', '-', '|', '|', ' ', 0, 0, true, RED WITHREDBACKGROUND, BLUE, BLUE, BLUE, BLUE);
				DrawTriangleEx(50, 30, 25, true,true, '%','#', '$','@', RED WITHGREYBACKGROUND, BLUE WITHGREYBACKGROUND, GREEN WITHGREYBACKGROUND,WHITE WITHGREYBACKGROUND, 0, 0);
				std::cout << "enter x:";
				std::cin >> x;
				std::cout << std::endl << "enter y:";
				std::cin >> y;
				std::cout << std::endl;
				typing = false;
				clear = false;
				input->reset();
			}
		}*/
		std::vector<std::thread> threads;
		threads.push_back(std::thread(clear));
		threads.push_back(std::thread(ActualUpdateEvents));
		for (auto& thread : threads) {
			thread.join();
		}
		fr.sleep();
	}
	return 0;
}
