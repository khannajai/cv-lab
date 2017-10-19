cmake_minimum_required(VERSION 2.8)
project(facerec)
find_package(OpenCV REQUIRED)
include_directories(include ${OpenCV_INCLUDE_DIRS})
add_executable(facerec facerec.cc)
target_link_libraries(facerec ${OpenCV_LIBS})

