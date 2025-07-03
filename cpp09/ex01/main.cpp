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

// Expr	*create_block(Expr *current, Iter &iter, int dist) {
// 	Expr	*right_child;
// 	int		flag = 0;

// 	while (lookahead(iter.it, iter.end, 1) != END) {
// 		if (current->get_branch() == root && flag++ && dist > 1)
// 			dist--;
// 		if (lookahead(iter.it, iter.end, dist) == NUM) {
// 			if (dist > 1)
// 				set_leave(current, iter, left);
// 			else
// 			{
// 				Expr	*tmp = new Expr(root);
// 				tmp->set_child(current, left);
// 				current = tmp;
// 			}
// 			right_child = new Expr(right);
// 			current->set_child(right_child, right);
// 			create_block(right_child, iter, 2);
// 			current->set_op((ops) pop(iter.it, iter.end));
// 		}
// 		else if (lookahead(iter.it, iter.end, dist) == OP) {
// 			if (dist > 1)
// 				set_leave(current, iter, left);
// 			else
// 			{
// 				Expr	*tmp = new Expr(root);
// 				tmp->set_child(current, left);
// 				current = tmp;
// 			}
// 			set_leave(current, iter, right);
// 			current->set_op((ops) pop(iter.it, iter.end));
// 			dist = 2;
// 		}
// 	}
// 	return (current);
// }

// int main(int argc, char **argv)
// {
// 	if (argc != 2) {
// 		std::cout << "./RPN \"<RPN mathematical expression>\"" << std::endl;
// 		std::cout << "\tp.e. ./RPN \"7 7 * 7 -\"" << std::endl;
// 		return (1);
// 	}
// 	bool				error;
// 	Expr				*AST = new Expr(root);
// 	tokens				toks = get_tokens(argv[1]);
// 	Iter				iter(toks.begin(), toks.end());

// 	if (lookahead(iter.it, iter.end, 1) == END)
// 	{
// 		std::cout << 0 << std::endl;
// 		return (0);
// 	}
// 	else if (lookahead(iter.it, iter.end, 2) == END) {
// 		std::cout << Leave(root, itoa(*iter.it, error)).get_value() << std::endl;
// 		return (0);
// 	}
// 	else {
// 		AST = create_block(AST, iter, 2);
// 		std::cout << AST->get_value() << std::endl;
// 	}

// }

bool is_number(std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool	is_op(std::string s) {
	if (!std::string(s).compare("+") || !std::string(s).compare("-")
	|| !std::string(s).compare("*") || !std::string(s).compare("/"))
		return (true);
	else
		return (false);
}

int	recursivo(tokens::iterator &it, tokens::iterator begin, tokens::iterator end) {
	int	contador = 0;
	bool	fail;
	ops		op_kind;	
	int		left, right;

	if (it == end)
		it -= 2;
	std::string s = *it;
	while (it != begin && contador < 2) {
		if (is_op(std::string(*it)))
		{
			op_kind = (ops) pop(it, begin);
			if (is_number(*it))
			{
				contador++;
				right = itoa(*it, fail);
				it--;
			}
			else if (is_op(*it))
			{
				contador++;
				right = recursivo(it, begin, end);
			}
			if (is_number(*it))
			{
				contador++;
				left = itoa(*it, fail);
				it--;
			}
			else if (is_op(*it))
			{
				contador++;
				left = recursivo(it, begin, end);
			}
			
			if (op_kind == add)
				return (left + right);
			else if (op_kind == sust)
				return (left - right);
			else if (op_kind == mult)
				return (left * right);
			else if (op_kind == divs)
				return (left / right);
		}
	}
	return (itoa(*it, fail));
}

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "./RPN \"<RPN mathematical expression>\"" << std::endl;
		std::cout << "\tp.e. ./RPN \"7 7 * 7 -\"" << std::endl;
		return (1);
	}
	tokens				toks = get_tokens(argv[1]);
	Iter				iter(toks.end(), toks.begin());
	std::cout << recursivo(iter.it, iter.begin, toks.end()) << std::endl;
}