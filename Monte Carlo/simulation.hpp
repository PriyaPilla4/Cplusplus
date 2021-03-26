//
//  simulation.hpp
//  ds2 project4
//
//  Created by Priya Pilla on 11/13/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef simulation_hpp
#define simulation_hpp

#include "datasets.hpp"
#include "monteCarlo.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <cmath>

class Simulation{
private:
    Datasets* datasets;
    MonteCarlo* monteCarlo;
    double base;
    double exponent;
    double failureToDetectBadBatch;
    double percentOfBatchesDetected;
public:
    Simulation();
    void runSimulation();
    void calculateStats();
    void printStats();
};

#endif /* simulation_hpp */
