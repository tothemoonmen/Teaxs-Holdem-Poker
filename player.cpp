#include "player.h"
#pragma once
#include <cctype> // Include the cctype library for the tolower() function
#include <stdexcept> // Include the stdexcept library for exception handling
#include <limits>
#include <vector>
//
// Created by AMYES on 3/11/2024.
//

player::player() {

    }


void player::playerDraw() {
    for (int i = 0; i < 2; i++) {
        playerHand[i].drawCard();
        for (int j = 0; j < 4; j++) {
            if (playerHand[i] == dealerHand[j] or
                playerHand[1] == playerHand[0]) {//logic so player can not have the same card as its self or dealer;
                playerHand[i].drawCard();
            }

        }
    }
}

void player::choice()  {
    fold= false;
    printPlayerHand();
    while (true) {
        char choice;
        cout << "What would you like to do? Enter 'R' for raise, 'C' to check, or 'F' to fold" << endl;
        cin >> choice;
        cout<<endl;
        choice = tolower(choice); // Convert choice to lowercase

        if (choice == 'r') { // Check if the choice is 'r' (either uppercase or lowercase)
            fold= false;
            double amount;
            cout << "How much do you want to raise?" << endl;
            cin >> amount;
            cout<<"Your purse is: "<<purse<<endl;

            if (cin.fail()) { // Check if the input for amount is invalid
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                cerr << "Invalid input for raise amount. Please enter a valid number." << endl;
                continue; // Continue to the next iteration of the loop
            } else if(amount>purse){
                cerr << "Insufficient funds. Please enter an amount less than are equal to: "<<purse << endl;
                continue; // Continue to the next iteration of the loop

            }
            else if(amount<currentbet){

                cerr << "Please enter an amount greater than are equal to the current bet of: $ "<<currentbet << endl;
                continue;

            }


            cout << "You raised by $" << amount << endl;
            currentbet= amount;//updating currentbet
            purse= purse -amount; // updating the player's purse  .
            pot= pot +amount;   // updating the pot.
            cout<<"Your purse is: "<<purse<<endl;

            printPot();
            break; // Exit the loop
        } else if (choice == 'c') { // Check if the choice is c
            fold= false;
            cout << "You chose to check to:"<<currentbet << endl;
            if(purse<currentbet){
                cout<<"You are going all in!"<<endl;
                pot+=purse;
                purse=0;
                printPot();

                break; // Exit the loop

            }
            else{

                purse = purse - currentbet; // updating the player's purse  .
                pot+=currentbet;   // updating the pot.
                cout<<"Your purse is: "<<purse<<endl;
                printPot();

                break; // Exit the loop

            }

        }
        else if(choice=='f'){
            fold= true;
            cout<< "You chose to fold."<<endl;
            cout<<"Starting new round! "<<endl;

            break;

        }
        else { // Invalid choice
            cerr << "Invalid choice. Please enter 'R' for raise, 'C' to check, or 'F' to fold" << endl;
        }
    }
}




int player::evlauteHand() {
    //These are used to keep track of the card matches, same suit, and if the cards are in a row
    //Everything is rested to one so that each time the function is called the values are not carried over from the last call
    int suitMatchCard1 = 1;
    int suitMatchCard2 = 1;
    int cardMatch1 = 1;
    int cardMatch2 = 1;
    int straight = 1;

//   Testing
//    cout<<"This is the dealerHand in player eval "<<endl;
//
//    for (int i = 0; i < 5; i++) {
//        dealerHand[i].print();
//    }
    for (int i = 0; i < 5; i++) {
        temp[i] = dealerHand[i];//set temp 0-4 to dealerHand
    }
    temp[5] = playerHand[0];// Set temp to values of player hand.
    temp[6] = playerHand[1]; // Set temp to values of player hand.
    cards sortTemp; // Define a temporary variable to hold a single card

//    Testing
//    cout<<"This is the temphand no sort"<<endl;
//   for(int i=0; i<7;i++){
//       temp[i].print();
//   }

    // Use a sorting algorithm
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 7; j++) {
            // Compare cards using the comparison operator
            if (temp[i] > temp[j]) {
                sortTemp = temp[i];
                temp[i] = temp[j];
                temp[j] = sortTemp;
            }
        }
    }
    if (playerHand[0].cardSuit == temp[1].cardSuit) {

    }
    // list print of sorting to check if sorted correctly
