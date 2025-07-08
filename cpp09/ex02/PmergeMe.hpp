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

listBin	splitMainChain(listBin &lb, std::map<uint32_t, uint32_t> &binding);

#endif