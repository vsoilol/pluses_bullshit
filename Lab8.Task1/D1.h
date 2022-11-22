#include <iostream>
#include <string>

#include "B1.h"

using namespace std;

class D1 : public B1
{
    std::string name;
public:
    D1()
    {
        this->name = "D1";
    }
    void show()
    {
        cout << this->name << "\n\t|\n\t";
        B1::show();
    }
};
