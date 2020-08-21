//
//  maze.hpp
//  projectnumber2
//
//  Created by Priya Pilla on 2/24/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef maze_hpp
#define maze_hpp

#include <stdio.h>
#include <fstream>
#include <string>
#include "room.hpp"


class Maze{
    
private:
    Room** rooms;
    //Room* theRoom;
    int rows;
    int cols;
   
    std::ifstream mazeFile;
    
    void LoadMaze();
    Passage* CreatePassage(std::string type);
    
public:
    
    Maze();
    Maze(std::string maze_File);
    Room* GetRoom(int row, int col);
    int GetNumberRows();
    int GetNumberCols();
    
    ~Maze();
    
    
};

#endif /* maze_hpp */
