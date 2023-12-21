#include "AForm.hpp"

AForm::AForm() : name("Default Name"), isSign(false), requireToSign(150), execToSign(150)
{
	cout << "Const Called" << endl;
}

AForm::AForm(string _name) : name(_name), isSign(false), requireToSign(150), execToSign(150)
{
	cout << "Name const Called" << endl;
}

AForm::AForm(string _name, int _requireToSign, int _execToSign) : name(_name), isSign(false), requireToSign(_requireToSign), execToSign(_execToSign) 
{
	cout << "Name And Const Called" << endl;
}

AForm::AForm(const AForm &var) : name(var.name), isSign(false), requireToSign(var.requireToSign), execToSign(var.execToSign)
{
	cout << "Copy Const Called" << endl;
}

AForm::~AForm()
{
	cout << "Deconts Called" << endl;
}

string AForm::getName() const
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
		cout << var.getName() << " signed " << this->name << endl;
	}
	else
	{
		cout << var.getName() << " Couldn't sign " << this->name << " Because To Low Then Sign Grade" << endl;
		throw GradeTooLowException();
	}
}

ostream &operator<<(std::ostream &out , const AForm &var)
{
	out << var.getName() + " form is " << (var.isSigned() ? "signed," : "not signed,");
	out << " requires grade " << var.isSigned() << " to sign and grade ";
	out << var.getExec() << " to execute";
	return (out);
}