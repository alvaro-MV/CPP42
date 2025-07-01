#ifndef MUTAN_STACK_H
# define MUTAN_STACK_H

# include <iostream>
# include <set>
# include <vector>
# include <utility>
# include <string>
# include <cstring>
# include <ctime>
# include <limits>
# include <deque>
#include <stack>

// stacks are implemented as container adaptors, which are classes 
// that use an encapsulated object 
// of a specific container class as its underlying container, 
// providing a specific set of member functions
//  to access its elements. Elements are pushed/popped from the "back" of the specific container, 
//  which is known as the top of the stack.
template <class T, class C = std::deque<T>>
class MutantStack {
	private:
		C		c;
	
	public:
		MutantStack() {

		};
		MutantStack(const MutantStack &ms) {
			this->c = ms.c;
		};
		MutantStack& operator=(const MutantStack &ms) {
			this->c = ms.c;
			return (*this);
		}
		~MutantStack() {
			std::cout << "Destroying MutantStack" << std::endl;
		}

		//Similar a c.back(), osea, devuelve un T.
		T &top() {
			return (c.back());
		}
		const T &top() const {
			return (c.back());
		}

 		//Similar a c.size()
		size_t size() const {
			return (c.size());
		}
		bool empty() const {
			return (c.empty());
		}
		void push(const T& value) {
			return (c.push_back(value));
		}
		// void push( value_type&& value ); Tambien ofrece esta, que diferencia existirá? Después de implementar std::move.
		
		void pop() {
			return (c.pop_back());
		}
		
		/* 				Iterator functions 				*/

		class iterator : public std::iterator<
											typename std::iterator_traits<typename C::iterator>::iterator_category,
											T>
		{
			typename C::iterator	it;
			public:
				iterator(typename C::iterator cit) : it(cit) {}
				// iterator(iterator &sit) {
				// 	it = sit.it;
				// }
				iterator& operator=(iterator &sit) {
					it = sit.it;
					return (*this);
				}
				iterator& operator++() {it++; return(*this);}
				iterator& operator--() {it--; return(*this);}
				iterator operator++(int) {
					typename C::iterator	tmp = *it;
					iterator retval(tmp);
					++it; 
					return retval;
				}
				iterator operator--(int) {
					typename C::iterator	tmp = *it;
					iterator retval(tmp);
					--it; 
					return retval;
				}
				bool operator!=(iterator other) const {return !(*this == other);}
				bool operator==(iterator &other) const {return it == other.it;}
				T operator*(void) const {return *it;}
		};
		// bool operator!=(iterator &other) const {return it != other.it;}
		iterator begin() {return iterator(c.begin());}
		iterator end() {return iterator(c.end());}
};

#endif