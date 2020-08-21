//
//  game.cpp
//  projectnumber2
//
//  Created by Priya Pilla on 2/25/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#include "game.hpp"
#include <vector>
#include <iostream>

inline std::string Game::GetPassageDescription(Passage* passage_){
    
    if (passage_->IsOpen() == false && passage_->RequiresKey() == true) {
        std::cout << "door way that requires a(n) " << passage_->GetRequiredKey();
        return "door way";
    }else if (passage_->IsOpen() == false) {
        std::cout << "solid wall";
        return "solid wall";
    }else if (passage_->IsOpen() == true) {
        std::cout << "open passage";
        return "open passage";
    }else{
        return "not working";
    }

}

inline Game::Game(){

}

inline Game::Game(Maze* maze_, Player* player_){

    maze = maze_;
    player = player_;
    currentRoom = new Room();
    
}

inline void Game::DisplayItems(){
    
    currentItems.push_back(currentRoom->AcquireNextItem());
    currentItems.push_back(currentRoom->AcquireNextItem());
    
    int k = 0;
    if (currentItems[k] != "no item" && GetCurrentRoomName() != "The Exit!") {
        while (k < currentItems.size()) {
            if (k > 0) {
                std::cout << "and a(n) "<< currentItems[k] << " ";
            }else{
                std::cout << "There is a(n) " << currentItems[k] << " ";
            }
            if (currentItems[k+1] != "no item") {
                k++;
            }else{
                break;
            }
            
        }
        std::cout << "in this room. You picked up the item(s)! " << std::endl;
    }else{
        std::cout << "There are no items in this room " << std::endl;
    }
    
    currentItems.clear();
    
}

inline void Game::DisplayPassages(){
    
    std::cout << "There is a(n) " ;
    GetPassageDescription(currentRoom->GetNorthPassage());
    std::cout << " to the North. " << std::endl;
    
    std::cout << "There is a(n) " ;
    GetPassageDescription(currentRoom->GetEastPassage());
    std::cout << " to the East. " << std::endl;
    
    std::cout << "There is a(n) " ;
    GetPassageDescription(currentRoom->GetSouthPassage());
    std::cout << " to the South. " << std::endl;
    
    std::cout << "There is a(n) " ;
    GetPassageDescription(currentRoom->GetWestPassage());
    std::cout << " to the West. " << std::endl;
    
}

inline std::string Game::GetCurrentRoomName(){
   
    currentRoom = maze->GetRoom(player->GetRow(), player->GetCol());
    return currentRoom->GetName();
}

inline void Game::LootRoom(){
    
    std::string tempItem;
    
    do {
        tempItem = currentRoom->AcquireNextItem();
            if (tempItem != "no item"){
                currentItems.push_back(tempItem);
                player->AddItem(tempItem);
            }else{
                break;
            }
    } while (tempItem != "no item");
    
}

inline bool Game::ValidDirection(std::string direction){
    
    if (player->GetRow() == 0 && player->GetCol() == 0) {
        if (direction == "N" || direction == "W") {
            return false;
        }else if (direction == "S"){
            if (player->HasItem("red_key")) {
                return true;
            }else{
                return false;
            }
        }else{
            return true;
        }
    }
    
    if (player->GetRow() == 0 && player->GetCol() == 1) {
        if (direction == "N" || direction == "S") {
            return false;
        }else{
            return true;
        }
    }
    
    if (player->GetRow() == 0 && player->GetCol() == 2) {
        if (direction == "N" || direction == "E" || direction == "S") {
            return false;
        }else{
            return true;
        }
    }
    
    if (player->GetRow() == 1 && player->GetCol() == 0) {
        if (direction == "S" || direction == "W") {
            return false;
        }else{
            return true;
        }
    }
    
    if (player->GetRow() == 1 && player->GetCol() == 1) {
          if (direction == "S" || direction == "N") {
              return false;
          }else{
              return true;
          }
      }
    
    if (player->GetRow() == 1 && player->GetCol() == 2) {
          if (direction == "S" || direction == "N") {
              return false;
          }else{
              return true;
          }
    }else{
        return false;
    }
    
   
}

inline void Game::MoveDirection(std::string direction){
    
    if (direction == "E") {
        player->SetPosition(player->GetRow(), player->GetCol()+1);
        currentRoom = maze->GetRoom(player->GetRow(), player->GetCol());
    }
    if (direction == "S") {
        player->SetPosition(player->GetRow()+1, player->GetCol());
        currentRoom = maze->GetRoom(player->GetRow(), player->GetCol());
    }
    if (direction == "W") {
        player->SetPosition(player->GetRow(), player->GetCol()-1);
        currentRoom = maze->GetRoom(player->GetRow(), player->GetCol());
    }
    if (direction == "N") {
        player->SetPosition(player->GetRow()-1, player->GetCol());
        currentRoom = maze->GetRoom(player->GetRow(), player->GetCol());
    }
   
}

inline bool Game::ExitFound(){
    
    if (currentRoom->GetName()== "The Exit!") {
        std::cout << "It took you " << player->GetMoveCount() << " moves, but you're free!" << std::endl;
        return true;
    }else{
        return false;
    }
    
}
