#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern_bur("Intern", 150);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur");

    std::cout << boss << std::endl;
    std::cout << intern_bur << std::endl;

    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pardon << std::endl;

    // Demonstrate signing/exec flows (clear and short for corrector)
    intern_bur.signForm(shrub); // expected to fail
    boss.signForm(shrub);
    boss.executeForm(shrub);

    boss.signForm(robot);
    boss.executeForm(robot);

    boss.signForm(pardon);
    boss.executeForm(pardon);

    std::cout << "\n----- Intern makeForm tests -----" << std::endl;
    Intern intern_obj;

    AForm *form1 = intern_obj.makeForm("shrubbery creation", "park");
    AForm *form2 = intern_obj.makeForm("robotomy request", "Marvin");
    AForm *form3 = intern_obj.makeForm("presidential pardon", "Ford");

    std::cout << *form1 << std::endl;
    std::cout << *form2 << std::endl;
    std::cout << *form3 << std::endl;

    boss.signForm(*form1);
    boss.executeForm(*form1);

    delete form1;
    delete form2;
    delete form3;

    std::cout << "\n----- Intern invalid form test -----" << std::endl;
    try
    {
        AForm *invalid = intern_obj.makeForm("invalid form", "target");
        (void)invalid;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}