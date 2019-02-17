#pragma once

//RPI3 WIRINGPI PIN NUMBERS FOR MOTORS
const int FRONT_RIGHT_BACKWARD = 8; //2
const int FRONT_RIGHT_FORWARD = 9; //3
const int FRONT_LEFT_BACKWARD = 23; //13
const int FRONT_LEFT_FORWARD = 0; //17
const int BACK_RIGHT_BACKWARD = 2; //27
const int BACK_RIGHT_FORWARD = 3; //22
const int BACK_LEFT_BACKWARD = 12; //10
const int BACK_LEFT_FORWARD = 13; //9

//MOVEMENT FUNCTIONS
int moveForward();
int moveBackward();
int rotateRight();
int rotateLeft();
void stopMove(int);

//MOVEMENT RETURN VALUES (used for determining last movement call)
const int FORWARD_MOVE = 1;
const int BACKWARD_MOVE = 2;
const int RIGHT_ROTATE = 3;
const int LEFT_ROTATE = 4;
