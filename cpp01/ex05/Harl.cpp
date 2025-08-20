#include "Harl.hpp"

Harl::Harl() {
	
	this->levels[0] = &Harl::debug;
	this->levels[1] = &Harl::info;
	this->levels[2] = &Harl::warning;
	this->levels[3] = &Harl::error;
	names[0] = "DEBUG";
	names[1] = "INFO",
	names[2] = "WARNING",
	names[3] = "ERROR";
}

Harl& Harl::operator=(const Harl& harl) {
	(void) harl;
	return (*this);
}

Harl::~Harl()
{

}

void Harl::debug(void) {
	
	std::cout << "[DEBUG]:" << std::endl;
	std::cout << "I love having extra bacon for" 
	<< "my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
	<< std::endl;
	std::cout << std::endl;
}

void Harl::info(void) {
	
	std::cout << "[INFO]:" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money."
	<< "You didn’t putenough bacon in my burger!"
	<< "If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning(void) {

	std::cout << "[WARNING]:" << std::endl;
	std::cout << "think I deserve to have some extra bacon for free."
	<< "I’ve been coming for"
	<< "years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error(void) {
	
	std::cout << "[ERROR]:" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

int Harl::printLevel(int i) {
	(this->*levels[i])();
	return (1);
}

void Harl::complain(std::string level) {

	int i = 0;

	while (i < 4)
	{
		(this->names[i].compare(level) == 0) && this->printLevel(i);
		i++;
	}
}