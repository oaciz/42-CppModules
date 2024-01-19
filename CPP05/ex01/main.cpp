#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat bureaucrat("Bob", 120);
	Form form("Form", 130, 130);
	try{
		bureaucrat.signForm(form);
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}