//    cout << "This is temp list sorted" << endl;
//    for (const auto &i: temp) {
//        i.print();
//    }

//This part of the code goes through and checks the amount of cards are counted as a straight
    for (int i = 0; i < 7; i++) {
        cards next = temp[i];
        next.indexCardValue();
        if (next.cardValue == temp[i + 1].cardValue) {
            straight += 1;
        } else if (next.cardValue == temp[i].cardValue) {
            continue;
        }

        else if (next.cardValue != temp[i + 1].cardValue) {
            straight = 1;
        }
    }
//    cout << "The straight count is: " << straight << endl;


    if (playerHand[0].cardSuit == playerHand[1].cardSuit) { // checks for Flush,kinds, and pairs hand if both cards are the same
        suitMatchCard1 += 1;
        for (auto &i: dealerHand) {
            if (playerHand[0].cardSuit == i.cardSuit) { // checks for Flush,kinds, and pairs hand for card 1
                suitMatchCard1 += 1;
            }
        }
    }
    else {
        for (auto &i: dealerHand) {
            if (playerHand[0].cardSuit == i.cardSuit) { // checks for Flush,kinds, and pairs hand for card 1
                suitMatchCard1 += 1;
            } else if (playerHand[1].cardSuit == i.cardSuit) { // checks for Flush,kinds, and pairs hand for card2
                suitMatchCard2 += 1;
            }
        }


        for (auto &i: dealerHand) {
            if (playerHand[0].cardValue == i.cardValue) { // checks for pairs and three/four of a kind for card 1
                cardMatch1 += 1;
            } else if (playerHand[1].cardValue == i.cardValue) { //checks for pairs and three/four of a kind for card 1
                cardMatch2 += 1;
            }
        }
    }
// Testing
//    cout<<"The suit count1 is"<<suitMatchCard1<<endl;
//    cout<<"The suit count2 is"<<suitMatchCard2<<endl;
//    cout<<"The card match count1 is: "<<cardMatch1<<endl;
//    cout<<"The card match count2 is: "<<cardMatch2<<endl;
//    cout<<endl;



    if(straight>=5){

         if(suitMatchCard1 >=5 or suitMatchCard2>=5){
             if(temp[6].cardValue == "Ace" ){
//                 cout<<"You have a royal flush! "<<endl;
                 return 1;   //Royal flush

             }
             else{
//                 cout<<"You have a Straight flush! "<<endl;
                 return 2;//Value for Straight Flush
             }
        }
    }
    if(cardMatch1==4 or cardMatch2==4){
//        cout<<"You have a four of kind! "<<endl;
        return 3;//Returns four of a kind value
    }

    else if(cardMatch1==3 and cardMatch2==2){
//        cout<<"You have a full house"<<endl;
        return 4;//returns full house value
    }
    else if(cardMatch1==2 and cardMatch2==3){
//        cout<<"You have a full house"<<endl;
        return 4;//returns full house value
    }
    if(suitMatchCard1 >=3 and suitMatchCard2>=2){
//        cout<<"You have a full house"<<endl;
        return 4;//returns full house value
    }
    else if(suitMatchCard1 >=2 and suitMatchCard2>=3){
//        cout<<"You have a full house"<<endl;
        return 4;//returns full house value
    }
    if(suitMatchCard1>=5 or suitMatchCard2>=5){
//        cout<<"You have a flush!"<<endl;
        return 5; // returns flush value.
    }
    if(straight>=5){
//        cout<<"You have a straight!"<<endl;
        return 6;//returns value for straight
    }

    if(cardMatch1==3 or cardMatch2==3){
//        cout<<"You have a three of a kind!"<<endl;
        return 7;//Returns three of a kind value
    }
    else if(cardMatch1==2 and cardMatch2==2) {
//        cout<<"You have a two pair!"<<endl;
        return 8;//Returns two pair value
    }
    else if(cardMatch1==2 or cardMatch2==2){
//        cout<<"You have a pair!"<<endl;
        return 9;//Returns pair value
    }
    else{
//        cout<<"You have a high card!"<<endl;
        return 10;//returns for high card
    }

}


void player::printPlayerHand() {
    cout<<"Your hand is:"<<endl;
    for(int i=0;i<2;i++) {
        playerHand[i].print();
    }
    cout<<endl;
}