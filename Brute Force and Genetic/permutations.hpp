//
//  permutations.hpp
//  project 3
//
//  Created by Priya Pilla on 10/28/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef permutations_h
#define permutations_h
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <sstream>

class Permutation
{
  public:
    Permutation(int length);
    void initS(int length);
    std::string printS();
    void perm1();
    void swap(int i, int j);
    int * getS();
    int fact(int n);
    
    double calculateCost();
    double calculateCost(std::vector<std::string> &pathVec);
    void readFile();
    void printMatrix();
    
  private:
    static const int MAX = 20;  // twenty cities max
    int nfact = 1;
    int n;
    int count = 1;
    int s[MAX];
    
    double edgesMatrix[20][20]; //edges - distances
    
};

#endif /* permutations_h */
