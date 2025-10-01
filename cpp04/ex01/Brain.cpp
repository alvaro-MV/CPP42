#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "(default)";
	std::cout << "Brain created with the idea: (default)" << std::endl;
}

Brain::Brain(std::string idea) {
	for (int i = 0; i < 100; i++)
		this->ideas[i] = idea;
	std::cout << "Brain created with the idea: " << idea << std::endl;
}

Brain::Brain(const Brain& brain) {
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
}

Brain& Brain::operator=(const Brain& brain) {
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destroyed. " << std::endl;
}

std::string Brain::get_idea_idx(int idx) const{
	if (idx < 0 ||idx >= 100) {
		std::cout << "idx out of range" << std::endl;
		return "";
	}
	return (this->ideas[idx]);
}

void Brain::set_idea_idx(int idx, std::string idea) {
	if (idx < 0 ||idx >= 100) {
		std::cout << "idx out of range" << std::endl;
		return ;
	}
	this->ideas[idx] = idea;
}