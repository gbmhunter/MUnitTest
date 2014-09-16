//!
//! @file 			GroupTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-09-16
//! @last-modified 	2014-09-16
//! @brief 			Contains tests which make sure the MTEST_GROUP() macro works correctly.
//! @details
//!					See README.rst in root dir for more info.

//===== SYSTEM LIBRARIES =====//
#include <iostream>

//===== USER SOURCE =====//
#include "../api/MUnitTestApi.hpp"

using namespace MbeddedNinja;

namespace MUnitTestTestsNs
{
	MTEST_GROUP(Group1Tests)
	{

		MTEST(TestInGroup)
		{
			CHECK(true);
		}

	}

	MTEST_GROUP(Group2Tests)
	{

		MTEST(TestInGroup)
		{
			CHECK(true);
		}

	}

} // namespace MUnitTestTestsNs
