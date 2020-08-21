//
//  main.cpp
//  Project 1
//
//  Created by Priya Pilla on 1/28/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "Game.cpp"
#include "QuestionBank.cpp"
#include "Question.cpp"
using namespace std;


int main(int argc, const char * argv[]) {
    
    string file_Name;
    int guessAns;
    int wager;
    
    cout << "Welcome to Numerical Wagers!" << endl;
    cout << "Please enter the name of the file containing your questions: " << endl;
    cin >> file_Name;
    cout << "Using file " << file_Name << endl;
    
    QuestionBank quesBank;
    Game game;
    
    quesBank.QuestionBank(file_Name);
    
    quesBank.GetNextQuestion();
    game.GetCurrentScore();
    
    cout << "Points to wager?" << endl;
    cin >> wager;
    
    game.SetWager(wager);
    
    cout << "Guess a digit: " << endl;
    cin >> guessAns;
    
    
    //handle # of questions in game
    
    //allow a user to select the option to play again or quit
    
    
    return 0;
}
