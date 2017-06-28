
# TravisCI is running cmake v2.8.7
cmake_minimum_required(VERSION 2.8.7)
project(MUnitTest)

add_definitions(-std=c++11)

include_directories(include)

add_subdirectory(src)
add_subdirectory(test)

# On Linux, "sudo make install" will typically copy the SerialFiller
# folder into /usr/local/include
install(DIRECTORY include/MUnitTest DESTINATION include)