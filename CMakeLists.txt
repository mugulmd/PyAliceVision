message("CMake version: ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}")
cmake_minimum_required(VERSION 3.11)
project(pyalicevision LANGUAGES CXX VERSION 0.1.0)


# CMake Find modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)


# C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# PyBind11 dependency
find_package(pybind11 REQUIRED)


# AliceVision dependency
add_definitions(-DBOOST_USE_WINAPI_VERSION=BOOST_WINAPI_VERSION_WIN7)
find_package(AliceVision REQUIRED)


# Subdirectories
add_subdirectory(src)
