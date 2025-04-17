#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include <iostream>
#include <cstring>

class Brain {

	protected:
		std::string ideas[100];
	
	public:
		Brain();
		Brain(std::string idea);
		Brain(const Brain& brain);
		Brain& operator=(const Brain& brain);
		~Brain();

		std::string get_idea_idx(int idx) const;
		void set_idea_idx(int idx, std::string idea);
};

#endif