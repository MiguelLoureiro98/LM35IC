#include "LM35IC.h"
#include <math.h>

namespace LM35{

    LM35IC::LM35IC(uint8_t pin, sensors sensor, units unit, double Vcc, uint8_t ADC_bits): 
        _pin(pin), _sensor(sensor), _unit(unit), _adc_res(Vcc / pow(2.0, static_cast<double>(ADC_bits))){ 

        };     

    double LM35IC::readTemp(){

        double adc_reading = 0.0;

        return 1.0 / _sensitivity * (1.0 / _gain * adc_reading * _adc_res + _offset);

    };

    double LM35IC::error(double temperature, bool worst_case){

        return _computeAccuracy(temperature, worst_case) + _adc_accuracy * _resolution;

    };

    void LM35IC::changeUnits(units unit){

        _unit = unit;

    };

    double LM35IC::_computeAccuracy(double temperature, bool worst_case){

        const bool above_reference_temperature = temperature < _reference_temperature ? false : true;
        const int intercept_index = _intercept_indices[worst_case];
        const int slope_index = _slope_indices[2 * worst_case + above_reference_temperature];

        return _sensors[_sensor][slope_index] * temperature + _sensors[_sensor][intercept_index]; 

    };

    double LM35IC::_computeResolution(){

        double sensor_range = _sensors[_sensor][1] - _sensors[_sensor][0];

        return (sensor_range) / (1.0 / _adc_res * _gain * _sensitivity * (sensor_range));

    };

    double LM35IC::_Celsius2Kelvin(double temperature_Celsius){

        return temperature_Celsius + 273.15;

    };

    double LM35IC::_Celsius2Fahrenheit(double temperature_Celsius){

        return 9.0 / 5.0 * temperature_Celsius + 32.0;

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