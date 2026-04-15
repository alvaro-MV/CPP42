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

bool is_number(std::string& s) {
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

bool	is_valid_input(tokens tok) {
	for (size_t i = 0; i < tok.size() - 1; i++) {
		if (!is_number(tok[i]) && !is_op(tok[i]))
			return (false);
	}
	return (true);
}

int	RPN_calc(tokens &toks) {
	std::stack<int> st;
	int a;
	int b;
	int result;
	int num;

	for (size_t i = 0; i < toks.size(); i++) {
		if (is_op(toks[i])) {
			if (st.size() < 2)
				throw std::runtime_error("Error");
			b = st.top(); st.pop();
            a = st.top(); st.pop();
			result = apply_op(a, b, toks[i]);
			st.push(result);
		}
		else {
			num = parseInt(toks[i]);
            st.push(num);
		}
	}
	if (st.size() != 1)
		throw std::runtime_error("Error");
	return st.top();
}

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "./RPN \"<RPN mathematical expression>\"" << std::endl;
		std::cout << "\tp.e. ./RPN \"7 7 * 7 -\"" << std::endl;
		return (1);
	}
	tokens	toks = get_tokens(remove_extra_spaces(argv[1]));
	
	try {
		std::cout << RPN_calc(toks) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}