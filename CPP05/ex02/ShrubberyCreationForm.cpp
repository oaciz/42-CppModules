#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Default", 145, 137),_target("Default Target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target_):AForm("Default", 145, 137),_target(target_) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &var):AForm("ShrubberyCreationForm", 145, 137), _target(var.getTarget()) {
	*this = var;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

std::string ShrubberyCreationForm::getTarget() const{
	return this->_target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &var) {
	if (this == &var)
		return *this;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	std::cout << "get grade: " << executor.getGrade() << " get exec: " << this->getExec() << std::endl;
	if((int)executor.getGrade() > this->getExec())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->isSigned() == false){
		throw(AForm::GradeTooSignedException());
	}
	else
	{
		std::ofstream ofs(this->getTarget() + "_shrubbery");
		if (!ofs.is_open())
			throw std::ofstream::failure(strerror(errno));
		ofs << "               ,@@@@@@@," << std::endl;
		ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
		ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
		ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
		ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
		ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
		ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
		ofs << "       |o|        | |         | |" << std::endl;
		ofs << "       |.|        | |         | |" << std::endl;
		ofs << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;

	}
}

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm &var){
	out << "Form " << var.getName() <<
	  ":\n\tsign-grade:\t" << var.getRequire() <<
	  "\n\texec-grade:\t" << var.getExec() <<
	  "\n\tis signed:\t" << var.isSigned() <<
	  std::endl;
	return (out);
}