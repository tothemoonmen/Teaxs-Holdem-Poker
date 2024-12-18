//
// Created by AMYES on 4/19/2024.
//

#ifndef TEAXSHOLDEM_BOT_H
#define TEAXSHOLDEM_BOT_H


#include "player.h"
#include "cards.h"
class bot: public player{
protected:
    cards botTemp[7];// creating a temporary hand to evaluate straights.;
public:
    bot();
    void botPrint();//prints computers hand
    void botDraw();// draws cards for computuer
    int botEvaluateHand(int dealerRange);//returns the corresponding value of the hand
    void botBetRound1();// Is the first round of betting for the computer
    void botBetRound2();// Is the second round of betting for the computer
    void botBetRound3();// Is the thrid round of betting for the computer
    void botBetRound4();// / Is the last round of betting for the computer
    void botGenBet(double percent);//Function used for the computer to bet based off of a percent of it's purse




protected:
  cards botHand[2];// creates computers hand of cards as an array
  int botPurse=1000;// The amount the computer has to bet with
  int botRaiseAmount=0;//The amount the computer has raised
    int botSuitCountCard1=1;//The amount of like suits in the botTemp
    int botSuitCountCard2=1;//the amount of like suits in the botTemp
    int botStarightCount=1;//The number of cards in a row in botTemp
    int botCardMatch1 = 1;//The amount of like cards in the botTemp
    int botCardMatch2 = 1;//The amount of like cards in the botTemp


};


#endif //TEAXSHOLDEM_BOT_H
