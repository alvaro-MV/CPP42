#ifndef RPN_H
# define RPN_H

# include <string>
# include <bits/stdc++.h>

enum branches {
	left = 1,
	right,
	root
};

enum ops {
	add = 1,
	sust,
	mult,
	divs,
	end
};

enum look_obj {
	NUM = 1,
	OP,
	END
};

typedef std::vector<std::string> tokens;

struct Iter
{
	tokens::iterator	it;
	tokens::iterator	begin;
	Iter(tokens::iterator it, tokens::iterator begin): 
													it(it),
													begin(begin) {};
};

class Node
{
	protected:
		branches	branch;
	
	public:
		virtual int	get_value() = 0;
		// int			get_branch();
		virtual 	~Node() {

		};
};

class Expr: public Node
{
	private:
		ops			op;
		Node		*left;
		Node		*right;
		branches	branch;
	
	public:
		Expr() {
			branch = root;
			left = nullptr;
			right = nullptr;
		}
		Expr(branches branch) {
			this->branch = branch;
			left = nullptr;
			right = nullptr;
		}
		Expr(const Expr& ex) {
			this->branch = ex.branch;
			this->left = ex.left;
			this->right = ex.right;
		}
		Expr &operator=(const Expr& ex) {
			this->branch = ex.branch;
			this->left = ex.left;
			this->right = ex.right;
			return (*this);
		}
		~Expr() {

		}
		// El resto
		int		get_value(void);
		Node	*get_child(branches branch);
		void	set_child(Node *child, branches branch);
		void	set_op(ops op);
		branches		get_branch();
};

class Leave: public Node
{
	private:
		branches	branch;
		int			value;
		
	public:
		Leave(branches branch, int value): branch(branch), value(value) {}

		Leave(const Leave& l) {
			branch = l.branch;
			value = l.value;
		}
		Leave& operator=(const Leave& l) {
			branch = l.branch;
			value = l.value;
			return (*this);
		}
		int			get_value();
		branches	get_branch();
};


look_obj	lookahead(tokens::iterator i, tokens::iterator e, int dist);
int			pop(tokens::iterator &i, tokens::iterator e);
int			itoa(std::string str, bool &fail);
void		set_leave(Expr *current, Iter &iter, branches b);


#endif