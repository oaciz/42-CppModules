#include "EasyfFnd.hpp"
#include <set>
#include <list>


int main()
{
	std::list<int> intArray;
	for (size_t i = 0; i < 4; ++i)
		intArray.push_back(i);

	std::set<int> map1(intArray.begin(), intArray.end());


	if(easyfind(intArray, 10))
		std::cout << "Found" << std::endl;
	else
		std::cout << "not Found" << std::endl;


	if(easyfind(map1, 3))
		std::cout << "Found" << std::endl;
	else
		std::cout << "not Found" << std::endl;


}