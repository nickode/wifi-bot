#include <wiringPi.h>
#include <iostream>
#include <thread>
#include <string>
#include "wifi-bot.h"
#include <SFML/Window.hpp>

int moveForward()
{
	digitalWrite(FRONT_RIGHT_FORWARD, HIGH);
	digitalWrite(FRONT_LEFT_FORWARD, HIGH);
	digitalWrite(BACK_RIGHT_FORWARD, HIGH);
	digitalWrite(BACK_LEFT_FORWARD, HIGH);
	
	return FORWARD_MOVE;
}

int moveBackward()
{
	digitalWrite(FRONT_RIGHT_BACKWARD, HIGH);
	digitalWrite(FRONT_LEFT_BACKWARD, HIGH);
	digitalWrite(BACK_RIGHT_BACKWARD, HIGH);
	digitalWrite(BACK_LEFT_BACKWARD, HIGH);
	
	return BACKWARD_MOVE;
}

int rotateRight()
{
	digitalWrite(FRONT_LEFT_FORWARD, HIGH);
	digitalWrite(BACK_LEFT_FORWARD, HIGH);
	digitalWrite(FRONT_RIGHT_BACKWARD, HIGH);
	digitalWrite(BACK_RIGHT_BACKWARD, HIGH);
	
	return RIGHT_ROTATE;
}

int rotateLeft()
{
	digitalWrite(FRONT_RIGHT_FORWARD, HIGH);
	digitalWrite(BACK_RIGHT_FORWARD, HIGH);
	digitalWrite(FRONT_LEFT_BACKWARD, HIGH);
	digitalWrite(BACK_LEFT_BACKWARD, HIGH);
	
	return LEFT_ROTATE;
}

void stopMove(int move_code)
{
	if(move_code == FORWARD_MOVE)
	{
		digitalWrite(FRONT_RIGHT_FORWARD, LOW);
		digitalWrite(FRONT_LEFT_FORWARD, LOW);
		digitalWrite(BACK_RIGHT_FORWARD, LOW);
		digitalWrite(BACK_LEFT_FORWARD, LOW);
	}
	else if(move_code == BACKWARD_MOVE)
	{
		digitalWrite(FRONT_RIGHT_BACKWARD, LOW);
		digitalWrite(FRONT_LEFT_BACKWARD, LOW);
		digitalWrite(BACK_RIGHT_BACKWARD, LOW);
		digitalWrite(BACK_LEFT_BACKWARD, LOW);
	}
	else if(move_code == RIGHT_ROTATE)
	{
		digitalWrite(FRONT_LEFT_FORWARD, LOW);
		digitalWrite(BACK_LEFT_FORWARD, LOW);
		digitalWrite(FRONT_RIGHT_BACKWARD, LOW);
		digitalWrite(BACK_RIGHT_BACKWARD, LOW);
	}
	else if(move_code == LEFT_ROTATE)
	{
		digitalWrite(FRONT_RIGHT_FORWARD, LOW);
		digitalWrite(BACK_RIGHT_FORWARD, LOW);
		digitalWrite(FRONT_LEFT_BACKWARD, LOW);
		digitalWrite(BACK_LEFT_BACKWARD, LOW);
	}
}

int main()
{
	
	using std::cout;
	using std::endl;
	int last_input = -1; //null
	bool exit;
	
	wiringPiSetup();
	
	pinMode(FRONT_RIGHT_FORWARD, OUTPUT);
	pinMode(FRONT_RIGHT_BACKWARD, OUTPUT);
	pinMode(FRONT_LEFT_FORWARD, OUTPUT);
	pinMode(FRONT_LEFT_BACKWARD, OUTPUT);
	pinMode(BACK_RIGHT_BACKWARD, OUTPUT);
	pinMode(BACK_RIGHT_FORWARD, OUTPUT);
	pinMode(BACK_LEFT_FORWARD, OUTPUT);
	pinMode(BACK_LEFT_BACKWARD, OUTPUT);
	
	
	while(!exit)
	{
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			last_input = moveForward();
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			last_input = moveBackward();
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			last_input = rotateRight();
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			last_input = rotateLeft();
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			exit = true;
		}
		else
		{
			stopMove(last_input);
		}
		
		delay(10);
		
	}
	
	cout << "Exiting program" << endl;
	
	return 0;
	
}

