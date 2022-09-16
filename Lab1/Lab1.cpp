#include <iostream>
#include <cmath>

using namespace std;

#define M_PI 3.14159265358979323846

double convertDegreeToRadian(double degree);
double calculateFirstExpression(int alphaDegree, int betaDegree);
double calculateSecondExpression(int alphaDegree, int betaDegree);

int main()
{
    int alphaDegree;
    int betaDegree;
    
    cout << "Enter alpha in degree: ";
    cin >> alphaDegree;
    
    cout << "Enter beta in degree: ";
    cin >> betaDegree;
    
    cout << calculateFirstExpression(alphaDegree, betaDegree) << endl;
    cout << calculateSecondExpression(alphaDegree, betaDegree) << endl;

    return 0;
}

double calculateFirstExpression(int alphaDegree, int betaDegree)
{
    double alphaRadian = convertDegreeToRadian(alphaDegree);
    double betaRadian = convertDegreeToRadian(betaDegree);

    double firstExpressionPart = pow(cos(alphaRadian) - cos(betaRadian), 2);
    double secondExpressionPart = pow(sin(alphaRadian) - sin(betaRadian), 2);

    double result = firstExpressionPart - secondExpressionPart;

    return result;
}

double calculateSecondExpression(int alphaDegree, int betaDegree)
{
    double alphaRadian = convertDegreeToRadian(alphaDegree);
    double betaRadian = convertDegreeToRadian(betaDegree);

    double result = -4 * pow(sin((alphaRadian - betaRadian) / 2), 2) * cos(alphaRadian + betaRadian);
    return result;
}

double convertDegreeToRadian(double degree)
{
    return degree * M_PI / 180;
}
