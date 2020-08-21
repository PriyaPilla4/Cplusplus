//
//  The Game.cpp
//  Project 1
//
//  Created by Priya Pilla on 1/28/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#include "Game.hpp"
#include "QuestionBank.cpp"
#include "Question.cpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Game::Game(QuestionBank* qs){
        qs->GetNextQuestion();
}

int Game::GetCurrentScore(){
        cout << "Current score: ";
        return currentScore;
        cout << endl;
}

void Game::SetWager(<#int#> _wager){
    amountWagered = _wager;
}


