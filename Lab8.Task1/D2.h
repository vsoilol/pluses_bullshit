#include <iostream>
#include <string>

#include "B2.h"
#include "D1.h"

using namespace std;

class D2 : private D1, private B2
{
    std::string name;
public:
    D2()
    {
        this->name = "D2";
    }
    void show()
    {
        cout << this->name << "\n|\t\\\n";
        B2::show();
        cout << "\t";
        D1::show();
    

    }
};
