/***************************************************************
  Student Name: Josh Cantwell
  File Name: Analytical.h
  Assignment number 4

 This file is responsible for getting the analytics of the files in this program
 and return them back to the simulation class.
***************************************************************/

#ifndef _analyticalmodel_h_
#define _analyticalmodel_h_

#include <fstream>
#include <iostream>
#include <string>

class AnalyticalModel {


    public:

        AnalyticalModel() {


        }

       void AnalyzeFileData(int numberOfBatches, int numberOfItems, int getItemsSampled);

    private:

       std::ifstream SimulationFile;



};

#endif
