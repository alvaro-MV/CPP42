#include "PmergeMe.hpp"

// Using the new Ford-Johnson algorithm
listBin mergeInsertion(listBin lb) {
	return mergeInsertionFordJohnson(lb);
}

std::list<u_int32_t> generateRandomList(std::size_t count) {
    std::list<u_int32_t> result;
    srand(static_cast<unsigned int>(time(NULL)));
    
    for (std::size_t i = 0; i < count; ++i) {
        u_int32_t val = static_cast<u_int32_t>(rand() % 5000);
        result.push_back(val);
    }
    return result;
}

int main() {
    listBin lb = generateRandomList(3524);	
	std::cout << std::endl << std::endl;
	listBin llb = mergeInsertion(lb);
	
	printList(llb, "llb");
	checkSorted(llb);

    return 0;
}