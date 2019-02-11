#include <wiringPi.h>
#include <softPwm.h>
#include <iostream>
#include <thread>
#include "wifi-bot.h"
#include <SFML/Window/Keyboard.hpp>

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

void toggleLed()
{
	softPwmWrite(RED, 255); //start red
	softPwmWrite(GREEN, 0);
	softPwmWrite(BLUE, 0);
	
	int j = 0; //second iterator for changing multiple colors in same loop
	
	while(toggle){
	
		for(int i = 0; i < 255; i++) //red -> orange -> yellow
		{
			softPwmWrite(GREEN, i);
			delay(5);
		}
		
		for(int i = 255; i > 0; i--) //yellow -> green
		{
			softPwmWrite(RED, i);
			delay(5);
		}
		
		for(int i = 255; i > 0; i--) //green -> blue
		{
			softPwmWrite(GREEN, i);
			delay(5);
			
		}
		for(int i = 0; i < 255; i++)
		{
			softPwmWrite(BLUE, ++j);
			delay(5);
		}
		
		for(int i = 0; i < 75; i++) //blue -> 80% indigo
		{
			
			softPwmWrite(RED, i);
			delay(5);
		}
		
		for(int i = 0; i < 75; i++)
		{
			softPwmWrite(BLUE, --j);
			delay(5);
		}
		
		for(int i = j; i > 130; i--) //80% indigo -> 100% indigo
		{
			softPwmWrite(BLUE, i);
			delay(5);
		}
		
		j = 130;
		
		for(int i = 75; i < 148; i++)
		{
			softPwmWrite(RED, i);
			delay(5);
			
		}
		
		for(int i = 75; i < 148; i++)
		{
			softPwmWrite(BLUE, ++j);
			delay(5);
		}
		
		for(int i = 203; i < 211; i++) //indigo -> violet
		{
			softPwmWrite(BLUE, i);
			delay(5);
		}
		
		j = 211;
		
		for(int i = 148; i < 255; i++)
		{
			softPwmWrite(RED, i);
			delay(5);
			
		}
		
		for(int i = 148; i < 255; i++)
		{
			softPwmWrite(BLUE, --j);
			delay(5);
		}
		
		for(int i = 104; i > 0; i--)
		{
			softPwmWrite(BLUE, i);
			delay(5);
		}
		
		j = 0;
	}
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
	
	wiringPiSetup();
	
	pinMode(FRONT_RIGHT_FORWARD, OUTPUT);
	pinMode(FRONT_RIGHT_BACKWARD, OUTPUT);
	pinMode(FRONT_LEFT_FORWARD, OUTPUT);
	pinMode(FRONT_LEFT_BACKWARD, OUTPUT);
	pinMode(BACK_RIGHT_BACKWARD, OUTPUT);
	pinMode(BACK_RIGHT_FORWARD, OUTPUT);
	pinMode(BACK_LEFT_FORWARD, OUTPUT);
	pinMode(BACK_LEFT_BACKWARD, OUTPUT);
	
	softPwmCreate(RED, 0, 255);
	softPwmCreate(GREEN, 0, 255);
	softPwmCreate(BLUE, 0, 255);
	
	
	using std::cout;
	using std::endl;
	int last_input = -1; //null
	toggle = true;
	std::thread led(toggleLed);
	bool exit = false;
	
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
	}
	
	toggle = false;
	cout << "Exiting program" << endl;
	led.join();
	softPwmWrite(RED, LOW);
	softPwmWrite(BLUE, LOW);
	softPwmWrite(GREEN, LOW);
	
	return 0;
	
}

