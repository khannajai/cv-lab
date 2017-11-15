cmake_minimum_required(VERSION 2.8)
project(calibrate)
find_package(OpenCV REQUIRED)
include_directories(include ${OpenCV_INCLUDE_DIRS})
add_executable(calibrate camera_calibration.cpp)
target_link_libraries(calibrate ${OpenCV_LIBS})

