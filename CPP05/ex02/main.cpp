#define warning "error"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try{
		Bureaucrat a("Bob", 73);
		//ShrubberyCreationForm form("Form");
		 RobotmyRequestForm asd("Form2");
		// PresidentialPardonForm abc("Form3");

		//a.signForm(abc);
		//a.executeForm(abc);
		//a.signForm(asd);
		//a.executeForm(asd);
		a.signForm(asd);
		asd.execute(a);
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}