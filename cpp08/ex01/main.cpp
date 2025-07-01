#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    
    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(21);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (Span::OutOfSpaceException &e)
    {
        const char	*error = e.what();
        std::cout << error;
    }


    // int ints[] = {12, 23, 1, 34};

    try {
        std::vector<int> v = {12, 23, 34};
        sp.addRange(v.begin(), v.end());
    }
    catch (Span::OutOfSpaceException &e)
    {
        const char	*error = e.what();
        std::cout << error;
    }
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    return (0);
}