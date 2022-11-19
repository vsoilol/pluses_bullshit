#include "Person/Person.h"
#include "Student/Student.h"
#include "Teacher/Teacher.h"
using namespace std;

int main(int argc, char* argv[])
{
    Person* person = new Person("Name", 30);

    std::cout << person << endl;

    person->operator++();

    cout << "Person after increment:\n" << person << endl;

    Student* student = new Student("Student", 20, "PIR-201");

    std::cout << student << endl;

    cout << "Does the student belong to the PIR-201 group: " << (student->checkGroup("PIR-201") ? "Yes" : "No") << endl;

    cout << "Does the student belong to the ASOIR-201 group: " << (student->checkGroup("ASOIR-201") ? "Yes" : "No") << endl;

    Teacher* teacher = new Teacher("TeacherName", 45, "Professor");

    cout << endl << teacher;

    getchar();

    return 0;
}
