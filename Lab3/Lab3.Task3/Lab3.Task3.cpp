#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int countWords(string str)
{
    stringstream s(str);
    
    string word;
 
    int count = 0;
    while (s >> word)
    {
        count++;
    }

    return count;
}

int main(int argc, char* argv[])
{
    const int n = 100;
    char text[n];

    cout << "Enter string: ";
    cin.getline(text, n);

    //int wordAmount = count(begin(text), end(text), ' ') + 1;
    cout << "Words amount: " << countWords(text);

    return 0;
}
