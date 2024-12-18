//
// Created by AMYES on 4/19/2024.
//

#include "bot.h"

bot::bot() {
}

void bot::botDraw() {

    for (int i = 0; i < 2; i++) {
        botHand[i].drawCard();
        for (int j = 0; j < 5; j++) {
            bool foundEqual = false;
            if (botHand[i] == dealerHand[j]) { // Check if bot's card is equal to any of the dealer's cards
                botHand[i].drawCard();
                foundEqual = true;
                break;
            }
            if (!foundEqual && (botHand[i] == playerHand[0] || botHand[i] ==
                                                               playerHand[1])) { // Check if bot's card is equal to any of the player's cards
                botHand[i].drawCard();
                break;
            }
            if (!foundEqual && botHand[0] == botHand[1]) { // Check if both cards drawn by the bot are the same
                botHand[i].drawCard();
                break;
            }
        }
    }

}

void bot::botPrint() {
        cout<<"The computer hand is:"<<endl;
        for(auto & i : botHand)
            i.print();
cout<<endl;
}


int bot::botEvaluateHand(int dealerRange){
    //These are used to keep track of the card matches, same suit, and if the cards are in a row
    //Everything is rested to one so that each time the function is called the values are not carried over from the last call
    botSuitCountCard1=1;
    botSuitCountCard2=1;
    botStarightCount=1;
    botCardMatch1 = 1;
    botCardMatch2 = 1;

    cards  botSortTemp; // Define a temporary variable to hold a single card

    for (int i = 0; i < 5; i++) {
        botTemp[i] = dealerHand[i];//seting botTemp 0-4 to dealerHand
    }

    botTemp[5] = botHand[0];//setting botTemp 5 to botHand 0
    botTemp[6] = botHand[1];//setting botTemp 6 to botHand 1

//    Testing
//    cout<<"This is the bot temphand no sort"<<endl;
//   for(int i=0; i<7;i++){
//       botTemp[i].print();
//   }
//   botPrint();

    // Use a sorting algorithm
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 7; j++) {
            // Compare cards using the comparison operator
            if (botTemp[i] > botTemp[j]) {
                botSortTemp = botTemp[i];
                botTemp[i] = botTemp[j];
                botTemp[j] = botSortTemp;
            }
        }
    }
//   Testing
//    botPrint();
//
//    cout<<"This is the bot temphand Sorted"<<endl;
//   for(int i=0; i<7;i++){
//       botTemp[i].print();
//   }


//This part of the code goes through and checks the amount of cards counted as a straight

    for (int i = 0; i < 7; i++) {
        cards botNext = botTemp[i];
        botNext.indexCardValue();
        if (botNext.cardValue == botTemp[i + 1].cardValue) {
            botStarightCount += 1;
        } else if (botNext.cardValue == botTemp[i].cardValue) {
            continue;
        }


        else if (botNext.cardValue != botTemp[i + 1].cardValue) {
            botStarightCount = 1;
        }
    }

//    cout << "The bot straight count is: " << botStarightCount << endl;
//
//    cout<<"bot card1"<<endl;
//    botHand[0].print();
//    cout<<"bot card2"<<endl;
//    botHand[1].print();

    if (botHand[0].cardSuit == botHand[1].cardSuit) { // checks for Flush,kinds, and pairs hand if both cards are the same
        botSuitCountCard1 += 1;
        for (int i = 0; i < dealerRange; i++) {
            if (botHand[0].cardSuit == dealerHand[i].cardSuit) { // checks for Flush,kinds, and pairs hand for card 1
                botSuitCountCard1 += 1;
            }
        }
    }
    else {
        for (int i = 0; i < dealerRange; i++) {
            if (botHand[0].cardSuit == dealerHand[i].cardSuit) { // checks for Flush,kinds, and pairs hand for card 1
                botSuitCountCard1 += 1;
            } else if (botHand[1].cardSuit == dealerHand[i].cardSuit) { // checks for Flush,kinds, and pairs hand for card2
                botSuitCountCard2 += 1;
            }
        }


        for (int i = 0; i < dealerRange; i++) {
            if (botHand[0].cardValue == dealerHand[i].cardValue) { // checks for pairs and three/four of a kind for card 1
                botCardMatch1 += 1;
            } else if (botHand[1].cardValue == dealerHand[i].cardValue) { //checks for pairs and three/four of a kind for card 1
                botCardMatch2 += 1;
            }
        }
    }
