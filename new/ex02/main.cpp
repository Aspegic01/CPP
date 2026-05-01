#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur");

    std::cout << boss << std::endl;
    std::cout << intern << std::endl;

    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pardon << std::endl;

    // Demonstrate signing/exec flows (clear and short for corrector)
    intern.signForm(shrub); // expected to fail
    boss.signForm(shrub);
    boss.executeForm(shrub);

    boss.signForm(robot);
    boss.executeForm(robot);

    boss.signForm(pardon);
    boss.executeForm(pardon);

    return 0;
}