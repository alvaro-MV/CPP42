#include "Sedl.hpp"

Sedl::~Sedl() {
	//Por ver
};


Sedl& Sedl::operator=(const Sedl &sedl) {
	this->_s1 = sedl._s1;
	this->_s2 = sedl._s2;
	return (*this);
}

std::string Sedl::replace_1_line(std::string line) {
	std::size_t	idx_str = 0;
	std::size_t	prev_idx = 0;
	std::string	ret_str = "";
	
	while (idx_str != -1)
	{
		idx_str = line.find(_s1, idx_str);
		if (idx_str > 0)
		{
			if (prev_idx > 0)
				ret_str += _s2;
			ret_str += line.substr(prev_idx, idx_str - prev_idx);
		}
		if (idx_str != -1)
		{
			idx_str += _s1.length();
			prev_idx = idx_str;
		}
		// std::cout << ret_str << std::endl;
	}
	return (ret_str);
}

void Sedl::replace_filename() {
	std::string	line;
	std::string	replaced_line;
	std::ifstream inputFile(this->_filename);

	std::fstream file_replaced(this->_filename + ".replaced", 
	std::ios::out | std::ios::in | std::ios::trunc);

	while (getline(inputFile, line))
	{
		replaced_line = replace_1_line(line);
		file_replaced << replaced_line << std::endl;
	}
}