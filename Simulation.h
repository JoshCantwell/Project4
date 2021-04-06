/***************************************************************
  Student Name: Josh Cantwell
  File Name: Simulation.h
  Assignment number 4

  This file will be responsible for reading the simulation description and getting the settings
  via file 1, file 2,... file n.
***************************************************************/

#ifndef _simulation_h_
#define _simulation_h_

#include <fstream>
#include <iostream>
#include "File.h"

class Simulation  {

    public:

        Simulation() {

            fileOne = new File();
            fileTwo = new File();
            fileThree = new File();
            fileFour = new File();
        }

        void ReadFiles(); 
        void RunSimulation();

        int RandomNumber();
    private:

        std::ofstream DataStructureFile;
        std::ifstream SimulationFile;

        File* fileOne;
        File* fileTwo;
        File* fileThree;
        File* fileFour;
};


#endif
