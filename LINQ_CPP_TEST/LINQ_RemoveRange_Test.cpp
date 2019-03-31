#include "CppUnitTest.h"
#include "../LINQ_CPP/LINQ.cpp"
#include <deque>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LINQ_CPP_TEST
{
	TEST_CLASS(LINQ_RemoveRange_Test)
	{
	public:
		TEST_METHOD(VectorInt) {
			LINQ<int> linq({ 1,2,3,4,5,6,7,8,9 });
			linq.RemoveRange({ 1,2,3,4,5 });
			Assert::AreEqual(4, (int)linq.Size());
		}

		TEST_METHOD(DequeInt) {
			LINQ<int, std::deque> linq({ 1,2,3,4,5,6,7,8,9 });
			linq.RemoveRange({ 1,2,3,4,5 });
			Assert::AreEqual(4, (int)linq.Size());
		}

	};
}