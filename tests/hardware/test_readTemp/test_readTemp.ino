//#include "../../../../../../../../../../Desktop/Projects/Repos/LM35IC/src/LM35IC.h"
#include "LM35IC.h"

using LM35::LM35IC;

const unsigned long Ts = 5.0 * 1000.0;
unsigned long previous_time = 0.0;
const uint8_t pin = A0;
LM35IC sensor = LM35IC(pin, LM35::sensors::LM35D, 1.0, 0.0, 3.3);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(pin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long current_time = millis();

  if(current_time - previous_time >= Ts){

    double temp = sensor.readTemp();

    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println("º C");

    previous_time = current_time;

  }

}
