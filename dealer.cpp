//
// Created by AMYES on 3/11/2024.
//


#include "dealer.h"

void dealer::printPot() const {
    cout<<"The pot is: "<< pot<<endl;
}

void dealer::showCards(int cardRange)const {

        cout<<"The dealer shows:"<<endl;
        for(int i = 0;i<cardRange; i++)
           dealerHand[i].print();
        cout<<endl;
}

void dealer::dealerDraw() {
    for(int i = 0;i<5; i++) {
        dealerHand[i].drawCard();
        for (int j = 0; j < i; j++) {
            if (dealerHand[j] == dealerHand[i]) {
                dealerHand[i].drawCard();
                // After drawing a new card, reset the inner loop to check all previous cards again
                j = -1; // Setting j to -1 because it will be incremented to 0 in the next iteration
            }
        }


    }
}


dealer::dealer() {


//Test for royal flush
//    cards ace;
//    ace.cardSuit ="Spades";
//    ace.cardValue ="Ace";
//
//    dealerHand[0] = ace;  // Ace of Spades
//    dealerHand[1].cardSuit = "Spades";
//    dealerHand[1].cardValue = "King";   // King of Spades
//    dealerHand[2].cardSuit = "Spades";
//    dealerHand[2].cardValue = "Queen";  // Queen of Spades
//    dealerHand[3].cardSuit = "Spades";
//    dealerHand[3].cardValue = "Jack";   // Jack of Spades
//    dealerHand[4].cardSuit = "Spades";
//    dealerHand[4].cardValue = "10";     // 10 of Spades

//You were right this originally would have broke the code and counts as a straight even though it is not;
//    dealerHand[0].cardSuit ="Spades";
//    dealerHand[0].cardValue ="2";
//    dealerHand[1].cardSuit = "Spades";
//    dealerHand[1].cardValue = "3";   // King of Spades
//    dealerHand[2].cardSuit = "Spades";
//    dealerHand[2].cardValue = "5";  // Queen of Spades
//    dealerHand[3].cardSuit = "Spades";
//    dealerHand[3].cardValue = "6";   // Jack of Spades
//    dealerHand[4].cardSuit = "Spades";
//    dealerHand[4].cardValue = "8";     // 10 of Spades

}


