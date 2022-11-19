#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student(std::string name, int age, std::string group) : Person(name, age)
{
    this->group = group;
}

std::string Student::getGroup() const
{
    return this->group;
}

const std::string Student::getInfo()
{
    string result = "\nName: " + this->getName() + "\nAge: " + std::to_string(this->getAge()) + "\nGroup: " + this
        ->getGroup();

    return result;
}

bool Student::checkGroup(std::string group)
{
    return this->group == group;
}

std::ostream& operator<<(std::ostream& output, const Student* student)
{
    return output << "Student:"
        << "\n\tName: " << student->getName()
        << "\n\tAge: " << student->getAge()
        << "\n\tGroup: " << student->getGroup() << endl;
}
