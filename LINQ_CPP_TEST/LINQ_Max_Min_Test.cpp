#include "CppUnitTest.h"
#include "../LINQ_CPP/LINQ.cpp"
#include <deque>
#include "TestClass.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LINQ_CPP_TEST
{
	TEST_CLASS(LINQ_Max_Min_Test)
	{

	public:
		TEST_METHOD(MaxVector) {
			LINQ<int> linq({ 2,5,4,8,4,3,1,54,654,1,5,321,1,31,54,68 });
			auto res = linq.Max();
			Assert::AreEqual(654, res);
		}

		TEST_METHOD(MaxList) {
			LINQ<int, std::list> linq({ 2,5,4,8,4,3,1,54,654,1,5,321,1,31,54,68 });
			auto res = linq.Max();
			Assert::AreEqual(654, res);
		}

		TEST_METHOD(MaxVectorL) {
			LINQ<TestClassForTest> linq({ TestClassForTest{1,2}, TestClassForTest{2,4}, TestClassForTest{1,6} });
			auto res = linq.Max<int>([](TestClassForTest one) {return one.i; });
			Assert::AreEqual(2, res);
		}

		TEST_METHOD(MaxListL) {
			LINQ<TestClassForTest> linq({ TestClassForTest{1,2}, TestClassForTest{2,4}, TestClassForTest{1,6} });
			auto res = linq.Min<int>([](TestClassForTest one) {return one.i; });
			Assert::AreEqual(1, res);
		}


	};
}