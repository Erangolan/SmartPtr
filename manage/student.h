#ifndef STUDENT_H
#define STUDENT_H
//Eran Golan 
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;
#include <string>
#include <list>

class student
{
    public:
        student(const char* firstName, const char* lastName, const char* id,
                 const char* address, const char* startingStudy, const char* studentDepartment);
        void setFirstName(const char* firstName){this->firstName = firstName;};
        void setLastName(const char* lastName){this->lastName = lastName;};
        void setId(const char* id){this->id = id;};
        string getId()const{return id;};
        string getStartingStudy()const{return startingStudy;};
        void setAddress(const char* address){this->address = address;};
        void setStartingStudy(const char* startingStudy){this->startingStudy = startingStudy;};
        void setStudentDepartment(const char* studentDepartment){this->studentDepartment = studentDepartment;};
        string getStudentDepartment()const{return studentDepartment;};

    private:
        string firstName;
        string lastName;
        string id;
        string address;
        string startingStudy;
        string studentDepartment;
};
ostream& operator<<(ostream& output, student& stud);
//}
#endif // STUDENT_H
