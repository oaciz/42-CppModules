#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <exception>
#include <iostream>
#include <vector>

template <typename T>
int easyfind(T &container, int val)
{

	typename T::iterator it1 = container.begin();
	typename T::iterator it2 = container.end();
	size_t result = std::count(it1, it2, val);
	if(result != 0)
		return val;
	else
		return 0;

}

#endif