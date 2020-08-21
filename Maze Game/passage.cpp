//
//  passage.cpp
//  projectnumber2
//
//  Created by Priya Pilla on 2/23/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//
#include <iostream>
#include "passage.hpp"

inline Passage::Passage(){
    
}

inline Passage::Passage(bool isOpen){
   
    if (isOpen == true) {
        is_Open = true;
    }
    
    if (isOpen == false) {
        is_Open = false;
    }
    
}

inline Passage::Passage(bool isOpen, std::string _key){
    
    is_Open = false;
    key = _key;
}

inline bool Passage::RequiresKey(){
    
    if (key != "no_key") {
        return true;
    }else{
        return false;
    }
}

inline std::string Passage::GetRequiredKey(){
    return key;
}

inline bool Passage::IsOpen(){
    
    if (is_Open == true) {
        return true;
    }else{
        return false;
    }
}

inline void Passage::Open(){
    if (GetRequiredKey() != "no_key") {
        is_Open = true;
    }
}
