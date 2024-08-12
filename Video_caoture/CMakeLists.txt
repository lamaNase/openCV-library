cmake_minimum_required(VERSION 3.10)
project(video_cap)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Find the Qt5 package
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

# Add executable
add_executable(video_cap main.cpp)

# Link OpenCV and Qt5 libraries
target_link_libraries(video_cap ${OpenCV_LIBS} Qt5::Core Qt5::Widgets)

