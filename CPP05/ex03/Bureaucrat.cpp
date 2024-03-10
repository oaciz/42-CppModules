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
	this->setGrade(--(this->grade));
}

void	Bureaucrat::increment()
{
	this->setGrade(++(this->grade));
}

void	Bureaucrat::setGrade(int _grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
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