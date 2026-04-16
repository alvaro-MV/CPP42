#include "Pmerge.hpp"
#include <algorithm>

// ==================== JACOBSTHAL ====================

static std::vector<unsigned int> generateOrder(size_t n)
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

    while (curr <= n)
    {
        jacob.push_back(curr);
        unsigned int next = curr + 2 * prev;
        prev = curr;
        curr = next;
    }

    unsigned int last = 1;

    for (size_t i = 1; i < jacob.size(); ++i)
    {
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

// ==================== VECTOR ====================

std::vector<unsigned int> fordJohnsonVector(std::vector<unsigned int> input)
{
    if (input.size() <= 1)
        return input;

    bool hasOdd = (input.size() % 2 == 1);
    unsigned int odd = 0;
    if (hasOdd)
        odd = input.back();

    std::vector< std::pair<unsigned int, unsigned int> > pairs;

    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        unsigned int x = input[i];
        unsigned int y = input[i + 1];

        if (x > y)
            pairs.push_back(std::make_pair(x, y));
        else
            pairs.push_back(std::make_pair(y, x));
    }

    std::vector<unsigned int> main_chain;
    for (size_t i = 0; i < pairs.size(); ++i)
        main_chain.push_back(pairs[i].first);

    main_chain = fordJohnsonVector(main_chain);

    // Insert b1
    if (!pairs.empty())
    {
        unsigned int b0 = pairs[0].second;
        unsigned int a0 = pairs[0].first;

        std::vector<unsigned int>::iterator it =
            std::find(main_chain.begin(), main_chain.end(), a0);

        if (it != main_chain.end())
        {
            std::vector<unsigned int>::iterator pos =
                std::lower_bound(main_chain.begin(), it, b0);
            main_chain.insert(pos, b0);
        }
    }

    std::vector<unsigned int> order = generateOrder(pairs.size());

    for (size_t i = 1; i < order.size(); ++i)
    {
        size_t idx = order[i] - 1;
        if (idx >= pairs.size())
            continue;

        unsigned int b = pairs[idx].second;
        unsigned int a = pairs[idx].first;

        std::vector<unsigned int>::iterator it =
            std::find(main_chain.begin(), main_chain.end(), a);

        if (it != main_chain.end())
        {
            std::vector<unsigned int>::iterator pos =
                std::lower_bound(main_chain.begin(), it, b);
            main_chain.insert(pos, b);
        }
    }

    if (hasOdd)
    {
        std::vector<unsigned int>::iterator pos =
            std::lower_bound(main_chain.begin(), main_chain.end(), odd);
        main_chain.insert(pos, odd);
    }

    return main_chain;
}

// ==================== DEQUE ====================

std::deque<unsigned int> fordJohnsonDeque(std::deque<unsigned int> input)
{
    if (input.size() <= 1)
        return input;

    bool hasOdd = (input.size() % 2 == 1);
    unsigned int odd = 0;
    if (hasOdd)
        odd = input.back();

    std::vector< std::pair<unsigned int, unsigned int> > pairs;

    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        unsigned int x = input[i];
        unsigned int y = input[i + 1];

        if (x > y)
            pairs.push_back(std::make_pair(x, y));
        else
            pairs.push_back(std::make_pair(y, x));
    }

    std::deque<unsigned int> main_chain;
    for (size_t i = 0; i < pairs.size(); ++i)
        main_chain.push_back(pairs[i].first);

    main_chain = fordJohnsonDeque(main_chain);

    if (!pairs.empty())
    {
        unsigned int b0 = pairs[0].second;
        unsigned int a0 = pairs[0].first;

        std::deque<unsigned int>::iterator it =
            std::find(main_chain.begin(), main_chain.end(), a0);

        if (it != main_chain.end())
        {
            std::deque<unsigned int>::iterator pos =
                std::lower_bound(main_chain.begin(), it, b0);
            main_chain.insert(pos, b0);
        }
    }

    std::vector<unsigned int> order = generateOrder(pairs.size());

    for (size_t i = 1; i < order.size(); ++i)
    {
        size_t idx = order[i] - 1;
        if (idx >= pairs.size())
            continue;

        unsigned int b = pairs[idx].second;
        unsigned int a = pairs[idx].first;

        std::deque<unsigned int>::iterator it =
            std::find(main_chain.begin(), main_chain.end(), a);

        if (it != main_chain.end())
        {
            std::deque<unsigned int>::iterator pos =
                std::lower_bound(main_chain.begin(), it, b);
            main_chain.insert(pos, b);
        }
    }

    if (hasOdd)
    {
        std::deque<unsigned int>::iterator pos =
            std::lower_bound(main_chain.begin(), main_chain.end(), odd);
        main_chain.insert(pos, odd);
    }

    return main_chain;
}