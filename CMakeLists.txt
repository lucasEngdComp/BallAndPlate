cmake_minimum_required(VERSION 3.15)
project(balanceball-master)

find_package(OpenCV REQUIRED)

include_directories(.)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        balanceball-master
        balanceball.cpp
        camera/camera.cpp
        camera/camera.hpp)

target_link_libraries(balanceball-master ${OpenCV_LIBS})