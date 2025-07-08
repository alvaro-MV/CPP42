#include "PmergeMe.hpp"


void printList(const listBin& lb, const std::string& name) {
    std::cout << name << ": ";
    for (const auto& binding : lb) {
        std::cout << "(" << binding << ") ";
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
listBin splitMainChain(listBin& lb, std::map<uint32_t, uint32_t> &binding) {
    listBin ret;

    if (lb.size() < 2)
        return ret;

    // printList(lb, "lb");
    std::cout << std::endl;
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
        
        // Insertamos una copia del nodo menor al final de ret
        ret.insert(ret.end(), *smaller);

        // Eliminamos el nodo menor de lb
        it = lb.erase(smaller);
        
        // std::cout << "larger: " << *larger << "  first: " << *first << std::endl;
        if (larger != first)
            it++;
        if (it == lb.end())
            break;
        next_it = std::next(it);

        // printList(lb, "lb");
        // std::cout << "  it " << *it << std::endl;
        // printList(ret, "ret");
        // std::cout << std::endl;
        // std::cout << "------------------------" << std::endl;
    }

    listBinIter retIt = ret.begin();
    for (listBinIter it = lb.begin(); it != lb.end(); it++) {
        if (retIt != ret.end()) {
            binding.insert(std::pair<uint32_t, uint32_t>(*it, *retIt));
            retIt++;
        }
    }

    for (const auto& [key, value] : binding)
    std::cout << '[' << key << "] = " << value << "; ";
    
    for (const auto& [key, value] : binding)
    std::cout <<  key << ", ";
    
    std::cout << std::endl;
    
    if (lb.size() != ret.size()) {
        
        listBinIter lastoflb = lb.end();
        lastoflb--;
        ret.insert(ret.end(), *lastoflb);

        // Eliminamos el nodo menor de lb
        it = lb.erase(lastoflb);
    }
    return ret;
}

// MAIN
// int main() {
//     listBin lb = {23,5,46,26,8,12,14,43,41,11};
// 	std::map<uint32_t, uint32_t> binding;

//     std::cout << "Antes del split:" << std::endl;
//     printList(lb, "lb");

//     listBin b = splitMainChain(lb, binding);

//     std::cout << "\nDespués del split:" << std::endl;
//     printList(lb, "lb");
//     printList(b, "ret");


//     listBin llb = {30, 34, 38, 47, 49, 17};

//     b.clear();
//     listBinIter it = llb.begin();
//     for (int i = 0; i < (llb.size() - (llb.size() % 2 == 0) * 1); i++) {
//         b.insert(b.end(), binding[*it]);
//         it++;
//     }
//     printList(b, "ret");

//     return 0;
// }











using namespace std;
#include <iostream>
#include <vector>
#include <cmath>
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

// int main(void) {
//     std::vector<int> vec{3, 8, 16, 45, 555, 800};
//     std::vector<int> b{10, 34, 500, 780};
//     insertVec(vec, b, 5, 3, 123);
//     printVec(vec);
//     printVec(b);
    
//     // TreeNode* root = buildCenteredTree(vec, 0, vec.size() - 1);
//     // printBinaryTree(root);
// }


#include <list>
#include <iostream>
#include <cstdint>

// void printList(std::list<int>& lst) {
//     for (const int& val : lst) {
//         std::cout << val << ", ";
//     }
//     std::cout << std::endl;
// }

void insertList(std::list<uint32_t>& lst,
                std::list<uint32_t>& b,
                uint32_t next,
                uint32_t prev) {

    uint32_t span = next - prev;

    auto b_it = b.begin();
    while (span-- && b_it != b.end()) {
        int bval = *b_it;

        // Buscar posición donde insertar en lst
        auto pos_it = lst.begin();
        int pos = 0;
        int mid = (int)(next - 1) / 2;

        std::advance(pos_it, mid); // iterador en la mitad

        if (bval > *pos_it) {
            while (pos_it != lst.end() && pos < (int)next - 1 && bval > *pos_it) {
                ++pos_it;
                ++pos;
            }
        } else if (bval < *pos_it) {
            int pos_tmp = pos;
            while (pos_it != lst.begin() && bval < *pos_it) {
                --pos_it;
                --pos;
            }
            if (bval > *lst.begin())
                ++pos_it;
        }

        std::cout << "inserting " << bval << " at position " << pos << std::endl;
        lst.insert(pos_it, bval);

        // Eliminar el elemento de `b`
        b_it = b.erase(b_it);
    }
}


// int main() {
//     listBin list = {9, 12, 14, 16, 22, 29, 31, 49};
//     std::list<uint32_t> b{20, 21};

//     uint32_t prev = 6;
//     uint32_t next = 11;
//     int dummy_value = 0;

//     std::cout << "Lista original:\n";
//     printList(list, "list");

//     std::cout << "\nBuffer:\n";
//     printList(b, "b");

//     std::cout << "\nInsertando elementos...\n";
//     insertList(list, b, next, prev);

//     std::cout << "\nLista final:\n";
//     printList(list, "list");

//     std::cout << "\nBuffer final:\n";
//     printList(b, "b");

//     return 0;
// }