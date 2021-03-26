//
//  genetic.hpp
//  project 3
//
//  Created by Priya Pilla on 10/31/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef genetic_hpp
#define genetic_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include "permutations.hpp"

class Genetic{
private:
    Permutation* p;
    std::vector<int> indexes;
    std::vector<std::string> paths;
    std::vector<std::string> mutatedPaths; 
    std::string leastCostPath;
    double leastCost;
    std::string secondLeastCostPath;
    double secondLeastCost;
    double cost;
    std::vector<double> costs;
    std::string path;
    
    int cities; //length
    int tours;
    int generations; 
    double percentMutations;
    
public:
    Genetic(Permutation* p, int cities, int tours, int generations, double percentMutations);
    double getLeastCost();
    void runGenetic();
    void findElites();
    void mutatePaths();
    void updatePathsAndCosts(int noOfMutationsInNextGen);
    std::vector<std::string> splitString(std::string const &str);
    std::vector<std::string> randomSwap(std::vector<std::string> &pathVec);
};

#endif /* genetic_hpp */
