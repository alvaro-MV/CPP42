#include "BitcoinExchange.hpp"

#define YEAR 1
#define MONTH 2
#define DAY 3

/* Básicamente hay que controlar:
	- Que se siga el formato Year-Month-Day
	- Que los valores tengan valores dentro del rango y que sean numéricos.
*/
bool	verifyDate(str date) {
	size_t	hypen;
	int		status = true;

	hypen = date.find('-');
	hypen = date.find('-', hypen + 1);
	if (hypen == str::npos)
		status = false;
	
	str year = getElfromDate(date, YEAR);
	if (year.size() > 4 || stoff(year) < 2008
		|| stoff(year) > 2025)
		status = false;
	
	str month = getElfromDate(date, MONTH);
	if (month.size() > 2 || stoff(month) < 0
		|| stoff(month) > 12)
		status = false;

	str day = getElfromDate(date, DAY);
	if (day.size() > 2 || stoff(day) < 0
		|| stoff(day) > 31)
		status = false;
	if (status == false)
		std::cerr << "Error: bad input => " << date << std::endl;
	return (status);
}

bool	verifyValue(str value) {
	str::iterator it = value.begin();
	bool	state = true;
	int		only_integer = 1;

	if (value.length() > 10 || (value.length() == 11 && value[0] != '-')) {
		std::cerr << "Error: not a positive number" << std::endl;
		return (false);
	}
	if (*it == '-')	
		it++;
	while (it != value.end() && (std::isdigit(*it) || *it == '.'))
	{
		if (*it == '.')
			only_integer--;
		if (only_integer < 0)
			return (false);
		it++;
	}
	if (it != value.end())
		state = false;

	double dobValue = stoff(value);
	if (dobValue > 1000)
	{
		std::cerr << "Error: too large number" << std::endl;
		state = false;
	}
	else if (dobValue < 0)
	{
		std::cerr << "Error: not a positive number" << std::endl;
		state = false;
	}
	return (state);
}

str	getElfromDate(str date, int element) {
	int del_pos = -1;
	int	prev = -1;
	while (element-- && del_pos < (int) date.size()) {
		prev = del_pos;
		del_pos = date.find('-', del_pos + 1);
		if (del_pos == (int) str::npos)
			del_pos = date.size();
	}
	return date.substr(prev + 1, del_pos - prev - 1);
}

float stoff(const std::string& str) {
    std::istringstream iss(str);
    float result;
    iss >> result;
    return result;
}

int	ft_stol(const std::string& str) {
    std::istringstream iss(str);
    long result;
    iss >> result;
    return result;
}

float	dateDistLex(str d1, str d2) {
	float contador = (stoff(getElfromDate(d1, YEAR)) - stoff(getElfromDate(d2, YEAR))) * 365 \
				   + (stoff(getElfromDate(d1, MONTH)) - stoff(getElfromDate(d2, MONTH))) * 30 \
				   + (stoff(getElfromDate(d1, DAY)) - stoff(getElfromDate(d2, DAY)));
	
	if (contador < 0)
		contador *= -1;
	return (contador);
}

database::iterator findNearestDate(database db, str needle_date) {
	database::iterator it = db.begin();
	database::iterator end = db.end();
	float	min = std::numeric_limits<float>::max();
	float	dist;
	float	prev = std::numeric_limits<float>::max();

	while (it != end) {
		dist = dateDistLex(it->first, needle_date);
		if (prev < dist)
			return (--it);
		if (dist < min)
			min = dist;
		prev = dist;
		it++;
	}
	end--;
	end--;
	return (end);
}

