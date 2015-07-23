#ifndef Buttons_h
#define Buttons_h

#include "Arduino.h"
class Buttons{
	public:
	Buttons(int pin);
	
	boolean read();
	boolean oneRead();
	boolean timerRead(unsigned long millisec);
	
	private:
	int _pin;
	unsigned long lastMillis;
	boolean temp;

	
};

#endif