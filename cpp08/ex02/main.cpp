#include "MutanStack.hpp"

int main()
{
	MutantStack<int> mstack;

	std::cout << "ms empyt? --> " << mstack.empty() << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	// mstack.pop();
	std::cout << "Cual es el sizeee???  " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	// std::stack<int> s(mstack);
	return 0;
}