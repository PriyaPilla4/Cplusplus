//
//  FileSystem.cpp
//  projectfour
//
//  Created by Priya Pilla on 4/18/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#include "fileSystem.hpp"
#include <iostream>
#include <string>

void FileSystem::AddNode(Node* newNode){
   
}

Node* FileSystem::FindNode(std::string name){
    return  currentDirectory->GetChild(name);
}
    
FileSystem::FileSystem(){
    root = new Node("/root", 'd');
    root->SetParent(nullptr);
    currentDirectory = root;
    
}

FileSystem::~FileSystem(){
    
}

std::string FileSystem::mkdir(std::string name){

    if(currentDirectory->GetChild(name) != nullptr){
        return "Error: " + name + " exists";
    }else if (currentDirectory->GetChild(name) == nullptr) {
        
        currentDirectory->AddChild(name, 'd');
        
            if (currentDirectory->GetChild(name) != nullptr) {
            currentDirectory->GetChild(name)->SetParent(currentDirectory);
                return "directory " + name + " created successfully";
            }else{
                return "directory " + name + " was not successfully created";
            }
        
    }else{
        return "";
    }
    
}

std::string FileSystem::touch(std::string name){

    if(currentDirectory->GetChild(name) != nullptr){
        return "Error: " + name + " exists";
    }else if (currentDirectory->GetChild(name) == nullptr) {
        currentDirectory->AddChild(name, 'f');
        
        if (currentDirectory->GetChild(name) != nullptr) {
            currentDirectory->GetChild(name)->SetParent(currentDirectory);
            return "file " + name + " created successfully";
        }else{
            return "file " + name + " was not successfully created";
        }
    }else{
        return "";
    }
   
}

std::string FileSystem::pwd(){
   
    std::string directoryPath = "";
    Node* tempDirectory;
    
    tempDirectory = currentDirectory;
    directoryPath = tempDirectory->GetName();
    
    while (tempDirectory->GetParent() != nullptr) {
       
        directoryPath.insert(0, tempDirectory->GetParent()->GetName() + "/");
        tempDirectory = tempDirectory->GetParent();
    }
    return directoryPath;
  
}

std::string FileSystem::ls(){
    
    std::string filesAndDirectories = "";
    
    for (int i = 0; i < currentDirectory->GetChildren().size(); i++) {
        if (currentDirectory->GetChildren().at(i) != nullptr){
            char c = currentDirectory->GetChildren().at(i)->GetType();
            std::string s(1, c);
            filesAndDirectories.append(s + " " + currentDirectory->GetChildren().at(i)->GetName() + "\n");
        }
    }
    
    return filesAndDirectories;
}

std::string FileSystem::rm(std::string name){
    
    if (currentDirectory->GetChild(name) != nullptr) {
        if ( currentDirectory->RemoveChild(name) == true) {
            return name + " removed successfully";
        }else{
            return "couldn't remove successfully";
        }
        
    }else{
        return "No such file or directory";
    }
 
}

std::string FileSystem::mv(std::string from, std::string to){
   
    if(currentDirectory->GetChild(from) != nullptr){
        currentDirectory->GetChild(from)->SetName(to);
        if (currentDirectory->GetChild(to) != nullptr) {
            return "file/dir renamed successfully";
        }
    }else{
        return "file not found";
    }
       
    return "";
}

std::string FileSystem::cd(std::string dirname){
   
    std::string directoryPath = "";
    Node* tempDirectory;
    
    if (dirname == "..") {
        if (currentDirectory->GetParent()  != nullptr) {
            currentDirectory = currentDirectory->GetParent();
            return pwd();
        }else{
            return "can't change to directory " + dirname;
        }
        
    }
    
    if (FindNode(dirname) != nullptr) {
        if (FindNode(dirname)->GetType() != 'd') {
            return dirname + ": is not a directory";
        }
        
        currentDirectory = FindNode(dirname);
        tempDirectory = currentDirectory;
        directoryPath = tempDirectory->GetName();
        
        while (tempDirectory->GetParent() != nullptr) {
            
            directoryPath.insert(0, tempDirectory->GetParent()->GetName() + "/");
            tempDirectory = tempDirectory->GetParent();
        }
        return directoryPath;
        
    }else if (FindNode(dirname) == nullptr){
       
        return dirname + ": no such directory";
    }else if (FindNode(dirname) == currentDirectory){
        return "can't change to directory " + dirname;
    }else{
        return "can't change to directory " + dirname;
    }
   
}
