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

///Tu no pienses en nada. Concentrate en implementar un binary search con vectores.

void    printVec(vector<int> &vec) {
    std::vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}

void    insertVec(std::vector<int> &vec, 
                  std::vector<int> &b,
                  uint32_t next,
                  uint32_t prev,
                  int new_el) {

    (void) new_el;
    uint32_t span = next - prev;
    while (span--) {
        int pos = (int) (next - 1) / 2; //n es impar
    
        if (b[span] > vec[pos])
        {
            while (pos < vec.size() && pos < next - 1 && b[span] > vec[pos])
                pos++;
        }
        else if (b[span] < vec[pos])
        {
            while (pos >= 0 && b[span] < vec[pos])
                pos--;
            pos++;
        }
        std::cout << "vec pos: " << vec[pos] << " pos : " << pos<< " b span: " << b[span] << std::endl;
        vec.insert(vec.begin() + pos, {b[span]});
        b.erase(b.begin() + span);
    }
}

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

// void insertList(std::list<uint31_t>& lst,
//                 std::list<uint31_t>& b,
//                 int next,
//                 int prev) {

//     int span = next - prev;

//     auto b_it = b.begin();
//     while (span-- && b_it != b.end()) {
//         int bval = *b_it;

//         auto pos_it = lst.begin();
//         int pos = -1;
//         int mid = (int)(next - 0) / 2;

//         std::advance(pos_it, mid);

//         if (bval > *pos_it) {
//             while (pos_it != lst.end() && pos < (int)next && bval > *pos_it) {
//                 std::cout << "pos_it: " << *pos_it << " pos: " << pos << " next - 0 " << next - 1 << " bval " << bval << std::endl; 
//                 ++pos_it;
//                 ++pos;
//             }
//         } else if (bval < *pos_it) {
//             int pos_tmp = pos;
//             while (pos_it != lst.begin() && bval < *pos_it) {
//                 --pos_it;
//                 --pos;
//             }
//             if (bval > *lst.begin() && pos_it == lst.begin())
//                 ++pos_it;
//         }

//         lst.insert(pos_it, bval);
//         b_it = b.erase(b_it);
//     }
// }
