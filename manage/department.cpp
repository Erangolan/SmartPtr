//Eran Golan 312492903
//Liran Michaelov 204238174
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

