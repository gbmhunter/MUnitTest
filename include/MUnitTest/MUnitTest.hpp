//!
//! @file				MUnitTest.hpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-09-03
//! @last-modified		2014-09-26
//! @brief				
//! @details
//!						See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef MUNIT_TEST_MUNIT_TEST_H
#define MUNIT_TEST_MUNIT_TEST_H

//===============================================================================================//
//==================================== FORWARD DECLARATION ======================================//
//===============================================================================================//

namespace MbeddedNinja
{
	class MUnitTest;
}

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

//===== SYSTEM LIBRARIES =====//
#include <cstdint>		// int8_t, int32_t e.t.c
#include <vector>
#include <iostream>
#include <cstring>

//===== USER SOURCE =====//
// none

//! @brief		Used for creating test groups.
#define MTEST_GROUP(name)									\
	namespace MTestGroup##name

//! @brief 		Used for creating tests
#define MTEST(Name)											\
	class Test##Name : public MbeddedNinja::Test			\
	{														\
	public:													\
		Test##Name() : Test(#Name, __FILE__, __LINE__){}	\
		~Test##Name(){};									\
		virtual void Run();									\
															\
	} test##Name##Object;									\
															\
	MbeddedNinja::AddToRegisterObj reg##Name(&test##Name##Object);		\
	void Test##Name::Run()


//! @brief		Used to check a boolean expression
#define CHECK(value)													\
	MbeddedNinja::TestRegister::Check(value, __FILE__, __LINE__)

//! @brief		Used to compare two variables. This is preferred over CHECK() as the error's when a CHECK_EQUAL()
//!				fail are more descriptive.
#define CHECK_EQUAL(actual, expected)									\
	MbeddedNinja::TestRegister::CheckEqual(actual, expected, __FILE__, __LINE__)

