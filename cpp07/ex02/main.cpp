#include <iostream>
#include "../ex01/iter.hpp"
#include "Array.hpp"

#define MAX_VAL 7

std::string toString(size_t sz) {
    std::ostringstream  oss;
    oss << sz;
    return (oss.str());
}

int main(int, char**)
{
    const char *what_message;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // iter(numbers, numbers.size(), print_I<int>);
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "Every comparison result equal.\n";

    Array<int> copy_numbers(numbers);
    for (int i = 0; i < MAX_VAL; i++)
        copy_numbers[i] = i;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "Every comparison after copy constructor called result equal.\n";

    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        what_message = e.what();
        std::cerr << what_message << '\n';
        what_message = NULL;
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {

        what_message = e.what();
        std::cerr << what_message << '\n';
    }
    delete [] mirror;//
    return 0;
}