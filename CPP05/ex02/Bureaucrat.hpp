#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
#include "AForm.hpp"

class AForm;
using std::string;
using std::cout;
using std::endl;
using std::exception;
using std::ostream;

class Bureaucrat
{
private:
	string	name;
	int		grade;
public:
	Bureaucrat();
	Bureaucrat(string _name);
	Bureaucrat(string _name, int _grade);
	Bureaucrat(const Bureaucrat &oth);
	Bureaucrat& operator=(const Bureaucrat &var);
	~Bureaucrat();

	class GradeTooHighException : public exception
	{
	public:
		const char *what() const throw()
		{
			return "Grade To High";
		}	
	};
	class GradeTooLowException : public exception
	{
	public:
		const char *what() const throw()
		{
			return "Grade To Low";
		}
	};

	int 	getGrade() const;
	void	setGrade(int _grade);
	string	getName() const;
	void	increment();
	void	decrement();
	void 	signForm(const AForm &var) const;
	void	executeForm(const AForm &form);
};

ostream &operator<<(ostream &out, const Bureaucrat& var);
#endif