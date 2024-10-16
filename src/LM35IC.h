#ifndef _LM35IC_H_
#define _LM35IC_H_

#include <stdint.h>

enum units{Celcius=0, Kelvin, Fahrenheit};

class LM35IC {

    public:

    // Define private attributes.
    private:

        uint8_t _pin;
        units _unit;
        double _Vcc;
        uint8_t _adc_bits;
        double _Vout_min;
        double _Vout_max;
        double _sensor_sensitivity;

};

#endif