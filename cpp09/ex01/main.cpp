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

bool is_number(const std::string& s) {
    if (s.empty())
        return false;

    size_t i = 0;

    if (s[i] == '-' || s[i] == '+')
    {
        if (s.size() == 1)
            return false;
        i++;
    }

    while (i < s.size())
    {
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
        i++;
    }

    return true;
}

bool	is_op(std::string s) {
	if (!std::string(s).compare("+") || !std::string(s).compare("-")
	|| !std::string(s).compare("*") || !std::string(s).compare("/"))
		return (true);
	else
		return (false);
}


bool is_valid_input(const tokens &tok)
{
    for (tokens::const_iterator it = tok.begin(); it != tok.end(); ++it)
    {
        std::string s = *it;
        if (!is_number(s) && !is_op(s))
            return false;
    }
    return true;
}

int RPN_calc(tokens &toks)
{
    std::stack<int> st;
    int a;
    int b;
    int result;
    int num;

    for (tokens::iterator it = toks.begin(); it != toks.end(); ++it)
    {
        if (is_op(*it))
        {
            if (st.size() < 2)
                throw std::runtime_error("Error");

            b = st.top();
            st.pop();

            a = st.top();
            st.pop();

            result = apply_op(a, b, *it);
            st.push(result);
        }
        else
        {
            num = parseInt(*it);
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
	
	tokens toks = get_tokens(remove_extra_spaces(argv[1]));

    try
    {
        if (!is_valid_input(toks))
            throw std::runtime_error("Error");

        std::cout << RPN_calc(toks) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}