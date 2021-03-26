//
//  permutations.cpp
//  project 3
//
//  Created by Priya Pilla on 10/28/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//
 
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include "permutations.hpp"

Permutation::Permutation(int length){
    n = length;
    initS(length);
}

//initialize tour
void Permutation::initS(int length){
    int i;
    for(i = 0; i < length; i++){
        s[i] = i+1;
    }
    s[i] = 0;
}
      
//generate permutation
void Permutation::perm1(){
    int m, k, p , q, i;
    
    m = n - 1;
    while(s[m]>s[m+1]){
        m = m - 1;
    }
        
    k = n-1;
        
    while(s[m] > s[k]){
        k = k - 1;
    }
    
    swap(m,k);
    p = m + 1;
    q = n-1;
			  
    while( p < q){
        swap(p,q);
        p++;
        q--;
    }
    
}

//calculate cost of tour
double Permutation::calculateCost(){
    static const int size = n+2;
    int updatedArray[size]; //new array with 2 + size of s
    double cost = 0.0;
    
    //prepend and append 0 to updated array
    for (int i = 0; i < n+2; i++) {
        if (i == 0 || i == n+1){
            updatedArray[i] = 0;
        }else{
            updatedArray[i] = s[i-1];
        }
    }
    
    //calculate cost
    for (int i = 0; i < size-1; i++) {
        int row = updatedArray[i];
        int column = updatedArray[i+1];
        
        cost += edgesMatrix[row][column];
    }
    return cost;
}
   	
//calculate cost of tour
double Permutation::calculateCost(std::vector<std::string> &pathVec){
    static const int size = n+2;
    int array[n]; //new array with 2 + size of s
    int uArray[size];
    double cost = 0.0;
       
    //convert vector of strings to vector of ints
    std::vector<int> intPathVec;
    for(std::vector<std::string>::iterator it=pathVec.begin() ; it!=pathVec.end();++it){
        std::istringstream iss(*it);
        int temp;
        iss >> temp;
        intPathVec.push_back(temp);
    }
        
    //convert vector to array
    std::copy(intPathVec.begin(), intPathVec.end(), array);
    
    //prepend and append 0 to updated array
    for (int i = 0; i < n+2; i++) {
        if (i == 0 || i == n+1){
            uArray[i] = 0;
        }else{
            uArray[i] = array[i-1];
        }
    }
    
    //calculate cost
    for (int i = 0; i < size-1; i++) {
        int row = uArray[i];
        int column = uArray[i+1];
        cost += edgesMatrix[row][column];
    }
       
    return cost;
}

//return tour
std::string Permutation::printS(){
    std::string path = "";
    for(int i = 0; i < n; i++){
        path = path + std::to_string(s[i]) + " ";
    }
    return path;
}
   

void Permutation::swap(int i, int j) {
    int c = s[i];
    s[i] = s[j];
    s[j] = c;
}
   
int * Permutation::getS(){
    return s;
}
   
int Permutation::fact(int n){
    int tot = 1;
    for(int i = 2; i <=n; i++){
        tot*=i;
    }
    return tot;
}

//reads edges from distances file into matrix
void Permutation::readFile(){
    std::ifstream inputfile;
    std::string distance;
    std::string filename = "distances.txt";
    
    inputfile.open(filename.c_str());
    
    if (inputfile.is_open()) {
    
        for (int i = 0; i < 20; i++){
            for (int j = 0; j < 20; j++){
                if(i == j){
                    edgesMatrix[i][j] = 0.0;
                }else{
                    inputfile >> edgesMatrix[i][j];
                }
            }
        }
        
    }else{
        std::cout << "Cannot open file" << std::endl;
    }
    
    inputfile.close();
}

//prints distances matrix
void Permutation::printMatrix(){
    for(int i = 0; i < 20; i++) {
       for(int j = 0; j < 20; j++) {
          std::cout << edgesMatrix[i][j] << " ";
       }
       std::cout << std::endl;
    }
}
  
 
