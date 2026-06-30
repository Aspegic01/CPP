#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern::~Intern() {}
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }

AForm* Intern::makeForm(const std::string &name, const std::string &target) {
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    int i = 0;
    
    while (i < 3 && formNames[i] != name) {
        i++;
    }

    switch (i) {
        case 0:
            std::cout << "Intern creates " << name << std::endl;
            return new ShrubberyCreationForm(target);
        case 1:
            std::cout << "Intern creates " << name << std::endl;
            return new RobotomyRequestForm(target);
        case 2:
            std::cout << "Intern creates " << name << std::endl;
            return new PresidentialPardonForm(target);
        default:
            std::cout << "Error: Intern cannot create form '" << name << "' (Unknown type)" << std::endl;
            return NULL;
    }
}