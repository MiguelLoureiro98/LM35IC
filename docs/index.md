# Welcome to the LM35IC library documentation

The LM35IC library is essentially a sensor driver for LM35 integrated circuit temperature sensors. 

This is a library to help users interface with the LM35 family of sensors.
It is flexible enough to be used with any of these sensors, as well as every Arduino board based on the ATMega328P.

## Features

- **Support for the whole LM35 family**: this library can be used with every LM35 sensor, including the LM35, LM35A, LM35CA, LM35C and LM35D sensors. Take a look at the data sheet for more details;
- **Error computation**: leverage the library's methods to compute the error associated with your measurements;
- **Signal conditioning compensation**: the library takes the gain and the offset of the signal conditioning circuit into account, making it far more flexible;
- **Support for different boards**: you can manually specify your board's operating voltage and ADC characteristics. This makes the library compatible with several Arduino boards.

## Documentation guide

Check our [installation page](installation.md) for instructions on how to install the package.

For a basic guide on how to use the library, please refer to our [basic usage](basics.md) guide.

If more detailed information about the class and types provided by the library is required, please refer to our [API reference](API_reference.md).
