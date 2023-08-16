#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

using std::string;
using std::endl;

class Bureaucrat;

class Aform
{
private:
	string		name;
	mutable bool isSign;
	int			requireToSign;
	int			execToSign;
public:
	class GradeToHighException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Aform Grade To High";
		}	
	};
	
	class GradeToLowException
	{
	public:
		const char *what() const throw()
		{
			return "Aform Grade To Low";
		}
	};

	class GradeToSignedException
	{
	public:
		const char *what() const throw()
		{
			return "Form Not Signed";
		}
	};

	Aform();
	Aform(const string _name);
	Aform(const string _name, int _requireToSign, int _execToSign);
	Aform(const Aform &var);
	virtual ~Aform();
	Aform &operator=(const Aform &var);

	string	getName() const;
	int		getRequire() const;
	int		getExec() const;

	void	setRequire(int _requireToSign);
	void	setExec(int	_execToSign);

	void	beSigned(Bureaucrat &var) const;
	bool	isSigned() const;
	virtual	void	execute(const Bureaucrat &executor) const = 0;

};

std::ostream &operator<<(std::ostream &out, const Aform &var);
#endif