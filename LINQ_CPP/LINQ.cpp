#include "LINQ.hpp"

template<typename T, template<typename, typename> class Cont>
LINQ<T, Cont>::LINQ()
{
}

template<typename T, template<typename, typename = std::allocator<T>> class Cont>
LINQ <T, Cont>::LINQ(InnerIterator begin, InnerIterator end)
{
	container = Cont<T>(begin, end);
}

template<typename T, template<typename, typename> class Cont>
LINQ<T, Cont>::~LINQ()
{
}

template<typename T, template<typename, typename> class Cont>
void LINQ<T, Cont>::Add(T element)
{
	container.insert(container.end(), { element });
}

template<typename T, template<typename, typename> class Cont>
void LINQ<T, Cont>::AddRange(std::initializer_list<T> list)
{
	container.insert(container.end(), list);
}

template<typename T, template<typename, typename> class Cont>
bool LINQ<T, Cont>::Contains(const T element)
{
	return std::find(container.begin(), container.end(), element) != container.end();
}

template<typename T, template<typename, typename> class Cont>
LINQ<T> LINQ<T, Cont>::Where(bool(*filter)(T elem))
{
	LINQ<T> resLinq;
	auto it = container.begin();
	while ((it = std::find_if(it, container.end(), filter)) != container.end()) {
		resLinq.Add(*it);
		it++;
	}
	return resLinq;
}

template<typename T, template<typename, typename> class Cont>
void LINQ<T, Cont>::ForEach(void(*command)(const T& elem))
{
	std::for_each(container.begin(), container.end(), command);
}

template<typename T, template<typename, typename> class Cont>
size_t LINQ<T, Cont>::Size()
{
	return container.size();
}

template<typename T, template<typename, typename> class Cont>
typename LINQ<T, Cont>::ReturnContainer & LINQ<T, Cont>::operator*()
{
	return container;
}

template<typename T, template<typename, typename> class Cont>
T LINQ<T, Cont>::First()
{
	if (container.size() == 0)
		throw std::exception("Size is low");
	return container.at(0);
}

template<typename T, template<typename, typename> class Cont>
T * LINQ<T, Cont>::FirstOrDefault()
{
	if (container.size() == 0)
		return nullptr;
	return &container.at(0);
}

template<typename T, template<typename, typename> class Cont>
std::list<T> LINQ<T, Cont>::ToList()
{
	return std::list<T>(container.begin(), container.end());
}

template<typename T, template<typename, typename> class Cont>
std::vector<T> LINQ<T, Cont>::ToVector()
{
	return std::vector<T>(container.begin(), container.end());
}

template<typename T, template<typename, typename> class Cont>
typename LINQ<T, Cont>::InnerIterator LINQ<T, Cont>::Begin()
{
	return container.begin();
}

template<typename T, template<typename, typename> class Cont>
typename LINQ<T, Cont>::InnerIterator LINQ<T, Cont>::End()
{
	return container.end();
}

template<typename T, template<typename, typename> class Cont>
void LINQ<T, Cont>::RemoveAt(int index)
{
	container.erase(container.begin() + index);
}

template<typename T, template<typename, typename = std::allocator<T>> class Cont>
void LINQ<T, Cont>::RemoveAll(T element)
{
	auto iter = std::remove(container.begin(), container.end(), element);
	container = Cont<T>(container.begin(), iter);
}

template<typename T, template<typename, typename = std::allocator<T>> class Cont>
void LINQ<T, Cont>::RemoveIf(bool(*filter)(const T &element))
{
	auto iter = std::remove_if(container.begin(), container.end(), filter);
	container = Cont<T>(container.begin(), iter);
}
