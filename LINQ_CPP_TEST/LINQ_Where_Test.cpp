#include "CppUnitTest.h"
#include "../LINQ_CPP/LINQ.cpp"
#include <deque>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LINQ_CPP_TEST
{
	TEST_CLASS(LINQ_Where_Test)
	{
		TEST_METHOD(VectorWhere) {
			LINQ<int> linq({ 1,2,3,4,5,6,7,8,9,10 });
			auto wh = linq.Where([](int e) {return e > 3; });
			Assert::AreEqual(7, (int)wh.Size());
		}

		TEST_METHOD(DequeWhere) {
			LINQ<int, std::deque> linq({ 1,2,3,4,5,6,7,8,9,10 });
			auto wh = linq.Where([](int e) {return e > 3; });
			Assert::AreEqual(7, (int)wh.Size());
		}
	};
}