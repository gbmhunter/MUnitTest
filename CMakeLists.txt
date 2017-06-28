
# TravisCI is running cmake v2.8.7
cmake_minimum_required(VERSION 2.8.7)
project(MUnitTest)

add_definitions(-std=c++14)

add_subdirectory(src)
add_subdirectory(test)