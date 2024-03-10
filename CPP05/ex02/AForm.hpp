#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string		name;
	mutable bool isSign;
	int			requireToSign;
	int			execToSign;
public:
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "AForm Grade To High";
			}
	};
	class GradeTooLowException:public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "AForm Grade To Low";
			}
	};
	class GradeTooSignedException:public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "Form Not Signed";
			}
	};

	AForm();
	AForm(const std::string _name);
	AForm(const std::string _name, int _requireToSign, int _execToSign);
	AForm(const AForm &var);
	virtual ~AForm();
	AForm &operator=(const AForm &var);

	std::string	getName() const;
	int		getRequire() const;
	int		getExec() const;

	void	setRequire(int _requireToSign);
	void	setExec(int	_execToSign);

	void beSigned(const Bureaucrat& var) const;
	bool	isSigned() const;
	virtual	void	execute(const Bureaucrat &executor) const = 0;

};

std::ostream &operator<<(std::ostream &out, const AForm &var);
#endif