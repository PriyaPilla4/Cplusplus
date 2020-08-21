//
//  room.cpp
//  projectnumber2
//
//  Created by Priya Pilla on 2/24/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#include "room.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

inline Room::Room(){
    
}

inline Room::Room(std::string _name, Passage* nP, Passage* eP, Passage* sP, Passage* wP){
    
    name = _name;
    northPassage = nP;
    eastPassage = eP;
    southPassage = sP;
    westPassage = wP;
}

inline std::string Room::GetName(){
    
    return name;
}

inline Passage* Room::GetNorthPassage(){
    
    return northPassage;
}

inline Passage* Room::GetEastPassage(){
    
    return eastPassage;
}

inline Passage* Room::GetSouthPassage(){
    
    return southPassage;
}

inline Passage* Room::GetWestPassage(){
    
    return westPassage;
}

inline void Room::AddItem(std::string item){
    
    std::stringstream check1 (item);
    std::string intermediate;
    
    while (getline(check1, intermediate, ' ')) {
        items.push_back(intermediate);
    }
    
}

inline std::string Room::AcquireNextItem(){
    
    int h = 0;
    std::string temp;
    
    if (h < items.size()) {
        while (h < items.size()) {
               temp = items[h];
               h++;
               items.erase (items.begin()+(h-1));
               //return temp;
               break;
           }
        return temp;
    }else{
        
        return "no item";
    }
   
}
