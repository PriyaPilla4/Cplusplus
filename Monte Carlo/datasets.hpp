//
//  datasets.hpp
//  ds2 project4
//
//  Created by Priya Pilla on 11/13/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef datasets_hpp
#define datasets_hpp

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <stdio.h>

class Datasets{
private:
    int noOfBatches;
    int noOfItemsInBatch;
    int percentOfBadBatches;
    int percentOfBadItemsInBadBatch;
    int noOfItemsSampledFromBatch;
    std::ifstream inStream;
    std::ofstream outStream;
    std::vector<std::string> files;
    int badBatchCounter;
    
public:
    Datasets();
    void createDatasets();
    void readFile(std::string filename);
    void badBatch();
    void goodBatch();
    std::vector<std::string> getFilesCreated();
    int getNoOfBatches();
    int getNoOfItemsSampledFromBatch();
    int getBadBatchCount();
    int getPercentOfBadItemsInBadBatch();
   
};
#endif /* datasets_hpp */
