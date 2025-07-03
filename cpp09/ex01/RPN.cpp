#include "RPN.hpp"

/* Se asume que no hay errores de en la entrada.
	Por lo tanto hay tres posibilidades:
		- O que estemos en el último, que entonces --> END
		- O que sea un número --> NUM
		- O que sea un operador --> 
*/
look_obj	lookahead(tokens::iterator i, tokens::iterator e, int dist)
{
	if (e - i <= dist)
		return (END);

	std::string ahead = *(i + dist);
	std::istringstream iss(ahead);
    int num;

    iss >> num;
	if (iss.fail() == false)
		return (NUM);
	else if (!ahead.compare("+") || !ahead.compare("-")
		|| !ahead.compare("*") || !ahead.compare("/"))
		return (OP);
}

int			pop(tokens::iterator &i, tokens::iterator e, int dist)
{
	
    int 	num;
    bool	itoa_fail;

	num = itoa(*i, itoa_fail);
	if (itoa_fail == false)
		return (++i, num);
	else if (!std::string(*i).compare("+"))
		return (++i, add);
	else if (!std::string(*i).compare("-"))
		return (++i, sust);
	else if (!std::string(*i).compare("*"))
		return (++i, mult);
	else if (!std::string(*i).compare("/"))
		return (++i, divs);
	else
		return (end);
}

void	set_leave(Expr &current, Iter &iter, branches branch) {
	Node	*node;
	bool	error;

	node = new Leave(left, itoa(*iter.it, error));
	current.set_child(node, left);
	pop(iter.it, iter.end, 1);
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

void	Expr::set_child(Node *child, branches branch) {
	if (branch == 1)
		this->left = child;
	else
		this->right = child;
}

int	Leave::get_value(void) {
	return (this->value);
}