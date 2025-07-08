#include "PmergeMe.hpp"

/* 
	Que necesito --> Una estructura de datos que soporte:

	- Extraer un subconjunto a través de par, impar.
	- Extraer un subconujnto a través de start-end. Como un substr pero general.
	- Inserción de forma sencilla (en realidad, todos).
	- Binary search and insertion, fundamentalmente con un pos.
	- Que pueda guardar un link al b que le corresponde. Esto es problematico, porque
		a la hora de hacer la recursividad ese campo no se puede reutilizar.
		La posible solucion es crear una copia sin iterador asociado.
		Tiene sentido crear una copia sin iterador asociado.
	
	- Otra posibilidad es trabajar con los indices. Guardar un indice que le corresponde.
		Este indice puede ser otra lista, que funcione como un stack, en el sentido de que
		conforme se hace una llamada recursiva, el indice se acumula en el frente de la lista.
		--> Push_front. Aunque tambien se puede hacer en el back y utilizar el back y pop_back, como en deque.
	
	- Si se hace con indices, se consigue que no se pisen lo fregado.
	- Sencillo acceder al array de b's. La cuestion es si después de las inserciones se ha de eliminar.
		Yo digo que no, porque si no habria que actualizar todos a cada momento.

	- Es una mierda, hay que trabajar con una puta copia, porque si no te vuelves loco.
	- Por lo tanto, basicamente, se trabaja construyendo el array, con dos iterador a y b, respectivamente.
	- 
*/
listBin	mergeInsertion(listBin lb) {
	std::map<uint32_t, uint32_t> binding;
	listBin llb;

	if (lb.size() == 1)
		return (lb);
    std::cout << "Antes del split:" << std::endl;
    printList(lb, "lb");

    listBin b = splitMainChain(lb, binding);

    std::cout << "\nDespués del split:" << std::endl;
    printList(lb, "lb");
    printList(b, "ret");
	
	llb = mergeInsertion(lb);
    printList(llb, "llb");
    listBinIter it = llb.begin();
    listBinIter bit = b.begin();
    for (int i = 0; i < (llb.size() - (llb.size() % 2 == 0) * 1); i++) {
        *bit = binding[*it];
        it++;
    }

	unsigned int prevMainChain = 0;
	unsigned int k = 1;
	while (!b.empty()) {
		unsigned int tNew = tSub(k);
		unsigned int tOld = tSub(k - 1);
		unsigned int nextMainChain = tNew + tOld;
		
		insertList(llb, b, nextMainChain, prevMainChain);
    	printList(b, "b dentro de el bucle de los t");
		prevMainChain = nextMainChain + 1;
		k++;
	}
	return (llb);
}

int main() {
    listBin lb = {26,12,19};
	
	listBin llb = mergeInsertion(lb);
    printList(llb, "llb");

    return 0;
}

unsigned int	tSub(unsigned int k) {
	unsigned twoMultiple = 1;
	unsigned signMultiple = 1;

	for (int i = 0; i < k + 1; i++) {
		twoMultiple *= 2;
		signMultiple *= -1;
	}
	signMultiple / -1;
	return ((twoMultiple + signMultiple) /3);
}