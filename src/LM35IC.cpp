#include "LM35IC.h"
#include <math.h>

namespace LM35{

    LM35IC::LM35IC(uint8_t pin, sensors sensor, double sensitivity, units unit, double Vcc, uint8_t ADC_bits): 
        _pin(pin), _sensor(sensor), _sensitivity(sensitivity), _unit(unit), _Vcc(Vcc), _adc_res(Vcc / pow(base, ADC_bits)){ 

        };     

}