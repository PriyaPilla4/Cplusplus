//
//  Terminal.hpp
//  projectfour
//
//  Created by Priya Pilla on 4/18/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef terminal_hpp
#define terminal_hpp

#include <stdio.h>
#include "fileSystem.hpp"

class Terminal{
private:
    FileSystem* fs;
    
public:
    Terminal();
    void Run();
};
#endif /* terminal_hpp */
