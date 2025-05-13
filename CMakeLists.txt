cmake_minimum_required(VERSION 3.14)
project(CopilotTrainingCpp)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create a build directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)

