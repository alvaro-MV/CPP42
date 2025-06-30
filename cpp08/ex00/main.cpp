#include "easyfind.hpp"

// int main(void) {
// 	int	ints[] =  {23, -5, 1, 6, 2, 0};
// 	std::vector<int> vInt(ints, ints + sizeof(ints) / sizeof(int));

// 	int pattern = 9877;
// 	try {
// 		std::vector<int> first_ocurrence = easyfind(vInt, pattern);
// 		std::cout << "{";
// 		for (std::vector<int>::iterator it = first_ocurrence.begin(); it != first_ocurrence.end(); it++)
// 			std::cout << *it << ", ";
// 		std::cout << "END}" << std::endl;
	
// 		std::cout << "{";
// 		for (std::vector<int>::iterator it = vInt.begin(); it != vInt.end(); it++)
// 			std::cout << *it << ", ";
// 		std::cout << "END}" << std::endl;
// 	}
// 	catch (std::out_of_range &out) {
// 		std::cerr << "Pattern " << pattern << " not found: " << out.what() << '\n';
// 	}
// }

int main(void) {
	int	ints[] =  {23, -5, 1, 6, 2, 0};
	std::list<int> lInt(ints, ints + sizeof(ints) / sizeof(int));

	int pattern = 1;
	try {
		std::list<int> first_ocurrence = easyfind(lInt, pattern);
		std::cout << "{";
		for (std::list<int>::iterator it = first_ocurrence.begin(); it != first_ocurrence.end(); it++)
			std::cout << *it << ", ";
		std::cout << "END}" << std::endl;
	
		std::cout << "{";
		for (std::list<int>::iterator it = lInt.begin(); it != lInt.end(); it++)
			std::cout << *it << ", ";
		std::cout << "END}" << std::endl;
	}
	catch (std::out_of_range &out) {
		std::cerr << "Pattern " << pattern << " not found: " << out.what() << '\n';
	}
}

// int main(void) {
// 	int	ints[] = {23, -5, 1, 6, 2, 0};
// 	std::deque<int> deqInt(ints, ints + sizeof(ints) / sizeof(int));
// 	int pattern = -5;
// 	try {
// 		std::deque<int> first_ocurrence = easyfind<std::deque<int> >(deqInt, pattern);
// 		std::cout << "{";
// 		for (std::deque<int>::iterator it = first_ocurrence.begin(); it != first_ocurrence.end(); ++it) {
// 			std::cout << *it << ", ";
// 		}
// 		std::cout << "END}" << std::endl;
	
// 		std::cout << "{";
// 		for (std::deque<int>::iterator it = deqInt.begin(); it != deqInt.end(); ++it) {
// 			std::cout << *it << ", ";
// 		}
// 		std::cout << "END}" << std::endl;
// 	}
// 	catch (std::out_of_range &out) {
// 		std::cerr << "Pattern " << pattern << " not found: " << out.what() << '\n';
// 	}
// }