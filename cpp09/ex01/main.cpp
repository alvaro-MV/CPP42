#include <bits/stdc++.h>
#include "RPN.hpp"

tokens	get_tokens(std::string line) {
    tokens toks;
    std::stringstream check1(line);
    
    std::string intermediate;
    
    while(getline(check1, intermediate, ' '))
    {
        toks.push_back(intermediate);
    }
	toks.push_back(std::string(""));
	return (toks);
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "./RPN \"<RPN mathematical expression>\"" << std::endl;
		std::cout << "\tp.e. ./RPN \"7 7 * 7 -\"" << std::endl;
		return (1);
	}
	bool				error;
	int					depth = root;
	// std::list<Node>		RPN_AST;
	Expr				current;
	Expr				tmp;
	tokens				toks = get_tokens(argv[1]);
	tokens::iterator	it = toks.begin();
	tokens::iterator	end = toks.end();
	Iter				iter(it, end);

	if (lookahead(it, end, 1) == END)
		return (0);
	else if (lookahead(it, end, 2) == END)
		return (Leave(root, itoa(*it, error)).get_value());

	while (lookahead(it, end, 1) != END) {
		if (depth == right)
			//tmp sirve aqui para generar uno por encima del anterior.
		current = Expr(root);
		if (lookahead(it, end, 2) == NUM) {
			// node = new Leave(left, itoa(*it, error));
			// current.set_child(node, left);
			// pop(it, end, 1);
			set_leave(current, iter, left);
			// Aqui logica recursiva.
			depth = right;
		}
		else if (lookahead(it, end, 2) == OP) {
			set_leave(current, iter, left);
			set_leave(current, iter, right);
		}
	}
}
