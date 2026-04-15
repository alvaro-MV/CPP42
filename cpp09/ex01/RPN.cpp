#include "RPN.hpp"

int parseInt(const std::string& str)
{
    char* end;
    long val = std::strtol(str.c_str(), &end, 10);

    // 1. No se ha convertido nada
    if (end == str.c_str())
        throw std::runtime_error("Error");

    // 2. Hay basura después del número
    while (*end)
    {
        if (!std::isspace(*end))
            throw std::runtime_error("Error");
        end++;
    }

    // 3. Overflow / underflow
    if (val > std::numeric_limits<int>::max() ||
        val < std::numeric_limits<int>::min())
        throw std::runtime_error("Error");

    return static_cast<int>(val);
}

int apply_op(int a, int b, const std::string& op)
{
    if (op == "+")
        return a + b;
    else if (op == "-")
        return a - b;
    else if (op == "*")
        return a * b;
    else if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("Error");
        return a / b; // división entera
    }
    else
        throw std::runtime_error("Error");
}