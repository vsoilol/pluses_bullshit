#pragma once
#include "../Person/Person.h"
#include <iostream>

class Student : public Person
{
    std::string group;
public:
    Student(std::string name, int age, std::string group);
    bool checkGroup(std::string group);
    std::string getGroup() const;
    friend std::ostream& operator<<(std::ostream& output, const Student* student);
};
