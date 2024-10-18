#include "LM35IC.h"
#include <math.h>

namespace LM35{

    LM35IC::LM35IC(uint8_t pin, sensors sensor, units unit, double Vcc, uint8_t ADC_bits): 
        _pin(pin), _sensor(sensor), _unit(unit), _adc_res(Vcc / pow(base, ADC_bits)){ 

        };     

}