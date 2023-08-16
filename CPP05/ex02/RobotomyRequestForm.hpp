#ifndef ROBOTMYREQUESTFORM_HPP
#define	ROBOTMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Aform.hpp"

class Bureaucrat;
class Aform;

class RobotmyRequestForm:public Aform
{
private:
	const std::string target;
public:
	RobotmyRequestForm();
	RobotmyRequestForm(std::string _target);
	RobotmyRequestForm(const RobotmyRequestForm &var);
	RobotmyRequestForm &operator=(const RobotmyRequestForm &var);
	~RobotmyRequestForm();
	void	execute(Bureaucrat const &executor) const;
	std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &out, RobotmyRequestForm &var);

#endif