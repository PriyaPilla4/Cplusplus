//
//  genetic.cpp
//  project 3
//
//  Created by Priya Pilla on 10/31/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include "genetic.hpp"


Genetic::Genetic(Permutation* p, int cities, int tours, int generations, double percentMutations){
    this->p = p;
    this->cities = cities; //length
    this->tours = tours;
    this->generations = generations;
    this->percentMutations = percentMutations;
    
    leastCostPath = "";
    leastCost = 0.0;
    secondLeastCostPath = "";
    secondLeastCost = 0.0;
    cost = 0.0;
    path = "";
}

double Genetic::getLeastCost(){
    return leastCost;
}

void Genetic::runGenetic(){
    costs.clear();
    bool firstGen = true;
      
      for (int k = 0; k < generations; k++) {
          
          path = "";
          
          // mutations + elites
          int minTours = paths.size();
      
          for(int i = 0; i < tours-minTours; i++){
              
              if (firstGen == true) {
                  firstGen = false;
              }else{
                  //check for duplicates
                  do {
                      p->perm1();
                  } while ((std::find(mutatedPaths.begin(), mutatedPaths.end(), p->printS()) != mutatedPaths.end()));
              }
              
              //get path
              path = p->printS();
             
              //add to vector of paths
              paths.push_back(path);
          
              std::vector<std::string> vecPath = splitString(path);
              //calculate cost of path
              cost = p->calculateCost(vecPath);
              
              //put cost in a vector
              costs.push_back(cost);
          }
          
          //find least and second least in costs
          findElites();
          
          //mutate paths
          mutatePaths();
      
          //compute number of mutations in next generation
          int noOfMutationsInNextGen = mutatedPaths.size() * (percentMutations / 100);
      
          //update paths and costs for next generation
          updatePathsAndCosts(noOfMutationsInNextGen);
      }
}

//find least and second least in costs
void Genetic::findElites(){
    //find min cost
    leastCost = *min_element(costs.begin(), costs.end());
    
    //get index of cost
    auto it = find(costs.begin(), costs.end(), leastCost);
    int index = it - costs.begin();
    
    //get least cost path
    leastCostPath = paths[index];
    
    //delete least cost and least cost path
    costs.erase(costs.begin() + index);
    paths.erase(paths.begin() + index);
    
    //find second least cost
    secondLeastCost = *min_element(costs.begin(), costs.end());
    
    //get index of cost
    it = find(costs.begin(), costs.end(), secondLeastCost);
    index = it - costs.begin();
    
    //get second least path
    secondLeastCostPath = paths[index];
}

//mutates paths for next generation
void Genetic::mutatePaths(){
    mutatedPaths.clear();
    std::vector<std::string> pathVec;
    
    for (int i = 0; i < tours; i++) {
            
        //splitting the path string
        if (i % 2 == 0) { //even
            pathVec = splitString(leastCostPath);
        }else{
            pathVec = splitString(secondLeastCostPath);
        }
            
        //gets mutated path
        std::vector<std::string> pathVecMutated = randomSwap(pathVec);
            
       //convert vector of strings to string
        std::string pathStringMutated = "";
        for(auto &element: pathVecMutated){
            pathStringMutated += element + " ";
        }
        
        mutatedPaths.push_back(pathStringMutated);
            
    }
}

//clear paths and add these mutations based on the percentage and 2 elites
void Genetic::updatePathsAndCosts(int noOfMutationsInNextGen){
    
    paths.clear();
    for (int i = 0; i < noOfMutationsInNextGen; i++) {
        paths.push_back(mutatedPaths[i]);
    }
    paths.push_back(leastCostPath);
    paths.push_back(secondLeastCostPath);
             
    //update costs vector
    costs.clear();
    for(auto &s: paths){
        std::vector<std::string> pathVec = splitString(s);
        double cost = p->calculateCost(pathVec);
        costs.push_back(cost);
    }
}

//converts string to vector string
std::vector<std::string> Genetic::splitString(std::string const &str){
    
    std::vector<std::string> path;
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(' ', end)) != std::string::npos)
    {
        end = str.find(' ', start);
        path.push_back(str.substr(start, end - start));
    }
    
    return path;
}

//randomly swaps 2 elements
std::vector<std::string> Genetic::randomSwap(std::vector<std::string> &pathVec){
    int randomIndex1 = 0;
    int randomIndex2 = 0;
    
    //makes sure 2 random indexes aren't the same
    do {
        randomIndex1 = rand() % pathVec.size();
        randomIndex2 = rand() % pathVec.size();
    } while (randomIndex1 == randomIndex2);
    
    //swaps 2 rand positions
    std::swap(pathVec[randomIndex1],pathVec[randomIndex2]);
    
    return pathVec;
}

