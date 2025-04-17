#include "Sedl.hpp"
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4)
		std::cout << "Usage: /path/sedloosers filename str s2" << std::endl;
	else
	{
		Sedl sedl(argv[1], argv[2], argv[3]);
		sedl.replace_filename();
	}
	return (0);
}

/* 

	- Método replace

	- Método para abrir el archivo.

	- Método para leerlo

	- Método para escribir en el archivo.replace

 */