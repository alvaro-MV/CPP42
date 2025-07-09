#include "PmergeMe.hpp"

std::deque<uint32_t> mergeInsertionDeq(std::deque<uint32_t>& input) {
    if (input.size() <= 1)
        return input;

    std::deque<uint32_t> main_chain;
    std::deque<uint32_t> b_list;

    splitMainChainDeq(input, main_chain, b_list);

    main_chain = mergeInsertionDeq(main_chain);

    // Insertar los b_i uno a uno en orden
    insertDequeSorted(main_chain, b_list);

    return main_chain;
}


static void checkSorted(const std::deque<uint32_t>& dq) {
    if (dq.empty()) {
        std::cout << "OK (empty)\n";
        return;
    }

    for (size_t i = 1; i < dq.size(); ++i) {
        if (dq[i] < dq[i - 1]) {
            std::cout << "KO: " << dq[i] << " < " << dq[i - 1] << "\n";
            return;
        }
    }

    std::cout << "OK\n";
}

void printDeque(const std::deque<uint32_t>& dq, const std::string& label) {
    std::cout << label << ":\t";
    for (size_t i = 0; i < 6; ++i)
        std::cout << dq[i] << " ";
    if (dq.size() > 6)
        std::cout << "[..]";
    std::cout << "\n";
}

std::deque<uint32_t> generateRandomList(std::size_t count) {
    std::deque<uint32_t> result;
    std::random_device rd;
	unsigned int rata = rd();
	std::cout << "rd: " << rata << std::endl;
    std::mt19937 gen(rata);
    std::uniform_int_distribution<uint32_t> dist(
        0, 10000);

    for (std::size_t i = 0; i < count; ++i)
        result.push_back(dist(gen));
    return result;
}

int main() {
    std::deque<uint32_t> input = generateRandomList(3000);
    printDeque(input, "Before");

    clock_t start = clock();
    std::deque<uint32_t> sorted = mergeInsertionDeq(input);
    clock_t end = clock();
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    duration *= 1000;

    printDeque(sorted, "After");
    checkSorted(sorted);

    std::cout << "Tiempo de ejecución: " << duration << " ms" << std::endl;

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