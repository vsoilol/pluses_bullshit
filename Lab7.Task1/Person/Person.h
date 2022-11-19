#pragma once
#include <iostream>

class Person
{
    std::string name;
    int age;
public:
    Person();
    Person(std::string name, int age);
    std::string getName() const;
    int getAge() const;
    virtual const std::string getInfo() = 0;
    const Person& operator ++();
    friend std::ostream& operator<<(std::ostream& output, const Person* matrix);
};
