//
//  The Game.hpp
//  Project 1
//
//  Created by Priya Pilla on 1/28/20.
//  Copyright © 2020 Priya Pilla. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>

class Game {
public:
    Game();
    Game(QuestionBank* qs);
    int AskQuestion(){
        
    };
    void AdjustPoints(bool);
    void SetWager(int);
    int GetWager();
    int GetCurrentScore();
private:
    QuestionBank* questions;
    int amountWagered;
    int currentScore;
};


#endif /* Game_hpp */
