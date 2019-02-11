#pragma once

//RPI3 WIRINGPI PIN NUMBERS FOR MOTORS
const int FRONT_RIGHT_BACKWARD = 8;
const int FRONT_RIGHT_FORWARD = 9;
const int FRONT_LEFT_BACKWARD = 23;
const int FRONT_LEFT_FORWARD = 0;
const int BACK_RIGHT_BACKWARD = 2;
const int BACK_RIGHT_FORWARD = 3;
const int BACK_LEFT_BACKWARD = 12;
const int BACK_LEFT_FORWARD = 13;

//RPI3 WIRINGPI PIN NUMBERS FOR LEDS
const int BLUE = 15;
const int RED = 16;
const int GREEN = 1;

//MOVEMENT FUNCTIONS
int moveForward();
int moveBackward();
int rotateRight();
int rotateLeft();
void stopMove(int);

//LED FUNCTIONS
void toggleLed();

//PROGRAM OPTIONS
bool toggle;
	

//MOVEMENT RETURN VALUES (used for determining last movement call)
const int FORWARD_MOVE = 1;
const int BACKWARD_MOVE = 2;
const int RIGHT_ROTATE = 3;
const int LEFT_ROTATE = 4;
