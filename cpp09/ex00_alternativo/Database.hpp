#ifndef DATABASE_H
# define DATABASE_H

#include "DataBtc.hpp"

class Database:public DataBtc {
	public:
		Database(std::string filename);
		Database(const Database &other);
		Database& operator=(const Database &other);
		~Database();

		struct CompareDateRows {
			bool operator()(DataBtc::Row a, DataBtc::Row b) const {
				if (a.year != b.year) return a.year < b.year;
				if (a.month != b.month) return a.month < b.month;
				return a.day < b.day;
			}
		};
		void	insertDatabase();
		Row		findNearest(Row &search) const;
	
	private:
		std::multimap<DataBtc::Row, double, CompareDateRows> database;
		
};

#endif