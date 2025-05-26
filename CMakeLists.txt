# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(LogUtilities VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create the library
add_library(LogUtils INTERFACE)

# Add include directories
target_include_directories(LogUtils INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Create the executable
add_executable(${PROJECT_NAME}
    tests/main.cpp)

# Link libraries to the executable
target_link_libraries(${PROJECT_NAME} LogUtils)

# Enable warnings for GCC
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()