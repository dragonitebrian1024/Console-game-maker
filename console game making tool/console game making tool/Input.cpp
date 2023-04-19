#include "Input.h"

InputManager::InputManager()
{
	ASCIIvalue = NULL;
}

void InputManager::Update()
{
	int entered = _kbhit();
	if(entered != 0)
    	 ASCIIvalue = _getch();

}