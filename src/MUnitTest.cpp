//!
//! @file				MUnitTest.cpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-09-04
//! @last-modified		2014-09-04
//! @brief
//! @details
//!						See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//========================================= INCLUDES ============================================//
//===============================================================================================//

// System libraries
#include <cstdint>		// int8_t, int32_t e.t.c
#include <cstring>		// strlen(), strncpy()
#include <cstdio>
//#include <iostream>		//!< @debug

// User libraries
// none

// User source
#include "../include/MUnitTest.hpp"


//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace MbeddedNinja
{


	//============================================================================================//
	//=============================== PUBLIC METHOD DEFINITIONS ==================================//
	//============================================================================================//

	//std::vector<Test*> TestRegister::listOfTests;
	std::vector<Test*> * TestRegister::listOfTestsPtr = nullptr;

	uint32_t TestRegister::currentTestIndex = 0;
	uint32_t TestRegister::numTestsThatFailed = 0;
	bool TestRegister::currTestFailed = false;

	//===========================================================================================//
	//=========================== PUBLIC OPERATOR OVERLOAD DEFINITIONS ==========================//
	//===========================================================================================//



	//============================================================================================//
	//============================== PRIVATE METHOD DEFINITIONS ==================================//
	//============================================================================================//

	// none

} // namespace MbeddedNinja

// EOF
