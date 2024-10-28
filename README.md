[![Arduino Library specifications](https://github.com/MiguelLoureiro98/LM35IC/actions/workflows/lint.yml/badge.svg)](https://github.com/MiguelLoureiro98/LM35IC/actions/workflows/lint.yml) [![Building (Examples)](https://github.com/MiguelLoureiro98/LM35IC/actions/workflows/examples.yml/badge.svg)](https://github.com/MiguelLoureiro98/LM35IC/actions/workflows/examples.yml)

# LM35IC temperature sensors library

Arduino sensor driver for LM35 integrated circuit temperature sensors. 

This is a library to help users interface with the LM35 family of sensors.
It is flexible enough to be used with any of these sensors, as well as every Arduino board based on the ATMega328P.

# Features

- **Support for the whole LM35 family**: this library can be used with every LM35 sensor, including the LM35, LM35A, LM35CA, LM35C and LM35D sensors. Take a look at the data sheet for more details;
- **Error computation**: leverage the library's methods to compute the error associated with your measurements;
- **Signal conditioning compensation**: the library takes the gain and the offset of the signal conditioning circuit into account, making it far more flexible;
- **Support for different boards**: you can manually specify your board's operating voltage and ADC characteristics. This makes the library compatible with several Arduino boards.

# Installation

The library has yet to be added to the Arduino Library Index. Once it is accepted, you will be able to install it using the Arduino Library Manager.

# Basic usage

See [this example](examples/basics.ino) for a basic guide on how to use this library.

# Examples

The library comes with several example sketches to help users understand how they can leverage its capabilities. The examples should be analysed in the following order:

1. [Get sensor reading](examples/basics.ino)
2. [Unit conversion](examples/unit_conversion.ino)
3. [Compute measurement accuracy](examples/compute_accuracy.ino)
4. [Compute measurement error](examples/compute_error.ino)
5. [Signal conditioning](examples/signal_conditioning.ino)
6. [Different ADC characteristics](examples/different_ADC.ino)

# Documentation

An official documentation website is currently under development.

# Licence

This project is licenced under the [MIT licence](LICENSE).
