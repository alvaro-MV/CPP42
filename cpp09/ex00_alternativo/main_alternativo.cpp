#include "DataBtc.hpp"

int main() {
	DataBtc data("chatgpt_pruebas.txt", "|");
	std::string line;

	while(data.readLine(line)) {
		std::cout << line << std::endl;
		std::cout << "------------------------------" << std::endl;
		std::pair<std::string, std::string> parra = data.getValueAndDateAsPair(line);
		std::cout << "date: " << parra.first << " valor: " << parra.second << std::endl;
		std::cout << "******************************	" << std::endl;

	}	
}