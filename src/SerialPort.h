#pragma once

#include <string>
#include <sstream>
#include "ISerialPort.h"

class SerialPort : public ISerialPort {
public:
    SerialPort(const std::string& name, const int speed);
    ~SerialPort();

    /**
     * @brief Simulates writing the specified buffer to the serial port.
     * 
     * @param buffer The buffer to write to the serial port.
     * @return The number of bytes written.
     */
    ssize_t write(const std::string& buffer) override;

    /**
     * @brief Simulates reading byte(s) from the serial port.
     * 
     * @param buffer The buffer to store the read data.
     * @return The number of bytes read, or 0 for EOF.
     */
    ssize_t read(std::string& buffer) override;

    /**
     * @brief Simulates reading a line from the serial port.
     * 
     * @return The line read from the serial port.
     */
    std::string readLine() override;

private:
    std::string port_name_;
    int speed_;
    std::stringstream simulated_buffer_; /**< Simulated buffer for serial communication. */

    /**
     * @brief Simulates opening the serial port.
     * 
     * @return 0 for success.
     */
    int open() override;

    /**
     * @brief Simulates closing the serial port.
     * 
     * @return 0 for success.
     */
    int close() override;

    /**
     * @brief Simulates configuring the serial port.
     * 
     * @return True for success.
     */
    bool configure() override;
};