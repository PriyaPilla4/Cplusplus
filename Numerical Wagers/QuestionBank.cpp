//
//  Question Bank.cpp
//  Project 1
//
//  Created by Priya Pilla on 1/28/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#include "QuestionBank.hpp"
#include "Question.cpp"
//#include "Game.cpp"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
using namespace std;



QuestionBank::QuestionBank(){
    
}

QuestionBank::QuestionBank(string fileName){
    questionsFile.open(fileName);
    LoadQuestions();
}

void QuestionBank::LoadQuestions(){
    for (int i = 0; i < 4; i++) {
        Question *q[i];
        questionsFile >> ans;
        getline(questionsFile, str);
        q[i] = new Question(ans, str);
        //q[i]->Question(ans, str);
        questions.push_back(*q[i]);
    }
    
    questionsFile.close();
}

Question QuestionBank::GetNextQuestion(){
    for (int n = 0; n < 4; n++) {
        cout << "Questions #" << n << endl;
        return q[n].getText();
        break;
    }
}



