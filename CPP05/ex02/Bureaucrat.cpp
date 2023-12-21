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
		throw GradeTooHighException();
	else
		grade++;
}

void	Bureaucrat::increment()
{
	if(grade < 1)
			throw GradeTooLowException();
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

void Bureaucrat::signForm(const AForm &var) const {
	var.beSigned(*this);
}


void	Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << name << " couldn't execute " << form.getName() + " because ";

		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out , const Bureaucrat& var){
	out << "Bureaucrat name => " << var.getName() << " | his grade => " << var.getGrade();
	return (out);
}