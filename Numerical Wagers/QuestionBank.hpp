//
//  Question Bank.hpp
//  Project 1
//
//  Created by Priya Pilla on 1/28/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef QuestionBank_hpp
#define QuestionBank_hpp
using namespace std;
#include <vector>
#include <fstream>
#include <stdio.h>

class QuestionBank{
public:
    QuestionBank();
    QuestionBank(string fileName);
    Question GetNextQuestion();
private:
    vector<Question> questions;
    ifstream questionsFile;
    void LoadQuestions();
    string ans;
    string str;
    
};

#endif /* QuestionBank_hpp */
