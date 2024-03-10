#include "RobotomyRequestForm.hpp"

RobotmyRequestForm::RobotmyRequestForm():AForm("RobotmyRequestForm", 72, 45), target("Default"){}

RobotmyRequestForm::RobotmyRequestForm(std::string _target): AForm("RobotmyRequestForm", 72, 45), target(_target){}

RobotmyRequestForm::RobotmyRequestForm(const RobotmyRequestForm &var):AForm("RobotmyRequestForm", 72, 45),target(var.target)
{
	*this = var;
}

RobotmyRequestForm::~RobotmyRequestForm(){}

RobotmyRequestForm &RobotmyRequestForm::operator=(const RobotmyRequestForm &var)
{
	if(this != &var)
		*this = var;
	return *this;

}

std::string RobotmyRequestForm::getTarget() const
{
	return this->target;
}

void	RobotmyRequestForm::execute(const Bureaucrat &executor) const
{
	srand(time(0));
	if((int)executor.getGrade() > this->getExec())
		throw (Bureaucrat::GradeTooLowException());
	else if(rand() % 2 == 0)
		std::cout << "UrrrrrrrrrU" << this->getTarget() << "Do robotic sound" << std::endl;
	else
		std::cout << "Robotomy BOOOOOOOOMMMM!!!" << std::endl;
}

std::ostream &operator<<(std::ostream &out, RobotmyRequestForm &var)
{
	out << "Form " << var.getName() <<
	":\ntsignn-grade:\t" << var.getRequire() <<
	"\ntexec-grade:\t" << var.getExec() <<
	"\ntis signed:\t" << var.isSigned() <<
	std::endl;
	return out;
}