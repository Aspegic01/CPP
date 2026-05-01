#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main (){
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;
	Bureaucrat a("a",1);
	a.executeForm(*rrf);
	a.signForm(*rrf);
	a.executeForm(*rrf);
	delete rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "a");
	delete rrf;
}