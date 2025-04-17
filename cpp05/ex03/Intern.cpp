#include "Intern.hpp"

Intern::~Intern(void) {
	std::cout << "DESTRUCTOR: The Intern has finished the day." << std::endl;
}

Intern::Intern(const Intern &intern) {
	(void) intern;
}

Intern& Intern::operator=(const Intern& intern) {
	(void) intern;
	return (*this);
}

std::string split(std::string& s, const std::string& delimiter) {

    size_t pos = 0;
    std::string token = "";
    if ((pos = s.find(delimiter)) != std::string::npos)
	{
        token = s.substr(0, pos);
        s.erase(0, pos + delimiter.length());
		while (!strncmp(s.c_str(), delimiter.c_str(), delimiter.length()))
        	s.erase(0, delimiter.length());
	}
	else
	{
		token = s;
		s = "";
	}
	return (token);
}

std::string getFormName(std::string name)
{
	std::string next_token = "";
	std::string formName = "";

	while ((next_token = split(name, " ")).compare(""))
	{
		next_token[0] = toupper(next_token[0]);
		formName += next_token;
	}
	if (strncmp(&(formName.c_str())[formName.length() - 4], "Form", strlen("Form")))
	{
		formName += "Form";
	}
	return (formName);
}

/* 
	1. Trimear
	2. Quitar espacios
	3. Tener un array con todos los nombres
	4. IsIn??
*/
AForm *Intern::makeForm(std::string name, std::string target) {
	size_t index = 0;
	std::string formName = getFormName(name);
	std::cout << formName << std::endl;
	std::string formTypes[] = {"ShruberryCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	while (index < 3)
	{
		if (formName == formTypes[index])
			break ;
		index++;
	}
	if (index < 3)	
	{
		switch(index)
		{
			case 0:
			{
				ShrubberyCreationForm *form = new ShrubberyCreationForm(target);
				std::cout << "Intern creates " << *form << std::endl;
				return (form);
			}
			case 1:
			{
				RobotomyRequestForm *form = new RobotomyRequestForm(target);
				std::cout << "Intern creates " << *form << std::endl;
				return (form);
			}
			case 2:
			{
				PresidentialPardonForm *form = new PresidentialPardonForm(target);
				std::cout << "Intern creates " << *form << std::endl;
				return (form);
			}
		}
	}
	std::cout << "The provided Form type does not exist!!" << std::endl;
	return (NULL);
}