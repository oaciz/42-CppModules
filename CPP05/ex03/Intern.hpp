#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP
# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;

class Intern {
private:
	AForm   *makeShrubberyCreationForm(const std::string target);
	AForm   *makeRobotomyRequestForm(const std::string target);
	AForm   *makePresidentialPardonForm(const std::string target);
public:
	Intern();
	Intern(const Intern& var);
	Intern &operator=(const Intern& var);
	~Intern();

	AForm	*makeForm(const std::string _name, const std::string target);

	class FormNotFound:public std::exception{
		public:
			const char* what() const throw(){
				return "Form Not Found";
			}
	};
};

#endif