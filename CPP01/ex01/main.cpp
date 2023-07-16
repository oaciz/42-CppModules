#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main()
{
	Zombie *zombieptr;
	int	count = 42;

	zombieptr = zombieHorde(count, "ecoleZombies");

	if(zombieptr != NULL)
	{
		for (int i = 0; i < count; i++)
			zombieptr[i].announce();
		delete[] zombieptr;
	}
}