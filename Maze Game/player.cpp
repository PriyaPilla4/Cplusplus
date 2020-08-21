//
//  player.cpp
//  projectnumber2
//
//  Created by Priya Pilla on 2/25/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#include "player.hpp"
#include <iostream>


inline Player::Player(){
    
}

inline int Player::GetRow(){
    
    return row;
}

inline int Player::GetCol(){
    
    return col;
}

inline void Player::SetPosition(int _row, int _col){
   
    row = _row;
    col = _col;
    IncrementMoves();
}

inline void Player::AddItem(std::string item){
    
    items.push_back(item);
}

inline bool Player::HasItem(std::string item){
    
    std::vector<std::string>::iterator it = std::find(items.begin(), items.end(), item);
    
    if (it != items.end()) {
        return true;
    }else{
        return false;
    }
    
}

inline void Player::UseItem(std::string item){
    
    auto it = std::find(items.begin(), items.end(), item);
    
    if (it != items.end()) {
        items.erase(it);
    }
    
}

inline int Player::GetMoveCount(){
    return moves;
}

inline void Player::IncrementMoves(){
    moves++;
}
