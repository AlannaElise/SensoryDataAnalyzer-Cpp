cmake_minimum_required(VERSION 4.0)
project(SensorDataAnalyzer)

set(CMAKE_CXX_STANDARD 20)

add_executable(SensorDataAnalyzer main.cpp
        FlightInstance.cpp
        FlightInstance.h
        DataCalculations.cpp
        DataCalculations.h)
