#ifndef MY_ULTRASONIC_SENSOR
#define MY_ULTRASONIC_SENSOR

#include "Arduino.h"

class UltrasonicSensor {
	
	private:
		byte trigger_pin;
		byte echo_pin;
		int distance;
		long duration;
	
	public:
		UltrasonicSensor(byte _trigger_pin, byte _echo_pin);
		void init();
		int measureDistance();
};

#endif
