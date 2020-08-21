//
//  Movie.cpp
//  ProjectThree
//
//  Created by Priya Pilla on 3/20/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#include "movie.hpp"
#include <vector>

Movie::Movie(){
    title = "";
    leadActorActress = "";
    description = "";
    yearReleased = 0;
    next = nullptr;
    prev = nullptr;
}

Movie::Movie(std::string _title, std::string _leadActorActress, std::string _description, int _yearReleased){
    title = _title;
    leadActorActress = _leadActorActress;
    description = _description;
    yearReleased = _yearReleased;
    next = nullptr;
    prev = nullptr;
}

Movie* Movie::GetNext(){
    return next;
}

void Movie::SetNext(Movie *next_){
    next = next_;
}

Movie* Movie::GetPrev(){
    return prev;
}

void Movie::SetPrev(Movie *prev_){
    prev = prev_;
}

void Movie::SetTitle(std::string title_){
    title = title_;
}

std::string Movie::GetTitle(){
    return title;
}

void Movie::SetLeadActorActress(std::string leadActorActress_){
    leadActorActress = leadActorActress_;
}

std::string Movie::GetLeadActorActress(){
    return leadActorActress;
}

void Movie::SetDescription(std::string description_){
    description = description_;
}

std::string Movie::GetDescription(){
    return description;
}

void Movie::SetYearReleased(int year_){
    yearReleased = year_;
}

int Movie::GetYearReleased(){
    return yearReleased;
}
