#include <iostream>
#include <string>

int main(int argc, char **argv) {
	int	i = 0, j = 0;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
			std::cout << static_cast<char> (std::toupper(argv[i][j++])) << std::ends;
	}
	std::cout << "" << std::endl;
	return (0);
}