//
//  main.cpp
//  project 3
//
//  Created by Priya Pilla on 10/28/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include "permutations.hpp"
#include "bruteforce.hpp"
#include "genetic.hpp"
#include "runprogram.hpp"

int main(int argc, const char * argv[]) {
   
    Runprogram* runprogram = new Runprogram();
    runprogram->run();
    
    return 0;
}
