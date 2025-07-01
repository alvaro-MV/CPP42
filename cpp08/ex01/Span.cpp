#include "Span.hpp"

void Span::addNumber(int n) {
	std::multiset<int>::iterator	it;

	// if (span.size() == N)
	// 	throw OutOfRangeExceptcion();
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

template <class Inputiterator>
void Span::addnumber(int n, Inputiterator first, Inputiterator last) {
	
}

unsigned int Span::shortestSpan() {
	// if (span.size() < 2)
	// 	throw NotEnoughNumbersinSpan();
	return (shortest);
}

unsigned int Span::longestSpan() {
	// if (span.size() < 2)
	// 	throw NotEnoughNumbersinSpan();
	return (max - min);
}