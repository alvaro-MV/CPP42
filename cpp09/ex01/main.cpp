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

void	create_block(Expr *current, Iter &iter, int dist) {
	Expr	*right_child;

	if (lookahead(iter.it, iter.end, dist) == NUM) {
		if (dist > 1)
			set_leave(current, iter, left);
		right_child = new Expr(right);
		std::cout << "el valor de la branch en right child: " << current->get_branch() << std::endl;
		current->set_child(right_child, right);
		std::cout << "el valor de la branch: " << current->get_branch() << std::endl;
		create_block(right_child, iter, 2);
		current->set_op((ops) pop(iter.it, iter.end));
	}
	else if (lookahead(iter.it, iter.end, dist) == OP) {
		if (dist > 1)
			set_leave(current, iter, left);
		set_leave(current, iter, right);
		current->set_op((ops) pop(iter.it, iter.end));
		std::cout << "current value right: " << current->get_child(right)->get_value() << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "./RPN \"<RPN mathematical expression>\"" << std::endl;
		std::cout << "\tp.e. ./RPN \"7 7 * 7 -\"" << std::endl;
		return (1);
	}
	bool				error;
	Expr				*AST = new Expr(root);
	std::cout << "Pero cual es el puto valor de la branch dentro del AST, niñoooo??? " <<  AST->get_branch() << std::endl;
	tokens				toks = get_tokens(argv[1]);
	Iter				iter(toks.begin(), toks.end());

	if (lookahead(iter.it, iter.end, 1) == END)
	{
		std::cout << 0 << std::endl;
		return (0);
	}
	else if (lookahead(iter.it, iter.end, 2) == END) {
		std::cout << Leave(root, itoa(*iter.it, error)).get_value() << std::endl;
		return (0);
	}
	else {

		while (lookahead(iter.it, iter.end, 1) != END) {
			static int nodes_traversed = 0;
			if (nodes_traversed > 0)
			{
				Expr	*tmp = new Expr(root);
				tmp->set_child(AST, left);
				create_block(tmp, iter, 1);
				AST = tmp;
			}
			else
				create_block(AST, iter, 2);
			nodes_traversed++;
		}
		std::cout << AST->get_value() << std::endl;
	}

}
