#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombieptr;

	if(N <= 0 || name.empty())
		return (NULL);
	
	zombieptr = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombieptr[i].setName(name);
	}

	return (zombieptr);
}