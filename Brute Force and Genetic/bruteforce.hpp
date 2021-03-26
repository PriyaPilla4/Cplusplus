//
//  bruteforce.hpp
//  project 3
//
//  Created by Priya Pilla on 10/31/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef bruteforce_hpp
#define bruteforce_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "permutations.hpp"

class BruteForce{
private:
    Permutation* p;
    std::vector<std::string> allPossiblePaths;
    int length;
    double cost;
    std::vector<double> costs;
    std::string path;
    std::string leastCostPath;
    double leastCost;
    
public:
    BruteForce(Permutation* p, int length);
    
    void setP(Permutation* p);
    void setAllPossiblePaths(std::vector<std::string> allPossiblePaths);
    void setLength(int length);
    void setCost(double cost);
    void setCosts(std::vector<double> costs);
    void setPath(std::string path);
    void setLeastCostPath(std::string leastCostPath);
    void setLeastCost(double leastCost);
    
    Permutation* getP();
    std::vector<std::string> getAllPossiblePaths();
    int getLength();
    double getCost();
    std::vector<double> getCosts();
    std::string getPath();
    std::string GetLeastCostPath();
    double getLeastCost();
    void computeOptimal();
    
    void runBruteForce();
    
    
};
#endif /* bruteforce_hpp */
