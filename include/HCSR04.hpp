#ifndef HCSR04_SENSOR
#define HCSR04_SENSOR

#include "Arduino.h"

class HCSR04{
	
	private:
		byte _trigger_pin;
		byte _echo_pin;
		int _distance;
		long _duration;
	
	public:
		HCSR04(byte trigger_pin, byte echo_pin);
		void init();
		int measureDistance();
};

#endif
