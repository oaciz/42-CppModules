#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>


class Bureaucrat
{
private:
	std::string name;
	int		grade;
public:
	Bureaucrat();
	Bureaucrat(std::string _name);
	Bureaucrat(std::string _name, int _grade);
	Bureaucrat(const Bureaucrat &oth);
	Bureaucrat& operator=(const Bureaucrat &var);
	~Bureaucrat();

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Grade To High";
		}	
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Grade To Low";
		}
	};

	int 	getGrade() const;
	void	setGrade(int _grade);
	std::string	getName() const;
	void	increment();
	void	decrement();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat& var);
#endif