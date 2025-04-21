#include "iter.hpp"

// void sum1(int& element) {
// 	element++;
// }

// int main(void) {
// 	int iArray[] = {12, 3, 65, 89, 100};
// 	iter(iArray, 5, sum1);
// 	iter(iArray, 5, print_T<int>);
// }

void hashFunction(std::string &key) {
    int hashCode = 0;
    for (int i = 0; i < key.length(); i++) {
        hashCode += key[i] * pow(31, i);
    }
    key = std::to_string(hashCode);
}

int main(void) {
	std::string sArray[3] = {"C++", "Python", "Lua"};
	std::string *hashArray = sArray;

	iter(hashArray, 3, hashFunction);
	iter(hashArray, 3, print_I<std::string>);
}
