//Eran Golan 

#include <iostream>
using namespace std;
#include <fstream>
#include "college.h"
#include "department.h"
#include "course.h"
#include "student.h"
#include "smartptr.h"

using namespace idllib;

int main(int argc, char *argv[])
{
    if(argc != 4){
        return 0;
        cout << "only 3 arguments";
    }
   ifstream init;
   init.open(argv[1]);

   college bo;
   bo.readFromInitFile(init);


   ifstream simulation;
   simulation.open(argv[2]);
   bo.readFromSimulationFile(simulation);

   ofstream output;
   output.open(argv[3]);

   return 0;
}

