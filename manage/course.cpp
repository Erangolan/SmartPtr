//Eran Golan 
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
