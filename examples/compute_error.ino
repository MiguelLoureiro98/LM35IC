/*********************************************************************************************
 
In addition to the sensor's accuracy, a measurement chain contains several other sources of
error, such as measurement resolution or ADC (Analog-to-Digital Converter) noise. To obtain an
estimate of the measurement error, these must also be taken into account.

This sketch shows how the library's computeError() method can be used to compute the
error of a given measurement. This computes the measurement error from the sensor's accuracy 
(which varies with temperature), measurement resolution, and ADC noise (2 LSB for the 
ATMega328P) using the following formula:

ERROR = SENSOR_ACCURACY(temperature) + ADC_NOISE * MEASUREMENT_RESOLUTION

with ADC_NOISE = 2.

Since this method relies on the computeAccuracy() method to compute the sensor's accuracy, the
temperature and a parameter indicating which accuracy curve should be used must be passed as 
arguments. See the "compute_accuracy.ino" example for more details.

Read the sensor's data sheet and the official documentation for more details.

**********************************************************************************************/

#include <stdint.h>
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

        // Compute measurement error.
        double measurement_error = sensor.computeError(temp, false);

        // Print value and its associated error to the serial monitor.
        Serial.print("Temperature: ");
        Serial.print(temp);
        Serial.print(" +/- ");
        Serial.print(measurement_error);
        Serial.println(" ºC");

        // Set the current time as the new reference time instant.
        previous_time = current_time;

    }

}