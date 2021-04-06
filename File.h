/***************************************************************
  Student Name: Josh Cantwell
  File Name: File.h
  Assignment number 4

  reason for this file is to store the individual settings of the test files
  in simulation.h.
***************************************************************/

#ifndef _file_h_
#define _file_h_

class File {


    public:

        void setNumberOfBatches(int numberOfBatches);
        void setNumberOfItems(int numberOfItems);
        void setPercentageOfBadBatches(int percentageOfBadBatches);
        void setPercentageOfBadItems(int percentageOfBadItems);
        void setItemsSampled(int itemsSampled);

        int getNumberOfBatches();
        int getNumberOfItems();
        int getPercentageOfBadBatches();
        int getPercentageOfBadItems();
        int getItemsSampled();

    private:

        int numberOfBatches;
        int numberOfItems;
        int percentageOfBadBatches;
        int percentageOfBadItems;
        int itemsSampled;

};

#endif
