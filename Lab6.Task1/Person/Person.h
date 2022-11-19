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
    const Person& operator ++();
    friend std::ostream& operator<<(std::ostream& output, const Person* matrix);
};
