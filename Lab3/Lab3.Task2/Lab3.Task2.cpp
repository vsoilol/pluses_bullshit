#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    char c1, c2;
    cout << "Enter C1: ";
    cin >> c1;

    cout << "Enter C2: ";
    cin >> c2;

    bool isC1 = true;
    string text;

    for (; n > 0; n--)
    {
        text += isC1 ? c1 : c2;
        isC1 = !isC1;
    }

    cout << "String: " << text;

    return 0;
}
