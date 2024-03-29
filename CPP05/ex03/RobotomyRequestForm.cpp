#include "RobotomyRequestForm.hpp"

static int randomnumber = 0;

RobotmyRequestForm::RobotmyRequestForm():AForm("RobotmyRequestForm", 72, 45), target("Default")
{
	std::cout << "Default Const Called" << std::endl;
}

RobotmyRequestForm::RobotmyRequestForm(std::string _target): AForm("RobotmyRequestForm", 0, 45), target(_target)
{
	std::cout << "Target Const Called" << std::endl;
}

RobotmyRequestForm::RobotmyRequestForm(const RobotmyRequestForm &var):AForm("RobotmyRequestForm", 0, 45),target(var.target)
{
	std::cout << "Copy Const Called" << std::endl;
	*this = var;
}

RobotmyRequestForm::~RobotmyRequestForm()
{
	std::cout << "Roboto Deconst " << this->getName() << " called " << std::endl;
}

RobotmyRequestForm &RobotmyRequestForm::operator=(const RobotmyRequestForm &var)
{
	std::cout << "RobotmyRequestForm Assignation operator called" << std::endl;
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
	if((int)executor.getGrade() > this->getExec())
		throw (Bureaucrat::GradeTooLowException());
	else if(randomnumber++ % 2 == 0)
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