
file(GLOB_RECURSE MUnitTest_SRC "*.cpp")

file(GLOB_RECURSE MUnitTest_HEADERS "../include/*.hpp" "../api/*.hpp")

add_library(MUnitTest ${MUnitTest_SRC} ${MUnitTest_HEADERS})

#target_include_directories(SerialFiller PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# On Linux, "sudo make install" will typically copy the library
# into the folder /usr/local/bin
install(TARGETS MUnitTest DESTINATION lib)