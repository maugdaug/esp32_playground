#include <Arduino.h>

void setup() {
	Serial.begin(115200);

}

void loop() {
	Serial.print("2nd");
	delay(1000);
}