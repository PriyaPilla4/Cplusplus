//
//  HashTable.hpp
//  ProjectThree
//
//  Created by Priya Pilla on 3/20/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef hashTable_hpp
#define hashTable_hpp

#include <stdio.h>
#include "movieList.hpp"

class HashTable{
private:
    
    MovieList* table;
    int size;
    double movieCount;
    void Resize();
    void Merge(std::vector<Movie>& allMovies, int left, int middle, int right);
    void Sort(std::vector<Movie>& allMovies, int left, int right);
    
public:
   
    HashTable();
    HashTable(int _size);
    ~HashTable();
    int Hash(std::string key);
    int GetSize();
    void Insert(std::string title, std::string leadActorActress, std::string description, int yearReleased);
    bool Delete (std::string title);
    Movie* Search(std::string title);
    void PrintYearFrequency();
    void PrintTable();
    void PrintSorted();
    
};
#endif /* hashTable_hpp */
