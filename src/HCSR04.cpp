#include "HCSR04.hpp"

namespace HCSR04Sensor{

HCSR04::HCSR04(byte trigger_pin, byte echo_pin) {
	this->_trigger_pin = trigger_pin;
	this->_echo_pin = echo_pin;
	init();
}

void HCSR04::init() {
	pinMode(this->_trigger_pin, INPUT);
	pinMode(this->_echo_pin, OUTPUT);
}

int HCSR04::measureDistance() {
	digitalWrite(this->_trigger_pin, LOW);
	delayMicroseconds(2);

	digitalWrite(this->_trigger_pin, HIGH);
	delayMicroseconds(10);
	digitalWrite(this->_trigger_pin, LOW);
	
	this->_duration = pulseIn(this->_echo_pin, HIGH);
	this->_distance = (this->_duration * 0.034) / 2;

	return this->_distance;
}

}
