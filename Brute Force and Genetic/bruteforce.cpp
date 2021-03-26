//
//  bruteforce.cpp
//  project 3
//
//  Created by Priya Pilla on 10/31/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include "bruteforce.hpp"

BruteForce::BruteForce(Permutation* p, int length){
    setP(p);
    setLength(length);
    setCost(0.0);
    setPath("");
    setLeastCostPath("");
   setLeastCost(0.0);
}

//setters and getters
void BruteForce::setP(Permutation* p){
    this->p = p;
}

void BruteForce::setAllPossiblePaths(std::vector<std::string> allPossiblePaths){
    this->allPossiblePaths = allPossiblePaths;
}

void BruteForce::setLength(int length){
    this->length = length;
}

void BruteForce::setCost(double cost){
    this->cost = cost;
}

void BruteForce::setCosts(std::vector<double> costs){
    this->costs = costs;
}

void BruteForce::setPath(std::string path){
    this->path = path;
}

void BruteForce::setLeastCostPath(std::string leastCostPath){
    this->leastCostPath = leastCostPath;
}

void BruteForce::setLeastCost(double leastCost){
    this->leastCost = leastCost;
}

Permutation* BruteForce::getP(){
    return p;
}

std::vector<std::string> BruteForce::getAllPossiblePaths(){
    return allPossiblePaths;
}

int BruteForce::getLength(){
    return length;
}

double BruteForce::getCost(){
    return cost;
}

std::vector<double> BruteForce::getCosts(){
    return costs;
}

std::string BruteForce::getPath(){
    return path;
}

std::string BruteForce::GetLeastCostPath(){
    return leastCostPath;
}

double BruteForce::getLeastCost(){
    return leastCost;
}

//compute optimal cost
void BruteForce::computeOptimal(){
    leastCost = *min_element(costs.begin(), costs.end()); //find min cost
    auto it = find(costs.begin(), costs.end(), leastCost); //get index of cost
    int index = it - costs.begin();
    leastCostPath = allPossiblePaths[index]; //get min path
}

void BruteForce::runBruteForce(){
    int total = p->fact(length);
    
    for(int i = 0; i < total; i++){
        //get path
        setPath(p->printS());
        
        //add path to vector
        allPossiblePaths.push_back(getPath());
        
        //calculate cost
        setCost(p->calculateCost());
        
        //put cost in a vector
        costs.push_back(cost);
        
        //gets next permutation
        p->perm1();
    }
    
    //get optimal cost
    computeOptimal();
}




