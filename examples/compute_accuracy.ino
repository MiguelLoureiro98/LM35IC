/*********************************************************************************************
 
Sensors have an associated accuracy. According to the data sheet, the accuracy of the LM35
family of sensors varies somewhat significantly with the temperature.

This sketch shows how the library's computeAccuracy() method can be used to compute the
accuracy of a given measurement. Two curves are provided by the data sheet: the typical 
accuracy curve, and the limit accuracy curve. Therefore, in addition to the temperature, 
the computeAccuracy() method receives a second argument. If this is set to false, the typical
accuracy curve will be used to compute the accuracy. Otherwise, the limit curve will be used.

Note that the accuracy curves differ from one sensor to another. 

Read the official documentation for more details.

**********************************************************************************************/

#include "LM35IC.h"

using LM35::LM35IC;

// Set the sampling time and the initial time.
const unsigned long Ts = 5.0 * 1000.0;
unsigned long previous_time = 0.0;

// Define the input pin and create a sensor instance.
const uint8_t pin = A0;
LM35IC sensor = LM35IC(pin);

void setup() {

    // Set up serial and analog input pin.
    Serial.begin(9600);
    pinMode(pin, INPUT);

}

void loop() {

    // Get the current time.
    unsigned long current_time = millis();

    // Check if enough time has passed (i.e. if the sampling time has been exceeded). If so, collect another sample.
    if(current_time - previous_time >= Ts){

        // Read temperature value.
        double temp = sensor.readTemp();

        // Compute the measurement's accuracy.
        double measurement_accuracy = sensor.computeAccuracy(temp, false);

        // Print value to the serial monitor.
        Serial.print("Temperature: ");
        Serial.print(temp);
        Serial.print(" +/- ");
        Serial.print(measurement_accuracy);
        Serial.println(" ºC");

        // Set the current time as the new reference time instant.
        previous_time = current_time;

    }

}