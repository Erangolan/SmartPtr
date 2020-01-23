//Eran Golan 
#include "college.h"
#include "department.h"
#include "course.h"
#include <string.h>
#include<iostream>
#include<iterator>
using namespace std;
#include <fstream>
#include <list>
#include "smartptr.h"

void college::readFromInitFile(ifstream& init)
{
    if(!init.is_open())
    {
        cout << "the file is closed";
        return;
    }

    string buffer;
    const char s[2] = ",";
    const char s1[2] = ":";
    while(!getline(init, buffer).eof()  && buffer[0] == '#')
        continue;
    char *temp = new char[buffer.length() + 1];      //casting from string to char*
    strcpy(temp, buffer.c_str());
    char* token = strtok(temp, s);
    setCollegeName(token);


    while(!getline(init, buffer).eof()  && buffer[0] == '#')
        continue;
    temp = token = new char[buffer.length() + 1];      //casting from string to char*
    strcpy(temp, buffer.c_str());
    token = strtok(temp, s1);
    token = strtok(NULL, s);
    while(token != NULL)
    {
        collegesDepartment.push_front(SmartPtr<department>(new department(token)));
        token = strtok(NULL,s);
    }


    while(!getline(init, buffer).eof()  && buffer[0] == '#')
        continue;
    temp = token = new char[buffer.length() + 1];       //casting from string to char*
    strcpy(temp, buffer.c_str());
    token = strtok(temp, s1);
    token = strtok(NULL, s);
    while(token != NULL)
    {
        collegesCourses.push_front(SmartPtr<course>(new course(token)));
        token = strtok(NULL,s);
    }

    while(!getline(init, buffer).eof()  && buffer[0] == '#')
        continue;

    temp = token = new char[buffer.length() + 1];       //casting from string to char*
    strcpy(temp, buffer.c_str());
    token = strtok(temp, s1);
    token = strtok(NULL, s);                  //department

    list<SmartPtr<course>>::iterator ptrCourse;
    for(ptrCourse = collegesCourses.begin(); ptrCourse != collegesCourses.end(); ptrCourse++)
    {
        char* token1 = strtok(NULL, s);
        if(ptrCourse->GetPtr()->getCourseNumber() == token1);
            break;
    }
    char* token1 = strtok(NULL, s);
    ptrCourse->GetPtr()->setNakaz(token1);
    token1 = strtok(NULL,s);
    ptrCourse->GetPtr()->setCourseName(token1);

    list<SmartPtr<department>>::iterator ptrDepartment;
    for(ptrDepartment = collegesDepartment.begin(); ptrDepartment != collegesDepartment.end(); ptrDepartment++)
    {
        char* token1 = strtok(NULL, s);
        if(ptrDepartment->GetPtr()->getDepartmentName() == token);
            break;
    }
    ptrDepartment->GetPtr()->pushToDepartmentCourses(*ptrCourse);
}


void college::readFromSimulationFile(ifstream &simulation)
{
    if(!simulation.is_open())
    {
        cout << "the file is closed";
        return;
    }

    string buffer;
    while(!getline(simulation, buffer).eof())
    {
        if(buffer[0] == '#')
            continue;

        char *token, *temp;
        const char s[2] = ",";
        int userChoise = (int)buffer[0] - 48;

        if(userChoise == 1)
        {
            temp = token = new char[buffer.length() + 1];      //casting from string to char*
            strcpy(temp, buffer.c_str());
            token = strtok(temp, s);
            char* token1 = strtok(NULL, s);
            char* token2 = strtok(NULL, s);
            char* token3 = strtok(NULL, s);
            char* token4 = strtok(NULL, s);
            char* token5 = strtok(NULL, s);
            char* token6 = strtok(NULL, s);
            collegeStudents.push_front(SmartPtr<student>(new student(token1, token2, token3, token4, token5, token6)));
            continue;
        }
        if(userChoise == 2)
        {
            temp = token = new char[buffer.length() + 1];      //casting from string to char*
            strcpy(temp, buffer.c_str());
            token = strtok(temp, s);
            token = strtok(NULL, s);
            char* token1 = strtok(NULL, s);
            list<SmartPtr<student>>::iterator ptrStud;
            for(ptrStud = collegeStudents.begin(); ptrStud != collegeStudents.end(); ptrStud++)
            {
                if(ptrStud->GetPtr()->getId() == token);
                    break;
            }

            list<SmartPtr<course>>::iterator ptrCourse;
            for(ptrCourse = collegesCourses.begin(); ptrCourse != collegesCourses.end(); ptrCourse++)
            {
                if(ptrCourse->GetPtr()->getCourseNumber() == token1)
                    break;
            }
            ptrCourse->GetPtr()->pushStudentsToCourse(*ptrStud);
            continue;
        }
        if(userChoise == 3)
        {
            temp = token = new char[buffer.length() + 1];      //casting from string to char*
            strcpy(temp, buffer.c_str());
            token = strtok(temp, s);
            token = strtok(NULL, s);
            char* token1 = strtok(NULL, s);
            list<SmartPtr<student>>::iterator ptrStud;
            for(ptrStud = collegeStudents.begin(); ptrStud != collegeStudents.end(); ptrStud++)
            {
                if(ptrStud->GetPtr()->getId() == token);
                    break;
            }
            list<SmartPtr<course>>::iterator ptrCourse;
            for(ptrCourse = collegesCourses.begin(); ptrCourse != collegesCourses.end(); ptrCourse++)
            {
                if(ptrCourse->GetPtr()->getCourseNumber() == token1)
                    break;
            }
            ptrCourse->GetPtr()->popStudentFromCourse(*ptrStud);
            continue;
        }
        if(userChoise == 4)
        {
            temp = token = new char[buffer.length() + 1];      //casting from string to char*
            strcpy(temp, buffer.c_str());
            token = strtok(temp, s);
            token = strtok(NULL, s);
            //char* token1 = strtok(NULL, s);
            list<SmartPtr<student>>::iterator ptrStud;
            for(ptrStud = collegeStudents.begin(); ptrStud != collegeStudents.end(); ptrStud++)
            {
                if(ptrStud->GetPtr()->getId() == token)
                    break;
            }
            collegeStudents.remove(*ptrStud);
        }
        if(userChoise == 5)
        {
            temp = token = new char[buffer.length() + 1];      //casting from string to char*
            strcpy(temp, buffer.c_str());
            token = strtok(temp, s);
            token = strtok(NULL, s);
            char* token1 = strtok(NULL, s);
            list<SmartPtr<student>>::iterator ptrStud;
            for(ptrStud = collegeStudents.begin(); ptrStud != collegeStudents.end(); ptrStud++)
            {
                if(ptrStud->GetPtr()->getStudentDepartment() == token
                && ptrStud->GetPtr()->getStartingStudy() == token1)
                    cout << (*ptrStud->GetPtr());
            }
        }
    }
}


/*ostream& operator<<(ostream& os, college& c)
{
    list<SmartPtr<student>>::iterator ptrStud;
    for(ptrStud = c.getCollegeStudents().begin(); ptrStud != c.getCollegeStudents().end(); ptrStud++)
    {
        os << ptrStud->GetPtr()->getId() << endl;
    }
    return os;
}*/



