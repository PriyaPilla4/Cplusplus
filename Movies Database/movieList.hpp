//
//  MovieList.hpp
//  ProjectThree
//
//  Created by Priya Pilla on 3/20/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef movieList_hpp
#define movieList_hpp

#include <stdio.h>
#include "movie.hpp"
#include <vector>

class MovieList{
private:
    
    Movie* head;
    
public:
    
    MovieList();
    void Insert(std::string title, std::string leadActorActress, std::string description, int year);
    void Insert(Movie* movie);
    bool Delete(std::string title);
    Movie* Search(std::string title);
    Movie* DetachAndGetFirst();
    std::vector<Movie> GetElements();
    void PrintList();
    
};

#endif /* movieList_hpp */
