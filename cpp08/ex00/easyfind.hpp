#include <list>
#include <vector>
#include <deque>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &array, int pattern) {
    typename T::iterator it = array.begin();
    while (it != array.end() ) {
        if (*it == pattern) {
            return (it);
        }
        it++;
    }
    throw std::out_of_range("Value not found");
}