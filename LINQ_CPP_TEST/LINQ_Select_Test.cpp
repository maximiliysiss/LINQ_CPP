#include "CppUnitTest.h"
#include "../LINQ_CPP/LINQ.cpp"
#include <deque>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LINQ_CPP_TEST
{
	TEST_CLASS(LINQ_Select_Test) {

		TEST_METHOD(VectorSelect) {
			LINQ<int> linq({ 1,2,3,4,5,6,7,8 });
			auto select = linq.Select<std::string>([](int e) {return std::to_string(e); });
			Assert::AreEqual(std::string("1"), select.First());
		}

		TEST_METHOD(DequeSelect) {
			LINQ<int, std::deque> linq({ 1,2,3,4,5,6,7,8 });
			auto select = linq.Select<std::string>([](int e) {return std::to_string(e); });
			Assert::AreEqual(std::string("1"), select.First());
		}
	};
}