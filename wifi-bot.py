import curses
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)

# GPIO.setup(,GPIO.OUT)
# GPIO.setup(,GPIO.OUT)
# GPIO.setup(,GPIO.OUT)
# GPIO.setup(,GPIO.OUT)
# GPIO.setup(,GPIO.OUT)
# GPIO.setup(,GPIO.OUT)
# GPIO.setup(,GPIO.OUT)
# GPIO.setup(,GPIO.OUT)

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
            break
        elif char == curses.KEY_DOWN:
            break
        elif char == curses.KEY_RIGHT:
            break
        elif char == curses.KEY_LEFT:
            break
        elif char == 10:
            break
finally:
    curses.nocbreak(); screen.keypad(0); curses.echo()
    curses.endwin()
    GPIO.cleanup()


