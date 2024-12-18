
#pragma once

//
// Created by AMYES on 3/11/2024.
//

#include "cards.h"
#include "iostream"
#include <cstdlib>
#include "random"
#include <ctime>
#include <thread>

using namespace std;

cards::cards(){
    cardSuit="Defult";
    cardValue="Defult";
}




// Assuming definitions for values and suits arrays




void cards::drawCard( ) {
    // Providing a seed value
    srand((unsigned) time(NULL));

    random_device rd;  // Obtain a random number from hardware

    mt19937 gen(rd()); // Seed the generator

    uniform_int_distribution<> distr(0,12);


    // Get a random number
    int randomValue = distr(gen);
    int randomSuit =distr(gen)%4;


    cardValue = values[randomValue];
    cardSuit = suits[randomSuit];
}


void cards::indexCardValue() {
//    cout<<"Card value before index:"<< cardValue<<endl;

    for(int i=0;i<13;i++){
        if(cardValue=="Ace"){
            break;
        }
        else if (cardValue== values[i]){
            cardValue= values[i+1];
//            cout<<"Card value after index:"<< cardValue<<endl;
            break;
        }
    }
}


bool cards::operator==(const cards &compare) const {
    if (compare.cardValue == cardValue){
        return true;
    }
    else{
        return false;
    }

}
ostream & operator << (ostream &out, const  cards &c){
    cout<<"The card suit is"<<endl;
    out<<c.cardSuit<<endl;
    out<<c.cardValue<<endl;
    return out;
}

bool cards::operator>(const cards &compare) const {
    int cardListValue = -1; // Initialize to some default value
    int compareListValue = -1; // Initialize to some default value
    for (int i = 0; i < 13; i++) {
        if (cardValue == values[i]) {
            cardListValue = i;
            break; // Break out of the loop once a match is found
        }
    }
    for (int i = 0; i < 13; i++) {
        if (compare.cardValue == values[i]) {
            compareListValue = i;
            break; // Break out of the loop once a match is found
        }
    }
    if (cardListValue == -1 || compareListValue == -1) {
        // Handle the case where a card value was not found in the values array
        return false;
    }
    // Return true if cardListValue is greater than compareListValue
    return cardListValue > compareListValue;
}


bool cards::operator<(const cards &compare) const {
    if(!cards::operator>(compare)){
        return true;
    }
    else {
        return false;
    }
}

cards cards::operator=(cards &compare) {
    cards cardEquals;
    cardValue = compare.cardValue;
    cardSuit = compare.cardSuit;
    return cardEquals;
}

void cards::print() const{
    cout<< cardValue << " of " << cardSuit<<endl;
}
