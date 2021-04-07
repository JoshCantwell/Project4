#include "Simulation.h"
#include "AnalyticalModel.h"
#include <cstdlib>
#include <ctime>


int Simulation::RandomNumber() {

    
    return  (rand() % 99);
    
}

void Simulation::ReadFiles() {

    int numberOfBatches;
    int numberOfItems;
    int percentageOfBadBatches;
    int percentageOfBadItems;
    int itemsSampled;

    SimulationFile.open("t1.txt");
    if(!SimulationFile.is_open()){
        std::cout << "Unable to open t1.txt" << std::endl;
    } else {

       while(!SimulationFile.eof()) {

           SimulationFile >> numberOfBatches;
           fileOne->setNumberOfBatches(numberOfBatches);
           SimulationFile >> numberOfItems;
           fileOne->setNumberOfItems(numberOfItems);
           SimulationFile >> percentageOfBadBatches;
           fileOne->setPercentageOfBadBatches(percentageOfBadBatches);
           SimulationFile >> percentageOfBadItems;
           fileOne->setPercentageOfBadItems(percentageOfBadItems);
           SimulationFile >> itemsSampled;
           fileOne->setItemsSampled(itemsSampled);
       }

    }
    SimulationFile.close();
    SimulationFile.open("t2.txt");
    if(!SimulationFile.is_open()){
        std::cout << "Unable to open t2.txt" << std::endl;
    } else {

       while(!SimulationFile.eof()) {

           SimulationFile >> numberOfBatches;
           fileTwo->setNumberOfBatches(numberOfBatches);
           SimulationFile >> numberOfItems;
           fileTwo->setNumberOfItems(numberOfItems);
           SimulationFile >> percentageOfBadBatches;
           fileTwo->setPercentageOfBadBatches(percentageOfBadBatches);
           SimulationFile >> percentageOfBadItems;
           fileTwo->setPercentageOfBadItems(percentageOfBadItems);
           SimulationFile >> itemsSampled;
           fileTwo->setItemsSampled(itemsSampled);
       }

    }
    SimulationFile.close();
    SimulationFile.open("t3.txt");
    if(!SimulationFile.is_open()){
        std::cout << "Unable to open t3.txt" << std::endl;
    } else {

       while(!SimulationFile.eof()) {

           SimulationFile >> numberOfBatches;
           fileThree->setNumberOfBatches(numberOfBatches);
           SimulationFile >> numberOfItems;
           fileThree->setNumberOfItems(numberOfItems);
           SimulationFile >> percentageOfBadBatches;
           fileThree->setPercentageOfBadBatches(percentageOfBadBatches);
           SimulationFile >> percentageOfBadItems;
           fileThree->setPercentageOfBadItems(percentageOfBadItems);
           SimulationFile >> itemsSampled;
           fileThree->setItemsSampled(itemsSampled);
       }

    }
    SimulationFile.close();
    SimulationFile.open("t4.txt");
    if(!SimulationFile.is_open()){
        std::cout << "Unable to open t4.txt" << std::endl;
    } else {

       while(!SimulationFile.eof()) {

           SimulationFile >> numberOfBatches;
           fileFour->setNumberOfBatches(numberOfBatches);
           SimulationFile >> numberOfItems;
           fileFour->setNumberOfItems(numberOfItems);
           SimulationFile >> percentageOfBadBatches;
           fileFour->setPercentageOfBadBatches(percentageOfBadBatches);
           SimulationFile >> percentageOfBadItems;
           fileFour->setPercentageOfBadItems(percentageOfBadItems);
           SimulationFile >> itemsSampled;
           fileFour->setItemsSampled(itemsSampled);
       }

    }

    SimulationFile.close();

}

