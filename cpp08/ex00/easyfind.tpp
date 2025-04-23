#include <iostream>
#include <vector>
#include <forward_list>

// Generic push_back_helper for containers with push_back
template<typename Container>
void push_back_helper(Container& c, int value, std::false_type) {
    c.push_back(value);
}

// Specialization for std::forward_list (which doesn't support push_back)
template<typename Container>
void push_back_helper(Container&, int, std::true_type) {
    // Do nothing – we should never reach here for forward_list
}

// Type trait emulation for C++98: checks if T is std::forward_list<int>
template<typename T>
struct is_forward_list {
    static const bool value = false;
};

template<>
struct is_forward_list<std::forward_list<int> > {
    static const bool value = true;
};

// Main push_back that dispatches to helper
template<typename T>
void push_back(T& ret, int next) {
    push_back_helper(ret, next, std::integral_constant<bool, is_forward_list<T>::value>());
}

template<typename T>
T easyfind(T container, int pattern) {
    T ret;
    int tmp;

    typename T::iterator cont_it = container.begin();
    while (cont_it != container.end()) {
        if (*cont_it == pattern)
            break ;
        ++cont_it;
    }

    if (cont_it != container.end()) {
        if (is_forward_list<T>::value) {
            for (typename T::iterator it = cont_it; it != container.end(); ++it) {
                if (!ret.empty()) {
                    tmp = ret.front();
                    ret.front() = *it;
                    ret.push_front(tmp);
                } else {
                    ret.push_front(*it);
                }
            }
        } else {
            for (typename T::iterator it = cont_it; it != container.end(); ++it)
                push_back(ret, *it);
        }
    } else {
        throw std::out_of_range("The pattern isn't found in container");
    }

    return ret;
}
