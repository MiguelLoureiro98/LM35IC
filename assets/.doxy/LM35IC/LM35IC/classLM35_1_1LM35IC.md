

# Class LM35::LM35IC



[**ClassList**](annotated.md) **>** [**LM35**](namespaceLM35.md) **>** [**LM35IC**](classLM35_1_1LM35IC.md)



[_**LM35**_](namespaceLM35.md) _sensor class._[More...](#detailed-description)

* `#include <LM35IC.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**LM35IC**](#function-lm35ic) (uint8\_t pin, [**sensors**](namespaceLM35.md#enum-sensors) sensor=LM35D, double gain=1.0, double offset=0.0, double Vcc=5.0, uint8\_t ADC\_bits=10) <br>_Class constructor._  |
|  double | [**computeAccuracy**](#function-computeaccuracy) (double temperature, bool worst\_case=false) const<br>_Compute an estimate of the sensor's accuracy for a given estimate._  |
|  double | [**computeError**](#function-computeerror) (double temperature, bool worst\_case=false) const<br>_Compute an error estimate for a given measurement._  |
|  double | [**getResolution**](#function-getresolution) () const<br>_Get the measurements' resolution._  |
|  double | [**readTemp**](#function-readtemp) () const<br>_Collect a sensor reading and convert it to a temperature value._  |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  double | [**Celsius2Fahrenheit**](#function-celsius2fahrenheit) (double temperature\_Celsius) <br>_Convert a temperature value from Celsius to Fahrenheit._  |
|  double | [**Celsius2Kelvin**](#function-celsius2kelvin) (double temperature\_Celsius) <br>_Convert a temperature value from Celsius to Kelvin._  |


























## Detailed Description


This class implements the operations associated with the sensor. These include collecting a sample, unit conversion, and computing measurement error, sensor accuracy and measurement chain resolution. 


    
## Public Functions Documentation




### function LM35IC 

_Class constructor._ 
```C++
LM35::LM35IC::LM35IC (
    uint8_t pin,
    sensors sensor=LM35D,
    double gain=1.0,
    double offset=0.0,
    double Vcc=5.0,
    uint8_t ADC_bits=10
) 
```





**Parameters:**


* `pin` Analog input pin connected to the sensor's output. 
* `sensor` Sensor type. 
* `gain` Signal conditioning circuit gain. 
* `offset` Signal conditioning circuit offset. 
* `Vcc` Arduino board operating voltage. 
* `ADC_bits` Number of bits of the Analog-to-Digital Converter. 




        

<hr>



### function computeAccuracy 

_Compute an estimate of the sensor's accuracy for a given estimate._ 
```C++
double LM35::LM35IC::computeAccuracy (
    double temperature,
    bool worst_case=false
) const
```





**Parameters:**


* `temperature` Temperature measurement in Celsius. 
* `worst_case` Accuracy curve that should be used. 'true' for worst-case curve, 'false' for typical curve.



**Returns:**

Sensor accuracy for the given measurement.




**See also:** [**LM35IC::computeError**](classLM35_1_1LM35IC.md#function-computeerror) 



        

<hr>



### function computeError 

_Compute an error estimate for a given measurement._ 
```C++
double LM35::LM35IC::computeError (
    double temperature,
    bool worst_case=false
) const
```



This method yields an estimate of the total measurement error. It takes into account the sensor's accuracy, the measurement's resolution, and the ADC noise. The method uses the [**LM35IC::computeAccuracy**](classLM35_1_1LM35IC.md#function-computeaccuracy) and [**LM35IC::getResolution**](classLM35_1_1LM35IC.md#function-getresolution) to compute the sensor's accuracy and the measurement's resolution, respectively.




**Parameters:**


* `temperature` Temperature measurement in Celsius. 
* `worst_case` Accuracy curve that should be used. 'true' for worst-case curve, 'false' for typical curve.



**Returns:**

Error estimate in Celsius. 





        

<hr>



### function getResolution 

_Get the measurements' resolution._ 
```C++
double LM35::LM35IC::getResolution () const
```





**Returns:**

Measurement resolution.




**See also:** [**LM35IC::computeError**](classLM35_1_1LM35IC.md#function-computeerror) 



        

<hr>



### function readTemp 

_Collect a sensor reading and convert it to a temperature value._ 
```C++
double LM35::LM35IC::readTemp () const
```





**Returns:**

Temperature value in Celsius. 





        

<hr>
## Public Static Functions Documentation




### function Celsius2Fahrenheit 

_Convert a temperature value from Celsius to Fahrenheit._ 
```C++
static double LM35::LM35IC::Celsius2Fahrenheit (
    double temperature_Celsius
) 
```





**Parameters:**


* `temperature_Celsius` Temperature in Celsius.



**Returns:**

Temperature in Fahrenheit. 





        

<hr>



### function Celsius2Kelvin 

_Convert a temperature value from Celsius to Kelvin._ 
```C++
static double LM35::LM35IC::Celsius2Kelvin (
    double temperature_Celsius
) 
```





**Parameters:**


* `temperature_Celsius` Temperature in Celsius.



**Returns:**

Temperature in Kelvin. 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/LM35IC.h`

