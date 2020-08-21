//
//  Terminal.cpp
//  projectfour
//
//  Created by Priya Pilla on 4/18/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#include "terminal.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>


Terminal::Terminal(){
    fs = new FileSystem();
}

void Terminal::Run(){
   
    std::string tempInput;
    std::string input[3];
    int k;
   
    
    do {
         k = 0;
        input[0]= "";
        input[1]= "";
        input[2]= "";
        
        std::cout << "$ ";
        std::getline(std::cin, tempInput);
        
      for(unsigned int i = 0; i<tempInput.length(); i++) {
          
          if (tempInput[i] != ' ') {
              input[k] = input[k] + tempInput[i];
          }
          if (tempInput[i] == ' '){
              k++;
          }
          
      }
        
        if (input[0] == "exit") {
            break;
        }
        
        if (input[0] == "ls") {
            std::cout << fs->ls() << std::endl;
        }
        
        if (input[0] == "mkdir") {
            std::cout << fs->mkdir(input[1]) << std::endl;
        }
        
        if (input[0] == "pwd") {
            std::cout << fs->pwd() << std::endl;
        }
        
        if (input[0] == "touch") {
            std::cout << fs->touch(input[1]) << std::endl;
        }
        
        if (input[0] == "rm") {
            std::cout << fs->rm(input[1]) << std::endl;
        }
        
        if (input[0] == "mv") {
            std::cout << fs->mv(input[1], input[2]) << std::endl;
        }
        
        if (input[0] == "cd") {
            std::cout << fs->cd(input[1]) << std::endl;
        }
        
        
    } while (input[0] != "exit");
    
    delete fs;
}
