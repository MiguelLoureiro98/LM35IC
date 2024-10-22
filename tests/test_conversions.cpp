#include <CppUTest/TestHarness.h>
#include <LM35IC.h>

using LM35::LM35IC;

TEST_GROUP(testConversions){

};

TEST(testConversions, testCelsius2Kelvin){

    double zero_Celsius = 0.0;
    double zero_Kelvin = 273.15;
    double ref_Celsius = 25.0;
    double ref_Kelvin = 298.15;
    double threshold = 0.001;

    double zero_Kelvin_from_Celsius = LM35IC::Celsius2Kelvin(zero_Celsius);
    double ref_Kelvin_from_Celsius = LM35IC::Celsius2Kelvin(ref_Celsius);

    DOUBLES_EQUAL(zero_Kelvin, zero_Kelvin_from_Celsius, threshold);
    DOUBLES_EQUAL(ref_Kelvin, ref_Kelvin_from_Celsius, threshold);

};

TEST(testConversions, testCelsius2Fahrenheit){

    double zero_Celsius = 0.0;
    double zero_Fahrenheit = 32.0;
    double ref_Celsius = 25.0;
    double ref_Fahrenheit = 77.0;
    double threshold = 0.001;

    double zero_Fahrenheit_from_Celsius = LM35IC::Celsius2Fahrenheit(zero_Celsius);
    double ref_Fahrenheit_from_Celsius = LM35IC::Celsius2Fahrenheit(ref_Celsius);

    DOUBLES_EQUAL(zero_Fahrenheit, zero_Fahrenheit_from_Celsius, threshold);
    DOUBLES_EQUAL(ref_Fahrenheit, ref_Fahrenheit_from_Celsius, threshold);

};