#define warning "error"
#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat omer("ömer", 32);

		std::cout << omer << std::endl;
		omer.decrement();
		std::cout << omer << std::endl;
		omer.increment();
		omer.increment();
		omer.increment();
		std::cout << omer << std::endl;
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	
}