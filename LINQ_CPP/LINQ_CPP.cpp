// LINQ_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "LINQ.cpp"
#include <iostream>
#include <string>

int main()
{
	LINQ<int> linq;
	linq.Add(12);
	int x = 15;
	linq.AddRange({ 1,2,3, x });
	auto resFind = linq.FirstOrDefault([](const int & elem) { return elem > 10; });
	auto res = linq.Select<std::string>([](const int & n) { return std::to_string(n); });
}
