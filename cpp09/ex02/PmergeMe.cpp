#include "PmergeMe.hpp"

binding createBinding(unsigned int a) {
	binding	bin;

	bin.a = a;
	return (bin);
}

/* 
	Basicamente lo que hay que hacer es:
		- Determinar cual de los pares, si uno o el otro es mas grande.
		- Pushear al binding del mayor el pequeño en el campo b.
		- Se mueve el pequeño a ret
		- Se elimina el pequeño de la cadena principal.
		- Se devuelve ret.
*/
listBin	splitMainChain(listBin &lb) {
	listBin	ret;
	listBinIter it;

	for (int i = 0; it != lb.end(); it++) {
		listBinIter end = ret.end();
		end--;
		if (i % 2)
		{
			listBinIter prev_it = it;
			prev_it--;
			if (prev_it->a < it->a) {
				it->setBindingValue(prev_it->a);
				ret.splice(end, lb, prev_it);				
			}
			else {
				it->setBindingValue(prev_it->a);
				ret.splice(end, lb, prev_it);				
			}
		}
		i++;
	}
	return (ret);
}