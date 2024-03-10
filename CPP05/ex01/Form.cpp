#include "Form.hpp"

Form::Form() :
name("Defaul Name"), isSign(false),requireToSign(150),execToSign(150){}

Form::Form(const std::string _name)
:name(_name), isSign(false),requireToSign(150),execToSign(150){}

Form::Form(const std::string _name, int _requireToSign, int _execToSign)
:name(_name),isSign(false),requireToSign(_requireToSign),execToSign(_execToSign)
{
	if (requireToSign > 150)
		throw GradeTooLowException();
	else if (requireToSign < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &var) 
:name(var.name),isSign(var.isSign),requireToSign(var.requireToSign),execToSign(var.execToSign){}

Form::~Form(){}

Form	&Form::operator=(const Form &var)
{
	(void)var;
	return(*this);
}

std::string Form::getName() const
{
	return this->name;
}

int Form::getRequireToSign() const
{
	return this->requireToSign;
}

int	Form::getExecToSign() const
{
	return this->execToSign;
}

void	Form::beSigned(const Bureaucrat &var)
{
	if(var.getGrade() <= this->requireToSign)
	{
		this->isSign = true;
		std::cout << var.getName() << " signed " << this->name << std::endl;
	}
	else
		throw GradeTooLowException();

}

bool	Form::isSigned() const
{
	return this->isSign;
}

std::ostream &operator<<(std::ostream &out , const Form& var)
{
	out << var.getName() + " form is " << (var.isSigned() ? "signed," : "not signed,");
	out << " requires grade " << var.isSigned() << " to sign and grade ";
	out << var.getExecToSign() << " to execute";
	return (out);
}