//Eran Golan 
#ifndef COURSE_H
#define COURSE_H
#include "student.h"
#include "smartptr.h"
#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;
using namespace idllib;

class course
{
    public:
        course(){}
        course(const string& courseNumber);
        course(const char* courseNumber);
        void setNakaz(const char* nakaz){this->nakaz = nakaz;};
        void setCourseName(const char* nakaz){this->courseName = courseName;};
        string getCourseNumber(){return this->courseNumber;};
        void pushStudentsToCourse(SmartPtr<student> newStud){studentsCourse.push_front(newStud);};
        void popStudentFromCourse(SmartPtr<student> oldStud){studentsCourse.remove(oldStud);};

    private:
        string courseNumber;
        string nakaz;
        string courseName;
        list<SmartPtr<student> >studentsCourse;
};

#endif // COURSE_H

