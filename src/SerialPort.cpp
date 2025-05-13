#include <iostream>
#include <sstream>
#include "SerialPort.h"

SerialPort::SerialPort(const std::string& name, const int speed)
    : port_name_(name), speed_(speed) {
    // Simulated open
    std::cout << "Simulated opening of serial port: " << port_name_ << " at speed: " << speed_ << std::endl;
}

SerialPort::~SerialPort() {
    this->close();
}

ssize_t SerialPort::write(const std::string& buffer) {
    // Simulated write to a buffer
    simulated_buffer_ << buffer;
    std::cout << "Simulated write: " << buffer << std::endl;
    return buffer.size();
}

ssize_t SerialPort::read(std::string& buffer) {
    // Simulated read from a buffer
    char ch;
    if (simulated_buffer_.get(ch)) {
        buffer = ch;
        return 1;
    }
    return 0; // EOF
}

std::string SerialPort::readLine() {
    // Read line from console input
    std::string line;
    std::cout << "Enter a line: ";
    std::getline(std::cin, line);
    std::cout << "Read line from console: " << line << std::endl;
    return line;
}

int SerialPort::open() {
    // Simulated open
    std::cout << "Simulated serial port open: " << port_name_ << std::endl;
    return 0; // Success
}

int SerialPort::close() {
    // Simulated close
    std::cout << "Simulated serial port close: " << port_name_ << std::endl;
    return 0; // Success
}

bool SerialPort::configure() {
    // Simulated configuration
    std::cout << "Simulated serial port configuration for: " << port_name_ << std::endl;
    return true; // Success
}