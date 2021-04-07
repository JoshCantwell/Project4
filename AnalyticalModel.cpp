#include "AnalyticalModel.h"

void AnalyticalModel::AnalyzeFileData(int numberOfBatches, int numberOfItems, int getItemsSampled) {

    int batch = 0;    
    for(int i=0; i < numberOfBatches; i++) {

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
    
                if(j % (numberOfItems/getItemsSampled) == 0) {
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



}
