//
//  Questions.hpp
//  Project 1
//
//  Created by Priya Pilla on 1/30/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef Question_hpp
#define Question_hpp
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

class Question{
public:
    Question();
    Question(string answ, string ques);
    string getText();
    bool answerContainsDigit(char digit){
        if (digit) {
            <#statements#>
        }
    };
    string getAnswerWithPlaceholders(vector<char>);
    bool allDigitsGuessed(string);
private:
    string text;
    string answer;
    string answ;
    string ques;
};


#endif /* Question_hpp */
