#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(byte _trigger_pin, byte _echo_pin) {
	this->trigger_pin = _trigger_pin;
	this->echo_pin = _echo_pin;
	init();
}

void UltrasonicSensor::init() {
	pinMode(this->trigger_pin, INPUT);
	pinMode(this->echo_pin, OUTPUT);
}

int UltrasonicSensor::measureDistance() {
	digitalWrite(this->trigger_pin, LOW);
	delayMicroseconds(2);

	digitalWrite(this->trigger_pin, HIGH);
	delayMicroseconds(10);
	digitalWrite(this->trigger_pin, LOW);
	
	this->duration = pulseIn(this->echo_pin, HIGH);
	this->distance = (this->duration * 0.034) / 2;

	return this->distance;
}
