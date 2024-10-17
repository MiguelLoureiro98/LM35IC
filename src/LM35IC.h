#ifndef _LM35IC_H_
#define _LM35IC_H_

#include <stdint.h>

namespace LM35{

    constexpr uint8_t base = 2;
    constexpr uint8_t n_sensors = 5;
    constexpr uint8_t n_details = 8;

    // Define units type.
    enum units{Celcius=0, Kelvin, Fahrenheit};

    // Define sensors type.
    enum sensors{LM35, LM35A, LM35CA, LM35C, LM35D=0};

    class LM35IC{

        // Define private attributes.
        private:

            uint8_t _pin;
            units _unit;
            sensors _sensor;
            double _sensitivity;
            double _sensors[n_sensors][n_details] = {{0.0, 100.0, 0.012, 0.6, 0.004, 0.02, 1.5, 0.0067},
                                                    {-55.0, 150.0, 0.005, 0.4, 0.0032, 0.00625, 1.0, 0.004},
                                                    {-55.0, 150.0, 0.0025, 0.2, 0.0016, 0.00625, 0.5, 0.004},
                                                    {-40.0, 110.0, 0.003077, 0.2, 0.002353, 0.0154, 0.5, 0.005882},
                                                    {-40.0, 110.0, 0.006154, 0.4, 0.004706, 0.0154, 1.0, 0.005882}};
            double _Vcc;
            uint8_t _adc_res;

        public:

            LM35IC(uint8_t pin, sensors sensor=LM35D, double sensitivity=0.01, units unit=Celcius, double Vcc=5.0, uint8_t ADC_bits=10);
            double readTemp();
            void changeUnits(units unit);
            double accuracy(double reading);
            double resolution();

    };
};

#endif