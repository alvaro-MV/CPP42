#include "Intern.hpp"

Intern::Intern() {}

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
	AForm *form;
	size_t index = 0;
	std::string formName = getFormName(name);
	std::string formTypes[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	std::string creationStr[] = {"Intern creates ", "Intern creates ", "Intern creates ", "The provided Form type does not exist!!"};

	while (index < 3 && formName != formTypes[index])
		index++;

	std::cout << creationStr[index];
	switch(index)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			return (NULL);
	}
	std::cout << *form;
	return (form);
}