#include "RPN.hpp"

int			pop(tokens::iterator &i, tokens::iterator e)
{
    int 	num;
    bool	itoa_fail;

	num = itoa(*i, itoa_fail);
	if (itoa_fail == false)
		return (--i, num);
	else if (!std::string(*i).compare("+"))
		return (--i, add);
	else if (!std::string(*i).compare("-"))
		return (--i, sust);
	else if (!std::string(*i).compare("*"))
		return (--i, mult);
	else if (!std::string(*i).compare("/"))
		return (--i, divs);
	else if (i == e)
		return (end);
	else
		return (end);
}

int	itoa(std::string str, bool &fail) {
	int num;
	std::istringstream iss(str);

    iss >> num;
	if (iss.fail() == false)
	{
		fail = false;
		return (num);
	}
	else
	{
		fail = true;
		return (-1);
	}
}
