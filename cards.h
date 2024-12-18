#pragma once

//
// Created by AMYES on 3/11/2024.
//

#ifndef TEAXSHOLDEM_CARDS_H
#define TEAXSHOLDEM_CARDS_H
#include "string"
#endif //TEAXSHOLDEM_CARDS_H
#include "iostream"
using namespace std;
class cards {

public:
    string cardValue;//card value saved as a string
    string cardSuit;// card suit saved as a string
    static const int N = 13;//the amount of cards in a suit
    static const int C = 4;//The suits in a deck of cards
    const char* values[N] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};//card values
    const char* suits[C] = {"Hearts", "Diamonds", "Clubs","Spades"};//card suits
    void indexCardValue();//takes a card and changes its value to the next in the values array
    void drawCard();// assings a card value and suit to a card
    cards();//constructor
    bool operator==(const cards &compare) const;//== overload
    bool operator>(const cards &compare) const;//> overload
    bool operator<(const cards &compare) const;//<overload
    cards operator=(cards &compare);//= overload
    void print() const;//prints card





};


