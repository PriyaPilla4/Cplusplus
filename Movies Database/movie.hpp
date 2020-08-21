//
//  Movie.hpp
//  ProjectThree
//
//  Created by Priya Pilla on 3/20/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef movie_hpp
#define movie_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

class Movie{
private:
    std::string title;
    std::string leadActorActress;
    std::string description;
    int yearReleased;
    Movie* next;
    Movie* prev;
    
public:
    Movie();
    Movie(std::string _title, std::string _leadActorActress, std::string _description, int _yearReleased);
    Movie* GetNext();
    void SetNext(Movie* next_);
    Movie* GetPrev();
    void SetPrev(Movie* prev_);
    void SetTitle(std::string title_);
    std::string GetTitle();
    void SetLeadActorActress(std::string leadActorActress_);
    std::string GetLeadActorActress();
    void SetDescription (std::string description_);
    std::string GetDescription();
    void SetYearReleased(int year_);
    int GetYearReleased();
    
};

#endif /* movie_hpp */
