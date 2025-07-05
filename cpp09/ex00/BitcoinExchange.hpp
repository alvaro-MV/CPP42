#ifndef BITCOIN_EXCHANGE_H
# define BITCOIN_EXCHANGE_H

# include <fstream>
# include <sstream>
# include <iostream>
# include <string>
#include <string>
# include <map>
#include <limits>

typedef std::string str;
typedef std::multimap<str, str> database;

float stoff(const std::string& str);
database::iterator find_nearest_date(database db, str needle_date);

#endif