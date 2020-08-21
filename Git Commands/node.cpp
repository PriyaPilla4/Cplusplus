//
//  Node.cpp
//  projectfour
//
//  Created by Priya Pilla on 4/18/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#include "node.hpp"
#include <iostream>
#include <vector>


void Node::RemoveHelper(Node* subtree){
   
    if ((subtree->GetChildren()).empty() == true) {
        
        for (int i = 0; i < children.size(); i++) {
            if (children.at(i) == subtree) {
                     children.erase(children.begin()+i);
            }
        }
        
    }else{
        for (int i = 0; i < (subtree->GetChildren()).size(); i++) {
            (subtree->GetChildren()).clear();
        }
        
        for (int i = 0; i < children.size(); i++) {
            if (children.at(i) == subtree) {
                     children.erase(children.begin()+i);
            }
        }
    }
}
    
Node::Node(std::string name, char type){
    SetName(name);
    SetType(type);
    if (name == "root") {
        SetParent(nullptr);
    }
}

Node::Node(){
    
}

void Node::AddChild(Node* child){
    children.push_back(child);
}

void Node::AddChild(std::string name, char type){
    Node* newChild = new Node(name, type);
    children.push_back(newChild);
    
}

bool Node::RemoveChild(std::string name){
  
    RemoveHelper(GetChild(name));
    
    if (GetChild(name) == nullptr) {
        return true;
    }else{
        return false;
    }

}

void Node::SetParent(Node* parent){
    this->parent = parent;
}

void Node::SetType(char type){
    this->type = type;
}

void Node::SetName(std::string name){
    this->name = name;
}

Node* Node::GetChild(std::string name){
    Node* theNode = nullptr;
    
    for (int i = 0; i < children.size(); i++) {
        if (children.at(i)->GetName() == name) {
            theNode = children.at(i);
        }
    }
    return theNode;
}

std::vector<Node*> Node::GetChildren(){
    return children;
}

Node* Node::GetParent(){
    return parent;
}

char Node::GetType(){
    return type;
}

std::string Node::GetName(){
    return this->name;
}
