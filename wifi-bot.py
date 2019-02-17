import curses
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)

FRONT_RIGHT_BACKWARD = 2
FRONT_RIGHT_FORWARD = 3
FRONT_LEFT_BACKWARD = 13
FRONT_LEFT_FORWARD = 17
BACK_RIGHT_BACKWARD = 27
BACK_RIGHT_FORWARD = 22
BACK_LEFT_BACKWARD = 10
BACK_LEFT_FORWARD = 9

GPIO.setup(FRONT_RIGHT_BACKWARD, GPIO.OUT)
GPIO.setup(FRONT_RIGHT_FORWARD, GPIO.OUT)
GPIO.setup(FRONT_LEFT_BACKWARD, GPIO.OUT)
GPIO.setup(FRONT_LEFT_FORWARD, GPIO.OUT)
GPIO.setup(BACK_RIGHT_BACKWARD, GPIO.OUT)
GPIO.setup(BACK_RIGHT_FORWARD, GPIO.OUT)
GPIO.setup(BACK_LEFT_BACKWARD, GPIO.OUT)
GPIO.setup(BACK_LEFT_FORWARD, GPIO.OUT)

def stopMove():
    GPIO.output(2,False)
    GPIO.output(3,False)
    GPIO.output(13,False)
    GPIO.output(17,False)
    GPIO.output(27,False)
    GPIO.output(22,False)
    GPIO.output(10,False)
    GPIO.output(9,False)

def moveForward():
    GPIO.output(FRONT_RIGHT_FORWARD, True)
    GPIO.output(FRONT_LEFT_FORWARD, True)
    GPIO.output(BACK_RIGHT_FORWARD, True)
    GPIO.output(BACK_LEFT_FORWARD, True)

def moveBackward():
    GPIO.output(FRONT_RIGHT_BACKWARD, True)
    GPIO.output(FRONT_LEFT_BACKWARD, True)
    GPIO.output(BACK_RIGHT_BACKWARD, True)
    GPIO.output(BACK_LEFT_BACKWARD, True)

def rotateRight():
    GPIO.output(FRONT_LEFT_FORWARD, True)
	GPIO.output(BACK_LEFT_FORWARD, True)
	GPIO.output(FRONT_RIGHT_BACKWARD, True)
	GPIO.output(BACK_RIGHT_BACKWARD, True)

def rotateLeft():
    GPIO.output(FRONT_RIGHT_FORWARD, True)
	GPIO.output(BACK_RIGHT_FORWARD, True)
	GPIO.output(FRONT_LEFT_BACKWARD, True)
	GPIO.output(BACK_LEFT_BACKWARD, True)



screen = curses.initscr()
curses.noecho()
curses.cbreak()
screen.keypad(True)

try:
    while True:
        char = screen.getch()
        
        if char == ord('q'):
            break
        elif char == curses.KEY_UP:
            moveForward()
            break
        elif char == curses.KEY_DOWN:
            moveBackward()
            break
        elif char == curses.KEY_RIGHT:
            rotateRight()
            break
        elif char == curses.KEY_LEFT:
            rotateLeft()
            break
        elif char == 10:
            stopMove()
            break
finally:
    curses.nocbreak(); screen.keypad(0); curses.echo()
    curses.endwin()
    GPIO.cleanup()


