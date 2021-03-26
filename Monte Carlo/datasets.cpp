//
//  datasets.cpp
//      - this file does part A of the project by creating the datasets.

//  ds2 project4
//
//  Created by Priya Pilla on 11/13/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.

#include "datasets.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <stdio.h>

Datasets::Datasets(){
    noOfBatches = 0;
    noOfItemsInBatch = 0;
    percentOfBadBatches = 0;
    percentOfBadItemsInBadBatch = 0;
    noOfItemsSampledFromBatch = 0;
    badBatchCounter = 0;
    files.clear();
}

int Datasets::getNoOfItemsSampledFromBatch(){
    return noOfItemsSampledFromBatch;
}

int Datasets::getNoOfBatches(){
    return noOfBatches;
}

int Datasets::getBadBatchCount(){ 
    return badBatchCounter;
}

int Datasets::getPercentOfBadItemsInBadBatch(){
    return percentOfBadItemsInBadBatch;
}

//create the datasets 
void Datasets::createDatasets(){
    
    std::cout << "Generating data sets:" << std::endl;
    
    //loop through no of batches
    for (int i = 0; i < noOfBatches; i++) {
            
        //open file for each new batch
        std::string outputFile = "ds" + std::to_string(i+1) + ".txt";
        files.push_back(outputFile);
        outStream.open(outputFile.c_str());

        //if random number is less than the percent of bad batches, it is a bad batch
        if (i < ((double)percentOfBadBatches/100)*(double)noOfBatches) {
            //bad batch counter
            badBatchCounter++;
               
            std::cout << "Create bad set batch # " << i+1;
            badBatch();
            std::cout << " total =  " << noOfItemsInBatch << " badpct =  " << percentOfBadItemsInBadBatch << std::endl;
            
        }else{
            goodBatch();
        }
            
        //close file for batch
        outStream.close();
    }
    
    std::cout << "Total bad sets = " << badBatchCounter << std::endl << std::endl;
}


void Datasets::readFile(std::string filename){
    //open file
    inStream.open(filename.c_str());

    //if file is open, read content
    if (inStream.is_open()) {
        inStream >> noOfBatches >> noOfItemsInBatch >> percentOfBadBatches
        >> percentOfBadItemsInBadBatch >> noOfItemsSampledFromBatch;
    }else{
        std::cout << "Cannot open file" << std::endl;
    }
    
    //print content
    std::cout << "Number of batches of items: " << noOfBatches << std::endl
    << "Number of items in each batch: " << noOfItemsInBatch << std::endl
    << "Percentage of batches containing bad items: " << percentOfBadBatches << "%" << std::endl
    << "Percentage of items that are bad in a bad set: " << percentOfBadItemsInBadBatch << "%" << std::endl
    << "Items sampled from each set: " << noOfItemsSampledFromBatch << std::endl << std::endl;
    
    inStream.close();
}

void Datasets::badBatch(){
    int badChipCounter = 0;
    
    //loop through no of chips
    for (int j = 0; j < noOfItemsInBatch ; j++) {
        
        //decide if chip is bad by rand no generator
        int randomBadChip = rand() % 100;
        
        //if random no is less than percent of bad chips, it is a bad chip
        if (randomBadChip < percentOfBadItemsInBadBatch) { //bad chip
            badChipCounter++;
            
            //write b to file
            outStream << "b" << std::endl;
            
        }else{ //good chip
            
            //write g to file
            outStream << "g" << std::endl;
        }
    }
    
    std::cout << ", totBad =  " << badChipCounter;
}

void Datasets::goodBatch(){
    for (int j = 0; j < noOfItemsInBatch; j++) {
        
        //write g to file for all the chips
       outStream << "g" << std::endl;
    }
}

std::vector<std::string> Datasets::getFilesCreated(){
    return files;
}


