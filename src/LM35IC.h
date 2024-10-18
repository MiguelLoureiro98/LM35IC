#ifndef _LM35IC_H_
#define _LM35IC_H_

#include <stdint.h>

namespace LM35{

    // Define units type.
    enum units{Celsius=0, Kelvin, Fahrenheit};

    // Define sensors type.
    enum sensors{LM35, LM35A, LM35CA, LM35C, LM35D=0};

    class LM35IC{

        // Define public methods.
        public:

            LM35IC(uint8_t pin, sensors sensor=LM35D, units unit=Celsius, double Vcc=5.0, uint8_t ADC_bits=10);
            double readTemp();
            double error(double temperature, bool worst_case=false);
            void changeUnits(units unit);

        // Define private methods.
        private:

            double _computeResolution();
            double _computeAccuracy(double temperature, bool worst_case);
            double _Celsius2Kelvin(double temperature_Celsius);
            double _Celsius2Fahrenheit(double temperature_Celsius);

        // Define private attributes.
        private:

            uint8_t _pin;
            units _unit;
            sensors _sensor;
            uint8_t _adc_res;
            double _gain;
            double _offset;
            static constexpr double _sensitivity = 0.01;
            static constexpr double _reference_temperature = 25.0;
            static constexpr double _adc_accuracy = 2.0;
            static constexpr uint8_t _n_sensors = 5;
            static constexpr uint8_t _n_details = 8;
            static constexpr double _sensors[_n_sensors][_n_details] = {{0.0, 100.0, 0.012, 0.6, 0.004, 0.02, 1.5, 0.0067},
                                                                        {-55.0, 150.0, 0.005, 0.4, 0.0032, 0.00625, 1.0, 0.004},
                                                                        {-55.0, 150.0, 0.0025, 0.2, 0.0016, 0.00625, 0.5, 0.004},
                                                                        {-40.0, 110.0, 0.003077, 0.2, 0.002353, 0.0154, 0.5, 0.005882},
                                                                        {-40.0, 110.0, 0.006154, 0.4, 0.004706, 0.0154, 1.0, 0.005882}};
            static constexpr uint8_t _slope_indices[4] = {2, 4, 5, 7};
            static constexpr uint8_t _intercept_indices[2] = {3, 6};
            double _resolution = _computeResolution();

    };
};

#endif