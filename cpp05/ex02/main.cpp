#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(std::time(0));

    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat low("LowWorker", 150);

        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robo("Unit42");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << "\n--- Initial forms ---\n";
        std::cout << shrub << std::endl;
        std::cout << robo << std::endl;
        std::cout << pardon << std::endl;

        std::cout << "\n--- Low tries to sign shrub (should fail) ---\n";
        low.signForm(shrub);

        std::cout << "\n--- Boss signs all ---\n";
        boss.signForm(shrub);
        boss.signForm(robo);
        boss.signForm(pardon);

        std::cout << "\n--- Low tries to execute shrub (should fail) ---\n";
        low.executeForm(shrub);

        std::cout << "\n--- Boss executes all ---\n";
        boss.executeForm(shrub);
        boss.executeForm(robo);
        boss.executeForm(pardon);

        std::cout << "\n--- End ---\n";
    }
    catch (std::exception &e) {
        std::cout << "UNCAUGHT EXCEPTION: " << e.what() << std::endl;
    }

    return 0;
}
