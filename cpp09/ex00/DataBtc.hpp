#ifndef DATA_H
# define DATA_H

# include <fstream>
# include <sstream>
# include <iostream>
# include <ios>
# include <string>
# include <string>
# include <map>
# include <limits>
# include <stdlib.h>


/* 
	DataBtc es la clase base para las bases de datos de cotizaciones de btc.
	Tanto Input como Database heredan de ella.
	Implementa lógica que comparten ambas clases derivadas,
	como la lectura del fichero,
	la verificación y conversión de las fechas, etc.
	


*/
class DataBtc {
	public:
		DataBtc();
		DataBtc(std::string filename, std::string del);
		DataBtc(const DataBtc& data);
		DataBtc& operator=(const DataBtc& data);
		virtual ~DataBtc();

		typedef struct  {
			int year;
			int month;
			int day;
			double		value;
		} Row;
		
		// A partir de aqui la mayoria irá en privado.
		bool readLine(std::string &line);
		std::pair<std::string, std::string> getDateAndValue(std::string &line);
		Row fillRow(std::pair<std::string, std::string> dateAndValue);

		class BadInput: public std::exception {
			const std::string _msg;

			public:
				BadInput(const std::string& _msg);
				~BadInput() throw();

				virtual const char *what() const throw();
		};


	protected:
		std::string			filename;
		const std::string	del;
		std::fstream		file;

		std::string trimDelAndSpaces(std::string s);
		std::pair<std::string, std::string> splitByDel(std::string &line, std::string del);
		size_t mfind(std::string &s, std::string pattern, size_t iters);
		bool convertValueToFloat(std::string value, double &out);
		bool convertValueToInt(const std::string &value, int &out);
};

#endif