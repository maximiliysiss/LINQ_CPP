#pragma once
#ifndef LINQ_HPP
#define LINQ_HPP

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

/*
	LINQ CLASS (as C# LINQ)
	It's a pity, but need #include<LINQ.cpp> :(
*/
template<typename T, template<typename, typename = std::allocator<T>> class Cont = std::vector>
class LINQ
{
	// Inner Container
	Cont<T> container;
public:
	// Inner Container's Iterator
	typedef typename Cont<T>::iterator InnerIterator;
	// Inner Container
	typedef Cont<T> ReturnContainer;
public:
	// Get Size
	size_t Size();
	// Get Inner Container by *
	ReturnContainer & operator*();
	LINQ();
	/*
		Constructor by Iterators
		Example: LINQ<int>(other.Begin(), other.End())
	*/
	LINQ(InnerIterator begin, InnerIterator end);
	~LINQ();
	// Add new Element to back
	void Add(T element);
	// Add element's range to back
	void AddRange(std::initializer_list<T>);
	// Contains
	bool Contains(const T element);
	// Where by function
	LINQ<T> Where(bool(*filter)(T elem));
	// For each element
	void ForEach(void(*command)(const T& elem));
	// Get First element or std::exception if not found
	T First();
	// Get point to first element or nullptr
	T* FirstOrDefault();
	// ToList
	std::list<T> ToList();
	// To Vector
	std::vector<T> ToVector();
	// Begin of inner container
	InnerIterator Begin();
	// End of inner container
	InnerIterator End();
	// Remove element by index
	void RemoveAt(int index);
	// Remove all elements by equals
	void RemoveAll(T element);
	// Remove elements by filter function
	void RemoveIf(bool(*filter)(const T & element));
};

#endif // !LINQ_HPP
