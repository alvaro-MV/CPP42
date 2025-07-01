#include "Span.hpp"

void	Span::insert_and_recalc(int n) {
	std::multiset<int>::iterator	it;

	span.insert(n);
	it = span.find(n);
	if (span.size() > 1)
	{
		if (it != span.begin()) {
			std::multiset<int>::iterator prev = it;
			prev--;
			if (prev != span.begin())
				this->shortest = *it - *prev < this->shortest ? *it - *prev : this->shortest;
		}
		if (it != span.end()) {
			std::multiset<int>::iterator next = it;
			next++;
			if (next != span.end())
				this->shortest = *next - *it < this->shortest ? *next - *it : this->shortest;
		}
	}
	else
		this->shortest = n;
	max = n > max ? n : max;
	min = n < min ? n : min;
}

void Span::addNumber(int n) {
	if (span.size() == N)
		throw Span::OutOfSpaceException(N);
	insert_and_recalc(n);
}

unsigned int Span::shortestSpan() {
	if (span.size() < 2)
			throw Span::Less2ThanException(N);
	return (shortest);
}

unsigned int Span::longestSpan() {
	if (span.size() < 2)
		throw Span::Less2ThanException(N);
	return (max - min);
}

const char	*Span::OutOfSpaceException::what(void) const throw() {
	std::string problem = "OutOfSpaceException: "
	+ std::to_string(this->_N)
	+" slots filled.\n";
	
	char *ret = new char[problem.length() + 1];
	std::strcpy(ret, problem.c_str());
	return (ret);
}

const char	*Span::Less2ThanException::what(void) const throw() {
	std::string problem = "Less2ThanException: less than two element filled. Impossible to calculate spans.\n";
	
	char *ret = new char[problem.length() + 1];
	std::strcpy(ret, problem.c_str());
	return (ret);
}