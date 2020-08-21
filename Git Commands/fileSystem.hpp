//
//  FileSystem.hpp
//  projectfour
//
//  Created by Priya Pilla on 4/18/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef fileSystem_hpp
#define fileSystem_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "node.hpp"

class FileSystem{
private:
    Node* root;
    Node* currentDirectory;
    void AddNode(Node* newNode);
    Node* FindNode(std::string name);
    
public:
    FileSystem();
    ~FileSystem();
    std::string mkdir(std::string name);
    std::string touch(std::string name);
    std::string pwd();
    std::string ls();
    std::string rm(std::string name);
    std::string mv(std::string from, std::string to);
    std::string cd(std::string dirname);
    
    
};

#endif /* fileSystem_hpp */
