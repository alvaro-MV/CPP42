#include "easyfind.hpp"

// int main(void) {
// 	std::vector<int> vInt = {23, -5, 1, 6, 2, 0};
// 	std::vector<int> first_ocurrence = easyfind(vInt, 1);
// 	std::cout << "{";
// 	for (int el : first_ocurrence) {
// 		std::cout << el << ", ";
// 	}
// 	std::cout << "END}" << std::endl;

// 	std::cout << "{";
// 	for (int el : vInt) {
// 		std::cout << el << ", ";
// 	}
// 	std::cout << "END}" << std::endl;
// }

int main(void) {
	std::list<int> listInt = {23, -5, 1, 6, 2, 0};

	std::list<int> first_ocurrence = easyfind(listInt, -5);
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