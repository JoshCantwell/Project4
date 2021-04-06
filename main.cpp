/***************************************************************
  Student Name: Josh Cantwell
  File Name: main.cpp
  Assignment number 4

***************************************************************/

#include <iostream>
#include "Simulation.h"

int main() {


    Simulation *sim = new Simulation();

    sim->ReadFiles();
    sim->RunSimulation();


}
