#ifndef WHATEVER_H
#define WHATEVER_H

#include <iostream>

template<typename T>
void swap(T &t1, T &t2) {
	T tmp;
	tmp = t1;
	t1 = t2;
	t2 = tmp;
}

template<typename T>
T const& min(T const &t1, T const &t2) {
	if (t1 < t2)
		return (t1);
	else
		return (t2);
}

template<typename T>
T const& max(T const &t1, T const &t2) {
	if (t1 > t2)
		return (t1);
	else
		return (t2);
}

#endif