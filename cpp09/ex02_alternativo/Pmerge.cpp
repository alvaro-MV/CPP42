#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>

// ==================== PARSING ====================

void parseInput(int argc, char **argv, std::vector<unsigned int> &input) {
    for (int i = 1; i < argc; ++i) {
        char *endptr;
        long val = std::strtol(argv[i], &endptr, 10);

        if (*endptr != '\0' || val < 0 || val > UINT_MAX) {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
        input.push_back(static_cast<unsigned int>(val));
    }
}

// ==================== PAIRS ====================

std::vector<std::pair<unsigned int, unsigned int> >
createPairs(const std::vector<unsigned int> &input)
{
    std::vector<std::pair<unsigned int, unsigned int> > pairs;

    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        unsigned int x = input[i];
        unsigned int y = input[i + 1];

        if (x > y)
            pairs.push_back(std::make_pair(x, y)); // (a,b)
        else
            pairs.push_back(std::make_pair(y, x));
    }
    return pairs;
}

void splitPairs(const std::vector<std::pair<unsigned int, unsigned int> > &pairs,
                std::vector<unsigned int> &main_chain)
{
    for (size_t i = 0; i < pairs.size(); ++i)
        main_chain.push_back(pairs[i].first);
}

// ==================== JACOBSTHAL ORDER ====================

std::vector<unsigned int> generateInsertionOrder(size_t n)
{
    std::vector<unsigned int> order;

    if (n == 0)
        return order;

    order.push_back(1);
    if (n == 1)
        return order;

    std::vector<unsigned int> jacob;
    jacob.push_back(1);

    unsigned int prev = 1;
    unsigned int curr = 3;

    while (curr <= n) {
        jacob.push_back(curr);
        unsigned int next = curr + 2 * prev;
        prev = curr;
        curr = next;
    }

    unsigned int last = 1;

    for (size_t i = 1; i < jacob.size(); ++i) {
        unsigned int j = jacob[i];

        order.push_back(j);

        for (unsigned int k = j - 1; k > last; --k)
            order.push_back(k);

        last = j;
    }

    for (unsigned int k = n; k > last; --k)
        order.push_back(k);

    return order;
}

// ==================== INSERTION ====================

void insertWithLimit(std::vector<unsigned int> &main_chain,
                     unsigned int value,
                     std::vector<unsigned int>::iterator limit)
{
    std::vector<unsigned int>::iterator pos =
        std::lower_bound(main_chain.begin(), limit, value);

    main_chain.insert(pos, value);
}

void insertWithJacobsthal(std::vector<unsigned int> &main_chain,
                          const std::vector<std::pair<unsigned int, unsigned int> > &pairs)
{
    if (pairs.empty())
        return;

    // Insert b1
    unsigned int b0 = pairs[0].second;
    unsigned int a0 = pairs[0].first;

    std::vector<unsigned int>::iterator it =
        std::find(main_chain.begin(), main_chain.end(), a0);

    if (it != main_chain.end())
        insertWithLimit(main_chain, b0, it);

    // Generate order
    std::vector<unsigned int> order = generateInsertionOrder(pairs.size());

    for (size_t i = 1; i < order.size(); ++i) {
        size_t idx = order[i] - 1;
        if (idx >= pairs.size())
            continue;

        unsigned int b = pairs[idx].second;
        unsigned int a = pairs[idx].first;

        std::vector<unsigned int>::iterator pos =
            std::find(main_chain.begin(), main_chain.end(), a);

        if (pos != main_chain.end())
            insertWithLimit(main_chain, b, pos);
    }
}

// ==================== FORD-JOHNSON ====================

std::vector<unsigned int> fordJohnson(std::vector<unsigned int> input)
{
    if (input.size() <= 1)
        return input;

    bool hasOdd = (input.size() % 2 == 1);
    unsigned int odd = 0;
    if (hasOdd)
        odd = input.back();

    std::vector<std::pair<unsigned int, unsigned int> > pairs =
        createPairs(input);

    std::vector<unsigned int> main_chain;
    splitPairs(pairs, main_chain);

    main_chain = fordJohnson(main_chain);

    insertWithJacobsthal(main_chain, pairs);

    if (hasOdd) {
        std::vector<unsigned int>::iterator pos =
            std::lower_bound(main_chain.begin(), main_chain.end(), odd);
        main_chain.insert(pos, odd);
    }

    return main_chain;
}

// ==================== MAIN ====================

bool isSorted(const std::vector<unsigned int> &v)
{
    for (size_t i = 1; i < v.size(); ++i)
    {
        if (v[i] < v[i - 1])
            return false;
    }
    return true;
}

void printPreview(const std::vector<unsigned int> &v, size_t limit = 5)
{
    size_t n = v.size();

    for (size_t i = 0; i < n && i < limit; ++i)
        std::cout << v[i] << " ";

    if (n > limit)
        std::cout << "... ";

    if (n > limit)
    {
        size_t start = (n > limit) ? n - limit : 0;
        for (size_t i = start; i < n; ++i)
            std::cout << v[i] << " ";
    }

    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<unsigned int> input;
    parseInput(argc, argv, input);

    std::vector<unsigned int> result = fordJohnson(input);
    if (isSorted(result))
    {
        std::cout << "OK: ";
        printPreview(result);
    }
    else
    {
        std::cout << "KO: ";
        printPreview(result);
    }
    return (0);
}