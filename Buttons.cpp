#include <Buttons.h>
#include "Arduino.h"

Buttons::Buttons(int pin){
	pinMode(pin,INPUT);
	_pin = pin;	
}

boolean Buttons::read(){
	return digitalRead(_pin);	
}

boolean Buttons::oneRead(){
	boolean btnState=digitalRead(_pin);

	if (!temp && btnState){
	temp = true;
	return true;	
	}else{
	if(!btnState) temp = false;	
	return false;		
	}
	
}

boolean Buttons::timerRead(unsigned long millisec){
	if (digitalRead(_pin)){
	if(lastMillis>millis())lastMillis=millis();
	
	if(millis()-lastMillis>millisec){
	lastMillis = millis();
	return true;
	}else{
	return false;
		
	}	
		
	}

	
	
}