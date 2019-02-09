#include "pch.h"
#include <iostream>
#include "conio.h"
#include "wifi-bot.h"

using namespace std;

int main()
{
	int input; //ascii code

	while (1) 
	{
		input = _getch();
		switch (input)
		{
			case FORWARD_KEY:
				break;
			case BACKWARD_KEY:  
				break;
			case RIGHT_KEY:
				break;
			case LEFT_KEY: 
				break;
		}
		input = NULL;
		cout << input << endl;

		
	}
}

