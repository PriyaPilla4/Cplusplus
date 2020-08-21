//
//  game.hpp
//  projectnumber2
//
//  Created by Priya Pilla on 2/25/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include "maze.hpp"
#include "player.hpp"

class Game{
    
private:
    Maze* maze;
    Player* player;
    Room* currentRoom;
    std::vector<std::string> currentItems;
    
    std::string GetPassageDescription(Passage* passage_);
    
public:
    Game();
    Game(Maze* maze_, Player* player_);
    
    void DisplayItems();
    void DisplayPassages();
    std::string GetCurrentRoomName();
    void LootRoom();
    bool ValidDirection(std::string direction);
    void MoveDirection(std::string direction);
    bool ExitFound();
    
    
};

#endif /* game_hpp */
