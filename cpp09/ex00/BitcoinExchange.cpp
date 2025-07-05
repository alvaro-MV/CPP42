#include "BitcoinExchange.hpp"

#define YEAR 1
#define MONTH 2
#define DAY 3

str	getElfromDate(str date, int element) {
	int	del_pos = -1;
	int	prev = -1;
	while (element--) {
		prev = del_pos;
		del_pos = date.find('-', del_pos + 1);
		if ((size_t) del_pos == str::npos)
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

float	dateDistLex(str d1, str d2) {
float	contador = (stoff(getElfromDate(d1, YEAR)) - stoff(getElfromDate(d2, YEAR))) * 365 \
				   + (stoff(getElfromDate(d1, MONTH)) - stoff(getElfromDate(d2, MONTH))) * 30 \
				   + (stoff(getElfromDate(d1, DAY)) - stoff(getElfromDate(d2, DAY)));
	
	if (contador < 0)
		contador *= -1;
	return (contador);
}

database::iterator find_nearest_date(database db, str needle_date) {
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

// int	main(void) {
// 	std::cout << "dist: " << dateDistLex("2022-02-26", "2023-10-12") << std::endl;
// 	std::cout << "dist: " << dateDistLex("2022-02-26", "2022-10-12") << std::endl;
// }