//! @brief		Used to compare two variables which a specified tolerance. This is useful for comparing
//!				floats and doubles in where there can be rounding error.
#define CHECK_CLOSE(actual, expected, tolerance)						\
	MbeddedNinja::TestRegister::CheckClose(actual, expected, tolerance, __FILE__, __LINE__)

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace MbeddedNinja
{

	//! @brief		String class designed for embedded applications.
	//! @details	Exceptions are not used.
	class Test
	{	
		
		public:


			//======================================================================================//
			//==================================== PUBLIC METHODS ==================================//
			//======================================================================================//
					

			Test(const char * name, const char * file, uint32_t line)
			{
				this->name = name;
				this->file = file;
				this->line = line;

			}

			virtual ~Test(){};

			virtual void Run(){};
		

			//======================================================================================//
			//============================ PUBLIC OPERATOR OVERLOAD DECLARATIONS ===================//
			//======================================================================================//

		

			//======================================================================================//
			//================================= PUBLIC VARIABLES ===================================//
			//======================================================================================//
				
			const char * name;
			const char * file;
			uint32_t line;
				

		
	}; // class MUnitTest


	class TestRegister
	{



	public:

		static void RegisterTest(Test * testToRegister)
		{
			//std::cout << "RegisterTest() called.\r\n" << std::endl;
			// Add test to the list of tests
			static std::vector<Test*> listOfTests;
			listOfTests.push_back(testToRegister);
			listOfTestsPtr = &listOfTests;

		}

		static uint8_t RunAllTests()
		{
			std::cout << "Running all unit tests..." << std::endl;
			//std::cout << "RunAllTests() called.\r\n" << std::endl;
			//listOfTests.push_back(nullptr);
			//std::cout << "listOfTests.size() = '" << listOfTestsPtr->size() << "'." << std::endl;

			for(currentTestIndex = 0; currentTestIndex < TestRegister::listOfTestsPtr->size(); currentTestIndex++)
			{
				// Run test
				//std::cout << "Running unit test.\r\n" << std::endl;

				// Set currTestFailed flag to false perfore running test, running test
				// will set this to true if test fails.
				currTestFailed = false;
				(*listOfTestsPtr)[currentTestIndex]->Run();
				if(currTestFailed)
					numTestsThatFailed++;

			}

			std::cout << "TEST SUMMARY:" << std::endl;
			std::cout << "Num of tests = '" << listOfTestsPtr->size() << "'." << std::endl;
			std::cout << "Num. passed = '" << listOfTestsPtr->size() - numTestsThatFailed << "'." << std::endl;
			std::cout << "Num. failed = '" << numTestsThatFailed << "'." << std::endl;

			// Return a C-style exit code, 0 if all pass, otherwise 1
			// In a large OS, this value could be returned from main().
			if(numTestsThatFailed == 0)
				return 0;
			else
				return 1;

		}

		template< typename Actual >
		static void Check(Actual const & actual, const char * file, uint32_t line)
		{

			if(!actual)
			{
				TestRegister::currTestFailed = true;
				std::cout << "Unit test '" << ((*TestRegister::listOfTestsPtr)[TestRegister::currentTestIndex])->name << "' failed due to "
						"failed CHECK() in file '" << file <<
						"'  on line '" << line << "'." << std::endl;
			}
		}

		//! @brief		Template method to compare two variables.
		template< typename Actual, typename Expected >
		static void CheckEqual(Actual const& actual, Expected const& expected, const char * file, uint32_t line)
		{
			//std::cout << "CheckEqual with two templated vars called." << std::endl;

			if (!(actual == expected))
			{
				TestRegister::currTestFailed = true;
				std::cout << "Unit test '" << ((*TestRegister::listOfTestsPtr)[TestRegister::currentTestIndex])->name << "' failed due to "
						"failed CHECK_EQUAL() in file '" << file << "'  on line '" << line << "'." << std::endl;
				std::cout << "Actual = '" << actual <<
						"', expected = '" << expected << "'." << std::endl;

			}
		}

		static void CheckEqual(const char * actual, const char * expected, const char * file, uint32_t line)
		{
			//std::cout << "CheckEqual with two const char * called." << std::endl;
			CheckEqualForCStrings(actual, expected, file, line);
		}

		static void CheckEqual(char * actual, char * expected, const char * file, uint32_t line)
		{
			//std::cout << "CheckEqual with two char * called." << std::endl;
			CheckEqualForCStrings(actual, expected, file, line);
		}

		static void CheckEqual(const char * actual, char * expected, const char * file, uint32_t line)
		{
			CheckEqualForCStrings(actual, expected, file, line);
		}

		static void CheckEqual(char * actual, const char * expected, const char * file, uint32_t line)
		{
			CheckEqualForCStrings(actual, expected, file, line);
		}

		static void CheckEqualForCStrings(const char * actual, const char * expected, const char * file, uint32_t line)
		{
			//std::cout << "CheckEqualForCStrings called." << std::endl;
			//std::cout << "strcmp() = '" << strcmp(expected, actual) << "'." << std::endl;
			if (strcmp(actual, expected))
			{
				TestRegister::currTestFailed = true;
				std::cout <<
						"Unit test '" <<
						((*TestRegister::listOfTestsPtr)[TestRegister::currentTestIndex])->name <<
						"' failed due to "
						"failed CHECK_EQUAL() in file '" << file <<
						"'  on line '" << line << "'." << std::endl;
				std::cout << "Actual = '" << actual <<
						"', expected = '" << expected << "'." << std::endl;

			}
		}

		//! @brief		Template method to compare two variables to within a specified tolerance.
		template< typename Actual, typename Expected, typename Tolerance >
		static void CheckClose(
			Actual const& actual,
			Expected const& expected,
			Tolerance const& tolerance,
			const char * file,
			uint32_t line)
		{

			if ((actual >= (expected + tolerance)) || (actual <= (expected - tolerance)))
			{
				TestRegister::currTestFailed = true;
				std::cout <<
					"Unit test '" <<
					((*TestRegister::listOfTestsPtr)[TestRegister::currentTestIndex])->name <<
					"' failed due to "
					"failed CHECK_CLOSE() in file '" << file << "'  on line '" << line << "'." << std::endl;
				std::cout << "Actual = '" << actual <<
					"', expected = '" << expected <<
					"', tolerance = '" << tolerance << "'." << std::endl;

			}
		}

	private:
		static std::vector<Test*> * listOfTestsPtr;
		static uint32_t currentTestIndex;
		static uint32_t numTestsThatFailed;
		static bool currTestFailed;

	};


	class AddToRegisterObj
	{

	public:
		AddToRegisterObj(Test * testToRegister)
		{
			//std::cout << "AddToRegisterObj() called.\r\n" << std::endl;
			TestRegister::RegisterTest(testToRegister);

		}

	};


} // namespace MbeddedNinja

#endif	// #ifndef MUNIT_TEST_MUNIT_TEST_H

// EOF
