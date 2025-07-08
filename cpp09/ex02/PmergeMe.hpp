#ifndef PMERGEME_H
# define PMERGEME_H

# include <list>
#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <cmath>
#include <iomanip>
#include <vector>

typedef std::list<uint32_t> listBin;
typedef std::list<uint32_t>::iterator listBinIter;


void printList(const listBin& lb, const std::string& name);
listBin	splitMainChain(listBin &lb, std::map<uint32_t, uint32_t> &binding);
void insertList(std::list<uint32_t>& lst,
                std::list<uint32_t>& b,
                uint32_t next,
                uint32_t prev);

unsigned int	tSub(unsigned int k);

#endif