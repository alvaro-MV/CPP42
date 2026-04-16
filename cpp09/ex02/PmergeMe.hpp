#ifndef PMERGEME_H
# define PMERGEME_H

# include <list>
# include <deque>
# include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <iomanip>

typedef std::list<u_int32_t> listBin;
typedef std::list<u_int32_t>::iterator listBinIter;
typedef std::list<std::pair<u_int32_t, u_int32_t> > pairList;
typedef std::list<std::pair<u_int32_t, u_int32_t> >::iterator pairListIter;

typedef std::deque<u_int32_t> deq;
typedef std::deque<u_int32_t>::iterator deqIter;

// New functions for Merge-Insert with pairs
void printList(const listBin& lb, const std::string& name);
void printPairs(const pairList& pl, const std::string& name);

// Core algorithm functions
listBin mergeInsertion(listBin lb);
listBin mergeInsertionFordJohnson(listBin input);

// Helper functions
listBin sortMainChain(listBin main_chain);
void insertWithJacobsthal(listBin& main_chain, listBin& b_list);
void insertBWithRange(listBin& main_chain, u_int32_t b_val, listBinIter limit);

// Jacobsthal sequence
std::vector<int> getJacobsthalSequence(int count);
int jacobsthalNumber(int n);

// Utility functions  
void checkSorted(const listBin& lb);
int tSub(int k);

// Deque versions
std::deque<u_int32_t> splitMainChainDeq(std::deque<u_int32_t>& input, std::deque<u_int32_t>& main_chain, std::deque<u_int32_t>& b_list);
void insertDequeSorted(std::deque<u_int32_t>& dq, std::deque<u_int32_t>& b);
std::deque<u_int32_t> mergeInsertionDeq(std::deque<u_int32_t>& input);

#endif