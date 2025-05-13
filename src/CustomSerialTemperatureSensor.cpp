#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "CustomSerialTemperatureSensor.h"

CustomSerialTemperatureSensor::CustomSerialTemperatureSensor(ISerialPort &serial_port)
    : serial_port_(serial_port) {}

float CustomSerialTemperatureSensor::readTemperature(const TemperatureUnit unit) {
    std::string response;
    if (unit == TemperatureUnit::Celsius) {
        response = runCommand(COMMAND_GET_TEMPERATURE_CELSIUS);
    } else {
        response = runCommand(COMMAND_GET_TEMPERATURE_FAHRENHEIT);
    }

    // Convert the response string to a float
    return std::stof(response);
}

float CustomSerialTemperatureSensor::readHumidity() {
    std::string response = runCommand(COMMAND_GET_HUMIDITY);
    // Convert the response string to a float with higher precision handling
    try {
        return std::stof(response);
    } catch (const std::exception& e) {
        std::cerr << "Error parsing humidity response: " << e.what() << std::endl;
        return -1.0f; // Return an invalid value to indicate an error
    }
}

std::string CustomSerialTemperatureSensor::readDeviceId() {
    
}

std::string CustomSerialTemperatureSensor::runCommand(const std::string& command) {
    std::string response;
    if (serial_port_.write(command) < 0) {
        std::cerr << "Error writing to serial port: " << strerror(errno) << std::endl;
    }
    else {
        response = serial_port_.readLine();
    }
    return response;
}
