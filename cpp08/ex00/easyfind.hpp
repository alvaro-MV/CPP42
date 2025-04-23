#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <typeinfo>
#include <stdexcept>

template<typename T>
T easyfind(T container, int pattern);

#include "easyfind.tpp"

#endif