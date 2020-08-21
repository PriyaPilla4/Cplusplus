//
//  maze.cpp
//  projectnumber2
//
//  Created by Priya Pilla on 2/24/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#include "maze.hpp"
#include <iostream>
#include <string>
#include <fstream>

inline Maze::Maze(){
    
}

inline void Maze::LoadMaze(){
    int i = 0;
    int j = 0;
    int k = 0;
    int rows = 0;
    int cols = 0;
    
    std::string rmName;
    std::string north;
    std::string east;
    std::string south;
    std::string west;
    
    Passage* northptr;
    Passage* eastptr;
    Passage* southptr;
    Passage* westptr;
    
    std::string _items = " ";
    
    mazeFile >> rows >> cols;
    
    rooms = new Room*[rows];
       for (int i = 0; i < rows; i++){
           rooms[i] = new Room[cols];
       }
    
    while (!mazeFile.eof()){
        
        if (i == 0) {
            mazeFile.ignore(1000, '\n');
            i = 1;
        }
    
    getline( mazeFile, rmName, ',' );
    getline( mazeFile, north, ',' );
    getline( mazeFile, east, ',' );
    getline( mazeFile, south, ',' );
    getline( mazeFile, west, ',' );
    
    if (mazeFile.peek()!=' '){
        getline( mazeFile, _items, '\n' );
    }
        
        northptr = CreatePassage(north);
        eastptr = CreatePassage(east);
        southptr = CreatePassage(south);
        westptr = CreatePassage(west);
       
        while (j < rows) {
            while (k < cols) {
                Room newRoom(rmName, northptr, eastptr, southptr, westptr);
                rooms[j][k] = newRoom;
                rooms[j][k].AddItem(_items);
                k++;
                break;
            }
            
            if (k == cols) {
                j++;
                k = 0;
            }
            
        break;
        }
        
        rmName = " ";
        north = " ";
        east = " ";
        south = " ";
        west = " ";
        _items = " ";
    }
    
}

inline Passage* Maze::CreatePassage(std::string type){
    
    Passage* passage = nullptr;
    
    if (type == "-") {
        passage = new Passage(false);
    }
    
    if (type == "+"){
        passage = new Passage(true);
    }
    
    if (type != "+" && type != "-") {
        
        passage = new Passage (false, type);
    }
    return passage;
}

inline Maze::Maze(std::string maze_File){
    
    mazeFile.open(maze_File.c_str());
    
    if (!mazeFile.is_open()){
        std::cout << "Could not open file " << maze_File << std::endl;
    }
    
    LoadMaze();
    mazeFile.close();
}

inline Room* Maze::GetRoom(int row, int col){

    return &rooms[row][col];
}

inline int Maze::GetNumberRows(){

    return rows;
}

inline int Maze::GetNumberCols(){
    
    return cols;
}

inline Maze::~Maze(){
   
}
