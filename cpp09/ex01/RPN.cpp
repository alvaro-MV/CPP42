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
	else return (END);
}

int			pop(tokens::iterator &i, tokens::iterator e)
{
	
    int 	num;
    bool	itoa_fail;

	std::cout << "pop dentro, el string que convierte es : " << *i << std::endl;
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
	else if (i == e)
		return (end);
	else
		return (end);
}

void	set_leave(Expr *current, Iter &iter, branches b) {
	Node	*node;
	bool	error;

	node = new Leave(b, itoa(*iter.it, error));
	std::cout << "LEave dentro, el valor es: " << node->get_value() << std::endl;
	current->set_child(node, b);
	pop(iter.it, iter.end);
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

inline int	add_fn(int a, int b) {
	return (a + b);
}

inline int	rest_fn(int a, int b) {
	return (a - b);
}

inline int	mult_fn(int a, int b) {
	return (a * b);
}

inline int	div_fn(int a, int b) {
	return (a / b);
}

branches Expr::get_branch() {
	return (this->branch);
}

branches Leave::get_branch() {
	return (this->branch);
}

void	Expr::set_child(Node *child, branches branch) {
	if (branch == 1)
		this->left = child;
	else
		this->right = child;
}

Node	*Expr::get_child(branches branch) {
	if (branch == 1)
		return (this->left);
	else
		return (this->right);
}

void	Expr::set_op(ops op) {
	this->op = op;
}

int	Expr::get_value(void) {
	int	oper = op;
	if (oper == add)
	{
		return (add_fn(this->get_child((branches) 1)->get_value(),
		this->get_child((branches) 2)->get_value()));
	}
	else if (oper == sust)
	{
		return (rest_fn(this->get_child((branches) 1)->get_value(),
		this->get_child((branches) 2)->get_value()));
	}
	else if (oper == mult)
	{
		return (mult_fn(this->get_child((branches) 1)->get_value(),
		this->get_child((branches) 2)->get_value()));
	}
	else if (oper == divs)
	{
		return (div_fn(this->get_child((branches) 1)->get_value(),
		this->get_child((branches) 2)->get_value()));
	}
	else
		return (0);
}

int	Leave::get_value(void) {
	return (this->value);
}