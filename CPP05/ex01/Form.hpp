#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

using std::string;

class Bureaucrat;

class Form
{
private:
	const string	name;
	mutable bool	isSign;
	int				requireToSign;
	int				execToSign;

public:
	class GradeToHighException : public std::exception
	{
		public:
			const char *what() const throw()
			{
				return "Form Grade To High";
			}
	};
	class GradeToLowException : public std::exception
	{
		public:
			const char *what() const throw()
			{
				return "Form Grade To Low";
			}
	};

	Form();
	Form(const string _name);
	Form(const string _name, int _requireToSign, int _execToSign);
	Form(const Form &var);
	~Form();
	Form &operator=(const Form &var);

	string getName() const;
	int getRequireToSign() const;
	int	getExecToSign() const;

	void	setRequireToSign(int _requireToSign);
	void	setExecToSign(int _execToSign);

	void	beSigned(const Bureaucrat &var) const;
	bool	isSigned() const;
};
std::ostream &operator<<(std::ostream &out , const Form& var);
#endif