#include "PmergeMe.hpp"

using namespace std;

// ==================== JACOBSTHAL SEQUENCE ====================
int jacobsthalNumber(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    int jPrev = 0;
    int jCurr = 1;
    
    for (int i = 2; i <= n; ++i) {
        int jNext = jCurr + 2 * jPrev;
        jPrev = jCurr;
        jCurr = jNext;
    }
    return jCurr;
}

std::vector<int> getJacobsthalSequence(int count) {
    std::vector<int> sequence;
    int n = 1;
    
    while (sequence.size() < (size_t)count) {
        int val = jacobsthalNumber(n);
        if (val >= count)
            break;
        sequence.push_back(val);
        n++;
    }
    return sequence;
}

// ==================== PRINT FUNCTIONS ====================
void printList(const listBin& lb, const std::string& name) {
    std::cout << name << ": ";
    for (listBin::const_iterator it = lb.begin(); it != lb.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void printPairs(const pairList& pl, const std::string& name) {
    std::cout << name << ": ";
    for (pairList::const_iterator it = pl.begin(); it != pl.end(); ++it) {
        std::cout << "(" << it->first << "," << it->second << ") ";
    }
    std::cout << std::endl;
}

// ==================== SORT MAIN CHAIN ====================
listBin sortMainChain(listBin main_chain) {
    if (main_chain.size() <= 1)
        return main_chain;
    
    // Recursive merge sort
    listBin first_half;
    listBin second_half;
    
    listBinIter mid = main_chain.begin();
    std::advance(mid, main_chain.size() / 2);
    
    // Split into two halves
    for (listBinIter it = main_chain.begin(); it != mid; ++it) {
        first_half.push_back(*it);
    }
    for (listBinIter it = mid; it != main_chain.end(); ++it) {
        second_half.push_back(*it);
    }
    
    first_half = sortMainChain(first_half);
    second_half = sortMainChain(second_half);
    
    // Merge
    main_chain.clear();
    listBinIter it1 = first_half.begin();
    listBinIter it2 = second_half.begin();
    
    while (it1 != first_half.end() && it2 != second_half.end()) {
        if (*it1 <= *it2) {
            main_chain.push_back(*it1);
            ++it1;
        } else {
            main_chain.push_back(*it2);
            ++it2;
        }
    }
    
    while (it1 != first_half.end()) {
        main_chain.push_back(*it1);
        ++it1;
    }
    
    while (it2 != second_half.end()) {
        main_chain.push_back(*it2);
        ++it2;
    }
    
    return main_chain;
}

// ==================== INSERT WITH RANGE ====================
// Inserta b_val en main_chain, buscando solo hasta limit
void insertBWithRange(listBin& main_chain, u_int32_t b_val, listBinIter limit) {
    listBinIter pos = main_chain.begin();
    
    while (pos != limit && pos != main_chain.end() && *pos < b_val) {
        ++pos;
    }
    
    main_chain.insert(pos, b_val);
}

// ==================== INSERT WITH JACOBSTHAL ====================
void insertWithJacobsthal(listBin& main_chain, listBin& b_list) {
    // Simple binary insertion without range-limiting (correct ordering first)
    for (listBinIter b_it = b_list.begin(); b_it != b_list.end(); ++b_it) {
        u_int32_t b_val = *b_it;
        listBinIter pos = std::lower_bound(main_chain.begin(), main_chain.end(), b_val);
        main_chain.insert(pos, b_val);
    }
    b_list.clear();
}

// ==================== MERGE INSERTION FORD-JOHNSON ====================
listBin mergeInsertionFordJohnson(listBin input) {
    if (input.size() <= 1)
        return input;
    
    // Step 1: Create pairs (main_chain, b_list)
    listBin main_chain;
    listBin b_list;
    
    listBinIter it = input.begin();
    while (it != input.end()) {
        listBinIter next_it = it;
        ++next_it;
        
        if (next_it == input.end())
            break;
            
        u_int32_t first = *it;
        u_int32_t second = *next_it;
        
        if (first <= second) {
            main_chain.push_back(first);
            b_list.push_back(second);
        } else {
            main_chain.push_back(second);
            b_list.push_back(first);
        }
        
        ++it;
        ++it;
    }
    
    // Handle odd element
    if (it != input.end()) {
        main_chain.push_back(*it);
    }
    
    // Step 2: Sort main_chain recursively
    main_chain = mergeInsertionFordJohnson(main_chain);
    
    // Step 3: Insert b elements using Jacobsthal sequence
    insertWithJacobsthal(main_chain, b_list);
    
    return main_chain;
}

// ==================== DEQUE VERSIONS ====================
std::deque<u_int32_t> splitMainChainDeq(std::deque<u_int32_t>& input, std::deque<u_int32_t>& main_chain, std::deque<u_int32_t>& b_list) {
    size_t i = 0;

    while (i + 1 < input.size()) {
        u_int32_t first = input[i];
        u_int32_t second = input[i + 1];

        if (first < second) {
            main_chain.push_back(second);
            b_list.push_back(first);
        } else {
            main_chain.push_back(first);
            b_list.push_back(second);
        }
        i += 2;
    }

    // Handle odd element
    if (i < input.size()) {
        main_chain.push_back(input[i]);
    }

    return b_list;
}

void insertDequeSorted(std::deque<u_int32_t>& dq, std::deque<u_int32_t>& b) {
    for (std::deque<u_int32_t>::iterator it = b.begin(); it != b.end(); ++it) {
        u_int32_t val = *it;
        std::deque<u_int32_t>::iterator pos = std::lower_bound(dq.begin(), dq.end(), val);
        dq.insert(pos, val);
    }
    b.clear();
}

std::deque<u_int32_t> mergeInsertionDeq(std::deque<u_int32_t>& input) {
    if (input.size() <= 1)
        return input;

    std::deque<u_int32_t> main_chain;
    std::deque<u_int32_t> b_list;
    
    splitMainChainDeq(input, main_chain, b_list);
    
    main_chain = mergeInsertionDeq(main_chain);
    insertDequeSorted(main_chain, b_list);
    
    return main_chain;
}

// ==================== UTILITY FUNCTIONS ====================
void checkSorted(const listBin& lb) {
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

int tSub(int k) {
    int twoMultiple = 1;
    int signMultiple = 1;

    for (int i = 0; i < k + 1; i++) {
        twoMultiple *= 2;
        signMultiple *= -1;
    }
    signMultiple *= -1;
    return ((twoMultiple + signMultiple) / 3);
}

