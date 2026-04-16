#include "PmergeMe.hpp"
#include "Pmerge.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <ctime>

// ==================== CHECK SORT ====================

static bool isSortedVector(const std::vector<unsigned int> &v)
{
    for (size_t i = 1; i < v.size(); ++i)
    {
        if (v[i] < v[i - 1])
            return false;
    }
    return true;
}

static bool isSortedDeque(const std::deque<unsigned int> &d)
{
    for (size_t i = 1; i < d.size(); ++i)
    {
        if (d[i] < d[i - 1])
            return false;
    }
    return true;
}

// ==================== PARSE ====================

static void parseInput(int argc, char **argv, std::vector<unsigned int> &input)
{
    for (int i = 1; i < argc; ++i)
    {
        char *end;
        long val = std::strtol(argv[i], &end, 10);

        if (*end != '\0' || val < 0)
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
        input.push_back(static_cast<unsigned int>(val));
    }
}

// ==================== PRINT ====================

static void printPreview(const std::vector<unsigned int> &v)
{
    size_t limit = 5;

    for (size_t i = 0; i < v.size() && i < limit; ++i)
        std::cout << v[i] << " ";

    if (v.size() > limit)
        std::cout << "... ";

    for (size_t i = (v.size() > limit ? v.size() - limit : 0); i < v.size(); ++i)
        std::cout << v[i] << " ";

    std::cout << std::endl;
}

// ==================== RUN ====================

void PmergeMe::run(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return;
    }

    std::vector<unsigned int> input;
    parseInput(argc, argv, input);

    std::cout << "Before: ";
    printPreview(input);

    // ==================== VECTOR ====================
    clock_t start = clock();
    std::vector<unsigned int> v = fordJohnsonVector(input);
    clock_t end = clock();

    std::cout << "Vector: ";
    if (isSortedVector(v))
        std::cout << "OK ";
    else
        std::cout << "KO ";
    printPreview(v);

    std::cout << "Time: "
              << (double)(end - start) / CLOCKS_PER_SEC * 1000
              << " ms" << std::endl;

    // ==================== DEQUE ====================
    std::deque<unsigned int> d(input.begin(), input.end());

    start = clock();
    d = fordJohnsonDeque(d);
    end = clock();

    std::cout << "Deque: ";
    if (isSortedDeque(d))
        std::cout << "OK";
    else
        std::cout << "KO";

    std::cout << " | Time: "
              << (double)(end - start) / CLOCKS_PER_SEC * 1000
              << " ms" << std::endl;
}