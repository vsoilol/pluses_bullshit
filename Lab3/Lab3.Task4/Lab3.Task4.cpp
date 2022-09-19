#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string getWordMinLength(string text)
{
    stringstream s(text);
    string word;
    string minWord = "";

    while (s >> word)
    {
        if (minWord.length() == 0)
        {
            minWord = word;
        }

        if (word.length() < minWord.length())
        {
            minWord = word;
        }
    }

    return minWord;
}


int main(int argc, char* argv[])
{
    const int n = 100;
    char text[n];

    cout << "Enter string: ";
    cin.getline(text, n);

    cout << getWordMinLength(text);
    
    return 0;
}
