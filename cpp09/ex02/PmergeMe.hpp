#ifndef PMERGEME_H
# define PMERGEME_H

# include <list>
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


void printList(const listBin& lb, const std::string& name);
listBin	splitMainChain(listBin &lb);
void insertList(std::list<uint32_t>& lst,
                std::list<uint32_t>& b,
                int next,
                int prev);
void insertListSorted(std::list<uint32_t>& lst, std::list<uint32_t>& b);

int	tSub(int k);
static void checkSorted(const listBin& lb);

#endif