//    Testing
//    cout<<"Bot temp after eval"<<endl;
//    for(int i=0; i<7;i++){
//        botTemp[i].print();
//    }
//    cout<<"The bot suit count1 is"<<botSuitCountCard1<<endl;
//    cout<<"The bot suit count2 is"<<botSuitCountCard2<<endl;
//    cout<<"The bot card match count1 is: "<<botCardMatch1<<endl;
//    cout<<"The bot card match count2 is: "<<botCardMatch2<<endl;
//    cout<<endl;


    if(botStarightCount>=5){

        if(botSuitCountCard1 >=5 or botSuitCountCard1>=5){
            if(temp[6].cardValue == "Ace" ){
                return 1;   //Royal flush

            }
            else{
                return 2;//Value for Straight Flush
            }
        }
    }
    if(botCardMatch1==4 or botCardMatch2==4){
        return 3;//Returns four of a kind value
    }

    else if(botCardMatch1==3 and botCardMatch2==2){
        return 4;//returns full house value
    }
    else if(botCardMatch1==2 and botCardMatch2==3){
        return 4;//returns full house value
    }
    if(botSuitCountCard1 >=3 and botSuitCountCard2>=2){
        return 4;//returns full house value
    }
    else if(botSuitCountCard1 >=2 and botSuitCountCard2>=3){
        return 4;//returns full house value
    }
    if(botSuitCountCard1>=5 or botSuitCountCard2>=5){
        return 5; // returns flush value.
    }
    if(botStarightCount>=5){
        return 6;//returns value for straight
    }

    if(botCardMatch1==3 or botCardMatch2==3){
        return 7;//Returns three of a kind value
    }
    else if(botCardMatch1==2 and botCardMatch2==2) {
        return 8;//Returns two pair value
    }
    else if(botCardMatch1==2 or botCardMatch2==2){
        return 9;//Returns pair value
    }
    else{
        return 10;//returns for high card
    }

}

void bot::botGenBet(double percent) {
    botRaiseAmount=(botPurse)*percent;//set bot rasie amount
//    cout<<"The current bet in bot bet is: "<<currentbet<<endl;
    if(currentbet<botRaiseAmount) {
        botPurse = botPurse - botRaiseAmount;//updates botPurse
        currentbet = botRaiseAmount;//update current bet
        pot = pot + botRaiseAmount;//update pot
        cout << "The computer raised: $ " << botRaiseAmount << endl;
        cout << "The computer has $" << botPurse << " remaining" << endl;
        cout << "The current bet amount is: " << currentbet << endl;
        cout<< "Your purse is: $"<<purse<<endl;
    }

    else if (currentbet>botPurse){//Makers sure the computer does not make money
        pot = botPurse+pot;//update pot
        currentbet=botPurse;//update current bet
        botPurse=0;//update bot purse
        cout<<"The computer is going all in!"<<endl;
        cout << "The computer raised: $ " << botRaiseAmount << endl;
        cout << "The computer has $" << botPurse << " remaining" << endl;
        botRaiseAmount=currentbet;
    }
    else{
        botRaiseAmount=currentbet;
        botPurse = botPurse - botRaiseAmount;//updates botPurse
        currentbet = botRaiseAmount;//update current bet
        pot = pot + botRaiseAmount;//update pot
        cout << "The computer raised: $ " << botRaiseAmount << endl;
        cout << "The computer has $" << botPurse << " remaining" << endl;
        cout << "The current bet amount is: " << currentbet << endl;
    }
//    cout<<"The current bet in bot bet at the end is: "<<currentbet<<endl;


}

void bot::botBetRound1() {
    dealerDraw();
    playerDraw();
    botDraw();
    botGenBet(0.05);
    choice();
    if(fold == true){
        botPurse+=pot;
        pot=0;
        botBetRound1();
    }
    else if(fold== false){
        showCards(3);
        botBetRound2();

    }
}
void bot::botBetRound2() {
    if(fold == true){
        botPurse+=pot;
        pot=0;
        botBetRound1();
    }
    else {
        botEvaluateHand(3);
//        Testing
//        cout<<"bot suit count card 1 is: "<<botSuitCountCard1;
//        cout<<"bot suit count card 2 is: "<<botSuitCountCard2;
        if (botSuitCountCard1 >= 3 or botSuitCountCard2 >= 3) {
            botGenBet(.08);

        } else if (botStarightCount >= 3) {
            botGenBet(.08);
        } else if (botCardMatch1 >= 2 or botCardMatch2 >= 2) {
            botGenBet(.01);
        } else if (botSuitCountCard1 >= 2 or botSuitCountCard2 >= 2) {
            botGenBet(.07);
        }
        choice();
        showCards(4);
        botBetRound3();



    }


}

