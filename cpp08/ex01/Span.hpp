#ifndef SPAN_H
# define SPAN_H

#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <string>
#include <cstring>
#include <limits>

class Span {
	private:
		unsigned int		N;
		std::multiset<int>	span;
		int		shortest;
		int		max;
		int		min;

		void	insert_and_recalc(int n);
	
	public:
	
		Span(unsigned int N): N(N) {
			shortest = std::numeric_limits<int>::max();
			max = 0;
			min =  std::numeric_limits<int>::max();
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
		void addRange(Inputiterator first, Inputiterator last) {
			while (first != last) {
				if (span.size() == N)
					throw  Span::OutOfSpaceException(N);
				insert_and_recalc(*first);
				first++;
			}
		}

		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		class OutOfSpaceException : public std::exception {
			private:
				size_t _N;

			public:
				OutOfSpaceException(unsigned int N): _N(N){}
				const char* what(void) const throw();
		};

		class Less2ThanException : public std::exception {
			private:
				size_t _N;

			public:
				Less2ThanException(unsigned int N): _N(N) {}
				const char* what(void) const throw();
		};
};

#endif