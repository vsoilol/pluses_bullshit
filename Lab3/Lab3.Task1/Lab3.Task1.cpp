#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
    string text;
    cout << "Enter string: ";
    getline(cin, text);

    char letterReplace, newLetter;

    cout << "Enter the letter you want to replace: ";
    cin >> letterReplace;

    cout << "Enter new letter: ";
    cin >> newLetter;

    replace( text.begin(), text.end(), letterReplace, newLetter);
    cout << "\nNew string: " << text;

    return 0;
}
