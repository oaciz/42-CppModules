#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"


class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool		isSign;
	const int	requireToSign;
	const int	execToSign;

public:
	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw()
			{
				return "Couldn't signed because Bureaucrat's Grade To High";
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw()
			{
				return "Couldn't signed because Bureaucrat's Grade To Low";
			}
	};

	Form();
	Form(const std::string _name);
	Form(const std::string _name, int _requireToSign, int _execToSign);
	Form(const Form &var);
	~Form();
	Form &operator=(const Form &var);

	std::string getName() const;
	int getRequireToSign() const;
	int	getExecToSign() const;

	void	beSigned(const Bureaucrat &var);
	bool	isSigned() const;
};
std::ostream &operator<<(std::ostream &out , const Form& var);
#endif