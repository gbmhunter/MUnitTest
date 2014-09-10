//!
//! @file				MUnitTest.hpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-09-03
//! @last-modified		2014-09-05
//! @brief				
//! @details
//!						See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef MUNIT_TEST_CPP_MUNIT_TEST_H
#define MUNIT_TEST_CPP_MUNIT_TEST_H

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

// System headers
#include <cstdint>		// int8_t, int32_t e.t.c
#include <vector>
#include <iostream>

// User headers
// none

#define MTEST_GROUP

// Used for creating tests
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


#define CHECK(value)													\
	MbeddedNinja::TestRegister::Check(value, __FILE__, __LINE__);

#define CHECK_EQUAL(actual, expected)									\
	MbeddedNinja::TestRegister::CheckEqual(actual, expected, __FILE__, __LINE__);

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
				std::cout << "Unit test '" << ((*TestRegister::listOfTestsPtr)[TestRegister::currentTestIndex])->name << "' failed due to "
						"failed CHECK() in file '" << file << "'  on line '" << line << "'." << std::endl;
			}
		}

		//! @brief		Template method to compare two variables.
		template< typename Expected, typename Actual >
		static void CheckEqual(Expected const& expected, Actual const& actual, const char * file, uint32_t line)
		{
			if (!(expected == actual))
			{

				std::cout << "Unit test '" << ((*TestRegister::listOfTestsPtr)[TestRegister::currentTestIndex])->name << "' failed due to "
										"failed CHECK_EQUAL() in file '" << file << "'  on line '" << line << "'." << std::endl;
				std::cout << "Expected = '" << expected << "', actual = '" << actual << "'." << std::endl;

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

#endif	// #ifndef MUNIT_TEST_CPP_MUNIT_TEST_H

// EOF
