//
//  main.cpp
//  ds2 project4
//
//  Created by Priya Pilla on 11/13/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#include "simulation.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <cmath>

int main(int argc, const char * argv[]) {
    
    Simulation* simulation = new Simulation();
    simulation->runSimulation();
    
    return 0;
}
