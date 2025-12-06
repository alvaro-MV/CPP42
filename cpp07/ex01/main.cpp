#include "iter.hpp"

void sum1(int& element) {
	element++;
}

void call_element(const int& element) {
	std::cout << "Me has llamado?? " << element << std::endl;
}

int main(void) {
	int iArray[] = {12, 3, 65, 89, 100};
	// iter(iArray, 5, call_element);
    iter(iArray, 5, sum1);
	iter(iArray, 5, print_I<int>);
}

// std::string toString(size_t sz) {
//     std::ostringstream  oss;
//     oss << sz;
//     return (oss.str());
// }

// void hashFunction(std::string &key) {
//     int hashCode = 0;
//     for (size_t i = 0; i < key.length(); i++) {
//         hashCode += key[i] * pow(31, i);
//     }
//     key = toString(hashCode);
// }

// int main(void) {
// 	std::string hashArray[3] = {"C++", "Python", "Lua"};
// 	// const std::string *hashArray = sArray;

// 	iter(hashArray, 3, hashFunction);
// 	iter(hashArray, 3, print_I<std::string>);
// }
