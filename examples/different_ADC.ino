/*********************************************************************************************

Different Arduino boards may have: 1) different operating voltages; 2) Analog-to-Digital
Converters (ADC) with a different number of bits.

These parameters determine the ADC's resolution, thus affecting the calculations that must be
performed to convert the raw ADC reading to a temperature value.

The LM35IC class assumes that the board it is running on operates at a 5 V voltage and has a
10-bit ADC. If your board does not meet these specifications, the board's parameters should be
passed to the class (5th and 6th parameter, respectively). Otherwise, the temperature values
read from the sensor will be wrong.

**********************************************************************************************/

#include <stdint.h>
#include "LM35IC.h"

using LM35::LM35IC;
using LM35::sensors;

// Set the sampling time and the initial time.
const unsigned long Ts = 5.0 * 1000.0;
unsigned long previous_time = 0.0;

// Define an LM35D sensor instance for an Arduino board with an operating voltage of 3.3 V 
//  (the class default is 5 V) and a 12-bit ADC (the class default is 10 bits).
// Make sure the parameters you pass to the class constructor match your board's specifications.
// Otherwise, your readings will be wrong.
const uint8_t pin_1 = A1;
LM35IC lm35d = LM35IC(pin_1, sensors::LM35D, 1.0, 0.0, 3.3, 12);

void setup() {

    // Set up serial and analog input pins.
    Serial.begin(9600);
    pinMode(pin_1, INPUT);

}

void loop() {

    // Get the current time.
    unsigned long current_time = millis();

    // Check if enough time has passed (i.e. if the sampling time has been exceeded). If so, collect another sample.
    if(current_time - previous_time >= Ts){

        // Read temperature values using different sensors and get their respective resolution.
        double low_res_reading = lm35d.readTemp();

        // Print all the relevant information to the serial monitor.
        Serial.print("Unconditioned LM35D temperature: ");
        Serial.print(low_res_reading);
        Serial.println(" ºC");

        // Set the current time as the new reference time instant.
        previous_time = current_time;

    }

}