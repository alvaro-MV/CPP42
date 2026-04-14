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
		DataBtc(std::string filename, std::string del);
		DataBtc(const DataBtc& data);
		DataBtc& operator=(const DataBtc& data);
		~DataBtc();

		typedef struct  {
			std::string year;
			std::string month;
			std::string day;
			float		value;
		} Row;
		
		// A partir de aqui la mayoria irá en privado.
		bool readLine(std::string &line);
		std::pair<std::string, std::string> getValueAndDateAsPair(std::string &line);
		Row fillRow();


	private:
		const std::string	del;
		std::fstream		file;
		std::string			filename;

		std::string trimDelAndSpaces(std::string s);
		std::pair<std::string, std::string> splitByDel(std::string &line, std::string del);

};

#endif