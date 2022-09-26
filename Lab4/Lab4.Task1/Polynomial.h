#pragma once
#include <string>

class Polynomial
{
    int degree;
    int* coefficients;
public:
    Polynomial(int degree);
    Polynomial(int* coefficients);
    Polynomial(int degree, int* coefficients);
    ~Polynomial();
    long calculate(int x);
    std::string toString();
};
