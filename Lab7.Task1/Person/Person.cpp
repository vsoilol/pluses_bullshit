#include "Person.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

Person::Person()
{
    this->age = 0;
    this->name = "";
}

Person::Person(std::string name, int age)
{
    this->name = name;
    this->age = age;
}


int Person::getAge() const
{
    return this->age;
}

std::string Person::getName() const
{
    return this->name;
}

const Person& Person::operator++()
{
    ++this->age;
    return *this;
}

std::ostream& operator<<(std::ostream& output, const Person* person)
{
    return output << "Person:"
        << "\n\tName: " << person->getName()
        << "\n\tAge: " << person->getAge() << endl;
}
