#pragma once

#include <string>
#include <cstddef> // Für std::ptrdiff_t

#ifdef _WIN32
using ssize_t = std::ptrdiff_t; // Definiere ssize_t für Windows
#endif

class ISerialPort {
public:
    virtual ~ISerialPort() = default;
    virtual ssize_t write(const std::string& buffer) = 0;
    virtual ssize_t read(std::string& buffer) = 0;
    virtual std::string readLine() = 0;
private:
    virtual int open() = 0;
    virtual int close() = 0;
    virtual bool configure() = 0;
};