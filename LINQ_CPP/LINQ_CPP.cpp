// LINQ_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "LINQ.cpp"
#include <iostream>

int main()
{
	LINQ<int> linq;
	linq.Add(12);
	int x = 15;
	linq.AddRange({ 1,2,3, x });
	auto res = *linq;

	LINQ<int> linq12(res.begin(), res.end());
	std::cout << linq.Size() << " " << res.at(4) << std::endl;
	std::cout << linq.Contains(78);

	auto resWhere = linq.Where([](int elem) { return elem > 10; });
	LINQ<int> linq1233(resWhere);

	auto listCopy = resWhere.ToList();
	resWhere.RemoveAll(12);

	linq.RemoveIf([](const int& el) {return el > 10; });
}
