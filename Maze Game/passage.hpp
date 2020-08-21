//
//  passage.hpp
//  projectnumber2
//
//  Created by Priya Pilla on 2/23/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef passage_hpp
#define passage_hpp

#include <stdio.h>
#include <iostream>

class Passage{
private:
    bool is_Open;
    std::string key = "no_key";
    
public:
    Passage();
    Passage(bool isOpen);
    Passage(bool isOpen, std::string key);
    
    bool IsOpen();
    bool RequiresKey();
    std::string GetRequiredKey();
    
    void Open();
};

#endif /* passage_hpp */
