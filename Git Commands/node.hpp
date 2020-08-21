//
//  Node.hpp
//  projectfour
//
//  Created by Priya Pilla on 4/18/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef node_hpp
#define node_hpp

#include <stdio.h>
#include <string>
#include <vector>

class Node{
private:
    char type;
    std::string name;
    std::vector<Node*> children;
    Node* parent;
    void RemoveHelper(Node* subtree);
    
public:
    Node(std::string name, char type);
    Node();
    void AddChild(Node* child);
    void AddChild(std::string name, char type);
    bool RemoveChild(std::string name);
    void SetParent(Node* parent);
    void SetType(char type);
    void SetName(std::string name);
    Node* GetChild(std::string name);
    std::vector<Node*> GetChildren();
    Node* GetParent();
    char GetType();
    std::string GetName();
    
};

#endif /* node_hpp */
