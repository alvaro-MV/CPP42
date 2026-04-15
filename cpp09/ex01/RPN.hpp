#ifndef RPN_H
# define RPN_H

# include <string>
# include <stack>
# include <bits/stdc++.h>
#include <cassert>

typedef std::vector<std::string> tokens;

int	parseInt(const std::string& str);
int apply_op(int a, int b, const std::string& op);

#endif