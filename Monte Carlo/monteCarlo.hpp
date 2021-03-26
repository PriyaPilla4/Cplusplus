//
//  monteCarlo.hpp
//  ds2 project4
//
//  Created by Priya Pilla on 11/13/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef monteCarlo_hpp
#define monteCarlo_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <fstream>

class MonteCarlo{
private:
    int noOfBatches;
    int noOfItemsSampledFromBatch;
    std::vector<std::string> files;
    std::vector<std::string> itemsInABatch;
    std::ifstream inStream;
    int badBatchCounter;
    
public:
    MonteCarlo();
    MonteCarlo(int noOfBatches, int noOfItemsSampledFromBatch, std::vector<std::string> files);
    int getBadBatchCount();
    void analyzeDataSets();
    void readFile(std::string filename);
    void sampleItems(int batchNo);
    
    
};

#endif /* monteCarlo_hpp */
