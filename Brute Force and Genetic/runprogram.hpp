//
//  runprogram.hpp
//  project 3
//
//  Created by Priya Pilla on 10/31/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef runprogram_hpp
#define runprogram_hpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sys/time.h>
#include <time.h>
#include <iostream>
#include "permutations.hpp"
#include "bruteforce.hpp"
#include "genetic.hpp"

class Runprogram{
private:
    int cities; //length
    int tours;
    int generations; 
    double percentMutations;
    double percentOfOptimal;
    struct timeval * t;
    
public:
    Runprogram();
    void run();
    void userInput();
    double calculatePercentOfOptimal(double bruteCost, double geneticCost);
};
#endif /* runprogram_hpp */
