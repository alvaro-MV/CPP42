#include "PmergeMe.hpp"
#include "PmergeMe.hpp"


void printList(const listBin& lb, const std::string& name) {
    std::cout << name << ": ";
    int i = 0;
    for (const auto& binding : lb) {
        std::cout << "(" << binding << ") ";
        i++;
        if (i % 2 == 0)
            std::cout << "| ";
    }
    std::cout << std::endl;
}

std::deque<uint32_t> splitMainChainDeq(std::deque<uint32_t>& input, std::deque<uint32_t>& main_chain, std::deque<uint32_t>& b_list) {
    size_t i = 0;

    while (i + 1 < input.size()) {
        uint32_t first = input[i];
        uint32_t second = input[i + 1];

        if (first < second) {
            main_chain.push_back(second);
            b_list.push_back(first);
        } else {
            main_chain.push_back(first);
            b_list.push_back(second);
        }
        i += 2;
    }

    // Si hay un impar
    if (i < input.size()) {
        main_chain.push_back(input[i]);
        // Aquí puedes meter dummy si lo necesitas: b_list.push_back(input[i]);
    }

    return b_list;
}

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <string>
#include <queue>

void insertDequeSorted(std::deque<uint32_t>& dq, std::deque<uint32_t>& b) {
    for (auto val : b) {
        auto pos = std::lower_bound(dq.begin(), dq.end(), val);
        dq.insert(pos, val);
    }
    b.clear();
}