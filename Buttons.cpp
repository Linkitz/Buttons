#include <Buttons.h>
#include "Arduino.h"

Buttons::Buttons(int pin){
	pinMode(pin,INPUT);
	_pin = pin;	
}

boolean Buttons::readUP(){
	
	if(!tempReadUP && digitalRead(_pin))tempReadUP = true;		
	else if(tempReadUP && !digitalRead(_pin)){
	tempReadUP = false;
	return true;		
	}	
	return false;	
}

boolean Buttons::readDown(){
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

boolean Buttons::toggle(){
	if(oneRead()) tempToggle=!tempToggle;
	return tempToggle;
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