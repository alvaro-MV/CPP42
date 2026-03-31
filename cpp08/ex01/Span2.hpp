#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <set>
# include <vector>
# include <utility>
# include <string>
# include <cstring>
# include <cstdlib>
# include <ctime>
# include <limits>

class Span {
	private:
		unsigned int		N;
		std::multiset<int>	span;
		int		shortest;
		int		max;
		int		min;

		void	insert_and_recalc(int n);
	
	public:

		Span();
		Span(unsigned int N);
		Span(const Span& s);
		Span&	operator=(const Span& s);
		~Span();

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

		int	shortestSpan() const;
		int	longestSpan() const;

		class OutOfSpaceException : public std::exception {
			private:
				unsigned int _N;

			public:
				OutOfSpaceException(unsigned int N): _N(N){}
				const char* what(void) const throw();
		};

		class Less2ThanException : public std::exception {
			private:
				unsigned int _N;

			public:
				Less2ThanException(unsigned int N): _N(N) {}
				const char* what(void) const throw();
		};
};

#endif