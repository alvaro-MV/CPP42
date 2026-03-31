#include "easyfind.hpp"

// int main(void) {
// 	int	ints[] =  {23, -5, 1, 6, 2, 0};
// 	std::vector<int> vInt(ints, ints + sizeof(ints) / sizeof(int));
	
// 	int pattern = 23;
// 	try {
// 		std::vector<int>::iterator first_ocurrence = easyfind(vInt, 23);
// 		std::cout << "{";
// 		for (; first_ocurrence != vInt.end(); first_ocurrence++)
// 			std::cout << *first_ocurrence << ", ";
// 		std::cout << "END}" << std::endl;
// 	}
// 	catch (std::out_of_range &out) {
// 		std::cerr << "Pattern " << pattern << " not found: " << out.what() << '\n';
// 	}
// }

// int main()
// {
//     int ints[] = {23, -5, 1, 6, 2, 0};
//     std::list<int> l(ints, ints + 6);

//     try {
//         std::list<int>::iterator it = easyfind(l, 1);
//         std::cout << "Found: " << *it << std::endl;
//     }
//     catch (std::exception &e) {
//         std::cout << e.what() << std::endl;
//     }
// }

int main(void) {
	int	ints[] = {23, -5, 1, 6, 2, 0};
	std::deque<int> deqInt(ints, ints + sizeof(ints) / sizeof(int));
	int pattern = -5;
	try {
		std::deque<int>::iterator first_ocurrence = easyfind<std::deque<int> >(deqInt, pattern);
		std::cout << "{";
		for (; first_ocurrence != deqInt.end(); ++first_ocurrence) {
			std::cout << *first_ocurrence << ", ";
		}
		std::cout << "END}" << std::endl;
	
		std::cout << "{";
		for (std::deque<int>::iterator it = deqInt.begin(); it != deqInt.end(); ++it) {
			std::cout << *it << ", ";
		}
		std::cout << "END}" << std::endl;
	}
	catch (std::out_of_range &out) {
		std::cerr << "Pattern " << pattern << " not found: " << out.what() << '\n';
	}
}