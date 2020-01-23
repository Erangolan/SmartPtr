//Eran Golan 

#include "department.h"
#include <string>

department::department(const string& departmentName) : departmentName(0)
{
    this->departmentName.assign(departmentName);
}

department::department(const char* departmentName)
{
    this->departmentName.assign(departmentName);
}

