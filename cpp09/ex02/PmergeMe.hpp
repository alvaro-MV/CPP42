#ifndef PMERGEME_H
# define PMERGEME_H

# include <list>
# include <deque>
#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <cmath>
#include <iomanip>
#include <random>
#include <vector>

typedef std::list<uint32_t> listBin;
typedef std::list<uint32_t>::iterator listBinIter;

typedef std::deque<uint32_t> deq;
typedef std::list<uint32_t>::iterator deqIter;


void printList(const listBin& lb, const std::string& name);
listBin	splitMainChain(listBin &lb);
void insertListSorted(std::list<uint32_t>& lst, std::list<uint32_t>& b);

int	tSub(int k);
static void checkSorted(const listBin& lb);


std::deque<uint32_t> splitMainChainDeq(std::deque<uint32_t>& input, std::deque<uint32_t>& main_chain, std::deque<uint32_t>& b_list);
void insertDequeSorted(std::deque<uint32_t>& dq, std::deque<uint32_t>& b);
std::deque<uint32_t> mergeInsertionDeq(std::deque<uint32_t>& input);

#endif