//
//  runprogram.cpp
//  project 3
//
//  Created by Priya Pilla on 10/31/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//
#include <iostream>
#include <string>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>  /*  for malloc */
#include "runprogram.hpp"


Runprogram::Runprogram(){
    cities = 0; //length
    tours = 0;
    generations = 0;
    percentMutations = 0;
    t = (struct timeval *)malloc(sizeof(struct timeval));
}

void Runprogram::run(){
    
     std::string bruteTime;
     std::string geneticTime;
     double startseconds;
     double startmicroseconds;
     
    
     //get user input
     userInput();
    
    int length = cities;
    Permutation* p = new Permutation(length);
    
     //read distances.txt file and initialize
     p->readFile();
     p->initS(length);
     
     BruteForce* bruteForce = new BruteForce(p, length);
    
    //brute force time start
    gettimeofday(t,NULL);
    time_t startSec = t->tv_sec;
    startseconds = t->tv_sec - startSec;
    startmicroseconds = t->tv_usec;
    
    //runs brute force algorithm
    bruteForce->runBruteForce();
    
    //brute force time end
    gettimeofday(t,NULL);
    bruteTime = "Seconds = " + std::to_string((t->tv_sec - startSec) - startseconds) + " Microseconds = " + std::to_string((t->tv_usec) - startmicroseconds);
    
    
    Genetic *genetic = new Genetic(p, cities, tours, generations, percentMutations);
    
    
    //genetic time start
    gettimeofday(t,NULL);
    startSec = t->tv_sec;
    startseconds = t->tv_sec - startSec;
    startmicroseconds = t->tv_usec;
    
    //runs genetic algorithm
    genetic->runGenetic();
    
    //genetic time end
    gettimeofday(t,NULL);
    geneticTime = "Seconds = " + std::to_string((t->tv_sec - startSec) - startseconds) + " Microseconds = " + std::to_string((t->tv_usec) - startmicroseconds);
    
    //output
    std::cout << "The number of cities run: " << cities << std::endl;
    std::cout << "Optimal cost from brute force: " << bruteForce->getLeastCost() << std::endl;
    std::cout << "Time the brute force algorithm took: " << bruteTime << std::endl;
    std::cout << "Cost from the genetic algorithm: " << genetic->getLeastCost() << std::endl;
    std::cout << "Time the genetic algorithm took: " << geneticTime << std::endl;
    std::cout << "Percent of optimal that the genetic algorithm produced: " << calculatePercentOfOptimal(bruteForce->getLeastCost(), genetic->getLeastCost()) << "%" << std::endl;
}

//gets user input
void Runprogram::userInput(){
    std::cout << "Enter values for the following:" << std::endl
    << "number of cities to run" << std::endl
    << "number of individual tours in a given generation" << std::endl
    << "number of generations to run" << std::endl
    << "percentage of generation that should be comprised of mutations" << std::endl;
    
    std::cin >> cities >> tours >> generations >> percentMutations;
}

//calculates percent of Optimal for genetic algorithm
double Runprogram::calculatePercentOfOptimal(double bruteCost, double geneticCost){
    percentOfOptimal = (geneticCost/bruteCost) * 100;
    return percentOfOptimal;
}


