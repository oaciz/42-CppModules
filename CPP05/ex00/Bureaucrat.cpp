#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("ÖMER"),grade(150)
{
	std::cout << "Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name) : name(_name), grade(150)
{
	std::cout << "Name Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
{
	if(_grade <= 1){
		throw GradeTooHighException();
	}
	else if(_grade >= 150)
		throw GradeTooLowException();
	setGrade(_grade);
	std::cout << "Name & Grade Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &var)
{
	*this = var;
	std::cout << "Copy Const Called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Deconst Called" << std::endl;
}

int	Bureaucrat::getGrade() const
{
	return grade;
}

std::string Bureaucrat::getName() const
{
	return name;
}

void	Bureaucrat::decrement()
{
	if(grade > 150)
		throw GradeTooLowException();
	else
		grade++;
}

void	Bureaucrat::increment()
{
	if(grade < 1)
		throw GradeTooHighException();
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

std::ostream &operator<<(std::ostream &out , const Bureaucrat& var){
	out << "Bureaucrat name => " << var.getName() << " | his grade => " << var.getGrade();
	return (out);
}