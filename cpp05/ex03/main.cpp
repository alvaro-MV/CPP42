#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "\n===== TEST 1: INTERN CREATES ALL FORMS =====\n";
    try {
        Intern someRandomIntern;
        AForm *form1 = someRandomIntern.makeForm("shrubbery creation", "Garden");
        AForm *form2 = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm *form3 = someRandomIntern.makeForm("presidential pardon", "Marvin");

        std::cout << "\nCreated forms:\n";
        std::cout << *form1 << std::endl;
        std::cout << *form2 << std::endl;
        std::cout << *form3 << std::endl;

        delete form1;
        delete form2;
        delete form3;
    }
    catch (std::exception &e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 2: INTERN FAILS WITH NON-EXISTENT FORM =====\n";
    try {
        Intern intern;
        AForm *bad = intern.makeForm("whatever this is", "Target");
        if (!bad)
            std::cout << "\nIntern returned NULL as expected.\n";
        delete bad;
    }
    catch (std::exception &e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 3: SIGNING AND EXECUTING FORMS =====\n";
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat low("LowWorker", 150);
        Intern intern;

        AForm *shrub = intern.makeForm("Shrubbery Creation", "Home");

        std::cout << "\n-- Attempt by low worker to sign --\n";
        low.signForm(*shrub);

        std::cout << "\n-- Boss signs the form --\n";
        boss.signForm(*shrub);

        std::cout << "\n-- Low worker tries to execute --\n";
        low.executeForm(*shrub);

        std::cout << "\n-- Boss executes --\n";
        boss.executeForm(*shrub);

        delete shrub;
    }
    catch (std::exception &e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 4: ROBOTOMY RANDOMNESS =====\n";
    try {
        Bureaucrat exec("Exec", 1);
        Intern intern;
        AForm *robo = intern.makeForm("robotomy request", "Unit42");

        exec.signForm(*robo);

        std::cout << "\n-- Execute robotomy 5 times to test randomness --\n";
        for (int i = 0; i < 5; i++)
            exec.executeForm(*robo);

        delete robo;
    }
    catch (std::exception &e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 5: PRESIDENTIAL PARDON =====\n";
    try {
        Bureaucrat president("President", 2);
        Intern intern;

        AForm *pardon = intern.makeForm("presidential pardon", "Arthur Dent");

        std::cout << "\n-- President signs --\n";
        president.signForm(*pardon);

        std::cout << "\n-- President executes --\n";
        president.executeForm(*pardon);

        delete pardon;
    }
    catch (std::exception &e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 6: FORM EXECUTION WITHOUT SIGNATURE =====\n";
    try {
        Bureaucrat boss("Boss", 1);
        Intern intern;
        AForm *shrub = intern.makeForm("shrubbery creation", "Backyard");

        std::cout << "\n-- Boss tries to execute without signing --\n";
        boss.executeForm(*shrub);

        delete shrub;
    }
    catch (std::exception &e) {
        std::cout << "Expected error: " << e.what() << std::endl;
    }

    std::cout << "\n===== ALL TESTS COMPLETED =====\n\n";
    return 0;
}
