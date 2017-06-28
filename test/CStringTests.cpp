//!
//! @file 			CStringTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-09-26
//! @last-modified 	2017-06-27
//! @brief 			Contains tests which makes sure CHECK_EQUAL() works for all types of C-string (const and non-const).
//! @details
//!					See README.rst in root dir for more info.

// System includes
#include <iostream>

// User source
#include "MUnitTest/MUnitTestApi.hpp"

using namespace MbeddedNinja;

namespace MUnitTestTestsNs
{
	MTEST_GROUP(CStringTests)
	{

		MTEST(NoConstCStringsTest)
		{
			char * cStr1 = (char *)"c string";
			char * cStr2 = (char *)"c string";
			CHECK_EQUAL(cStr1, cStr2);
		}

		MTEST(BothConstCStringsTest)
		{
			const char * cStr1 = "c string";
			const char * cStr2 = "c string";
			CHECK_EQUAL(cStr1, cStr2);
		}

		MTEST(LeftConstCStringsTest)
		{
			char * cStr1 = (char *)"c string";
			const char * cStr2 = "c string";
			CHECK_EQUAL(cStr1, cStr2);
		}

		MTEST(RightConstCStringsTest)
		{
			const char * cStr1 = "c string";
			char * cStr2 = (char *)"c string";
			CHECK_EQUAL(cStr1, cStr2);
		}
	}

} // namespace MUnitTestTestsNs
