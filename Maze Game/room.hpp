//
//  room.hpp
//  projectnumber2
//
//  Created by Priya Pilla on 2/24/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef room_hpp
#define room_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "passage.hpp"

class Room{
    
private:
    std::string name = "no name";
    std::vector<std::string> items;
    Passage* northPassage;
    Passage* eastPassage;
    Passage* southPassage;
    Passage* westPassage;
    
public:
    
    Room();
    Room(std::string _name, Passage* nP , Passage* eP, Passage* sP , Passage* wP);
    std::string GetName();
    Passage* GetNorthPassage();
    Passage* GetEastPassage();
    Passage* GetSouthPassage();
    Passage* GetWestPassage();
    
    void AddItem(std::string item);
    std::string AcquireNextItem();
    
};

#endif /* room_hpp */
