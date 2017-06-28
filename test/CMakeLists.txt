
file(GLOB_RECURSE MUnitTest_Test_SRC "*.cpp")

file(GLOB_RECURSE MUnitTest_Test_HEADERS "../include/*.hpp" "../api/*.hpp")

add_executable(MUnitTest_Test ${MUnitTest_Test_SRC} ${MUnitTest_Test_HEADERS})

target_link_libraries(MUnitTest_Test MUnitTest)
#target_include_directories(SerialFiller PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# On Linux, "sudo make install" will typically copy the library
# into the folder /usr/local/bin
#install(TARGETS MUnitTest DESTINATION lib)