//
//  Menu.hpp
//  ProjectThree
//
//  Created by Priya Pilla on 3/20/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef menu_hpp
#define menu_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "hashTable.hpp"



class Menu{
private:
    HashTable* movieTable;
    int GetSelection();
    void AddMovie();
    void SearchMovie();
    
    HashTable hashObj; // added
    
public:
    Menu();
    void LoadMovies(std::string filename);
    HashTable* GetMovieTable();
    void StartMenu();
    
};

#endif /* menu_hpp */
