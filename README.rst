============
MUnitTestCpp
============

------------------------------------------------------------------------------------------------
A microcontroller-friendly C++ unit test module specifically designed for embedded applications.
------------------------------------------------------------------------------------------------

.. image:: https://api.travis-ci.org/mbedded-ninja/MUnitTestCpp.png?branch=master   
	:target: https://travis-ci.org/mbedded-ninja/MUnitTestCpp

- Author: gbmhunter <gbmhunter@gmail.com> (www.mbedded.ninja)
- First Ever Commit: 2014-09-04
- Last Modified: 2014-09-04
- Version: v1.2.1.0
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
	
Changelog
=========

========= ========== ===================================================================================================
Version   Date       Comment
========= ========== ===================================================================================================
v1.2.1.0  2014-09-04 Got rid of unneccessary MStringCpp dependency in Makefile.
v1.2.0.0  2014-09-04 Added CHECK_EQUAL() macro and added tests to 'test/BasicTests.cpp', closes #3.
v1.1.0.0  2014-09-04 Added CHECK() macro and added it to 'test/BasicTests.cpp', closes #2.
v1.0.0.0  2014-09-04 Initial commit. Basic TEST() macro works and test code called correctly in ''test/BasicTests.cpp'.
========= ========== ===================================================================================================