void Simulation::RunSimulation() {
        
    //Simulation 1
    int badBatch = 0;
    std::srand(time(0));
    float flt = fileOne->getPercentageOfBadBatches()/100.0;

    int numberOfBatches = fileOne->getNumberOfBatches()*flt;
    std::cout << "\n\nSimulation 1:" << std::endl;
    std::cout << "      Number of Batches of items:                     "  << fileOne->getNumberOfBatches()  << std::endl;
    std::cout << "      Number Of Items in each Batch:                  " << fileOne->getNumberOfItems() << std::endl;
    std::cout << "      Percentage of batches containing bad items:     " << fileOne->getPercentageOfBadBatches() << std::endl;
    std::cout << "      Percentage of bad items in a bad batch:         " << fileOne->getPercentageOfBadItems() << std::endl;
    std::cout << "      Number of items sampled:                        " << fileOne->getNumberOfItems() << std::endl;
   
    //Creating the Files
    std::cout << "\nGenerating data set:\n" << std::endl;
    for(int i=0; i < fileOne->getNumberOfBatches();i++) {

        if(badBatch % (fileOne->getNumberOfBatches()/numberOfBatches) == 0){
                    
            std::cout << "      Create bad set Batch # " << badBatch << " ";
            std::string fileName = "ds" + std::to_string(i) + ".txt";
            int bad = 0;
            float badPercentage = 0; 
            DataStructureFile.open(fileName);
            for(int j = 0; j < fileOne->getNumberOfItems(); j++) {
                int rand = RandomNumber();
               
                    if(rand >= fileOne->getPercentageOfBadItems() - 1) {
                        DataStructureFile << "g"   <<std::endl;
                    } else {
                        DataStructureFile << "b" << std::endl;
                        bad++;
                    }
            }
 
            badPercentage = bad;
            badPercentage = badPercentage/fileOne->getNumberOfItems();
            std::cout << "totBad = " << bad << " total = " << fileOne->getNumberOfItems() << " badpct = " << fileOne->getPercentageOfBadItems() << std::endl;
        
            DataStructureFile.close();
                
        } else {

            std::string fileName = "ds" + std::to_string(i) + ".txt";
            DataStructureFile.open(fileName);
          
            for(int j = 0; j < fileOne->getNumberOfItems(); j++) {

                DataStructureFile << "g"  <<std::endl;
            }
        
            DataStructureFile.close();
       }
            badBatch++;
    }

    std::cout << "      Total Bad sets = " << numberOfBatches << std::endl;
    //Analyzing the Files
    std::cout << "\nAnalyzing Data Sets:" << std::endl;
        
    AnalyticalModel *am;
    am = new AnalyticalModel();
    am->AnalyzeFileData(fileOne->getNumberOfBatches(), fileOne->getNumberOfItems(), fileOne->getItemsSampled());


    //Simulation 2
    badBatch = 0;
    std::srand(time(0));
    flt = fileTwo->getPercentageOfBadBatches()/100.0;

    numberOfBatches = fileTwo->getNumberOfBatches()*flt;
    std::cout << "\n\nSimulation 2:" << std::endl;
    std::cout << "      Number of Batches of items:                     "  << fileTwo->getNumberOfBatches()  << std::endl;
    std::cout << "      Number Of Items in each Batch:                  " << fileTwo->getNumberOfItems() << std::endl;
    std::cout << "      Percentage of batches containing bad items:     " << fileTwo->getPercentageOfBadBatches() << std::endl;
    std::cout << "      Percentage of bad items in a bad batch:         " << fileTwo->getPercentageOfBadItems() << std::endl;
    std::cout << "      Number of items sampled:                        " << fileTwo->getNumberOfItems() << std::endl;
   
    //Creating the Files
    std::cout << "\nGenerating data set:\n" << std::endl;
    for(int i=0; i < fileTwo->getNumberOfBatches();i++) {

        if(badBatch % (fileTwo->getNumberOfBatches()/numberOfBatches) == 0){
                    
            std::cout << "      Create bad set Batch # " << badBatch << " ";
            std::string fileName = "ds" + std::to_string(i) + ".txt";
            int bad = 0;
            float badPercentage = 0; 
            DataStructureFile.open(fileName);
            for(int j = 0; j < fileTwo->getNumberOfItems(); j++) {
                int rand = RandomNumber();
               
                    if(rand >= fileTwo->getPercentageOfBadItems() - 1) {
                        DataStructureFile << "g"   <<std::endl;
                    } else {
                        DataStructureFile << "b" << std::endl;
                        bad++;
                    }
            }
 
            badPercentage = bad;
            badPercentage = badPercentage/fileTwo->getNumberOfItems();
            std::cout << "totBad = " << bad << " total = " << fileTwo->getNumberOfItems() << " badpct = " << fileTwo->getPercentageOfBadItems() << std::endl;
        
            DataStructureFile.close();
                
        } else {

            std::string fileName = "ds" + std::to_string(i) + ".txt";
            DataStructureFile.open(fileName);
          
            for(int j = 0; j < fileTwo->getNumberOfItems(); j++) {

                DataStructureFile << "g" <<std::endl;
            }
        
            DataStructureFile.close();
       }
            badBatch++;
    }

    std::cout << "      Total Bad sets = " << numberOfBatches << std::endl;
    
    //Analyzing the Files
    std::cout << "\nAnalyzing Data Sets:" << std::endl;
        
   
    am->AnalyzeFileData(fileTwo->getNumberOfBatches(), fileOne->getNumberOfItems(), fileOne->getItemsSampled());

    //Simulation 3
    badBatch = 0;
    std::srand(time(0));
    flt = fileThree->getPercentageOfBadBatches()/100.0;

    numberOfBatches = fileThree->getNumberOfBatches()*flt;
    std::cout << "\n\nSimulation 3:" << std::endl;
    std::cout << "      Number of Batches of items:                     "  << fileThree->getNumberOfBatches()  << std::endl;
    std::cout << "      Number Of Items in each Batch:                  " << fileThree->getNumberOfItems() << std::endl;
    std::cout << "      Percentage of batches containing bad items:     " << fileThree->getPercentageOfBadBatches() << std::endl;
    std::cout << "      Percentage of bad items in a bad batch:         " << fileThree->getPercentageOfBadItems() << std::endl;
    std::cout << "      Number of items sampled:                        " << fileThree->getNumberOfItems() << std::endl;
   
    //Creating the Files
    std::cout << "\nGenerating data set:\n" << std::endl;
    for(int i=0; i < fileThree->getNumberOfBatches();i++) {

        if(badBatch % (fileThree->getNumberOfBatches()/numberOfBatches) == 0){
                    
            std::cout << "      Create bad set Batch # " << badBatch << " ";
            std::string fileName = "ds" + std::to_string(i) + ".txt";
            int bad = 0;
            float badPercentage = 0; 
            DataStructureFile.open(fileName);
            for(int j = 0; j < fileThree->getNumberOfItems(); j++) {
                int rand = RandomNumber();
               
                    if(rand >= fileThree->getPercentageOfBadItems() - 1) {
                        DataStructureFile << "g"   <<std::endl;
                    } else {
                        DataStructureFile << "b" << std::endl;
                        bad++;
                    }
            }
 
            badPercentage = bad;
            badPercentage = badPercentage/fileThree->getNumberOfItems();
            std::cout << "totBad = " << bad << " total = " << fileThree->getNumberOfItems() << " badpct = " << fileThree->getPercentageOfBadItems() << std::endl;
        
            DataStructureFile.close();
                
        } else {

            std::string fileName = "ds" + std::to_string(i) + ".txt";
            DataStructureFile.open(fileName);
          
            for(int j = 0; j < fileThree->getNumberOfItems(); j++) {

                DataStructureFile << "g" <<std::endl;
            }
        
            DataStructureFile.close();
       }
            badBatch++;
    }

    std::cout << "      Total Bad sets = " << numberOfBatches << std::endl;
    
    //Analyzing the Files
    std::cout << "\nAnalyzing Data Sets:" << std::endl;
        
   
    am->AnalyzeFileData(fileOne->getNumberOfBatches(), fileOne->getNumberOfItems(), fileOne->getItemsSampled());
    //Simulation 4
    badBatch = 0;
    std::srand(time(0));
    flt = fileFour->getPercentageOfBadBatches()/100.0;

    numberOfBatches = fileFour->getNumberOfBatches()*flt;
    std::cout << "\n\nSimulation 4:" << std::endl;
    std::cout << "      Number of Batches of items:                     "  << fileFour->getNumberOfBatches()  << std::endl;
    std::cout << "      Number Of Items in each Batch:                  " << fileFour->getNumberOfItems() << std::endl;
    std::cout << "      Percentage of batches containing bad items:     " << fileFour->getPercentageOfBadBatches() << std::endl;
    std::cout << "      Percentage of bad items in a bad batch:         " << fileFour->getPercentageOfBadItems() << std::endl;
    std::cout << "      Number of items sampled:                        " << fileFour->getNumberOfItems() << std::endl;
   
    //Creating the Files
    std::cout << "\nGenerating data set:\n" << std::endl;
    for(int i=0; i < fileFour->getNumberOfBatches();i++) {

        if(badBatch % (fileFour->getNumberOfBatches()/numberOfBatches) == 0){
                    
            std::cout << "      Create bad set Batch # " << badBatch << " ";
            std::string fileName = "ds" + std::to_string(i) + ".txt";
            int bad = 0;
            float badPercentage = 0; 
            DataStructureFile.open(fileName);
            for(int j = 0; j < fileFour->getNumberOfItems(); j++) {
                int rand = RandomNumber();
               
                    if(rand >= fileFour->getPercentageOfBadItems() - 1) {
                        DataStructureFile << "g"   <<std::endl;
                    } else {
                        DataStructureFile << "b" << std::endl;
                        bad++;
                    }
            }
 
            badPercentage = bad;
            badPercentage = badPercentage/fileFour->getNumberOfItems();
            std::cout << "totBad = " << bad << " total = " << fileFour->getNumberOfItems() << " badpct = " << fileFour->getPercentageOfBadItems() << std::endl;
        
            DataStructureFile.close();
                
        } else {

            std::string fileName = "ds" + std::to_string(i) + ".txt";
            DataStructureFile.open(fileName);
          
            for(int j = 0; j < fileFour->getNumberOfItems(); j++) {

                DataStructureFile << "g"  <<std::endl;
            }
        
            DataStructureFile.close();
       }
            badBatch++;
    }

    std::cout << "      Total Bad sets = " << numberOfBatches << std::endl;
    
    //Analyzing the Files
  
    std::cout << "\nAnalyze Data Sets:" << std::endl;
    am->AnalyzeFileData(fileOne->getNumberOfBatches(), fileOne->getNumberOfItems(), fileOne->getItemsSampled());
  
    delete am;

}
