#include "Form.hpp"

Form::Form() :
name("Defaul Name"), isSign(false),requireToSign(150),execToSign(150)
{
	cout << "Const Called" << endl;
}

Form::Form(const string _name)
:name(_name), isSign(false),requireToSign(150),execToSign(150)
{
	cout << "Name Const Called" << endl;
}

Form::Form(const string _name, int _requireToSign, int _execToSign)
:name(_name),isSign(false),requireToSign(_requireToSign),execToSign(_execToSign)
{
	cout << "Name Other Value Const Called" << endl;
}

Form::Form(const Form &var) 
:name(var.name),isSign(var.isSign),requireToSign(var.requireToSign),execToSign(var.execToSign)
{
	cout << "Copy Const Called" << endl;
}

Form::~Form()
{
	cout << "Form Deconst Called" << endl;
}

Form	&Form::operator=(const Form &var)
{
	(void)var;
	return(*this);
}

string Form::getName() const
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

void	Form::setRequireToSign(int _requireToSign)
{
	this->requireToSign = _requireToSign;
}

void	Form::setExecToSign(int _execToSign)
{
	this->execToSign = _execToSign;
}

void	Form::beSigned(const Bureaucrat &var) const
{
	if(var.getGrade() <= this->requireToSign)
	{
		this->isSign = true;
		cout << var.getName() << " signed " << this->name << endl;
	}
	else
	{
		cout << getName() << " Couldn't signed " << this->name << " Because To Low Then Sign Grade" << endl;
		throw GradeToLowException();
	}

}

bool	Form::isSigned() const
{
	return this->isSign;
}

ostream &operator<<(ostream &out , const Form& var)
{
	out << var.getName() + " form is " << (var.isSigned() ? "signed," : "not signed,");
	out << " requires grade " << var.isSigned() << " to sign and grade ";
	out << var.getExecToSign() << " to execute";
	return (out);
}