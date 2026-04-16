#include "PmergeMe.hpp"

// Compilacion test - simplificado
int main() {
    listBin lb;
    lb.push_back(5);
    lb.push_back(2);
    lb.push_back(8);
    
    listBin result = mergeInsertion(lb);
    
    printList(result, "Resultado");
    checkSorted(result);
    
    return 0;
}
