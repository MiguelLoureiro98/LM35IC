/******************************************************************************
MIT License

Copyright (c) 2024 Miguel Santos Loureiro

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.   
******************************************************************************/

#include "LM35IC.h"
#include <math.h>
#include <Arduino.h>

#define TESTING 1

#if TESTING != 0
#define ADC_reading(x) 0.0
#else
#define ADC_reading(x) analogRead(x)
#endif

namespace LM35{

    LM35IC::LM35IC(uint8_t pin, sensors sensor, double gain, double offset, double Vcc, uint8_t ADC_bits): 
        _pin(pin), _sensor(sensor), _gain(gain), _offset(offset), _adc_res(Vcc / pow(2.0, static_cast<double>(ADC_bits))){ 

        };     

    double LM35IC::readTemp() const {

        const double adc_reading = analogRead(_pin); //ADC_reading(_pin);

        return 1.0 / _sensitivity * (1.0 / _gain * adc_reading * _adc_res + _offset);

    };

    double LM35IC::computeError(double temperature, bool worst_case) const {

        return computeAccuracy(temperature, worst_case) + _adc_accuracy * _resolution;

    };

    double LM35IC::computeAccuracy(double temperature, bool worst_case) const {

        const bool above_reference_temperature = temperature < _reference_temperature ? false : true;
        const int intercept_index = _intercept_indices[worst_case];
        const int slope_index = _slope_indices[2 * worst_case + above_reference_temperature];

        return _sensors[_sensor][slope_index] * abs(temperature - _reference_temperature) + _sensors[_sensor][intercept_index]; 

    };

    double LM35IC::getResolution() const {

        return this->_resolution;

    };

    double LM35IC::Celsius2Kelvin(double temperature_Celsius){

        return temperature_Celsius + 273.15;

    };

    double LM35IC::Celsius2Fahrenheit(double temperature_Celsius){

        return 9.0 / 5.0 * temperature_Celsius + 32.0;

    };

    double LM35IC::_computeResolution() const {

        const double sensor_range = _sensors[_sensor][1] - _sensors[_sensor][0];

        return (sensor_range) / trunc((1.0 / _adc_res * _gain * _sensitivity * (sensor_range)));

    };

    constexpr double LM35IC::_sensitivity;
    constexpr double LM35IC::_reference_temperature;
    constexpr double LM35IC::_adc_accuracy;
    constexpr uint8_t LM35IC::_n_sensors;
    constexpr uint8_t LM35IC::_n_details;
    constexpr double LM35IC::_sensors[_n_sensors][_n_details];
    constexpr uint8_t LM35IC::_slope_indices[4];
    constexpr uint8_t LM35IC::_intercept_indices[2];

};