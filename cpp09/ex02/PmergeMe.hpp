#ifndef PMERGEME_H
# define PMERGEME_H

# include <list>
#include <cstdlib>

struct binding
{
	unsigned int a;
	std::list<unsigned int> b;
	void	setBindingValue(unsigned int value) {
		this->b.push_front(value);
	}
};

typedef std::list<binding> listBin;
typedef std::list<binding>::iterator listBinIter;

listBin	splitMainChain(listBin &lb);

#endif