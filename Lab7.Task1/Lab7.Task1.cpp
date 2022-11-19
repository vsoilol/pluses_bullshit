#include "Person/Person.h"
#include "Student/Student.h"
#include "Teacher/Teacher.h"
using namespace std;

int main(int argc, char* argv[])
{
    Student* student = new Student("Student", 20, "PIR-201");

    Teacher* teacher = new Teacher("TeacherName", 45, "Professor");

    Person* persons[] = {teacher, student, new Teacher("TeacherName2", 30, "Professor2")};

    for (auto person : persons)
    {
        cout << person->getInfo() << endl;
    }

    getchar();
    return 0;
}
