#ifndef DATABASE_H
# define DATABASE_H

#include "DataBtc.hpp"

class BitcoinExchange:public DataBtc {
	public:
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		struct CompareDateRows {
			bool operator()(const DataBtc::Row &a, const DataBtc::Row &b) const {
				if (a.year != b.year) return a.year < b.year;
				if (a.month != b.month) return a.month < b.month;
				return a.day < b.day;
			}
		};
		void	insertDatabase();
		Row		findNearest(const Row &search) const;
	
	private:
		std::multimap<DataBtc::Row, double, CompareDateRows> database;
		
};

#endif