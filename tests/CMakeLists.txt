# Set up testing
include(CTest)
include(FetchContent)
FetchContent_Declare(
  googletest
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable(TemperatureSensorTests
  TemperatureSensorTests.cpp
)

target_link_libraries(TemperatureSensorTests
  CustomSerialTemperatureSensor
  GTest::gtest_main
  GTest::gmock_main
  GTest::gtest
  GTest::gmock
)

include(GoogleTest)
gtest_discover_tests(TemperatureSensorTests)

# Ensure both the application and tests are built
add_dependencies(TemperatureSensorTests TemperatureSensorApp)