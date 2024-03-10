#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Omar"),grade(150){}

Bureaucrat::Bureaucrat(std::string _name) : name(_name), grade(150){}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
{
	setGrade(_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &var)
{
	*this = var;
}

Bureaucrat::~Bureaucrat(){}

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
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = _grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &var) {
	setGrade(var.grade);
	return (*this);
}

void	Bureaucrat::signForm(Form &form) const
{
	if (form.isSigned())
		std::cout << this->getName() << " signed "<< form.getName() << std::endl;
	else if (this->grade < form.getRequireToSign())
		form.beSigned(*this);
	else
		std::cout << this->getName() << " could'nt sign "<< form.getName() << " because " << "Bureaucrat's Grade To Low" << std::endl;
}
std::ostream &operator<<(std::ostream &out , const Bureaucrat& var){
	out << "Bureaucrat name => " << var.getName() << " | his grade => " << var.getGrade();
	return (out);
}