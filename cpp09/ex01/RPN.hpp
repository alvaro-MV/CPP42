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

int			pop(tokens::iterator &i, tokens::iterator e);
int			itoa(std::string str, bool &fail);

#endif