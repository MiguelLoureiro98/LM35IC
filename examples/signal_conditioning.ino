/*********************************************************************************************

The Arduino ADC (Analog-to-Digital Converter) can only read voltages ranging from 0 to 5 V.
In cases where the sensor's output voltage does not lie within this limits, a signal 
conditioning circuit becomes a necessity.

At the very least, this circuit must offset the sensor's output voltage so that its lowest 
value corresponds to 0 V. In some cases, this circuit will also amplify or attenuate the 
sensor's output voltage by multiplying it by some gain. Both of these operations affect the 
calculations that must be performed to compute the temperature value from a raw ADC reading.

If a signal conditioning circuit is used, its gain and offset must be specified when 
initialising an LM35IC class instance. These are the 3rd and 4th parameters, respectively,
with the first being the analog input pin and the second being the type of sensor (this 
library supports the LM35_normal, LM35A, LM35CA, LM35C, and LM35D sensors).

WARNING: To run this sketch, two LM35D sensors and one LM35C sensor are required.

**********************************************************************************************/

#include <stdint.h>
#include "LM35IC.h"

using LM35::LM35IC;
using LM35::sensors;

// Set the sampling time and the initial time.
const unsigned long Ts = 5.0 * 1000.0;
unsigned long previous_time = 0.0;

// Define an LM35D sensor instance with a signal conditioning gain of 1 (this is the default).
// According to the data sheet, this will result in an output voltage ranging from 0 to 1 V.
const uint8_t pin_1 = A1;
LM35IC lm35d = LM35IC(pin_1, sensors::LM35D);

// Define an LM35D sensor instance with a signal conditioning gain of 5.
// This means the output voltage will range from 0 to 5 V.
// This way, we can improve the reading's resolution.
const uint8_t pin_2 = A0;
LM35IC lm35d_conditioned = LM35IC(pin_2, sensors::LM35D, 5.0);

// Define an LM35C sensor instance with a signal conditioning offset of 0.4.
// This means the output voltage will range from 0 to 1.5 V.
// For this particular sensor, this is the minimum offset required to read its values using an Arduino.
// This is because the Arduino ADC can only read voltages ranging from 0 to 5 V.
// If the sensor's output signal was left unconditioned, it would range from -0.4 to 1.1 V, and the Arduino
//  ADC would not be able to read it. An offset alone has no effect on the reading's resolution.
const uint8_t pin_3 = A2;
LM35IC lm35c = LM35IC(pin_3, sensors::LM35C, 1.0, 0.4);

void setup() {

    // Set up serial and analog input pins.
    Serial.begin(9600);
    pinMode(pin_1, INPUT);
    pinMode(pin_2, INPUT);
    pinMode(pin_3, INPUT);

}

void loop() {

    // Get the current time.
    unsigned long current_time = millis();

    // Check if enough time has passed (i.e. if the sampling time has been exceeded). If so, collect another sample.
    if(current_time - previous_time >= Ts){

        // Read temperature values using different sensors and get their respective resolution.
        double low_res_reading = lm35d.readTemp();
        double low_res_resolution = lm35d.getResolution();
        double high_res_reading = lm35d_conditioned.readTemp();
        double high_res_resolution = lm35d_conditioned.getResolution();
        double lm35c_reading = lm35c.readTemp();
        double lm35c_resolution = lm35c.getResolution();

        // Print all the relevant information to the serial monitor.
        Serial.print("Unconditioned LM35D temperature: ");
        Serial.print(low_res_reading);
        Serial.print(" ºC   Resolution: ");
        Serial.print(low_res_resolution);
        Serial.println(" ºC");
        Serial.print("Conditioned LM35D temperature: ");
        Serial.print(high_res_reading);
        Serial.print(" ºC   Resolution: ");
        Serial.print(high_res_resolution);
        Serial.println(" ºC");
        Serial.print("LM35C with offset temperature: ");
        Serial.print(lm35c_reading);
        Serial.print(" ºC   Resolution: ");
        Serial.print(lm35c_resolution);
        Serial.println(" ºC");

        // Set the current time as the new reference time instant.
        previous_time = current_time;

    }

}