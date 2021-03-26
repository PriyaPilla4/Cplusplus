//
//  simulation.cpp
//   - this file generates the simulation by calling functions in datasets and monteCarlo class. Calculates and prints out stats for simulation

//  ds2 project4
//
//  Created by Priya Pilla on 11/13/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#include "simulation.hpp"
#include "datasets.hpp"
#include "monteCarlo.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <cmath>

Simulation::Simulation(){
    base = 0;
    exponent = 0;
    failureToDetectBadBatch = 0;
    percentOfBatchesDetected = 0;
    datasets = nullptr;
    monteCarlo = nullptr;
}

void Simulation::runSimulation(){
        //store files names
       std::string files[] = {"t1.txt", "t2.txt", "t3.txt", "t4.txt"};
       int noOfFiles = sizeof(files)/sizeof(files[0]);
       
       //loop through files
       for (int i = 0; i < noOfFiles; i++) {
           std::cout << "Simulation " << i+1 << ":"<< std::endl;
           
           datasets = new Datasets();
           
           //read file
           datasets->readFile(files[i]);
           //create datasets
           datasets->createDatasets();
           
           monteCarlo = new MonteCarlo(datasets->getNoOfBatches(), datasets->getNoOfItemsSampledFromBatch(), datasets->getFilesCreated());
           
           //do analysis of the files of batches created in the simulation
           monteCarlo->analyzeDataSets();
           
           //calculate stats
           calculateStats();
           
           //print stats
           printStats();
           
       }

}

void Simulation::calculateStats(){
    base = 1 - ((double)datasets->getPercentOfBadItemsInBadBatch() / 100);
    exponent = datasets->getNoOfItemsSampledFromBatch();
    failureToDetectBadBatch = pow(base, exponent);
    percentOfBatchesDetected = ((double)monteCarlo->getBadBatchCount()/(double)datasets->getBadBatchCount()) * 100;
}

void Simulation:: printStats(){
    //print stats
    std::cout << std::endl << "Base = " << base << " exponent = " << exponent << std::endl;
    std::cout << "P(failure to detect bad batch) = " << failureToDetectBadBatch << std::endl;
    std::cout << "Percentage of bad batches actually detected =  " << percentOfBatchesDetected << "%" << std::endl << std::endl;
}


