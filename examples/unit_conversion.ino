/*********************************************************************************************
 
By default, the values read from the sensor are given in Celsius. The LM35IC class provides
two methods to convert values to Kelvin and Fahrenheit.

This sketch shows how the Celsius2Kelvin() method can be used to convert temperature values to
Kelvin once they have been read from the sensor. Since this is a static method, it must be
invoked as LM35IC::Celsius2Kelvin(). The temperature in Celsius must be passed as an argument.

To convert values to Fahrenheit, the procedure is identical, but the Celsius2Fahrenheit()
method must be called instead.

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
        
        // Convert the value to Kelvin.
        double tempKelvin = LM35IC::Celsius2Kelvin(temp);

        // Print value to the serial monitor.
        Serial.print("Temperature: ");
        Serial.print(tempKelvin);
        Serial.println(" K");

        // Set the current time as the new reference time instant.
        previous_time = current_time;

    }

}