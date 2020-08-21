//
//  main.cpp
//  projectnumber2
//
//  Created by Priya Pilla on 2/23/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "passage.cpp"
#include "room.cpp"
#include "maze.cpp"
#include "player.cpp"
#include "game.cpp"


int main(int argc, const char * argv[]) {
    
    std::string fileName;
    std::string move;
    bool check2 = false;
    
    std::cout << "Welcome to The Maze." << std::endl << "Please enter the filename of your maze:" << std::endl;
    
    std::cin >> fileName;
    
    Maze* mazePtr = new Maze(fileName);
    Player* playerPtr = new Player;
    
    Game game(mazePtr, playerPtr);
    
    do {
        bool check = false;
        std::cout << "You are in " << game.GetCurrentRoomName() << std::endl;
        game.DisplayItems();
        game.DisplayPassages();
        std::cout << "Which way would you like to move?" << std::endl << "N - North, E - East, S - South, W - West, Q - Quit" << std::endl;
        
        do {
            std::cin >> move;
            
            if (move == "E" && game.ExitFound() == true) {
                check2 = true;
                break;
            }
            
            if (move == "Q") {
                std::cout << "Better luck next time!" << std::endl;
                break;
            }
           
            if (game.ValidDirection(move) == true) {
                game.MoveDirection(move);
                game.LootRoom();
                check = true;
            }else{
                std::cout << "You can't go that way!" << std::endl << "Please enter a valid direction: " << std::endl;
            }
           
        } while (check == false);
        
        if (move == "Q") {
            break;
        }
        
        if (check2 == true) {
            break;
        }
        
    } while (move != "Q");
    
    
    return 0;
}
