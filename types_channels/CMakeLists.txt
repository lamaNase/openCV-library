cmake_minimum_required(VERSION 3.10)
project(ImageFlip)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include directories
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable
add_executable(image_types_channels main.cpp)

# Link OpenCV libraries
target_link_libraries(image_types_channels ${OpenCV_LIBS})

