#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try{
		Bureaucrat bureaucrat("Bob", 2);
		Form form("Form", 5, 5);
		bureaucrat.signForm(form);

	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}