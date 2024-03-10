#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

# include <string>
# include <iostream>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public AForm
{
private:
	const std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target_);
	ShrubberyCreationForm(const ShrubberyCreationForm& var);
	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& var);

	void execute(Bureaucrat const &executor) const;
	std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm &var);


#endif