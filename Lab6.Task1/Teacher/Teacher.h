#pragma once
#include "../Person/Person.h"

class Teacher : public Person
{
    std::string position;
public:
    Teacher(std::string name, int age, std::string position);
    std::string getPosition() const;
    friend std::ostream& operator<<(std::ostream& output, const Teacher* teacher);
};
