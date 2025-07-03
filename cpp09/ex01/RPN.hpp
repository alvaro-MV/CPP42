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
	tokens::iterator	end;
	public:
	Iter(tokens::iterator it, tokens::iterator end): 
													it(it),
													end(end) {};
};

class Node
{
	protected:
		branches	branch;
	
	public:
		virtual int	get_value() = 0;
};

class Expr: public Node
{
	private:
		branches	branch;
		ops			op;
		Node		*left;
		Node		*right;
	
	public:
		Expr() {
			left = nullptr;
			right = nullptr;
		}
		Expr(branches branch): branch(branch) {
			left = nullptr;
			right = nullptr;
		}
		Expr(const Expr& ex) {
			this->branch = branch;
			this->left = ex.left;
			this->right = ex.right;
		}
		Expr &operator=(const Expr& ex) {
			this->branch = branch;
			this->left = ex.left;
			this->right = ex.right;
			return (*this);
		}
		~Expr() {
			delete left;
			delete right;
		}
		// El resto
		int		get_value(void);
		void	set_child(Node *child, branches branch);
};

class Leave: public Node
{
	private:
		branches	branch;
		int			value;
	
	public:
		Leave(branches branch, int value): branch(branch), value(value) {}
		int		get_value();
};


look_obj	lookahead(tokens::iterator i, tokens::iterator e, int dist);
int			pop(tokens::iterator &i, tokens::iterator e, int dist);
int			itoa(std::string str, bool &fail);
void		set_leave(Expr &current, Iter &iter, branches branch);


#endif