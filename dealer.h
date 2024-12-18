#pragma once
//
// Created by AMYES on 3/11/2024.
//
#include "string"
#include "cards.h"
#include "iostream"
#include <cstring> // Include the <cstring> header for strcmp

using namespace std;
#ifndef TEAXSHOLDEM_DEALER_H
#define TEAXSHOLDEM_DEALER_H

#endif //TEAXSHOLDEM_DEALER_H
class dealer{

protected:
    int pot=0;//Where all the bets go
     cards dealerHand[5];//array of 5 cards to make the dealers hand
    int currentbet=0;//currenetbet is used so the computer and user bet the same are greater

public:
    dealer();//constructor
    void showCards(int cardRange) const;//prints the dealer cards
    void printPot() const;//prints the pot
    void dealerDraw();//dealer draws a cards
};