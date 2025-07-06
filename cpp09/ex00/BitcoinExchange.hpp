#ifndef BITCOIN_EXCHANGE_H
# define BITCOIN_EXCHANGE_H

# include <fstream>
# include <sstream>
# include <iostream>
# include <ios>
# include <string>
# include <string>
# include <map>
# include <limits>
# include <stdlib.h>

typedef std::string str;
typedef std::multimap<str, str> database;

float stoff(const std::string& str);
int	ft_stol(const std::string& str);
bool	verifyDate(str date);
bool	verifyValue(str value);
str	getElfromDate(str date, int element);

database::iterator findNearestDate(database db, str needle_date);

#endif