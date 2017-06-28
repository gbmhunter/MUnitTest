//!
//! @file 			main.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-09-04
//! @last-modified 	2017-06-27
//! @brief 			Contains main entry point for unit tests.
//! @details
//!					See README.rst in root dir for more info.

// System libraries
#include <stdio.h>
#include <iostream>

// User source
#include "MUnitTest/MUnitTestApi.hpp"

using namespace MbeddedNinja;

int main()
{
	std::cout << "main() entered.\r\n" << std::endl;
	TestRegister::RunAllTests();
	return 0;
	/*
	try
    {
        UnitTest::TestReporterStdout reporter;
		UnitTest::TestRunner runner(reporter);
	
	
		return runner.RunTestsIf(
			UnitTest::Test::GetTestList(),
			"ParamTests",
			UnitTest::True(),
			0);
    }
    catch(std::exception const& e)
    {
         printf("%s", e.what());
         // If you are feeling mad (not in main) you could rethrow! 
    }*/
	
}
