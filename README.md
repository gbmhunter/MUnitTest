
MUnitTest
=========


A microcontroller-friendly C++ unit test module specifically designed for embedded applications.


.. image:: https://api.travis-ci.org/mbedded-ninja/MUnitTest.png?branch=master   
	:target: https://travis-ci.org/mbedded-ninja/MUnitTest

- Author: gbmhunter <gbmhunter@gmail.com> (www.mbedded.ninja)
- First Ever Commit: 2014-09-04
- Last Modified: 2017-06-27
- Version: v2.0.0
- Company: mbedded.ninja
- Project: MToolkit Module
- Language: C++
- Compiler: GCC	
- uC Model: n/a
- Computer Architecture: n/a
- Operating System: n/a
- Documentation Format: Doxygen
- License: GPLv3

Description
===========

A microcontroller-friendly C++ unit test module specifically designed for embedded applications.

To be compatible with mid-range microcontrollers, no exceptions are used, the entire module has a no-throw guarantee.
	

External Dependencies
=====================

Nothing here yet.

Issues
======

See GitHub Issues.

Limitations
===========

Nothing here yet.

Usage
=====

See the unit tests in the 'test/' directory for basic examples.

::

	#include "MUnitTest/api/MUnitTestApi.hpp"

	MTEST(BasicTestThatWillAlwaysFail)
	{
		CHECK(false);
	}
	
	MTEST(BasicTestThatWillAlwaysPass)
	{
		CHECK(true);
	}
	
	// The following test is inside a "test group"
	MTEST_GROUP(MyTestGroup)
	{
		MTEST(MakeSureMyVarIsFive)
		{
			CHECK_EQUAL(myVar, 5);
		}
	}
	
	int main()
	{
		// Run all tests, this will run the 
		// three above, and return the result from main()
		// 0 indicates all passed, 1 indicates at least 1 unit test failed
		return TestRegister::RunAllTests();
		
	{
	
	