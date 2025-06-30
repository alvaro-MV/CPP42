#include <iostream>
#include <vector>
#include <deque>

template<typename T>
T easyfind(T container, int pattern) {
    T ret;

    typename T::iterator cont_it = container.begin();
    while (cont_it != container.end()) {
        if (*cont_it == pattern)
            break ;
        ++cont_it;
    }

    if (cont_it != container.end()) {
        for (typename T::iterator it = cont_it; it != container.end(); ++it)
            ret.push_back(*it);
    } else {
        throw std::out_of_range("The pattern isn't found in container");
    }

    return ret;
}
