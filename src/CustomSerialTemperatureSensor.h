/**
 * @file    CustomSerialTemperatureSensor.h
 *
 * @brief   Header file for the CustomSerialTemperatureSensor class.
 */

#pragma once

#include <string>
#include "SerialPort.h"

/**
 * @class CustomSerialTemperatureSensor
 *
 * @brief A driver class for a custom demo serial temperature sensor.
 *
 * @details This class provides methods to read temperature in Celsius or Fahrenheit,
 * read humidity, and to get the device ID from a UART temperature sensor.
 *
 * The sensor communicates via UART and supports a few commands:
 * Get temperature in Celsius: Get the temperature in Celsius: "GTC"
 * Get temperature in Fahrenheit: Get the temperature in Fahrenheit: "GTF"
 * Get humidity: Get the humidity: "GHU"
 * Get device ID: Get the device ID: "GID"
 * Each command is terminated by a newline character (\n).
 */
class CustomSerialTemperatureSensor {
public:
    /**
     * @enum TemperatureUnit
     * 
     * @brief Enumeration for temperature units.
     */
    enum class TemperatureUnit {
        Celsius,
        Fahrenheit
    };

    /**
     * @brief Constructor for CustomSerialTemperatureSensor.
     * 
     * @param port The serial port name to which the sensor is connected.
     */
    CustomSerialTemperatureSensor(ISerialPort &serial_port);

    /**
     * @brief Reads the temperature from the sensor.
     * 
     * @param unit The unit of temperature to read (Celsius or Fahrenheit).
     * @return The temperature in the specified unit.
     */
    float readTemperature(const TemperatureUnit unit);

    /**
     * @brief Reads the humidity from the sensor.
     * 
     * @return The humidity as a percentage.
     */
    float readHumidity();

    /**
     * @brief Reads the device ID from the sensor.
     * 
     * @return The device ID as a string.
     */
    std::string readDeviceId();

    static constexpr const char* COMMAND_GET_TEMPERATURE_CELSIUS = "GTC\n"; /**< Command to get the temperature in Celsius. */
    static constexpr const char* COMMAND_GET_TEMPERATURE_FAHRENHEIT = "GTF\n"; /**< Command to get the temperature in Fahrenheit. */
    static constexpr const char* COMMAND_GET_HUMIDITY = "GHU\n"; /**< Command to get the humidity. */
    static constexpr const char* COMMAND_GET_DEVICE_ID = "GID\n"; /**< Command to get the device ID. */
private:
    ISerialPort &serial_port_; /**< The serial port used for communication. */

    /**
     * @brief Sends the specified command and returns the response.
     * 
     * @param command The command to run.
     * @return The output of the command.
     */
    std::string runCommand(const std::string& command);


};