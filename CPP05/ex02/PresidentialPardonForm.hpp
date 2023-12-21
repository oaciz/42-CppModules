#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

using std::cout;
using std::endl;
using std::string;

class PresidentialPardonForm : public AForm
{
private:
	const string target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(string _target);
	PresidentialPardonForm(PresidentialPardonForm &var);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &var);
	void	execute(Bureaucrat const &executor) const;
	string	getTarget() const;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm *a);