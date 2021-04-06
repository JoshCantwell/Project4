#include "Simulation.h"
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
        
    int badBatch = 0;
    std::srand(time(0));
    //Simulation 1
    float flt = fileOne->getPercentageOfBadBatches()/100.0;

    int numberOfBatches = fileOne->getNumberOfBatches()*flt;
    std::cout << numberOfBatches << std::endl;
    std::cout << "Simulation 1:" << std::endl;
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
            bool isBad;    
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

                DataStructureFile << "g" << " " << rand <<std::endl;

            }
        
            DataStructureFile.close();
       }
    
            badBatch++;
    }

    std::cout << "      Total Bad sets = " << numberOfBatches << std::endl;
    
    //Analyzing the Files
    std::cout << "\nAnalyzing Data Sets:" << std::endl;

        
    int batch = 0;    
    for(int i=0; i < fileOne->getNumberOfBatches(); i++) {

        std::string fileName = "ds";
        fileName += std::to_string(i);
        fileName += ".txt";

        SimulationFile.open(fileName);
        int badItems = 0;
        if(!SimulationFile.is_open()){
            std::cout << "Unable to open " << fileName << std::endl;
        } else {
       
                
            
            int checks = 0;
            
            
                
            int j = 1;
            while(!SimulationFile.eof()) {
          
                    
               
                std::string read;
                SimulationFile >> read;
    
                if(j % (fileOne->getNumberOfItems()/fileOne->getItemsSampled()) == 0) {
                
                    checks++;
                    if(read == "b"){
                        
                        badItems++;
                
                    }
                }
                j++;
       
            }
       
            if(badItems > 0) {

                std::cout << "  batch #" << batch << " is bad" << std::endl;
        
    
            }
   
                
            SimulationFile.close();
        }

        batch++;

    }

    //Simulation 2
    std::cout << "Simulation 2:" << std::endl;
    std::cout << "      Number of Batches of items:                     "  << fileTwo->getNumberOfBatches()  << std::endl;
    std::cout << "      Number Of Items in each Batch:                  " << fileTwo->getNumberOfItems() << std::endl;
    std::cout << "      Percentage of batches containing bad items:     " << fileTwo->getPercentageOfBadBatches() << std::endl;
    std::cout << "      Percentage of bad items in a bad batch:         " << fileTwo->getPercentageOfBadItems() << std::endl;
    std::cout << "      Number of items sampled:                        " << fileTwo->getNumberOfItems() << std::endl;
    

    //Simulation 3

    std::cout << "Simulation 3:" << std::endl;
    std::cout << "      Number of Batches of items:                     "  << fileThree->getNumberOfBatches()  << std::endl;
    std::cout << "      Number Of Items in each Batch:                  " << fileThree->getNumberOfItems() << std::endl;
    std::cout << "      Percentage of batches containing bad items:     " << fileThree->getPercentageOfBadBatches() << std::endl;
    std::cout << "      Percentage of bad items in a bad batch:         " << fileThree->getPercentageOfBadItems() << std::endl;
    std::cout << "      Number of items sampled:                        " << fileThree->getNumberOfItems() << std::endl;
    

    //Simulation 4 

    std::cout << "Simulation 4:" << std::endl;
    std::cout << "      Number of Batches of items:                     "  << fileFour->getNumberOfBatches()  << std::endl;
    std::cout << "      Number Of Items in each Batch:                  " << fileFour->getNumberOfItems() << std::endl;
    std::cout << "      Percentage of batches containing bad items:     " << fileFour->getPercentageOfBadBatches() << std::endl;
    std::cout << "      Percentage of bad items in a bad batch:         " << fileFour->getPercentageOfBadItems() << std::endl;
    std::cout << "      Number of items sampled:                        " << fileFour->getNumberOfItems() << std::endl;
    


}
