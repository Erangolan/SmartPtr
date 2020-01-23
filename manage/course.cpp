//Eran Golan 312492903
//Liran Michaelov 204238174
#include "course.h"
#include <string>

course::course(const string& courseNumber) : courseNumber(0)
{
    this->courseNumber.assign(courseNumber);
}

course::course(const char* courseNumber)
{
    this->courseNumber.assign(courseNumber);
}


/*
course::~course()
{
    //dtor
}
*/
