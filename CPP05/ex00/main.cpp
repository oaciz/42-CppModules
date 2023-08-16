#define warning "error"
#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat omer("ömer", 200);
		omer.decrement();
		std::cout << omer << std::endl;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
}