void bot::botBetRound3() {
    if (fold == true) {
        botPurse += pot;
        pot = 0;
        botBetRound1();
    }
    else if(fold== false){
        botEvaluateHand(4);
        if (botSuitCountCard1 >= 4 or botSuitCountCard2 >= 4) {
            botGenBet(.08);
        } else if (botStarightCount >= 4) {
            botGenBet(.08);
        } else if (botCardMatch1 >= 3 or botCardMatch2 >=3 ) {
            botGenBet(.09);
        } else if (botSuitCountCard1 >= 3 or botSuitCountCard2 >= 3) {
            botGenBet(.07);
        } else{
            botGenBet(0.05);
        }
        choice();
        showCards(5);
        botBetRound4();
    }
}
    void bot::botBetRound4() {
        //Use this to skip to the end to test the evaluation
//    dealerDraw();
//    playerDraw();
//    botDraw();
        int botHandValue = botEvaluateHand(5);
        int playerHandValue = evlauteHand();
//    cout<<"The bot hand value is"<<botHandValue<<endl;

        cout << endl;

        if (fold == true) {
            // If the bot decides to fold, it adds the pot to its purse, resets the pot to zero,
            // and proceeds to the next round.
            botPurse += pot;
            pot = 0;
            botBetRound1();
        } else if (fold == false) {
            // If the bot doesn't fold, it evaluates its hand strength and decides on a betting strategy.
            if (botCardMatch1 >= 4 or botCardMatch2 >= 4) {

                if (botSuitCountCard1 >= 5 or botSuitCountCard2 >= 5) {
                    // If the bot has a flush possibility, it further adjusts its betting strategy.
                    botGenBet(.09);
                } else if (botStarightCount >= 5) {
                    // If the bot has a straight possibility, it adjusts its betting strategy.
                    botGenBet(.09);
                } else {
                    // If the bot has matching cards, it adjusts the betting strategy accordingly.
                    botGenBet(.04);
                }
            } else {
                // If the bot doesn't have strong matching cards, it adopts a conservative betting strategy.
                botGenBet(0.05);
            }
            choice();
        }

// Comparison of hand strengths between the player and the bot.
        if (playerHandValue < botHandValue) {
            // If the player's hand is less than , they win the pot, and the bot loses.
            cout << "You won $" << pot << endl;
            botPrint();
            cout << "The bot hand value is: " << botHandValue << endl;
            cout << "Your hand value is: " << playerHandValue << endl;
            printPlayerHand();
            showCards(5);
            purse = pot + purse;
            pot = 0;
            currentbet = 0;
            if (botPurse == 0) {
                // Check if the bot's purse is empty, indicating game over.
                cout << "Game Over!" << endl;
            }
            else {
                // Start a new round if the game is not over.
                cout << "Starting New round!" << endl;
                botBetRound1();
            }
        }
        else if (playerHandValue == botHandValue) {
            // If both hands have equal value, compare the highest cards.
            botPrint();
            printPlayerHand();
            showCards(5);
            cards botHighTemp;
            cards playerHighTemp;
            if (botHand[0] > botHand[1]) {
                botHighTemp = botHand[0];
            } else {
                botHighTemp = botHand[1];
            }

            if (playerHand[0] > playerHand[1]) {
                playerHighTemp = playerHand[0];
            } else {
                playerHighTemp = playerHand[1];
            }

            if (playerHighTemp > botHighTemp) {
                // Player wins if their highest card is stronger.
                cout << "You won $" << pot << endl;
                purse = pot + purse;
                pot = 0;
                currentbet = 0;
                cout << "The bot hand value is: " << botHandValue << endl;
                cout << "Your hand value is: " << playerHandValue << endl;
                if (botPurse == 0) {
                    cout << "Game Over!" << endl;
                } else {
                    cout << "Starting New round!" << endl;
                    botBetRound1();
                }
            } else if (playerHighTemp < botHighTemp) {
                // Player loses if the bot's highest card is stronger.
                cout << "You lost!" << endl;
                cout << "You had the same hand but the computer had a higher card :(" << endl;
                cout << "The bot hand value is: " << botHandValue << endl;
                cout << "Your hand value is: " << playerHandValue << endl;
                if (purse == 0) {
                    cout << "Game Over!" << endl;
                } else {
                    cout << "Starting New round!" << endl;
                    botBetRound1();
                }
            } else if (playerHighTemp == botHighTemp) {
                // If both players have equal highest cards, it's a draw.
                cout << "It's a draw!" << endl;
                cout << "The bot hand value is: " << botHandValue << endl;
                cout << "Your hand value is: " << playerHandValue << endl;
                purse = purse + (pot / 2);
                botPurse = botPurse + (pot / 2);
                pot = 0;
                currentbet = 0;
                botBetRound1();
            }
        }
        else if (botHandValue < playerHandValue) {
            // If the bot's hand is less than , the player loses the pot.
            cout << "You lost!" << endl;
            botPrint();
            printPlayerHand();
            showCards(5);
            cout << "The bot hand value is: " << botHandValue << endl;
            cout << "Your hand value is: " << playerHandValue << endl;
            botPurse = botPurse + pot;
            pot = 0;
            currentbet = 0;
            if (purse == 0) {
                cout << "Game Over!" << endl;
            } else {
                cout << "Starting New round!" << endl;
                botBetRound1();
            }
        }

    }




