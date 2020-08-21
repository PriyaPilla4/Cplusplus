//
//  HashTable.cpp
//  ProjectThree
//
//  Created by Priya Pilla on 3/20/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#include "hashTable.hpp"
#include <string>
#include <functional>
#include <iostream>
#include <vector>

HashTable::HashTable(){
    size = 13;
    movieCount = 0.0;
    table = new MovieList [13];
}

HashTable::HashTable(int _size){
    size = _size;
    table = new MovieList [size];
}

HashTable::~HashTable(){
    delete table;
}

void HashTable::Resize(){
    
}

void HashTable::Merge(std::vector<Movie>& allMovies, int left, int middle, int right){
 
    int mergedSize = right - left + 1;
    int mergePos = 0;
    int leftPos = 0;
    int rightPos = 0;
    
    std::vector<Movie>*mergedMovies = new std::vector<Movie>[mergedSize];
    
    
    leftPos = left;
    rightPos = middle + 1;
    
    while (leftPos <= middle && rightPos <= right) {
        if (allMovies.at(leftPos).GetYearReleased() <= allMovies.at(rightPos).GetYearReleased()) {
            mergedMovies->at(mergePos) = allMovies.at(leftPos);
            ++leftPos;
        }else{
           mergedMovies->at(mergePos) = allMovies.at(rightPos);
            ++rightPos;
        }
        ++mergePos;
    }
    
    while (leftPos <= middle) {
       mergedMovies->at(mergePos) = allMovies.at(leftPos);
        ++leftPos;
        ++mergePos;
    }
    
    while (rightPos <= right) {
       mergedMovies->at(mergePos) = allMovies.at(rightPos);
        ++rightPos;
        ++mergePos;
    }
    
    for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
        
        allMovies.at(left + mergePos) = mergedMovies->at(mergePos);
       
    }
    
    for (int i = 0; i < allMovies.size(); i++) {
        std::cout << "Title:        " <<  "Lead actor/actress:     " << "Description      " << "Year released:    "<< std::endl;
        std::cout << allMovies.at(i).GetTitle() << "  " << allMovies.at(i).GetLeadActorActress() << "  " << allMovies.at(i).GetDescription() << "  " << allMovies.at(i).GetYearReleased() << std::endl;
    }
    
}

void HashTable::Sort(std::vector<Movie>& allMovies, int left, int right){
    
    int j = 0;
    
    if (left < right) {
        j = (left + right)/2;
        
        Sort(allMovies,  left,  j);
        Sort(allMovies, j+1, right);
        Merge(allMovies, left, j, right);
    }
}

int HashTable::Hash(std::string key){
    int stringHash = 5381;

    for (char& strChar : key) {
        stringHash = (stringHash * 33) + strChar;
    }

    return stringHash % GetSize();
}

int HashTable::GetSize(){
   
    return size;
}

void HashTable::Insert(std::string title, std::string leadActorActress, std::string description, int yearReleased){
    
   if (Search(title) == nullptr) {
       
        table[Hash(title)].Insert(title, leadActorActress, description, yearReleased);
       
    }
    
}

bool HashTable::Delete (std::string title){
    
    MovieList* bucketList;
    Movie* itemNode;
    
    bucketList = &table[Hash(title)];
    itemNode = bucketList->Search(title);
    if (itemNode != nullptr) {
        
        if (bucketList->Delete(title) == true) {
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
   
}

Movie* HashTable::Search(std::string title){
   
    MovieList* bucketList;
    Movie* itemNode;
    
    bucketList = &table[Hash(title)];
    itemNode = bucketList->Search(title);
    if (itemNode != nullptr) {
        return itemNode;
    }else{
        return nullptr;
    }
    
}

void HashTable::PrintYearFrequency(){
    
    Movie *tempMovie = new Movie;
    int year[15];
    int j = 0;
    int count[15];
    
    for (int i = 0; i < GetSize(); i++) {
        tempMovie = table[i].DetachAndGetFirst();
        while (tempMovie->GetNext() != nullptr) {
                 year[j] = tempMovie->GetYearReleased();
                
            j++;
        }
        
    }
    
    for (int i = 0; i < 15; i++) {
        
        for (int k = 0; k <15; k++) {
            if (year[i] == year[k]) {
                count[i]++;
            }
        }
    }
    for (int i = 0; i < 15; i++) {
        std::cout << year[i] << " " << count[i] << std::endl;
    }
    
}

void HashTable::PrintTable(){
   
    std::cout << "Title:    " << "Lead Actor/Actress:    " << "Description:   " << "Year Released:    " << std::endl;
    for (int i = 0; i < GetSize(); i++) {
        table[i].PrintList();
    }
   
}

void HashTable::PrintSorted(){
    
    std::vector<Movie>*newVector = new std::vector <Movie>[15];
    int j = 0;
    
    for (int i = 0; i < GetSize(); i++) {
        while (table[i].DetachAndGetFirst() != nullptr) {
            
            newVector[j] = table[i].GetElements();
            j++;
            
        }
        
    }

    Sort(*newVector, newVector->front().GetYearReleased(), newVector->back().GetYearReleased()) ;
}
