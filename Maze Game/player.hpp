//
//  player.hpp
//  projectnumber2
//
//  Created by Priya Pilla on 2/25/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

class Player{
    
private:
    int row = 0;
    int col = 0;
    int moves = 0;
    
    std::vector<std::string> items;
    
public:
    Player();
    
    int GetRow();
    int GetCol();
    void SetPosition(int _row, int _col);
    
    void AddItem(std::string item);
    bool HasItem(std::string item);
    void UseItem(std::string item);
    
    int GetMoveCount();
    void IncrementMoves();
    
};

#endif /* player_hpp */
