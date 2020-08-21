//
//  Menu.cpp
//  ProjectThree
//
//  Created by Priya Pilla on 3/20/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#include "menu.hpp"
#include <fstream>
#include <string>
#include <iostream>




Menu::Menu(){
  movieTable = &hashObj;
}

int Menu::GetSelection(){

    int choice = 0;
    
    
    do {
        std::cout << "--------Make a choice:----------" << std::endl
        << "Read database file (1)" << std::endl
         << "Add a new movie (2)" << std::endl
         << "Search for a movie by title (3)" << std::endl
         << "Delete a movie (4)" << std::endl
         << "Display all movies (5)" << std::endl
         << "Display movies sorted by release date (6)" << std::endl
         << "List number of movies per year (7)" << std::endl
         << "Exit (-1)" << std::endl
        << "-------------------------------" << std::endl
        << "Your choice:" << std::endl;
        
        std::cin >> choice;
        
        if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != -1) {
            std::cout << "Please enter a valid choice" << std::endl;
        }
        
    } while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != -1);
    
    
    
    return choice;
}

void Menu::AddMovie(){
   
    std::string title;
    std::string leadActorActress;
    std::string description;
    int year;
    
    std::cout << "Enter movie's title: " << std::endl;
    std::cin >> title;
    std::cout << "Enter movie's lead actor/actress: " << std::endl;
    std::cin >> leadActorActress;
    std::cout << "Enter movie's description: " << std::endl;
    std::cin >> description;
    std::cout << "Enter movie's release year: " << std::endl;
    std::cin >> year;
     
    movieTable->Insert(title, leadActorActress, description, year);
    std::cout << "Movie inserted successfully..." << std::endl;
}

void Menu::SearchMovie(){
   
    std::string title;
    Movie* movie;
    
    std::cout << "Enter movie's title: " << std::endl;
    std::cin >> title;
    
    movie = movieTable->Search(title);
    if (movie != nullptr) {
        std::cout << "Movie found:" << std::endl;
        std::cout << "Title: " << movie->GetTitle() << std::endl;
        std::cout << "Lead Actor/Actress: " << movie->GetLeadActorActress() << std::endl;
        std::cout << "Description: " << movie->GetDescription() << std::endl;
        std::cout << "Year released: " << movie->GetYearReleased() << std::endl;
    }else{
        std::cout << "Movie not found" << std::endl;
    }
}

void Menu::LoadMovies(std::string filename){
    
    std::ifstream hashFile;
    
    hashFile.open(filename.c_str());
    
    if (!hashFile.is_open()) {
        std::cout << "Could not open file " << std::endl;
    }
    
    std::string title;
    std::string leadActorActress;
    std::string description;
    int year;
 
    
    while (!hashFile.eof()) {
        
        
        getline(hashFile, title, ',');
        getline(hashFile, leadActorActress, ',');
        getline(hashFile, description, ',');
       
        hashFile >> year;
        
         hashFile.ignore(1000, '\n');
        
        if (hashFile.peek() == '\n'){
             hashFile.ignore(1000, '\n');
        }
        
        
        movieTable->Insert(title, leadActorActress, description, year);
        
    }
    
    hashFile.close();
    std::cout << "File loaded successfully.." << std::endl;
}

HashTable* Menu::GetMovieTable(){
    return movieTable;
}

void Menu::StartMenu(){
   
    int choice = 0;
    std::string name;
    std::string deleteMovie;
    std::cout << std::endl << "Welcome to The Movie Database" <<std::endl;
    do {
        choice = GetSelection();
        
        switch (choice) {
            case 1:
                
                std::cout << "Enter filename: " << std::endl;
                std::cin >> name;
                LoadMovies(name);
                break;
                
            case 2:
                AddMovie();
                break;
                
            case 3:
                SearchMovie();
                break;
                
            case 4:
                std::cout << "Enter movie title to delete: " << std::endl;
                std::cin >> deleteMovie;
                if (movieTable->Delete(deleteMovie) == true) {
                    std::cout << "Movie has been deleted! " << std::endl;
                }else{
                    std::cout << "Movie couldn't be deleted " << std::endl;
                }
                break;
                
            case 5:
                movieTable->PrintTable();
                break;
                
            case 6:
                movieTable->PrintSorted();
                break;
                
            case 7:
                //list number of movies per year
                movieTable->PrintYearFrequency();
                break;
            case -1:
                break;
                
            default:
                break;
        }
        
    } while (choice != -1);
    
    
        
    
}


