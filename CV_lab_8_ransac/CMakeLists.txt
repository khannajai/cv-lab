
cmake_minimum_required(VERSION 2.6)
project(ransac)
add_executable(ransac ransac.cpp)
target_link_libraries(airplanes ${CMAKE_THREAD_LIBS_INIT})
