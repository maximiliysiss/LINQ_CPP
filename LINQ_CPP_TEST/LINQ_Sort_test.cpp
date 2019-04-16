#include "CppUnitTest.h"
#include "../LINQ_CPP/LINQ.cpp"
#include <deque>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LINQ_CPP_TEST
{
	TEST_CLASS(LINQ_Sort_Test)
	{
		TEST_METHOD(VectorSort) {
			LINQ<int> linq({ 1,3,4,5,6,8,10,1,1,12,3,2,123,4,654 });
			auto res = linq.OrderBy<int>([](int i) {return i; });
			Assert::AreEqual(true, std::is_sorted(res.begin(), res.end()));
		}

		TEST_METHOD(DequeSort) {
			LINQ<int, std::deque> linq({ 1,3,4,5,6,8,10,1,1,12,3,2,123,4,654 });
			auto res = linq.OrderBy<int>([](int i) {return i; });
			Assert::AreEqual(true, std::is_sorted(res.begin(), res.end()));
		}

		TEST_METHOD(VectorSortDesc) {
			LINQ<int> linq({ 1,3,4,5,6,8,10,1,1,12,3,2,123,4,654 });
			auto res = linq.OrderByDesc<int>([](int i) {return i; });
			Assert::AreEqual(true, std::is_sorted(res.rbegin(), res.rend()));
		}

		TEST_METHOD(DequeSortDesc) {
			LINQ<int, std::deque> linq({ 1,3,4,5,6,8,10,1,1,12,3,2,123,4,654 });
			auto res = linq.OrderByDesc<int>([](int i) {return i; });
			Assert::AreEqual(true, std::is_sorted(res.rbegin(), res.rend()));
		}
	};
}