#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <fstream>
#include "ISerialPort.h"
#include "CustomSerialTemperatureSensor.h"

class MockSerialPort : public ISerialPort {
public:
    MOCK_METHOD(ssize_t, write, (const std::string& buffer), (override));
    MOCK_METHOD(ssize_t, read, (std::string& buffer), (override));
    MOCK_METHOD(std::string, readLine, (), (override));

    MOCK_METHOD(int, open, (), (override));
    MOCK_METHOD(int, close, (), (override));
    MOCK_METHOD(bool, configure, (), (override));
};

TEST(CustomSerialTemperatureSensor, EmptyTest) {
    // This is a placeholder test. You can add your own tests here.
    EXPECT_TRUE(true);
}

TEST(CustomSerialTemperatureSensor, ReadHumidity) {
    MockSerialPort mockSerialPort;
    CustomSerialTemperatureSensor sensor(mockSerialPort);

    EXPECT_CALL(mockSerialPort, write(CustomSerialTemperatureSensor::COMMAND_GET_HUMIDITY))
        .Times(1)
        .WillOnce(::testing::Return(0));

    EXPECT_CALL(mockSerialPort, readLine())
        .Times(1)
        .WillOnce(::testing::Return("45.6"));

    float humidity = sensor.readHumidity();

    EXPECT_FLOAT_EQ(humidity, 45.6);
}
