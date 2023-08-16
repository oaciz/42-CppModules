#include "Aform.hpp"

Aform::Aform() : name("Default Name"), isSign(false), requireToSign(150), execToSign(150)
{
	cout << "Const Called" << endl;
}

Aform::Aform(string _name) : name(_name), isSign(false), requireToSign(150), execToSign(150)
{
	cout << "Name const Called" << endl;
}

Aform::Aform(string _name, int _requireToSign, int _execToSign) : name(_name), isSign(false), requireToSign(_requireToSign), execToSign(_execToSign) 
{
	cout << "Name And Const Called" << endl;
}

Aform::Aform(const Aform &var) : name(var.name), isSign(false), requireToSign(var.requireToSign), execToSign(var.execToSign)
{
	cout << "Copy Const Called" << endl;
}

Aform::~Aform()
{
	cout << "Deconts Called" << endl;
}

string Aform::getName() const
{
	return this->name;
}

int	Aform::getRequire() const
{
	return this->requireToSign;
}

int	Aform::getExec() const
{
	return this->execToSign;
}

void	Aform::setRequire(int _requireToSign)
{
	this->requireToSign = _requireToSign;
}

void	Aform::setExec(int _execToSign)
{
	this->execToSign = _execToSign;
}

bool	Aform::isSigned() const
{
	return this->isSign;
}

void	Aform::beSigned(Bureaucrat &var) const
{
	if(var.getGrade() <= this->requireToSign)
	{
		this->isSign = true;
		cout << var.getName() << " signed " << this->name << endl;
	}
	else
	{
		cout << var.getName() << " Couldn't sign " << this->name << " Because To Low Then Sign Grade" << endl;
		throw GradeToLowException();
	}
}

ostream &operator<<(std::ostream &out , const Aform &var)
{
	out << var.getName() + " form is " << (var.isSigned() ? "signed," : "not signed,");
	out << " requires grade " << var.isSigned() << " to sign and grade ";
	out << var.getExec() << " to execute";
	return (out);
}