#include <iostream>
#include <string>

#include "D2.h"

using namespace std;

class D3 : public D2
{
    std::string name;
public:
    D3()
    {
        this->name = "D3";
    }

    void show()
    {
        cout << this->name << "\n|\n";
        D2::show();
    }
};
