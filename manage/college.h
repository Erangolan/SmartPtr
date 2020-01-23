//Eran Golan 312492903
//Liran Michaelov 204238174
#ifndef COLLEGE_H
#define COLLEGE_H
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "department.h"
#include "course.h"
#include "student.h"
#include "smartptr.h"
#include <list>
using namespace idllib;
using namespace std;

class college
{
    public:
        void setCollegeName(string collegeName){this->collegeName = collegeName;};
        string getCollegeName(){return this->collegeName;};
        void readFromInitFile(ifstream& init);
        void readFromSimulationFile(ifstream& simulation);
        list<SmartPtr<course>>& getCollegeCourses(){return this->collegesCourses;};
        list<SmartPtr<student>>& getCollegeStudents(){return this->collegeStudents;};

    private:
       string collegeName;
       list<SmartPtr<department> >collegesDepartment;
       list<SmartPtr<course> >collegesCourses;
       list<SmartPtr<student> >collegeStudents;
};
//ostream& operator<<(ostream& os, college& c);
#endif // COLLEGE_H
