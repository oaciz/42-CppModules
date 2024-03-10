#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string _target);
	PresidentialPardonForm(PresidentialPardonForm &var);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &var);
	void	execute(Bureaucrat const &executor) const;
	std::string	getTarget() const;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm *a);