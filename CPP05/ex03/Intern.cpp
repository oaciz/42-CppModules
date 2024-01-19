#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {
	std::cout << "Intern Default Const Called" << std::endl;
}

Intern::Intern(const Intern &var) {
	*this = var;
	std::cout << "Intern Copy Const Called" << std::endl;
}

Intern &Intern::operator=(const Intern &var) {
	(void)var;
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern Deconst Called" << std::endl;
}

AForm *Intern::makeShrubberyCreationForm(const std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makePresidentialPardonForm(const std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRobotomyRequestForm(const std::string target) {
	return (new RobotmyRequestForm(target));
}

AForm *Intern::makeForm(const std::string _name, const std::string target) {
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm	*(Intern::*fnPtr[3])(const std::string);
	bool formFound = false;
	int i;

	i = -1;
	fnPtr[0] = &Intern::makeShrubberyCreationForm;
	fnPtr[1] = &Intern::makeRobotomyRequestForm;
	fnPtr[2] = &Intern::makePresidentialPardonForm;
	while(++i < 3){
		if (_name == forms[i]){
			std::cout << "Intern Creates " << _name << std::endl;
			formFound = true;
			break ;
		}
	}
	try{
		if(!formFound)
			throw (FormNotFound());
		return (this->*fnPtr[i])(target);
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
		return (NULL);
	}
}