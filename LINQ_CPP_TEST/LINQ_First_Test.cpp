#include "CppUnitTest.h"
#include "../LINQ_CPP/LINQ.cpp"
#include <deque>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LINQ_CPP_TEST
{
	TEST_CLASS(LINQ_First_Test)
	{
	public:
		TEST_METHOD(VectorInt)
		{
			LINQ<int> linq({ 1,2,3 });
			Assert::AreEqual(1, linq.First());
		}

		TEST_METHOD(VectorString)
		{
			LINQ<std::string> linq({ "One", "Two" });
			Assert::AreEqual(std::string("One"), linq.First());
		}

		TEST_METHOD(ListString)
		{
			LINQ<std::string, std::list> linq({ "One", "Two" });
			Assert::AreEqual(std::string("One"), linq.First());
		}

		TEST_METHOD(ListInt)
		{
			LINQ<int, std::list> linq({ 1,2,3 });
			Assert::AreEqual(1, linq.First());
		}

		TEST_METHOD(DequeString)
		{
			LINQ<std::string, std::deque> linq({ "One", "Two" });
			Assert::AreEqual(std::string("One"), linq.First());
		}

		TEST_METHOD(DequeInt)
		{
			LINQ<int, std::deque> linq({ 1,2,3 });
			Assert::AreEqual(1, linq.First());
		}
	};
}