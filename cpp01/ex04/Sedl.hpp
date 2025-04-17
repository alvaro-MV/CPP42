#ifndef SEDL_H
#define SEDL_H

#include <string>
#include <fstream>
#include <iostream>

class Sedl
{
private:
	std::string	_filename;
	std::string	_s1;
	std::string	_s2;

public:
	//Constructors
	Sedl(std::string filename, 
		std::string s1, 
		std::string s2):
		_filename(filename),
		_s1(s1),
		_s2(s2) {};

	Sedl(const Sedl& sedl):
		_s1(sedl._s1),
		_s2(sedl._s2) {};

	Sedl &operator=(const Sedl &sedl);
	~Sedl();

	//Member methods
	std::string replace_1_line(std::string line);
	void		replace_filename();
	

};

#endif