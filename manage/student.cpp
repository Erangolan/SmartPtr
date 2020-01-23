//Eran Golan 312492903
//Liran Michaelov 204238174
#include "student.h"

student::student(const char* firstName, const char* lastName, const char* id,
                 const char* address,
                  const char* startingStudy,
                  const char* studentDepartment)
{
    setFirstName(firstName);
    setLastName(lastName);
    setId(id);
    setAddress(address);
    setStartingStudy(startingStudy);
    setStudentDepartment(studentDepartment);
}

ostream& operator<<(ostream& output, student& stud)
{
    output << stud.getId() << endl;
    return output;
}



