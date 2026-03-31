#include "Span.hpp"

Span::Span(): N(0) {
	shortest = std::numeric_limits<int>::max();
	max = 0;
	min =  std::numeric_limits<int>::max();
}

Span::Span(unsigned int N): N(N) {
	shortest = std::numeric_limits<int>::max();
	max = 0;
	min =  std::numeric_limits<int>::max();
}

Span::Span(const Span& s) {
	N = s.N;
	span = s.span;
	shortest = s.shortest;
	max = s.max;
	min = s.min;
}

Span&	Span::operator=(const Span& s) {
	N = s.N;
	span = s.span;
	shortest = s.shortest;
	max = s.max;
	min = s.min;
	return (*this);
}

Span::~Span() {
	std::cout << "Span destroyed\n";
}

void	Span::insert_and_recalc(int n) {
	std::multiset<int>::iterator	it;

	span.insert(n);
	it = span.find(n);
	if (span.size() > 1)
	{
		if (it != span.begin()) {
			std::multiset<int>::iterator prev = it;
			prev--;
			if (it != span.begin()) {
				std::multiset<int>::iterator prev = it;
				--prev;
				shortest = std::min(shortest, *it - *prev);
			}
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
		throw Span::OutOfSpaceException();
	insert_and_recalc(n);
}

int Span::shortestSpan() const {
	if (span.size() < 2)
			throw Span::Less2ThanException();
	return (shortest);
}

int Span::longestSpan() const {
	if (span.size() < 2)
		throw Span::Less2ThanException();
	return (max - min);
}

Span::OutOfSpaceException::OutOfSpaceException() {}
Span::Less2ThanException::Less2ThanException() {}

const char* Span::OutOfSpaceException::what() const throw() {
    return "OutOfSpaceException: span is full";
}

const char* Span::Less2ThanException::what() const throw() {
    return "Less2ThanException: not enough elements";
}