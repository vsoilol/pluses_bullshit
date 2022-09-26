#include "Polynomial.h"

#include <iostream>
#include <cmath>
using namespace std;

Polynomial::Polynomial(int degree): coefficients(nullptr)
{
    this->degree = degree;
}

Polynomial::Polynomial(int* coefficients): degree(0)
{
    this->coefficients = coefficients;
}

Polynomial::Polynomial(int degree, int* coefficients)
{
    this->coefficients = coefficients;
    this->degree = degree;
}

Polynomial::~Polynomial()
{
    delete this->coefficients;
    this->coefficients = NULL;
    cout << "Polynomial deleted" << endl;
}

long Polynomial::calculate(int x)
{
    long result = 0;

    for (int i = 0; i <= degree; i++)
    {
        result += (long)(coefficients[i] * pow(x, i));
    }

    return result;
}

string Polynomial::toString()
{
    string result;

    result += to_string(coefficients[degree]) + "*x^" + to_string(degree);

    for (int i = degree - 1; i >= 0; i--)
    {
        string sign;
        int coefficient;

        if(coefficients[i] == 0)
        {
            continue;
        }

        if (coefficients[i] < 0)
        {
            sign = " - ";
            coefficient = abs(coefficients[i]);
        }
        else
        {
            sign = " + ";
            coefficient = coefficients[i];
        }

        if (i == 0)
        {
            result += sign + to_string(coefficient);
            continue;
        }

        if (i == 1)
        {
            result += sign + to_string(coefficient) + "*x";
            continue;
        }

        result += sign + to_string(coefficient) + "*x^" + to_string(i);
    }

    return result;
}
