#ifndef Buttons_h
#define Buttons_h

#include "Arduino.h"
class Buttons{
	public:
	Buttons(int pin);
	
	boolean readUP();
	boolean readDown();	
	boolean oneRead();
	boolean timerRead(unsigned long millisec);
	boolean toggle();
	 
	
	private:
	int _pin;
	unsigned long lastMillis;
	boolean temp;
	boolean tempToggle;
	boolean tempReadUP;
};

#endif