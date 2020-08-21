//
//  Question.cpp
//  Project 1
//
//  Created by Priya Pilla on 1/28/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#include "Question.hpp"
//#include "QuestionBank.cpp"
//#include "Game.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;


Question::Question(){
 
}

Question::Question(string answ, string ques){
    text = ques;
    answer = answ;
}

string Question::getText(){
    return text;
}

