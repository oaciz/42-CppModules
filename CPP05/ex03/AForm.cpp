#include "AForm.hpp"

AForm::AForm() : name("Default Name"), isSign(false), requireToSign(25), execToSign(20)
{
	std::cout << "Const Called" << std::endl;
}

AForm::AForm(std::string _name) : name(_name), isSign(false), requireToSign(25), execToSign(20)
{
	std::cout << "Name const Called" << std::endl;
}

AForm::AForm(std::string _name, int _requireToSign, int _execToSign) : name(_name), isSign(false), requireToSign(_requireToSign), execToSign(_execToSign) 
{
	if (requireToSign > 150)
		throw GradeTooLowException();
	else if (requireToSign < 1)
		throw GradeTooHighException();
	std::cout << "Name And Const Called" << std::endl;
}

AForm::AForm(const AForm &var) : name(var.name), isSign(false), requireToSign(var.requireToSign), execToSign(var.execToSign)
{
	std::cout << "Copy Const Called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Deconts Called" << std::endl;
}

std::string AForm::getName() const
{
	return this->name;
}

int	AForm::getRequire() const
{
	return this->requireToSign;
}

int	AForm::getExec() const
{
	return this->execToSign;
}

void	AForm::setRequire(int _requireToSign)
{
	this->requireToSign = _requireToSign;
}

void	AForm::setExec(int _execToSign)
{
	this->execToSign = _execToSign;
}

bool	AForm::isSigned() const
{
	return this->isSign;
}

void AForm::beSigned(const Bureaucrat& var) const
{
	if(var.getGrade() <= this->requireToSign)
	{
		this->isSign = true;
		std::cout << var.getName() << " signed " << this->name << std::endl;
	}
	else
	{
		std::cout << var.getName() << " Couldn't sign " << this->name << " Because To Low Then Sign Grade" << std::endl;
		throw GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &out , const AForm &var)
{
	out << var.getName() + " form is " << (var.isSigned() ? "signed," : "not signed,");
	out << " requires grade " << var.isSigned() << " to sign and grade ";
	out << var.getExec() << " to execute";
	return (out);
}