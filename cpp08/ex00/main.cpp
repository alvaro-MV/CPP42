#include "easyfind.hpp"

// int main(void) {
// 	std::vector<int> vInt = {23, -5, 1, 6, 2, 0};
// 	int pattern = 9877;
// 	try {
// 		std::vector<int> first_ocurrence = easyfind(vInt, pattern);
// 		std::cout << "{";
// 		for (int el : first_ocurrence) {
// 			std::cout << el << ", ";
// 		}
// 		std::cout << "END}" << std::endl;
	
// 		std::cout << "{";
// 		for (int el : vInt) {
// 			std::cout << el << ", ";
// 		}
// 		std::cout << "END}" << std::endl;
// 	}
// 	catch (std::out_of_range &out) {
// 		std::cerr << "Pattern " << pattern << " not found: " << out.what() << '\n';
// 	}
// }

int main(void) {
	std::forward_list<int> listInt = {23, -5, 1, 6, 2, 0};
	int pattern = -5;
	try {
		std::forward_list<int> first_ocurrence = easyfind(listInt, pattern);
		std::cout << "{";
		for (int el : first_ocurrence) {
			std::cout << el << ", ";
		}
		std::cout << "END}" << std::endl;
	
		std::cout << "{";
		for (int el : listInt) {
			std::cout << el << ", ";
		}
		std::cout << "END}" << std::endl;
	}
	catch (std::out_of_range &out) {
		std::cerr << "Pattern " << pattern << " not found: " << out.what() << '\n';
	}
}

// int main(void) {
// 	std::forward_list<int> listInt = {23, -5, 1, 6, 2, 0};
// 	int pattern = -5;
// 	try {
// 		std::forward_list<int> first_ocurrence = easyfind(listInt, pattern);
// 		std::cout << "{";
// 		for (int el : first_ocurrence) {
// 			std::cout << el << ", ";
// 		}
// 		std::cout << "END}" << std::endl;
	
// 		std::cout << "{";
// 		for (int el : listInt) {
// 			std::cout << el << ", ";
// 		}
// 		std::cout << "END}" << std::endl;
// 	}
// 	catch (std::out_of_range &out) {
// 		std::cerr << "Pattern " << pattern << " not found: " << out.what() << '\n';
// 	}
// }