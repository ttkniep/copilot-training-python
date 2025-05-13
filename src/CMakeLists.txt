add_library(CustomSerialTemperatureSensor
    CustomSerialTemperatureSensor.cpp
    SerialPort.cpp
)

target_include_directories(CustomSerialTemperatureSensor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add an executable for the application
add_executable(TemperatureSensorApp
    main.cpp
)

target_link_libraries(TemperatureSensorApp
    CustomSerialTemperatureSensor
)
