cmake_minimum_required(VERSION 2.8.4)
project(List)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES parts4.cpp sllist.cpp utils.cpp )
add_executable(List ${SOURCE_FILES})