#include "AnalyticalModel.h"
#include <iomanip>
#include <math.h>

void AnalyticalModel::AnalyzeFileData(int amountOfBadBatches, int numberOfBatches, int numberOfItems, int getItemsSampled, int getPercentageOfBadBatches, int getPercentageOfBadItems) {

    int bBatches = 0;
    int batch = 0;   
    float batchesDetected;
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
                bBatches += 1;
                std::cout << "  batch #" << batch << " is bad" << std::endl;
            }
            SimulationFile.close();
        }
        batch++;

   
    }

    float base = 1 - (getPercentageOfBadItems/ 100.0);

    float result = pow(base, getItemsSampled);

        
    batchesDetected = (bBatches);

    batchesDetected = batchesDetected/amountOfBadBatches;
    std::cout << "Base: " << std::fixed << std::setprecision(6) <<  base << " exponent = " << getItemsSampled <<  std::endl;
    std::cout << "P(failure to detect bad batch) = " << std::fixed << std::setprecision(6) << result << std::endl;

    std::cout << "Percentage of bad batches actually detected = " << batchesDetected << std::endl;
    

}
