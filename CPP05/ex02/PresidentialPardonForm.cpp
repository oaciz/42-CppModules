#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():Aform("PresidentialPardonForm", 25, 5), target("Default")
{
	cout << "Presi Default Const Called" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(string _target) : Aform("PresidentialPardonForm", 25, 5), target(_target)
{
	cout << "Presi Target Const Called" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &var)
{
	cout << "PresidentialPardonForm Copy Const Called" << var.getName() << " into " << this->getName();
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &var)
{
	cout << "PresidentialPardonForm Deconstructor " << this->getName() << " Called" << endl;
	if(this != &var)
		*this = var;
	return *this;
}

string PresidentialPardonForm::getTarget() const
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