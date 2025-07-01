#ifndef SPAN_H
# define SPAN_H

#include <iostream>
#include <set>
#include <utility>

class Span {
	private:
		unsigned int		N;
		std::multiset<int>	span;
		int		shortest;
		int		max;
		int		min;
	
	public:
	
		Span(unsigned int N): N(N) {
			shortest = 2147483647;
			max = 0;
			min = 2147483647;
		}
		Span(const Span& s) {
			N = s.N;
			span = s.span;
			shortest = s.shortest;
			max = s.max;
			min = s.min;
		}
		Span&	operator=(const Span& s) {
			N = s.N;
			span = s.span;
			shortest = s.shortest;
			max = s.max;
			min = s.min;
			return (*this);
		}
		~Span() {
			std::cout << "Span destroyed\n";
		}

		void			addNumber(int n);

		template <class Inputiterator>
		void			addnumber(int n, Inputiterator first, Inputiterator last);

		unsigned int	shortestSpan();
		unsigned int	longestSpan();

};

#endif