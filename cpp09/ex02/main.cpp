#include <PmergeMe.hpp>

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
listBin	mergeInsertion(listBin rata) {
	std::map<uint32_t, uint32_t> binding;
	listBin b = splitMainChain(rata, binding);
	rata = mergeInsertion(rata);
	// rata.decrLevelBinding();
	
	unsigned int prevMainChain = 0;
	unsigned int k = 1;
	while (!b.empty()) {
		unsigned int tNew = tSub(k);
		unsigned int tOld = tSub(k - 1);
		unsigned int nextMainChain = tNew + tOld;
		
		binaryInsert(rata, b, nextMainChain, prevMainChain, tNew - tOld);
		prevMainChain = nextMainChain + 1;
		k++;
	}
	return (rata);
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