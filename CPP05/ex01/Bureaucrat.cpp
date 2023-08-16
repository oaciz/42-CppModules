#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("ÖMER"),grade(150)
{
	cout << "Default Constructor Called" << endl;
}

Bureaucrat::Bureaucrat(string _name) : name(_name), grade(150)
{
	cout << "Name Constructor Called" << endl;
}

Bureaucrat::Bureaucrat(string _name, int _grade) : name(_name)
{
	setGrade(_grade);
	cout << "Name & Grade Constructor Called" << endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &var)
{
	*this = var;
	cout << "Copy Const Called" << endl;
}

Bureaucrat::~Bureaucrat()
{
	cout << "Deconst Called" << endl;
}

int	Bureaucrat::getGrade() const
{
	return grade;
}

string Bureaucrat::getName() const
{
	return name;
}

void	Bureaucrat::decrement()
{
	if(grade > 150)
		throw GradeToHighException();
	else
		grade++;
}

void	Bureaucrat::increment()
{
	if(grade < 1)
			throw GradeToLowException();
		else
			grade--;
}

void	Bureaucrat::setGrade(int _grade)
{
	grade = _grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &var) {
	setGrade(var.grade);
	return (*this);
}

void	Bureaucrat::signForm(const Form &var) const
{
	var.beSigned(*this);
}
std::ostream &operator<<(std::ostream &out , const Bureaucrat& var){
	out << "Bureaucrat name => " << var.getName() << " | his grade => " << var.getGrade();
	return (out);
}