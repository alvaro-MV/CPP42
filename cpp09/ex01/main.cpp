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

std::string remove_extra_spaces(const std::string& input) {
    std::stringstream ss(input);
    std::string word, result;

    while (ss >> word) {
        if (!result.empty())
            result += " ";
        result += word;
    }

    return result;
}


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

int	RPN_calc(tokens::iterator &it, tokens::iterator begin, tokens::iterator end) {
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
				right = RPN_calc(it, begin, end);
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
				left = RPN_calc(it, begin, end);
			}
			if (contador < 2) {
				std::cerr << "Error" << std::endl;
				exit(1);
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
	tokens				toks = get_tokens(remove_extra_spaces(argv[1]));
	tokens::iterator end = toks.end();
	std::cout << RPN_calc(end, toks.begin(), toks.end()) << std::endl;
}