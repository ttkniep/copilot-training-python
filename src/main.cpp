#include <iostream>
#include "CustomSerialTemperatureSensor.h"
#include "SerialPort.h"

int main() {
    SerialPort serial_port("COM1", 9600); // Simulated serial port
    CustomSerialTemperatureSensor sensor(serial_port);

    std::cout << "Reading temperature in Celsius..." << std::endl;
    float temperature = sensor.readTemperature(CustomSerialTemperatureSensor::TemperatureUnit::Celsius);
    std::cout << "Temperature: " << temperature << " °C" << std::endl;

    std::cout << "Reading device ID..." << std::endl;
    std::string device_id = sensor.readDeviceId();
    std::cout << "Device ID: " << device_id << std::endl;

    return 0;
}
