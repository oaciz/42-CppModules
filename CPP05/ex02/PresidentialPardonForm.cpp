#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", 25, 5), target("Default"){}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("PresidentialPardonForm", 25, 5), target(_target){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &var)
{
	std::cout << "PresidentialPardonForm Copy Const Called" << var.getName() << " into " << this->getName();
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Deconstructor " << this->getName() << " called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &var)
{
	std::cout << "PresidentialPardonForm Deconstructor " << this->getName() << " Called" << std::endl;
	if(this != &var)
		*this = var;
	return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->target;
}

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm &var)
{
	out << "Form " << var.getName() <<
	  ":\n\tsign-grade:\t" << var.getRequire() <<
	  "\n\texec-grade:\t" << var.getExec() <<
	  "\n\tis signed:\t" << var.isSigned() <<
	  std::endl;
	return (out);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if ((int)executor.getGrade() > this->getExec())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->isSigned() == false)
		throw (AForm::GradeTooSignedException());
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;

}