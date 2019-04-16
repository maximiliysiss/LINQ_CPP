// LINQ_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "LINQ.cpp"
#include <iostream>
#include <string>


class Test {
public:
	int t;
	int g;
};

int main()
{
	LINQ<Test> linq({ Test{12,8}, Test{112,3}, Test{3,4} });

	int res = linq.Max<int>([](Test one) {return one.g; });
}
