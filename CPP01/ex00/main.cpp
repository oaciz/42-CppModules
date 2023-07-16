#include "Zombie.hpp"

void randomChump( std::string name );
Zombie* newZombie( std::string name );

int	main()
{
	randomChump("ismail");

	Zombie* zombieptr = newZombie("Talha");
	
	zombieptr->announce();
	delete zombieptr;
	
	std::cout << "The Last Message" << std::endl;
}