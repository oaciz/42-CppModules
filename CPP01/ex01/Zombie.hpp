#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

using std::string;

class Zombie
{
	private:
		string	_name;
	
	public:
		Zombie(string name);
		Zombie();
		void	setName(string name);
		void announce( void );
		~Zombie();
};

#endif
