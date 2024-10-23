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

#ifndef _LM35IC_H_
#define _LM35IC_H_

#include <stdint.h>

namespace LM35{

    // Define sensors type.
    enum sensors{LM35_normal, LM35A, LM35CA, LM35C, LM35D};

    class LM35IC{

        // Define public methods.
        public:

            LM35IC(uint8_t pin, sensors sensor=LM35D, double gain=1.0, double offset=0.0, double Vcc=5.0, uint8_t ADC_bits=10);
            double readTemp() const;
            double computeError(double temperature, bool worst_case=false) const;
            double getResolution() const;
            double computeAccuracy(double temperature, bool worst_case=false) const;
            static double Celsius2Kelvin(double temperature_Celsius);
            static double Celsius2Fahrenheit(double temperature_Celsius);

        // Define private methods.
        private:

            double _computeResolution() const;

        // Define private attributes.
        private:

            uint8_t _pin;
            sensors _sensor;
            double _gain;
            double _offset;
            double _adc_res;
            static constexpr double _sensitivity = 0.01;
            static constexpr double _reference_temperature = 25.0;
            static constexpr double _adc_accuracy = 2.0;
            static constexpr uint8_t _n_sensors = 5;
            static constexpr uint8_t _n_details = 8;
            static constexpr double _sensors[_n_sensors][_n_details] = {{-55.0, 150.0, 0.005, 0.4, 0.0032, 0.00625, 1.0, 0.004},
                                                                        {-55.0, 150.0, 0.0025, 0.2, 0.0016, 0.00625, 0.5, 0.004},
                                                                        {-40.0, 110.0, 0.003077, 0.2, 0.002353, 0.0154, 0.5, 0.005882},
                                                                        {-40.0, 110.0, 0.006154, 0.4, 0.004706, 0.0154, 1.0, 0.005882},
                                                                        {0.0, 100.0, 0.012, 0.6, 0.004, 0.02, 1.5, 0.0067}};
            static constexpr uint8_t _slope_indices[4] = {2, 4, 5, 7};
            static constexpr uint8_t _intercept_indices[2] = {3, 6};
            const double _resolution = _computeResolution();

    };
};

#endif