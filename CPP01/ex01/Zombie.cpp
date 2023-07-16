#include "Zombie.hpp"

Zombie::Zombie(string name) : _name(name)
{

}
Zombie::Zombie() : _name("undefined")
{

}
void	Zombie::setName(string name)
{
	_name = name;
}

void Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": zombie death" << std::endl;
}
