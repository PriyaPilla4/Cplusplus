//
//  monteCarlo.cpp
//       - this file does part B of the project byt implementing the monte carlo algorithm. reads the sample number of items in the batch and checks to see if any of them are bad

//  ds2 project4
//
//  Created by Priya Pilla on 11/13/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#include "monteCarlo.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <fstream>
#include <stdio.h>

MonteCarlo::MonteCarlo(){
    noOfBatches = 0;
    noOfItemsSampledFromBatch = 0;
    files.clear();
    itemsInABatch.clear();
    badBatchCounter = 0;
}

MonteCarlo::MonteCarlo(int noOfBatches, int noOfItemsSampledFromBatch, std::vector<std::string> files){
    this->noOfBatches = noOfBatches;
    this->noOfItemsSampledFromBatch = noOfItemsSampledFromBatch;
    this->files = files;
}

int MonteCarlo::getBadBatchCount(){
    return badBatchCounter;
}

//analyze the data sets
void MonteCarlo::analyzeDataSets(){
    
    std::cout << "Analyzing Data Sets:" << std::endl;
    
    badBatchCounter = 0;
    
    //loop through each file created in simulation
    for (int i = 0; i < files.size(); i++) {
        
        //read file
        readFile(files[i]);
        
        //take sample of each batch to check if it is bad
        sampleItems(i+1);
    }
    
}

void MonteCarlo::readFile(std::string filename){
    itemsInABatch.clear();
    
    //open file
    inStream.open(filename.c_str());

    std::string item;
    
    //if file is open, read content
    if (inStream.is_open()) {
        
        while (true) {
            inStream >> item;
            
            if(inStream.eof()){
                break;
            }
            //adds items in the file to a vector
            itemsInABatch.push_back(item);
        }
        
    }else{
        std::cout << "Cannot open file" << std::endl;
    }
    
    inStream.close();
}

//checks the sample no. of items to see if the batch is bad
void MonteCarlo::sampleItems(int batchNo){
    for (int j = 0; j < noOfItemsSampledFromBatch; j++) {
        
        if (itemsInABatch[j] == "b") {
            badBatchCounter++;
            std::cout << "batch #" << batchNo << " is bad" << std::endl;
            break;
        }
    }
    
}


