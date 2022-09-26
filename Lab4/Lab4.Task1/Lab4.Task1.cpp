#include <iostream>
#include <sstream>
#include <string>
#include "Polynomial.h"
using namespace std;

string arrayToString(int array[], int size)
{
    string result;

    for (int i = 0; i < size; i++)
    {
        result += to_string(array[i]);

        if (i != size - 1)
        {
            result += ", ";
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    string values;
    int degree;

    cout << "Enter degree: ";
    cin >> degree;

    int* coefficients = new int[degree + 1];
    cout << "Enter coefficients: ";

    int* lastElement = coefficients + degree + 1;
    for(int* element = coefficients; element < lastElement; element++)
    {
        cin >> *element;
    }

    Polynomial* polynomial = new Polynomial(degree, coefficients);

    int x;
    
    cout << "Enter x: ";
    cin >> x;

    cout << endl << polynomial->toString() << " = " << polynomial->calculate(x) << endl << endl;

    delete polynomial;
    
    return 0;
}
