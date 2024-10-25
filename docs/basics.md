# Basic usage

Here is an example of how to use the LM35IC library to collect temperature measurements using the LM35D sensor.
Copy this sketch to the Arduino IDE, compile it, and upload it. Make sure your sensor's output pin is connected to pin A0.

If you are using another LM35 sensor, take a look at [this example](https://github.com/MiguelLoureiro98/LM35IC/blob/main/examples/signal_conditioning/signal_conditioning.ino).

```cpp

/*********************************************************************************************
 
This is a very simple example that illustrates how the library can be used to read temperature
values from a sensor. For this sketch, the LM35D sensor was used (this is the default).

Note that this library supports all sensors from the LM35 family.

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

        // Print value to the serial monitor.
        Serial.print("Temperature: ");
        Serial.print(temp);
        Serial.println("º C");

        // Set the current time as the new reference time instant.
        previous_time = current_time;

    }

}

```