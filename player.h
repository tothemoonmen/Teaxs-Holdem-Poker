#pragma once

//
// Created by AMYES on 3/11/2024.
//

#ifndef TEAXSHOLDEM_PLAYER_H
#define TEAXSHOLDEM_PLAYER_H
#endif //TEAXSHOLDEM_PLAYER_H

#include "cards.h"
#include "dealer.h"
class player :public dealer {
protected:
    cards playerHand[2];//Creates player hand which is an array of cards
    int purse=1000;// betting amount player has
    cards temp[7];// creating a temporary hand to evaluate straights.
    bool fold= false;//use to see if player folds

public:
player();
void playerDraw();//draws a card for the player
void printPlayerHand();//prints player hand
int evlauteHand();//returns the corresponding value of the hand
void choice();// user decides to fold, raise or check
};


