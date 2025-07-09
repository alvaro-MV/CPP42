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

/*
	Basicamente lo que hay que hacer es:
		- Determinar cual de los pares, si uno o el otro es mas grande.
		- Pushear al binding del mayor el pequeño en el campo b.
		- Se mueve el pequeño a ret
		- Se elimina el pequeño de la cadena principal.
		- Se devuelve ret.
*/
listBin splitMainChain(listBin& lb) {
    listBin ret;

    if (lb.size() < 2)
        return ret;

    auto it = lb.begin();
    auto next_it = std::next(it);

    while (next_it != lb.end()) {
        auto first = it;
        auto second = next_it;

        listBinIter smaller, larger;
        if (*first < *second) {
            smaller = first;
            larger = second;
        } else {
            smaller = second;
            larger = first;
        }
        
        ret.insert(ret.end(), *smaller);

        it = lb.erase(smaller);
        
        if (larger != first)
            it++;
        if (it == lb.end())
            break;
        next_it = std::next(it);
    }

    if (lb.size() != ret.size()) {
        
        listBinIter lastoflb = lb.end();
        lastoflb--;
        ret.insert(ret.end(), *lastoflb);

        it = lb.erase(lastoflb);
    }
    return ret;
}

using namespace std;
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <string>
#include <queue>


void insertListSorted(std::list<uint32_t>& lst, std::list<uint32_t>& b) {
    for (auto it_b = b.begin(); it_b != b.end(); ++it_b) {
        uint32_t val = *it_b;

        auto pos = lst.begin();
        while (pos != lst.end() && *pos < val)
            ++pos;
        lst.insert(pos, val);
    }

    b.clear();
}

