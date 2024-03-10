#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try{
		Bureaucrat	chad("Chad", 2);
		Intern		asd;
		AForm		*forms[4];

		forms[0] = asd.makeForm("shrubbery creation", "document");
		forms[1] = asd.makeForm("robotomy request", "Marie");
		forms[2] = asd.makeForm("presidential pardon", "Marie");
		forms[3] = asd.makeForm("robotomy request", "random");
		//forms[3] = asd.makeForm("random request", "random");

		for (int i = 0; i < 4; ++i)
		{
			if (forms[i])
			{
				std::cout << std::endl << *(forms[i]) << "   a    " << std::endl;
				chad.signForm(*(forms[i]));
				chad.executeForm(*(forms[i]));
			}
		}

		for (int i = 0; i < 4; i++)
			delete forms[i];
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}