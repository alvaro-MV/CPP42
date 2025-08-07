#include "PmergeMe.hpp"

listBin	mergeInsertion(listBin lb) {
	listBin llb;

	if (lb.size() == 1)
		return (lb);

    listBin b = splitMainChain(lb);

	llb = mergeInsertion(lb);
    listBinIter it = llb.begin();
    listBinIter bit = b.begin();

	int prevMainChain = 0;
	int k = 1;
	while (!b.empty()) {
		int tNew = tSub(k);
		int tOld = tSub(k - 1);
		int nextMainChain = tNew + tOld;
		
		insertListSorted(llb, b);
		prevMainChain = nextMainChain + 1;
		k++;
	}
	return (llb);
}

static void checkSorted(const listBin& lb) {
    if (lb.empty()) {
        std::cout << "OK" << std::endl;
        return;
    }
    listBin::const_iterator it = lb.begin();
    listBin::const_iterator next = it;
    ++next;
    while (next != lb.end()) {
        if (*next < *it) {
            std::cout << "KO" << std::endl;
			std::cout << "[" << *next << "]--" << "[" << *it << "]" << std::endl;
            return;
        }
        ++it;
        ++next;
    }
    std::cout << "OK" << std::endl;
}

std::list<uint32_t> generateRandomList(std::size_t count) {
    std::list<uint32_t> result;
    std::random_device rd;
	unsigned int rata = rd();
	std::cout << "rd: " << rata << std::endl;
    std::mt19937 gen(rata);
    std::uniform_int_distribution<uint32_t> dist(
        0, 5000);

    for (std::size_t i = 0; i < count; ++i)
        result.push_back(dist(gen));
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

int	tSub(int k) {
	int twoMultiple = 1;
	int signMultiple = 1;

	for (int i = 0; i < k + 1; i++) {
		twoMultiple *= 2;
		signMultiple *= -1;
	}
	signMultiple *= -1;
	return ((twoMultiple + signMultiple) /3);
}