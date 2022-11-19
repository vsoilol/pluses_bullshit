#include "Teacher.h"
#include <iostream>
#include <string>
using namespace std;

Teacher::Teacher(std::string name, int age, std::string position) : Person(name, age)
{
    this->position = position;
}

std::string Teacher::getPosition() const
{
    return this->position;
}

std::ostream& operator<<(std::ostream& output, const Teacher* teacher)
{
    return output << "Teacher:"
        << "\n\tName: " << teacher->getName()
        << "\n\tAge: " << teacher->getAge()
        << "\n\tPosition: " << teacher->getPosition() << endl;
}

const std::string Teacher::getInfo()
{
    string result = "\nName: " + this->getName() + "\nAge: " + std::to_string(this->getAge()) + "\nPosition: " + this
        ->getPosition();

    return result;
}

