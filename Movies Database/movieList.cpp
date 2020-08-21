//
//  MovieList.cpp
//  ProjectThree
//
//  Created by Priya Pilla on 3/20/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#include "movieList.hpp"
#include <vector>
MovieList::MovieList(){
    
    head = nullptr;
}

void MovieList::Insert(std::string title, std::string leadActorActress, std::string description, int year){
    
    Movie* newNode = new Movie;
    
    if (head == nullptr) { // List empty
        head = newNode;
        //details
        newNode->SetTitle(title);
        newNode->SetLeadActorActress(leadActorActress);
        newNode->SetDescription(description);
        newNode->SetYearReleased(year);
      
    }
    else {
        newNode->SetNext(head);
        head->SetPrev(newNode);
        head = newNode;
        //details
        newNode->SetTitle(title);
        newNode->SetLeadActorActress(leadActorActress);
        newNode->SetDescription(description);
        newNode->SetYearReleased(year);
    }
 
   
}

void MovieList::Insert(Movie* movie){

    
    if (head == nullptr) {
        head = movie;
        head->SetNext(nullptr);
        head->SetPrev(nullptr);
    }else{
    
    movie->SetNext(head);
    head->SetPrev(movie);
        head = movie;
        
    }
            
}

bool MovieList::Delete(std::string title){
   
    Movie* sucNode = new Movie;
    Movie* predNode = new Movie;
    Movie* curNode = new Movie;
    
    curNode = Search(title);
    
    //CODE FOR DELETE
    sucNode = curNode->GetNext();
    predNode = curNode->GetPrev();

    if (sucNode != nullptr) {
        sucNode->SetPrev(predNode);
    }

    if (predNode != nullptr) {
        predNode->SetNext(sucNode);
    }

    if (curNode == head) { // Removed head
        head = sucNode;
    }

    if (Search(title) == nullptr) {
        return true;
    }else{
        return false;
    }

}

Movie* MovieList::Search(std::string title){
   
    Movie* temp = new Movie;
    temp = head;
   
    int check = 0;
    
    if (temp != nullptr) {
       
        while (temp != nullptr) {
            if (temp->GetTitle() == title) {
                check = 1;
                return temp;
            }else{
                temp = temp->GetNext();
            }
        }
        if (check == 0) {
           
            return nullptr;
        }
        return nullptr;
    }else{
       
        return nullptr;
    }
       
  
}

Movie* MovieList::DetachAndGetFirst(){
   
    Movie* temp = new Movie;
    Movie* sucNode = new Movie;
    
    temp = head;
    sucNode = head -> GetNext();
    head->SetNext(sucNode);
    
    return temp;
   
}

std::vector<Movie> MovieList::GetElements(){
  
    std::vector<Movie> vector;
    int k = 0;
    Movie* temp = head;
    
    while (temp != nullptr) {
        
        vector.push_back(*temp);
        temp = temp->GetNext();
        k++;
       
    }

    return vector;
}

void MovieList::PrintList(){
    
    Movie* temp = head;
   
    while (temp != nullptr) {
        
        std::cout << temp->GetTitle() << "   " << temp->GetLeadActorActress() << "   "  << temp->GetDescription() << "  " << temp->GetYearReleased() << std::endl;
        temp = temp->GetNext();
    }
    
   
}
