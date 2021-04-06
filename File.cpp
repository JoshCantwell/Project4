#include "File.h"
#include <iostream>
void File::setNumberOfBatches(int numberOfBatches) {

    this->numberOfBatches = numberOfBatches;

}

void File::setNumberOfItems(int numberOfItems){

    this->numberOfItems = numberOfItems;

}

void File::setPercentageOfBadBatches(int percentageOfBadBatches){
    this->percentageOfBadBatches = percentageOfBadBatches;

}

void File::setPercentageOfBadItems(int percentageOfBadItems){
    this->percentageOfBadItems = percentageOfBadItems;

}

void File::setItemsSampled(int itemsSampled){
    this->itemsSampled = itemsSampled;
}

int File::getNumberOfBatches(){
    return this->numberOfBatches;

}

int File::getNumberOfItems(){
    return this->numberOfItems;

}

int File::getPercentageOfBadBatches(){

    return this->percentageOfBadBatches;
}
int File::getPercentageOfBadItems(){
    return this->percentageOfBadItems;
}
int File::getItemsSampled(){
    return this->itemsSampled;
}
