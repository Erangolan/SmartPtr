//Eran Golan 
#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <stdio.h>
#include <iostream>
#include <list>
#include<iterator>
#include "course.h"
#include "smartptr.h"
using namespace std;
using namespace idllib;
class department
{
    public:
        department(){}
        department(const string& departmentName);
        department(const char* departmentName);
        void setDepatmentName(string departmentName){this->departmentName = departmentName;};
        string getDepartmentName(){return this->departmentName;};
        void pushToDepartmentCourses(SmartPtr<course> newCourse){departmentsCourses.push_front(newCourse);};
        void popStudentFromDepartment(SmartPtr<student> oldStud){departmentStudents.remove(oldStud);};
        list<SmartPtr<course>>& getDepartmentCourses(){return this->departmentsCourses;};
        list<SmartPtr<student>>& getDepartmentStudents(){return this->departmentStudents;};

    private:
        string departmentName;
        list<SmartPtr<course> >departmentsCourses;
        list<SmartPtr<student> > departmentStudents;
};

#endif // DEPARTMENT_H
